#include <QApplication>

#include "view/viewcalculator.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  ViewCalculator w;
  w.show();
  return a.exec();
}
