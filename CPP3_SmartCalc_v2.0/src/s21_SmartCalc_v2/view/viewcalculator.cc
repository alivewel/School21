#include "viewcalculator.h"

#include "ui_viewcalculator.h"

ViewCalculator::ViewCalculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ViewCalculator) {
  setFixedSize(360, 550);
  ui->setupUi(this);

  controller_ = new s21::Controller;

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
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_bracket_open, SIGNAL(clicked()), this,
          SLOT(functions()));
  connect(ui->pushButton_bracket_close, SIGNAL(clicked()), this,
          SLOT(functions()));

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

ViewCalculator::~ViewCalculator() { delete ui; }

void ViewCalculator::funcPushGraph() {
  emit signal(ui->pushButton_graph->text());
}

void ViewCalculator::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text() + button->text();
  QString new_label_value_x = ui->result_show_value_x->text() + button->text();

  if (ui->checkBoxInputX->isChecked()) {
    ui->result_show_value_x->setText(new_label_value_x);
    str_value_x = new_label_value_x;
  } else {
    ui->result_show->setText(new_label);
  }
}

void ViewCalculator::value_x() {
  if (!ui->checkBoxInputX->isChecked()) {
    QString current_label = ui->result_show->text();

    // Проверяем, заканчивается ли текущая метка на "x"
    if (!current_label.endsWith("x")) {
      QString new_label = current_label + "x";
      ui->result_show->setText(new_label);
    }
  }
}

void ViewCalculator::graph() {
  ViewGraph = new class ViewGraph;
  ViewGraph->show();

  QString current_label = ui->result_show->text();
  ViewGraph->draw_plot(current_label);
}

void ViewCalculator::functions() {
  if (!ui->checkBoxInputX->isChecked()) {
    QPushButton *button = (QPushButton *)sender();
    QString new_label = "";
    if (button->text() == "mod" || button->text() == "(" ||
        button->text() == ")") {
      new_label = ui->result_show->text() + button->text();
    } else {
      new_label = ui->result_show->text() + button->text() + "(";
    }
    ui->result_show->setText(new_label);
  }
}

void ViewCalculator::clearEverything() {
  ui->result_show->setText("");
  ui->result_show_value_x->setText("");
}

void ViewCalculator::clearLastSymbolHelp(QLabel *widget) {
  QString new_label = widget->text();
  new_label = new_label.remove(new_label.length() - 1, 1);
  widget->setText(new_label);
}

void ViewCalculator::clearLastSymbol() {
  if (ui->checkBoxInputX->isChecked()) {
    clearLastSymbolHelp(ui->result_show_value_x);
  } else {
    clearLastSymbolHelp(ui->result_show);
  }
}

void ViewCalculator::addDotToWidgetText(QLabel *widget) {
  QString new_label = widget->text();
  if (!new_label.isEmpty()) {
    QChar last_char = new_label.right(1).at(0);
    if (last_char.isDigit()) {
      if (ui->checkBoxInputX->isChecked()) {
        int dotCount = new_label.count('.');
        if (dotCount < 1) {  // Проверка количества точек
          widget->setText(new_label + ".");
        }
      } else {
        widget->setText(new_label + ".");
      }
    }
  }
}

void ViewCalculator::on_pushButton_dot_clicked() {
  if (ui->checkBoxInputX->isChecked()) {
    addDotToWidgetText(ui->result_show_value_x);
  } else {
    addDotToWidgetText(ui->result_show);
  }
}

void ViewCalculator::arithmetic() {
  if (!ui->checkBoxInputX->isChecked()) {
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
}

bool ViewCalculator::containsChar(const QString &str, QChar target) {
  return str.indexOf(target) != -1;
}

void ViewCalculator::calculate() {
  QString value = ui->result_show->text();
  if (containsChar(value, 'x') && str_value_x != "") {
    int pos = 0;
    while ((pos = value.indexOf('x', pos)) != -1) {
      value.replace(pos, 1, str_value_x);
      pos += str_value_x.length();
    }
  }

  std::string inputString = value.toStdString();
  auto result = controller_->Calculator(inputString);

  QString answer = QString::number(result.first, 'g', 10);
  if (result.second || answer == "inf" || answer == "-inf" || answer == "nan") {
    QMessageBox::critical(nullptr, "Ошибка", "Введены некорректные данные!");
    ui->result_show->setText("");
    ui->result_show_value_x->setText("");
    str_value_x = "";
  } else {
    ui->result_show->setText(answer);
    ui->checkBoxInputX->setChecked(false);
  }
}
