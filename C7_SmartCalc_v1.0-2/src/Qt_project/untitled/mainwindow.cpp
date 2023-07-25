#include "mainwindow.h"

#include <QRegularExpression>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  setFixedSize(360, 510);
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_bracket_open, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_bracket_close, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));

  connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this,
          SLOT(operations()));
  connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(arithmetic()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(arithmetic()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(arithmetic()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(arithmetic()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(arithmetic()));

  connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(clearEverything()));
  connect(ui->pushButton_clear, SIGNAL(clicked()), this,
          SLOT(clearLastSymbol()));

  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(functions()));

  connect(ui->pushButton_operate, SIGNAL(clicked()), this, SLOT(calculate()));
  connect(ui->pushButton_value_x, SIGNAL(clicked()), this, SLOT(value_x()));
  connect(ui->pushButton_graph, SIGNAL(clicked()), this, SLOT(graph()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::funcPushGraph() { emit signal(ui->pushButton_graph->text()); }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text() + button->text();
  ui->result_show->setText(new_label);
}

void MainWindow::value_x() {
  QString current_label = ui->result_show->text();

  // Проверяем, заканчивается ли текущая метка на "x"
  if (!current_label.endsWith("x")) {
    QString new_label = current_label + "x";
    ui->result_show->setText(new_label);
  }
}

void MainWindow::graph() {
  graphwindow = new class graphwindow;
  graphwindow->show();

  QString current_label = ui->result_show->text();
  graphwindow->draw_plot(current_label);
}

void MainWindow::functions() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text() + button->text() + "(";
  ui->result_show->setText(new_label);
}

void MainWindow::clearEverything() { ui->result_show->setText(""); }

void MainWindow::clearLastSymbol() {
  QString new_label = ui->result_show->text();
  new_label = new_label.remove(new_label.length() - 1, 1);
  ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked() {
  QString new_label = ui->result_show->text();
  if (!new_label.isEmpty()) {  // проверка на пустую строку
    QChar last_char = new_label.right(1).at(0);
    if (last_char.isDigit())  // проверка на последний символ - цифра
      ui->result_show->setText(ui->result_show->text() + ".");
  }
}

void MainWindow::arithmetic() {
  QPushButton *button = (QPushButton *)sender();
  QString result_label = ui->result_show->text();
  if (button == ui->pushButton_plus) {
    ui->result_show->setText(result_label + "+");
  } else if (button == ui->pushButton_minus) {
    ui->result_show->setText(result_label + "-");
  } else if (button == ui->pushButton_mult) {
    ui->result_show->setText(result_label + "*");
  } else if (button == ui->pushButton_divide) {
    ui->result_show->setText(result_label + "/");
  } else if (button == ui->pushButton_pow) {
    ui->result_show->setText(result_label + "^");
  }
}

void MainWindow::operations() {
  QPushButton *button = (QPushButton *)sender();
  double all_numbers;
  QString new_label;

  if (button->text() == "+/-") {
    all_numbers = (ui->result_show->text()).toDouble();
    all_numbers = all_numbers * -1;
    new_label = QString::number(all_numbers, 'g', 15);
    ui->result_show->setText(new_label);
  } else if (button->text() == "%") {
    all_numbers = (ui->result_show->text()).toDouble();
    all_numbers = all_numbers * 0.01;
    new_label = QString::number(all_numbers, 'g', 15);
    ui->result_show->setText(new_label);
  }
}

void MainWindow::calculate() {
  QString value;
  value = ui->result_show->text();
  double result;
  QByteArray str_bit = value.toLocal8Bit();
  char *res_str = str_bit.data();
  int status = calculator(res_str, &result);
  QString answer = QString::number(result, 'g', 10);
  if (status) {
    ui->result_show->setText("Error");
  } else {
    ui->result_show->setText(answer);
  }
}
