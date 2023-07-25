#include "graphwindow.h"

#include "ui_graphwindow.h"

graphwindow::graphwindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::graphwindow) {
  setFixedSize(420, 330);
  ui->setupUi(this);

  connect(ui->pushButton_build_graph, SIGNAL(clicked()), this,
          SLOT(redraw_plot()));
}

graphwindow::~graphwindow() { delete ui; }

void graphwindow::draw_plot(const QString &input) {
  ui->graph->clearGraphs();
  x.clear();
  y.clear();
  QString new_label = input;
  inputString = input;
  QString value, origin_string;

  double xBegin = ui->doubleSpinBox_Xmin->value();
  double xEnd = ui->doubleSpinBox_Xmax->value();

  h = 0.005 * (qFabs(xBegin) + qFabs(xEnd));
  ui->graph->xAxis->setRange(xBegin, xEnd);
  ui->graph->yAxis->setRange(xBegin, xEnd);

  Y = 0;
  if (xBegin < xEnd) {
    for (X = xBegin; X <= xEnd; X += h) {
      if (fabs(X) < EPS) X = 0;
      x.push_back(X);
      origin_string = new_label;
      value = origin_string.replace("x", ('(' + QString::number(X) + ')'));
      QByteArray str_bit = value.toLocal8Bit();
      char *res_str = str_bit.data();
      int check = calculator(res_str, &Y);
      if (!check) {
        y.push_back(Y);
      } else {
        ui->label_error->setText(
            "<html><head/><body><p><span style=\" "
            "color:#ff0000;\">Error</span></p></body></html>");
        ui->label_error->setAlignment(Qt::AlignCenter);
        QFont font("Arial", 20);
        ui->label_error->setFont(font);
      }
    }
  }
  ui->graph->addGraph();
  ui->graph->graph(0)->setData(x, y);
  ui->graph->replot();
  x.clear();
  y.clear();
}

void graphwindow::redraw_plot() { draw_plot(inputString); }
