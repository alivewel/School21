#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
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
} type_t;

typedef struct Node {
  double value;
  type_t type;
  struct Node* next;
} Node;

void pushStack(Node** head, double value);
void pushStackType(Node** head, int type);
double popStack(Node** top);
int popStackType(Node** top);
void print_stack(Node* head);
int searchNumber(char* str, double* value);
int type_operator(char str);
void func_reverse_stack(Node** head_outstring, Node** reverse_stack);
double unaryOperation(double num1, int oper);
double binaryOperation(double num1, double num2, int oper);
double arithmetic(Node** head_stack);
int priority(int type);
int type_function(char* str);
int parser_function(char* str, int* type);
int calculator(char* str, double* result);
int checkOperatorOrDot(char ch);
int validation(char* str);
void clean_stack(Node* stack);

#endif  // SRC_S21_CALC_H_