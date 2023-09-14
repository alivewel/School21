#ifndef SRC_VIEWCALCULATOR_H
#define SRC_VIEWCALCULATOR_H

#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QVector>
#include <iostream>
#include <string>

#include "../controller/controller.h"
#include "viewgraph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ViewCalculator;
}
QT_END_NAMESPACE

class ViewCalculator : public QMainWindow {
  Q_OBJECT

 public:
  ViewCalculator(QWidget *parent = nullptr);
  ~ViewCalculator();
  bool containsChar(const QString &str, QChar target);
  void clearLastSymbolHelp(QLabel *widget);
  void addDotToWidgetText(QLabel *widget);

 private:
  Ui::ViewCalculator *ui;
  s21::Controller *controller_;
  ViewGraph *ViewGraph;

  QString str_value_x;

 private slots:
  void digits_numbers();
  void functions();
  void on_pushButton_dot_clicked();
  void arithmetic();
  void clearEverything();
  void clearLastSymbol();
  void calculate();
  void value_x();
  void graph();
  void funcPushGraph();

 signals:
  void signal(QString);
};
#endif  // SRC_VIEWCALCULATOR_H
