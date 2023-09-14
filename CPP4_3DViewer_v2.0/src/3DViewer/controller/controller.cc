#include "controller.h"

namespace s21 {

s21::Controller* s21::Controller::controller_ = nullptr;

Controller* Controller::GetInstance() {
  if (!controller_) {
    controller_ = new Controller();
  }
  return controller_;
}

Controller* Controller::GetInstance(Model* m) {
  if (!controller_) {
    controller_ = new Controller(m);
  }
  return controller_;
}

void Controller::StartParsingFile(std::string pathToFile, int* error) {
  model_->StartParsingFile(pathToFile, error);
}

long Controller::GetVerticesAmount() const {
  return model_->GetVerticesAmount();
}

long Controller::GetFacetsAmount() const { return model_->GetFacetsAmount(); }

const std::vector<double>& Controller::GetVertexes() const {
  return model_->GetVertexes();
}

const std::vector<int>& Controller::GetFacets() const {
  return model_->GetFacets();
}

long Controller::GetCountEdge() const { return model_->GetCountEdge(); }

const std::string& Controller::GetPath() const { return model_->GetPath(); }

void Controller::ResetInfo() { model_->ResetInfo(); }

void Controller::MoveModel(double step, int coord) {
  model_->MoveModel(step, coord);
}

void Controller::Rotate(double angle, int coord) {
  model_->Rotate(angle, coord);
}

void Controller::Zoom(double scale) { model_->Zoom(scale); }

}  // namespace s21
