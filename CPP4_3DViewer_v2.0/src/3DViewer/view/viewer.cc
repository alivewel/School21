#include "viewer.h"

#include <QColorDialog>
#include <QDir>
#include <QFileDialog>
#include <iostream>

#include "ui_viewer.h"

Viewer::Viewer(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Viewer), controller_(controller) {
  ui->setupUi(this);
  SettingsLoad("new");
  QCoreApplication::instance()->connect(QCoreApplication::instance(),
                                        &QCoreApplication::aboutToQuit, this,
                                        &Viewer::SettingsSave);
}

Viewer::~Viewer() { delete ui; }

void Viewer::on_uploadFileButton_clicked() {
  QString filename = QFileDialog::getOpenFileName(
      this, tr("Open File"), "../../../", "All files (*.obj)");
  if (!filename.isEmpty()) {
    int error = 0;
    std::string pathToFile = filename.toStdString();
    controller_->ResetInfo();
    controller_->StartParsingFile(pathToFile, &error);
    if (!error && controller_->GetVerticesAmount() &&
        controller_->GetFacetsAmount() && !controller_->GetFacets().empty() &&
        !controller_->GetVertexes().empty()) {
      ui->GLwidget->update();
      QFileInfo fileInfo(filename);
      QString basename = fileInfo.fileName();
      QMessageBox::information(this, tr("File Name"), basename);
      ui->label_filename_value->setText(basename);
      ResetMoveRotateZoom();
      ModelInfo();
    } else {
      QMessageBox::information(this, tr("Error"),
                               "File is corrupt or you don't have permission");
    }
  } else {
    QMessageBox::information(this, tr("Error"),
                             "File path entered incorrectly");
  }
}

void Viewer::on_doubleSpinBox_move_x_valueChanged(double arg1) {
  if (ui->GLwidget->moveX != arg1) {
    controller_->MoveModel(arg1 - ui->GLwidget->moveX,
                           ui->GLwidget->thicknessOfFacets);
    UpdateVertices();
    ui->GLwidget->update();
    ui->GLwidget->moveX = arg1;
  }
}

void Viewer::on_doubleSpinBox_move_y_valueChanged(double arg1) {
  if (ui->GLwidget->moveY != arg1) {
    controller_->MoveModel(arg1 - ui->GLwidget->moveY, ui->GLwidget->y);
    UpdateVertices();
    ui->GLwidget->update();
    ui->GLwidget->moveY = arg1;
  }
}

void Viewer::on_doubleSpinBox_move_z_valueChanged(double arg1) {
  if (ui->GLwidget->moveZ != arg1) {
    controller_->MoveModel(arg1 - ui->GLwidget->moveZ, ui->GLwidget->z);
    UpdateVertices();
    ui->GLwidget->update();
    ui->GLwidget->moveZ = arg1;
  }
}

void Viewer::on_doubleSpinBox_rotate_x_valueChanged(double arg1) {
  controller_->Rotate(arg1 - ui->GLwidget->rotateX, ui->GLwidget->x);
  UpdateVertices();
  ui->GLwidget->update();
  ui->GLwidget->rotateX = arg1;
}

void Viewer::on_doubleSpinBox_rotate_y_valueChanged(double arg1) {
  controller_->Rotate(arg1 - ui->GLwidget->rotateY, ui->GLwidget->y);
  UpdateVertices();
  ui->GLwidget->update();
  ui->GLwidget->rotateY = arg1;
}

void Viewer::on_doubleSpinBox_rotate_z_valueChanged(double arg1) {
  controller_->Rotate(arg1 - ui->GLwidget->rotateZ, ui->GLwidget->z);
  UpdateVertices();
  ui->GLwidget->update();
  ui->GLwidget->rotateZ = arg1;
}

void Viewer::on_doubleSpinBox_zoom_valueChanged(double arg1) {
  if (arg1 > ui->GLwidget->zoom) {
    for (int i = 1; i <= arg1 - ui->GLwidget->zoom; i++) controller_->Zoom(1.1);
  } else {
    for (int i = 1; i <= ui->GLwidget->zoom - arg1; i++) controller_->Zoom(0.9);
  }
  UpdateVertices();
  ui->GLwidget->zoom = arg1;
  ui->GLwidget->update();
}

