#ifndef SRC_MODEL_H
#define SRC_MODEL_H

#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <utility>

namespace s21 {
class Model {
 public:
  enum class TokenType {
    ISNULL = 0,
    VALUE = 1,
    X = 2,
    PLUS = 3,
    MINUS = 4,
    MULT = 5,
    DIV = 6,
    POW = 7,
    MOD = 8,
    SIN = 9,
    COS = 10,
    TAN = 11,
    ASIN = 12,
    ACOS = 13,
    ATAN = 14,
    LN = 15,
    SQRT = 16,
    BKT_OPEN = 17,
    BKT_CLOSE = 18,
    LOG = 19,
    ERROR = -1
  };

  void SetInputString(const std::string str);
  void PrepareString();
  int Validation();
  bool CheckOperatorOrDot(char ch);
  std::pair<double, int> Calculate(std::string inputString);
  bool IsOperator(char ch);
  TokenType TypeOperator(char ch);
  bool IsUnaryMinus(int i);
  bool IsUnaryPlus(int i);
  TokenType GetOperatorTokenType(const std::string &operatorName);
  TokenType ParserFunction(size_t *i);
  int SearchNumber(size_t *i, double *value);
  int Priority(TokenType type);  //
  double MyOpn();
  double Arithmetic(std::stack<std::pair<TokenType, double>> headStack);
  double UnaryOperation(double num1, TokenType oper);
  double BinaryOperation(double num1, double num2, TokenType oper);
  void ReverseStack(std::stack<std::pair<TokenType, double>> &stack);
  void PrintStack(std::stack<std::pair<Model::TokenType, double>> s);

 private:
  std::string inputString_{};
  bool isUnaryMinus_{};
  bool isUnaryPlus_{};
  const std::map<std::string, TokenType> operatorsMap_{
      {"sin", TokenType::SIN},   {"cos", TokenType::COS},
      {"tan", TokenType::TAN},   {"tg", TokenType::TAN},
      {"asin", TokenType::ASIN}, {"acos", TokenType::ACOS},
      {"atan", TokenType::ATAN}, {"atg", TokenType::ATAN},
      {"sqrt", TokenType::SQRT}, {"ln", TokenType::LN},
      {"mod", TokenType::MOD},   {"log", TokenType::LOG}};
};

}  // namespace s21

#endif  // SRC_MODEL_H
