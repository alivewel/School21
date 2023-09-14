#include "model.h"

namespace s21 {

Model::Model() {
  objectInfo_ = new ObjectInfo();
  transform_ = new Transform(objectInfo_);
  parserFile_ = new ParserFile(objectInfo_);
}

Model::~Model() {
  delete objectInfo_;
  delete transform_;
  delete parserFile_;
}

void Model::StartParsingFile(std::string pathToFile, int* error) {
  parserFile_->StartParsingFile(pathToFile, error);
}

long Model::GetVerticesAmount() const {
  return objectInfo_->GetVerticesAmount();
}

long Model::GetFacetsAmount() const { return objectInfo_->GetFacetsAmount(); }

const std::vector<double>& Model::GetVertexes() const {
  return objectInfo_->GetVertexes();
}

const std::vector<int>& Model::GetFacets() const {
  return objectInfo_->GetFacets();
}

long Model::GetCountEdge() const { return objectInfo_->GetCountEdge(); }

const std::string& Model::GetPath() const { return objectInfo_->GetPath(); }

void Model::ResetInfo() { objectInfo_->ResetInfo(); }

void Model::MoveModel(double step, int coord) {
  transform_->MoveModel(step, coord);
}

void Model::Rotate(double angle, int coord) {
  transform_->Rotate(angle, coord);
}

void Model::Zoom(double scale) { transform_->Zoom(scale); }

}  // namespace s21