void Viewer::on_pushButton_vertices_set_color_clicked() {
  ui->GLwidget->verticesColor = QColorDialog::getColor(Qt::gray);
}

void Viewer::on_pushButton_facets_set_color_clicked() {
  ui->GLwidget->facetsColor = QColorDialog::getColor(Qt::gray);
}

void Viewer::on_pushButton_background_set_color_clicked() {
  ui->GLwidget->backgroundColor = QColorDialog::getColor(Qt::gray);
}

void Viewer::on_comboBox_projection_type_activated(int index) {
  ui->GLwidget->isParallel = index;
  ui->GLwidget->update();
}

void Viewer::on_comboBox_facets_type_activated(int index) {
  ui->GLwidget->isSolid = index;
  ui->GLwidget->update();
}

void Viewer::on_pushButton_screenshot_clicked() {
  QString desktopPath =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
  QFileDialog dialog(this);
  QString screenshot_filename =
      dialog.getSaveFileName(this, "Save screenshot as...", desktopPath,
                             "BMP (*.bmp);; JPEG (*.jpeg)");
  ui->GLwidget->setStyleSheet(
      "background-color: " + ui->GLwidget->backgroundColor.name() + ";");
  QPixmap screenshot = ui->GLwidget->grab();

  screenshot.save(screenshot_filename);
}

void Viewer::on_pushButton_gif_clicked() {
  timer_ = new QTimer(0);
  timer_->start(100);
  connect(timer_, SIGNAL(timeout()), this, SLOT(RecordGif()));
}

void Viewer::on_doubleSpinBox_size_of_vertices_valueChanged(double arg1) {
  ui->GLwidget->sizeOfVertices = arg1;
  ui->GLwidget->update();
}

void Viewer::on_doubleSpinBox_thickness_of_facets_valueChanged(double arg1) {
  ui->GLwidget->thicknessOfFacets = arg1;
  ui->GLwidget->update();
}

void Viewer::on_comboBox_way_to_display_currentIndexChanged(int index) {
  ui->GLwidget->displayPoint = index;
  ui->GLwidget->update();
}

void Viewer::on_pushButton_save_settings_clicked() { SettingsSave(); }

void Viewer::on_pushButton_load_settings_clicked() { SettingsLoad("new"); }

void Viewer::on_pushButton_default_settings_clicked() {
  SettingsLoad("default");
}

void Viewer::ModelInfo() {
  if (controller_->GetVerticesAmount()) {
    ui->label_number_of_vertices_info->setText(
        QString::number(controller_->GetVerticesAmount()));

  } else {
    ui->label_number_of_vertices_info->setText("");
    ui->GLwidget->verticesAmount = 0;
  }
  if (controller_->GetFacetsAmount()) {
    ui->label_number_of_facets_info->setText(
        QString::number(controller_->GetCountEdge()));

  } else {
    ui->label_number_of_facets_info->setText("");
  }
  UpdateVertices();
  UpdateFacets();
}

void Viewer::UpdateVertices() {
  if (controller_->GetVerticesAmount()) {
    ui->GLwidget->verticesAmount = controller_->GetVerticesAmount();
  }
  if (!controller_->GetVertexes().empty()) {
    ui->GLwidget->vertices = controller_->GetVertexes();
  }
}

void Viewer::UpdateFacets() {
  if (controller_->GetFacetsAmount()) {
    ui->GLwidget->facetsAmount = controller_->GetFacetsAmount();
  }
  if (!controller_->GetFacets().empty()) {
    ui->GLwidget->facets = controller_->GetFacets();
  }
}

void Viewer::ResetMoveRotateZoom() {
  ui->doubleSpinBox_move_x->setValue(0.0);
  ui->doubleSpinBox_move_y->setValue(0.0);
  ui->doubleSpinBox_move_z->setValue(0.0);
  ui->doubleSpinBox_rotate_x->setValue(0.0);
  ui->doubleSpinBox_rotate_y->setValue(0.0);
  ui->doubleSpinBox_rotate_z->setValue(0.0);
  ui->doubleSpinBox_zoom->setValue(0.0);
  ui->GLwidget->moveX = 0.0;
  ui->GLwidget->moveY = 0.0;
  ui->GLwidget->moveZ = 0.0;
  ui->GLwidget->rotateX = 0.0;
  ui->GLwidget->rotateY = 0.0;
  ui->GLwidget->rotateZ = 0.0;
  ui->GLwidget->zoom = 0.0;
}

