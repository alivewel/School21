#ifndef CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_PARSER_H
#define CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_PARSER_H

#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "objectinfo.h"

namespace s21 {

constexpr int kOK = 0;
constexpr int kCORRUPT_FILE = 2;
constexpr int kFAIL = 1;

class ParserFile {
 public:
  ParserFile(ObjectInfo* objectInfo) : objectInfo_(objectInfo) {}
  ~ParserFile() = default;
  void StartParsingFile(std::string pathToFile, int* error);
  void FreeData();

  long verticesAmount;
  long facetsAmount;
  std::vector<double> vertices;
  std::vector<int> facets;
  long countEdge;

 private:
  ObjectInfo* objectInfo_;
  std::string path_;

  void DecreaseModel();
};

class StrategyParser {
 public:
  virtual ~StrategyParser() {}
  virtual int AlgorithmRead(const std::string& fileName) = 0;
};

class FirstRead : public StrategyParser {
 public:
  FirstRead(ParserFile* parser) : parser_(parser) {}
  ~FirstRead() {}

  int AlgorithmRead(const std::string& fileName);

 private:
  ParserFile* parser_;
};

class SecondRead : public StrategyParser {
 public:
  SecondRead(ParserFile* parser) : parser_(parser) {}
  ~SecondRead() {}

  int AlgorithmRead(const std::string& fileName);
  int GetVertice(size_t* i, const std::string& str, std::string& coordinate);
  int GetFace(size_t* i, const std::string& str, std::string& face);
  void SetVerticesParser(const std::string& str, int* count_v, int* i_v);
  void SetFacetsParser(const std::string& str, int* count_v, int* i_f);

 private:
  ParserFile* parser_;
};

class ContextParser {
 public:
  ContextParser(StrategyParser* s) : strategy_(s) {}
  ~ContextParser() { delete strategy_; }

  int ContextInterface(const std::string& fileName) {
    return strategy_->AlgorithmRead(fileName);
  }

 private:
  StrategyParser* strategy_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_SRC_3DVIEWER_MODEL_PARSER_H
