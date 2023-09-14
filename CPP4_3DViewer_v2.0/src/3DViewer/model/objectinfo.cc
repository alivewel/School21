#include "objectinfo.h"

namespace s21 {

long ObjectInfo::GetVerticesAmount() const { return verticesAmount_; }
long ObjectInfo::GetFacetsAmount() const { return facetsAmount_; }
const std::vector<double>& ObjectInfo::GetVertexes() const { return vertices_; }
const std::vector<int>& ObjectInfo::GetFacets() const { return facets_; }
long ObjectInfo::GetCountEdge() const { return countEdge_; }
const std::string& ObjectInfo::GetPath() const { return path_; }
void ObjectInfo::ResetInfo() {
  path_ = "";
  verticesAmount_ = facetsAmount_ = countEdge_ = 0;
  vertices_.clear();
  facets_.clear();
}

void ObjectInfo::SetVerticesAmount(long verticesAmount) {
  verticesAmount_ = verticesAmount;
}
void ObjectInfo::SetFacetsAmount(long facetsAmount) {
  facetsAmount_ = facetsAmount;
}
void ObjectInfo::SetVertexes(const std::vector<double>& vertices) {
  vertices_ = vertices;
}
void ObjectInfo::SetFacets(const std::vector<int>& facets) { facets_ = facets; }
void ObjectInfo::SetCountEdge(long countEdge) { countEdge_ = countEdge; }
void ObjectInfo::SetPath(const std::string& newPath) { path_ = newPath; }
}  // namespace s21