void Viewer::SettingsSave() {
  QString settingFile = PathOfTheProgram() + "3DViewer/setting/settings.ini";
  QSettings settings(settingFile, QSettings::IniFormat);

  settings.setValue("backgroundColor", ui->GLwidget->backgroundColor);
  settings.setValue("verticesColor", ui->GLwidget->verticesColor);
  settings.setValue("facetsColor", ui->GLwidget->facetsColor);

  settings.setValue("projection_type",
                    ui->comboBox_projection_type->currentIndex());
  settings.setValue("facets_type", ui->comboBox_facets_type->currentIndex());
  settings.setValue("thickness_of_facets",
                    ui->doubleSpinBox_thickness_of_facets->value());
  settings.setValue("way_to_display",
                    ui->comboBox_way_to_display->currentIndex());
  settings.setValue("size_of_vertices",
                    ui->doubleSpinBox_size_of_vertices->value());
}

void Viewer::SettingsLoad(const QString &typeSettings) {
  QString settingFile;
  if (typeSettings == "new") {
    settingFile = PathOfTheProgram() + "3DViewer/setting/settings.ini";
  } else if (typeSettings == "default") {
    settingFile = PathOfTheProgram() + "3DViewer/setting/defaultsettings.ini";
  }
  QSettings settings(settingFile, QSettings::IniFormat);
  ui->GLwidget->backgroundColor =
      settings.value("backgroundColor").value<QColor>();
  ui->GLwidget->verticesColor = settings.value("verticesColor").value<QColor>();
  ui->GLwidget->facetsColor = settings.value("facetsColor").value<QColor>();

  ui->comboBox_projection_type->setCurrentIndex(
      settings.value("projection_type", "").toInt());
  ui->GLwidget->isParallel = ui->comboBox_projection_type->currentIndex();
  ui->comboBox_facets_type->setCurrentIndex(
      settings.value("facets_type", "").toInt());
  ui->GLwidget->isSolid = ui->comboBox_facets_type->currentIndex();
  ui->doubleSpinBox_thickness_of_facets->setValue(
      settings.value("thickness_of_facets", "").toInt());
  ui->GLwidget->thicknessOfFacets =
      ui->doubleSpinBox_thickness_of_facets->value();
  ui->comboBox_way_to_display->setCurrentIndex(
      settings.value("way_to_display", "").toInt());
  ui->GLwidget->displayPoint = ui->comboBox_way_to_display->currentIndex();

  ui->doubleSpinBox_size_of_vertices->setValue(
      settings.value("size_of_vertices", "").toInt());
  ui->GLwidget->sizeOfVertices = ui->doubleSpinBox_size_of_vertices->value();
  ui->GLwidget->update();
}

void Viewer::RecordGif() {
  if (giftime_ < 5.0) {
    ui->GLwidget->setStyleSheet(
        "background-color: " + ui->GLwidget->backgroundColor.name() + ";");
    imgVector_.push_back(ui->GLwidget->grab().toImage());
    giftime_ += 0.1;
  } else if (giftime_ >= 5.0) {
    SaveGif();
    timer_->stop();
  }
}

void Viewer::SaveGif() {
  QString desktopPath =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
  QFileDialog dialog(this);
  QString gif_filename = dialog.getSaveFileName(this, "Save gif as...",
                                                desktopPath, "GIF (*.gif);;");
  gif_.setDefaultDelay(100);
  for (QVector<QImage>::Iterator img = imgVector_.begin();
       img != imgVector_.end(); ++img) {
    QImage imgScaled = img->scaled(640, 480);
    gif_.addFrame(imgScaled);
  }
  gif_.save(gif_filename);
  imgVector_.clear();
  giftime_ = 0.0;
}

QString Viewer::PathOfTheProgram() {
  QString filePath = QApplication::applicationDirPath();
  QDir dir(filePath);
  QString baseDir = dir.absolutePath();
  int number = baseDir.lastIndexOf("/src/");
  QString result = baseDir.left(number + 5);
  return result;
}
