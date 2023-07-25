#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#define EPS 1e-7

extern "C" {
#include "../../s21_calc.h"
}

namespace Ui {
class graphwindow;
}

class graphwindow : public QWidget {
  Q_OBJECT

 public:
  explicit graphwindow(QWidget *parent = nullptr);
  ~graphwindow();

  void draw_plot(const QString &input);

 private:
  Ui::graphwindow *ui;

  double xBegin, xEnd, h, X, Y;
  int N;
  QVector<double> x, y;

  QString inputString;

 private slots:

  void redraw_plot();
};

#endif  // GRAPHWINDOW_H
