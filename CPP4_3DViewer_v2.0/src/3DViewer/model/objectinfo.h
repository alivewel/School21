#ifndef CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_OBJECTINFO_H
#define CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_OBJECTINFO_H

#include <string>
#include <vector>

namespace s21 {
class ObjectInfo {
 public:
  ObjectInfo() = default;
  ~ObjectInfo() = default;
  long GetVerticesAmount() const;
  long GetFacetsAmount() const;
  const std::vector<double>& GetVertexes() const;
  const std::vector<int>& GetFacets() const;
  long GetCountEdge() const;
  const std::string& GetPath() const;
  void ResetInfo();

  void SetVerticesAmount(long verticesAmount);
  void SetFacetsAmount(long facetsAmount);
  void SetVertexes(const std::vector<double>& vertices);
  void SetFacets(const std::vector<int>& facets);
  void SetCountEdge(long countEdge);
  void SetPath(const std::string& newPath);

 private:
  std::string path_;
  long verticesAmount_;
  long facetsAmount_;
  std::vector<double> vertices_;
  std::vector<int> facets_;
  long countEdge_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_OBJECTINFO_H