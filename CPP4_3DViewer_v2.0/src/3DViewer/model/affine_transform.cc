#include "affine_transform.h"

namespace s21 {

void Transform::MoveModel(double step, int coord) {
  std::vector<double> tempVerticesVector = objectInfo_->GetVertexes();
  for (size_t i = 0; i < tempVerticesVector.size(); i += 3) {
    size_t targetIndex = i + coord;
    if (targetIndex < tempVerticesVector.size()) {
      tempVerticesVector[targetIndex] += step;
    }
  }
  objectInfo_->SetVertexes(tempVerticesVector);
}

void Transform::Rotate(double angle, int coord) {
  double sinAngle = sin(angle);
  double cosAngle = cos(angle);
  std::vector<double> tempVerticesVector = objectInfo_->GetVertexes();
  for (size_t i = 0; i < tempVerticesVector.size(); i += 3) {
    size_t targetIndex = i + coord;
    if (targetIndex < tempVerticesVector.size() &&
        targetIndex + 1 < tempVerticesVector.size() &&
        targetIndex + 2 < tempVerticesVector.size()) {
      double x1 = tempVerticesVector[i];
      double y1 = tempVerticesVector[i + 1];
      double z1 = tempVerticesVector[i + 2];
      if (coord == 0) {
        tempVerticesVector[i + 1] = y1 * cosAngle - sinAngle * z1;
        tempVerticesVector[i + 2] = y1 * sinAngle + cosAngle * z1;
      } else if (coord == 1) {
        tempVerticesVector[i] = x1 * cosAngle + sinAngle * z1;
        tempVerticesVector[i + 2] = -x1 * sinAngle + cosAngle * z1;
      } else if (coord == 2) {
        tempVerticesVector[i] = x1 * cosAngle - sinAngle * y1;
        tempVerticesVector[i + 1] = x1 * sinAngle + cosAngle * y1;
      }
    }
  }
  objectInfo_->SetVertexes(tempVerticesVector);
}

void Transform::Zoom(double scale) {
  MoveModel(scale - 1.0, 0);  // Увеличиваем X-координаты вершин
  MoveModel(scale - 1.0, 1);  // Увеличиваем Y-координаты вершин
  MoveModel(scale - 1.0, 2);  // Увеличиваем Z-координаты вершин
}

}  // namespace s21
