#ifndef CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_AFFINE_TRANSFORM_H
#define CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_AFFINE_TRANSFORM_H

#include <cmath>
#include <string>
#include <vector>

#include "objectinfo.h"

namespace s21 {
class Transform {
 public:
  Transform(ObjectInfo* objectInfo) : objectInfo_(objectInfo) {}
  ~Transform() = default;
  void MoveModel(double step, int coord);
  void Rotate(double angle, int coord);
  void Zoom(double scale);

 private:
  ObjectInfo* objectInfo_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_AFFINE_TRANSFORM_H
