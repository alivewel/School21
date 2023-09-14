#include "controller.h"

std::pair<double, int> s21::Controller::Calculator(std::string inputString) {
  model_.SetInputString(inputString);
  return model_.Calculate(inputString);
}