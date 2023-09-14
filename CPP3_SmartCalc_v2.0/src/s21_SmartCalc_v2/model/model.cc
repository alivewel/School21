#include "model.h"

using namespace s21;

void Model::SetInputString(const std::string str) { inputString_ = str; }

void Model::PrepareString() {
  std::string result = "";
  for (char& c : inputString_) {
    if (std::isalpha(c)) {
      c = std::tolower(c);
    }
    if (c != ' ') {
      result += c;
    }
  }
  inputString_ = result;
}

bool Model::CheckOperatorOrDot(char ch) {
  bool result = false;
  if (ch == '*' || ch == '/' || ch == '^' || ch == '+' || ch == '-' ||
      ch == '.') {
    result = true;
  }
  return result;
}

int Model::Validation() {
  int error = 0;
  if (inputString_.empty() || inputString_.length() > 255) {
    error = 1;
  } else {
    int brackOpen = 0, brackClose = 0;
    size_t i = 0;
    while (i < inputString_.length()) {
      if (inputString_[i] == '(')
        brackOpen++;
      else if (inputString_[i] == ')')
        brackClose++;
      if (i == inputString_.length() - 1 && brackOpen != brackClose) error = 1;
      if (inputString_[i] == '(' &&
          (inputString_[i + 1] == '*' || inputString_[i + 1] == '/' ||
           inputString_[i + 1] == '^' || inputString_[i + 1] == 'm'))
        error = 1;
      if (i == 0 && (inputString_[i] == '*' || inputString_[i] == '/' ||
                     inputString_[i] == '^' || inputString_[i] == 'm' ||
                     inputString_[i] == '.'))
        error = 1;
      if (CheckOperatorOrDot(inputString_[i]) &&
          CheckOperatorOrDot(inputString_[i + 1]) &&
          i != inputString_.length() - 1)
        error = 1;
      if (i != 0 && inputString_[i] == '.' &&
          (!(isdigit(inputString_[i - 1])) ||
           !(isdigit(inputString_[i + 1]))) &&
          i != inputString_.length() - 1)
        error = 1;
      if (i != inputString_.length() - 1 && inputString_[i] == '(' &&
          inputString_[i + 1] == ')')
        error = 1;
      double value = 0.0;
      if (isdigit(inputString_[i]))
        if (SearchNumber(&i, &value)) error = 1;
      if (isalpha(inputString_[i])) {
        if (static_cast<int>(ParserFunction(&i)) == -1) error = 1;
      }
      i++;
    }
  }
  return error;
}

std::pair<double, int> Model::Calculate(std::string inputString) {
  double result = 0.0;
  int successCalculate = 0;
  SetInputString(inputString);
  PrepareString();
  successCalculate = Validation();
  if (!successCalculate) {
    result = MyOpn();
  }
  return std::make_pair(result, successCalculate);
}

bool Model::IsOperator(char ch) {
  bool result = false;
  std::string operators = ("+-/*^()");
  if (operators.find(ch) != std::string::npos) {
    result = true;
  }
  return result;
}

Model::TokenType Model::TypeOperator(char ch) {
  TokenType result = TokenType::ISNULL;
  if (ch == '+')
    result = TokenType::PLUS;
  else if (ch == '-')
    result = TokenType::MINUS;
  else if (ch == '*')
    result = TokenType::MULT;
  else if (ch == '/')
    result = TokenType::DIV;
  else if (ch == '^')
    result = TokenType::POW;
  else if (ch == '(')
    result = TokenType::BKT_OPEN;
  else if (ch == ')')
    result = TokenType::BKT_CLOSE;
  return result;
}

bool Model::IsUnaryMinus(int i) {
  if (inputString_[i] == '-' && (i == 0 || inputString_[i - 1] == '(') &&
      isdigit(inputString_[i + 1])) {
    isUnaryMinus_ = true;
  }
  return isUnaryMinus_;
}

bool Model::IsUnaryPlus(int i) {
  if (inputString_[i] == '+' && (i == 0 || inputString_[i - 1] == '(') &&
      isdigit(inputString_[i + 1])) {
    isUnaryPlus_ = true;
  }
  return isUnaryPlus_;
}

Model::TokenType Model::GetOperatorTokenType(const std::string& operatorName) {
  auto it = operatorsMap_.find(operatorName);
  if (it != operatorsMap_.end()) {
    return it->second;
  }
  return TokenType::ERROR;
}

Model::TokenType Model::ParserFunction(size_t* i) {
  std::string funcString = "";
  while (isalpha(inputString_[*i])) {
    funcString += inputString_[*i];
    (*i)++;
  }
  (*i)--;
  return GetOperatorTokenType(funcString);
}

int Model::SearchNumber(size_t* i, double* value) {
  std::string numberString = "";
  double number = 0.0;
  int countDot = 0, error = 0;
  while (isdigit(inputString_[*i]) || (inputString_[*i] == '.')) {
    if (inputString_[*i] == '.') countDot++;
    numberString += inputString_[*i];
    (*i)++;
  }
  (*i)--;
  if (countDot > 1) {
    error = 1;
  }
  number = std::stod(numberString);
  *value = number;
  return error;
}

int Model::Priority(TokenType type) {
  int prior = 0;
  if (type >= TokenType::SIN && type <= TokenType::LN)
    prior = 5;
  else if (type == TokenType::SQRT || type == TokenType::POW)
    prior = 4;
  else if (type == TokenType::MULT || type == TokenType::DIV ||
           type == TokenType::MOD)
    prior = 3;
  else if (type == TokenType::PLUS || type == TokenType::MINUS)
    prior = 2;
  else if (type == TokenType::BKT_OPEN)
    prior = 1;
  return prior;
}

