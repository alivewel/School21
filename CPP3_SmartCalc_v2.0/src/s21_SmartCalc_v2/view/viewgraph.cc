#include "viewgraph.h"

#include "ui_viewgraph.h"

ViewGraph::ViewGraph(QWidget *parent) : QWidget(parent), ui(new Ui::ViewGraph) {
  setFixedSize(420, 330);
  ui->setupUi(this);

  controller_ = new s21::Controller;

  connect(ui->pushButton_build_graph, SIGNAL(clicked()), this,
          SLOT(redraw_plot()));
}

ViewGraph::~ViewGraph() { delete ui; }

void ViewGraph::draw_plot(const QString &input) {
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

  //  Y = 0;
  if (xBegin < xEnd) {
    for (X = xBegin; X <= xEnd; X += h) {
      if (fabs(X) < EPS) X = 0;
      x.push_back(X);
      origin_string = new_label;
      value = origin_string.replace("x", ('(' + QString::number(X) + ')'));

      std::string inputString = value.toStdString();
      auto result = controller_->Calculator(inputString);

      if (!result.second) {
        y.push_back(result.first);
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
  ui->graph->graph(0)->setPen(QColor(50, 50, 50, 255));
  ui->graph->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->graph->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
  ui->graph->replot();
  x.clear();
  y.clear();
}

void ViewGraph::redraw_plot() { draw_plot(inputString); }
