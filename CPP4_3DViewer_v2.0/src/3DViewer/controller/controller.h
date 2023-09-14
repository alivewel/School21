#ifndef CPP4_3DVIEWER_V2_SRC_3DVIEWER_CONTROLLER_CONTROLLER_H
#define CPP4_3DVIEWER_V2_SRC_3DVIEWER_CONTROLLER_CONTROLLER_H

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  Controller(const Controller& other) = delete;
  Controller(Controller&& other) = delete;
  void operator=(const Controller& other) = delete;
  ~Controller(){};
  static Controller* GetInstance();
  static Controller* GetInstance(Model* m);

  long GetVerticesAmount() const;
  long GetFacetsAmount() const;
  const std::vector<double>& GetVertexes() const;
  const std::vector<int>& GetFacets() const;
  long GetCountEdge() const;
  const std::string& GetPath() const;
  void ResetInfo();
  void StartParsingFile(std::string pathToFile, int* error);
  void MoveModel(double step, int coord);
  void Rotate(double angle, int coord);
  void Zoom(double scale);

 private:
  Controller(){};
  explicit Controller(Model* m) : model_(m){};
  static Controller* controller_;
  Model* model_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_SRC_3DVIEWER_CONTROLLER_CONTROLLER_H
