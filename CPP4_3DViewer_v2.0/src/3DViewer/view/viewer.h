#ifndef CPP4_3DVIEWER_V2_SRC_3DVIEWER_VIEW_VIEWER_H
#define CPP4_3DVIEWER_V2_SRC_3DVIEWER_VIEW_VIEWER_H

#include <QApplication>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

#include "../qtgifimage/src/gifimage/qgifimage.h"
#include "controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QMainWindow {
  Q_OBJECT

 public:
  Viewer(s21::Controller *controller, QWidget *parent = nullptr);
  ~Viewer();

 private slots:
  void on_uploadFileButton_clicked();
  void on_doubleSpinBox_move_x_valueChanged(double arg1);
  void on_doubleSpinBox_move_y_valueChanged(double arg1);
  void on_doubleSpinBox_move_z_valueChanged(double arg1);
  void on_doubleSpinBox_rotate_x_valueChanged(double arg1);
  void on_doubleSpinBox_rotate_y_valueChanged(double arg1);
  void on_doubleSpinBox_rotate_z_valueChanged(double arg1);
  void on_doubleSpinBox_zoom_valueChanged(double arg1);
  void on_pushButton_vertices_set_color_clicked();
  void on_pushButton_facets_set_color_clicked();
  void on_pushButton_background_set_color_clicked();
  void on_comboBox_projection_type_activated(int index);
  void on_comboBox_facets_type_activated(int index);
  void on_pushButton_screenshot_clicked();
  void on_pushButton_gif_clicked();
  void on_doubleSpinBox_size_of_vertices_valueChanged(double arg1);
  void on_doubleSpinBox_thickness_of_facets_valueChanged(double arg1);
  void on_comboBox_way_to_display_currentIndexChanged(int index);
  void on_pushButton_save_settings_clicked();
  void on_pushButton_load_settings_clicked();
  void on_pushButton_default_settings_clicked();
  void RecordGif();

 private:
  Ui::Viewer *ui;
  s21::Controller *controller_;
  QTimer *timer_;
  QGifImage gif_;
  QVector<QImage> imgVector_;
  double giftime_ = 0.0;

  void ModelInfo();
  void UpdateVertices();
  void UpdateFacets();
  void ResetMoveRotateZoom();
  void SettingsSave();
  void SettingsLoad(const QString &typeSettings);
  void SaveGif();
  QString PathOfTheProgram();
};
#endif  // CPP4_3DVIEWER_V2_SRC_3DVIEWER_VIEW_VIEWER_H