double Model::MyOpn() {
  std::stack<std::pair<TokenType, double>> operators;
  std::stack<std::pair<TokenType, double>> outstring;
  TokenType token = TokenType::ISNULL;
  for (size_t i = 0; i < inputString_.length(); ++i) {
    if (IsOperator(inputString_[i]) && !IsUnaryMinus(i) && !IsUnaryPlus(i)) {
      token = TypeOperator(inputString_[i]);
    }
    if (inputString_[i] == ')') {
      while (!operators.empty() &&
             operators.top().first != TokenType::BKT_OPEN &&
             operators.top().first != TokenType::POW) {
        auto typeOperator = operators.top().first;
        operators.pop();
        outstring.push(std::make_pair(typeOperator, 0.0));
      }
      operators.pop();
    }
    if (isalpha(inputString_[i])) {
      token = ParserFunction(&i);
    }
    if (isdigit(inputString_[i])) {
      token = TokenType::VALUE;
      double value = 0.0;
      SearchNumber(&i, &value);
      if (IsUnaryMinus(i)) {
        value *= -1;
        isUnaryMinus_ = false;
      }
      if (IsUnaryPlus(i)) {
        isUnaryPlus_ = false;
      }
      outstring.push(std::make_pair(TokenType::VALUE, value));
    }
    if (inputString_[i] == '(')
      operators.push(std::make_pair(TokenType::BKT_OPEN, 0.0));
    if (token != TokenType::ISNULL && token != TokenType::VALUE &&
        token != TokenType::BKT_OPEN && token != TokenType::BKT_CLOSE) {
      if (operators.empty()) {
        operators.push(std::make_pair(token, 0.0));
      } else {
        if (Priority(operators.top().first) < Priority(token)) {
          operators.push(std::make_pair(token, 0.0));
        } else {
          while (!operators.empty() &&
                 Priority(operators.top().first) >= Priority(token)) {
            if (operators.top().first == TokenType::POW &&
                token == TokenType::POW) {
              break;
            }
            outstring.push(operators.top());
            operators.pop();
          }
          operators.push(std::make_pair(token, 0.0));
        }
      }
    }
  }
  while (!operators.empty()) {
    outstring.push(operators.top());
    operators.pop();
  }
  ReverseStack(outstring);
  return Arithmetic(outstring);
  ;
}

void Model::ReverseStack(std::stack<std::pair<TokenType, double>>& stack) {
  std::stack<std::pair<TokenType, double>> tempStack;
  while (!stack.empty()) {
    tempStack.push(stack.top());
    stack.pop();
  }
  stack = std::move(tempStack);
}

double Model::UnaryOperation(double num1, TokenType oper) {
  double result = 0;
  if (oper == TokenType::SIN)
    result = sin(num1);
  else if (oper == TokenType::COS)
    result = cos(num1);
  else if (oper == TokenType::TAN)
    result = tan(num1);
  else if (oper == TokenType::ASIN)
    result = asin(num1);
  else if (oper == TokenType::ACOS)
    result = acos(num1);
  else if (oper == TokenType::ATAN)
    result = atan(num1);
  else if (oper == TokenType::LN)
    result = log(num1);
  else if (oper == TokenType::LOG)
    result = log10(num1);
  else if (oper == TokenType::SQRT)
    result = sqrt(num1);
  return result;
}

double Model::BinaryOperation(double num1, double num2, TokenType oper) {
  double result = 0;
  if (oper == TokenType::PLUS)
    result = num1 + num2;
  else if (oper == TokenType::MINUS)
    result = num2 - num1;
  else if (oper == TokenType::MULT)
    result = num1 * num2;
  else if (oper == TokenType::DIV)
    result = num2 / num1;
  else if (oper == TokenType::MOD)
    result = fmod(num2, num1);
  else if (oper == TokenType::POW)
    result = pow(num2, num1);
  return result;
}

void Model::PrintStack(std::stack<std::pair<Model::TokenType, double>> s) {
  while (!s.empty()) {
    Model::TokenType token = s.top().first;
    double value = s.top().second;
    s.pop();
    std::cout << "Token: " << static_cast<int>(token) << ", Value: " << value
              << std::endl;
  }
}

double Model::Arithmetic(
    std::stack<std::pair<Model::TokenType, double>> outstring) {
  std::stack<std::pair<TokenType, double>> numbers;
  TokenType token, someOperator;
  double num1 = 0.0, num2 = 0.0, resultTemp = 0.0, result = 0.0;
  while (!outstring.empty()) {
    token = outstring.top().first;
    if (token == TokenType::VALUE) {
      numbers.push(outstring.top());
      outstring.pop();
    } else {
      if ((token >= TokenType::PLUS && token <= TokenType::POW) ||
          token == TokenType::MOD) {
        if (!numbers.empty()) {
          num1 = numbers.top().second;
          numbers.pop();
        }
        if (!numbers.empty()) {
          num2 = numbers.top().second;
          numbers.pop();
          someOperator = outstring.top().first;
          outstring.pop();
          resultTemp = BinaryOperation(num1, num2, someOperator);
          numbers.push(std::make_pair(TokenType::VALUE, resultTemp));
        }
      } else {
        if (!numbers.empty()) {
          num1 = numbers.top().second;
          numbers.pop();
          someOperator = outstring.top().first;
          outstring.pop();
          resultTemp = UnaryOperation(num1, someOperator);
          numbers.push(std::make_pair(TokenType::VALUE, resultTemp));
        }
      }
    }
  }
  if (!numbers.empty()) {
    result = numbers.top().second;
  }
  return result;
}
