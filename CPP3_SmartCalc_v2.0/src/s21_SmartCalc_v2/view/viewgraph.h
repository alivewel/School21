#ifndef SRC_VIEWGRAPH_H
#define SRC_VIEWGRAPH_H

#include <QWidget>

#include "../controller/controller.h"
#define EPS 1e-7

namespace Ui {
class ViewGraph;
}

class ViewGraph : public QWidget {
  Q_OBJECT

 public:
  explicit ViewGraph(QWidget *parent = nullptr);
  ~ViewGraph();

  void draw_plot(const QString &input);

 private:
  Ui::ViewGraph *ui;
  s21::Controller *controller_;

  double xBegin, xEnd, h, X, Y;
  int N;
  QVector<double> x, y;

  QString inputString;

 private slots:

  void redraw_plot();
};

#endif  // SRC_VIEWGRAPH_H
