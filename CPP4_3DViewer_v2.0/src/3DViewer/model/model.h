#ifndef CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_MODEL_H
#define CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_MODEL_H

#include <iostream>
#include <string>
#include <vector>

#include "affine_transform.h"
#include "objectinfo.h"
#include "parser.h"

namespace s21 {
class Model {
 public:
  Model();
  ~Model();
  Model(const Model &other) = delete;
  Model(Model &&other) = delete;
  void operator=(const Model &other) = delete;
  long GetVerticesAmount() const;
  long GetFacetsAmount() const;
  const std::vector<double> &GetVertexes() const;
  const std::vector<int> &GetFacets() const;
  long GetCountEdge() const;
  const std::string &GetPath() const;
  void ResetInfo();
  void StartParsingFile(std::string pathToFile, int *error);
  void MoveModel(double step, int coord);
  void Rotate(double angle, int coord);
  void Zoom(double scale);

 private:
  Transform *transform_;
  ParserFile *parserFile_;
  ObjectInfo *objectInfo_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_MODEL_H
