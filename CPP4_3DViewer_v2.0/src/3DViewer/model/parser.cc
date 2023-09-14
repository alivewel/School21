#include "parser.h"

namespace s21 {

void ParserFile::StartParsingFile(std::string pathToFile, int* error) {
  FreeData();
  ContextParser firstRead(new FirstRead(this));
  *error = firstRead.ContextInterface(pathToFile);
  if (!*error) {
    ContextParser secondRead(new SecondRead(this));
    *error = secondRead.ContextInterface(pathToFile);
  }
  if (!*error) {
    DecreaseModel();
    objectInfo_->SetVerticesAmount(verticesAmount);
    objectInfo_->SetFacetsAmount(facetsAmount);
    objectInfo_->SetCountEdge(countEdge);
    objectInfo_->SetVertexes(vertices);
    objectInfo_->SetFacets(facets);
  }
  FreeData();
}

void ParserFile::DecreaseModel() {
  int amountVertices = verticesAmount * 3;
  int maxCoord = 0;
  for (int i = 0; i < amountVertices; i++) {
    if (maxCoord < fabs(vertices[i])) maxCoord = fabs(vertices[i]);
  }
  if (maxCoord > 10) {
    maxCoord /= 10;
    for (int i = 0; i < amountVertices; i++) {
      vertices[i] /= maxCoord;
    }
  }
}

void ParserFile::FreeData() {
  facetsAmount = 0;
  verticesAmount = 0;
  vertices.clear();
  facets.clear();
  countEdge = 0;
}

int FirstRead::AlgorithmRead(const std::string& fileName) {
  std::ifstream fp;
  fp.open(fileName);
  int error = kOK;
  if (fp.eof()) {
    error = kCORRUPT_FILE;
  } else {
    std::string str = "";
    while (std::getline(fp, str)) {
      if (str[0] == 'v' && str[1] == ' ') {
        parser_->verticesAmount++;
      }
      if (str[0] == 'f' && str[1] == ' ') {
        for (size_t i = 1; i < str.size(); i++) {
          if (str[i - 1] == ' ' && (std::isdigit(str[i]) || str[i] == '-'))
            parser_->facetsAmount++;
        }
      }
    }
    fp.close();
    if (parser_->verticesAmount == 0 || parser_->facetsAmount == 0)
      error = kFAIL;
  }
  return error;
}

int SecondRead::AlgorithmRead(const std::string& fileName) {
  std::ifstream fp;
  fp.open(fileName);
  int error = kOK;
  if (fp.eof()) {
    error = kCORRUPT_FILE;
  } else {
    parser_->vertices.resize(parser_->verticesAmount * 3);
    parser_->facets.resize(parser_->facetsAmount * 2);
    if (!parser_->vertices.empty() && !parser_->facets.empty()) {
      int count_v = 0;
      int i_v = 0;
      int i_f = 0;
      std::string str = "";
      while (std::getline(fp, str)) {
        if (str[0] == 'v' && str[1] == ' ') {
          SetVerticesParser(str, &count_v, &i_v);
        }
        if (str[0] == 'f' && str[1] == ' ') {
          SetFacetsParser(str, &count_v, &i_f);
        }
      }
      parser_->countEdge = parser_->facetsAmount / 2;
    } else {
      error = kCORRUPT_FILE;
      parser_->FreeData();
    }
    fp.close();
  }
  return error;
}

int SecondRead::GetVertice(size_t* i, const std::string& str,
                           std::string& coordinate) {
  int error = kOK;
  while ((*i) < str.size() && str[*i] != ' ' && str[*i] != '\n' && !error) {
    coordinate += str[(*i)++];
  }
  return error;
}

int SecondRead::GetFace(size_t* i, const std::string& str, std::string& face) {
  int error = kOK;
  int faceIsReceived = 0;
  while ((*i) < str.size() && str[*i] != ' ' && str[*i] != '\n' && !error) {
    if (std::isdigit(str[*i]) || str[*i] == '-') {
      if (!faceIsReceived) face += str[*i];
    } else if (face[0] && str[*i] == '/') {
      faceIsReceived = 1;
    }
    (*i)++;
  }
  return error;
}

void SecondRead::SetVerticesParser(const std::string& str, int* count_v,
                                   int* i_v) {
  *count_v += 1;
  for (size_t i = 2, xyz = 0; i < str.size() && xyz < 3; i++) {
    if (std::isdigit(str[i]) || str[i] == '-') {
      std::string coordinate;
      GetVertice(&i, str, coordinate);
      parser_->vertices[*i_v] = atof(coordinate.c_str());
      *i_v += 1;
      xyz++;
    }
  }
}

void SecondRead::SetFacetsParser(const std::string& str, int* count_v,
                                 int* i_f) {
  int firstItem = -1;
  for (size_t i = 2; i < str.size(); i++) {
    if (std::isdigit(str[i]) || str[i] == '-') {
      std::string face;
      GetFace(&i, str, face);
      parser_->facets[*i_f] = atoi(face.c_str()) - 1;
      if (parser_->facets[*i_f] < 0) {
        parser_->facets[*i_f] += (*count_v + 1);
      }
      if (firstItem >= 0) {
        parser_->facets[*i_f + 1] = parser_->facets[*i_f];
        *i_f += 1;
      } else {
        firstItem = parser_->facets[*i_f];
      }
      *i_f += 1;
    }
  }
  parser_->facets[*i_f] = firstItem;
  *i_f += 1;
}

}  // namespace s21
