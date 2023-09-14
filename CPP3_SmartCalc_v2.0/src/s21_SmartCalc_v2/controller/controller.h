#ifndef SRC_CONTROLLER_H
#define SRC_CONTROLLER_H

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  std::pair<double, int> Calculator(std::string inputString);

 private:
  Model model_;
};

}  // namespace s21

#endif  // SRC_CONTROLLER_H
