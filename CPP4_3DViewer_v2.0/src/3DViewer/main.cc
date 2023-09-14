#include <QApplication>

#include "controller/controller.h"
#include "model/model.h"
#include "view/viewer.h"

int main(int argc, char* argv[]) {
  s21::Model model;
  s21::Controller* controller = s21::Controller::GetInstance(&model);
  QApplication a(argc, argv);
  Viewer w(controller);
  w.show();
  return a.exec();
}
