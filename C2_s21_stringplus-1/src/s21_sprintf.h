#ifndef SRC_S21_SPRINTF_H
#define SRC_S21_SPRINTF_H

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>

#include "s21_string.h"

typedef struct {
  int amountNull;     // количество нулей в флаге Null
  int width;          // ширина во флаге
  int precision;      // точность во флаге точка
  int flagNull;       // флаг 0
  int flagMinus;      // флаг -
  int flagPlus;       // флаг +
  int flagWidth;      // флаг ширина (число)
  int flagPrecision;  // флаг точность
  int flagSharp;      // флаг #
  int spec_e;         // спецификатор е
  int spec_E;         // спецификатор Е
  int spec_g;         // спецификатор g
  int spec_g_low;  // маленькое число при спецификаторе G
  int spec_G;         // спецификатор G
  int spec_o;         // спецификатор o
  int spec_x;         // спецификатор x
  int spec_X;         // спецификатор X
  int spec_p;         // спецификатор p
  int length_h;       // длина h
  int length_l;       // длина l
  int length_L;       // длина L
  int degree_spec_e;  // степень флага Е
  int process;        // отработка печати
  int flagReset;  // флаг разрешения обнуления флагов
  int posBuff;    // позиция буффера
  int amountСharNumbG;  // количество знаков целой части числа с плавающей
                        // точкой при спецификаторе g или G
} flag;

void resetFlags(flag *num);  // сброс флагов при переходе к следующему %
int s21_atoi(char *number);
void flagNull(char *fmt,
              flag *num);  // считывание количества нулей из форматной строки
int countСharacterNumb(
    long long int numb);  // функция для счета количества знаков в целом числе
int countСharSpecG(double numb);  // функция для счета количества знаков в целой
                                  // части double при спецификаторе g
int countСharSpecE(double *numb);  // функция для счета количества знаков в
                                   // целой части double при спецификаторе e
char *intToChar(int64_t n, char *dest);           // перевод int в char
char *intToCharUnsigned(uint64_t n, char *dest);  // перевод unsigned int в char
int roundInt(
    int numb,
    int charRound);  // функция для округления целого числа по заданной точности
char *doubleToChar(double numb, char *dest,
                   flag *num);  // перевод double в char
uint64_t dexToOctal(
    uint64_t numb);  // перевод числа из дестиричной системы в восьмиричную
char *dexToHexLow(
    uint64_t num,
    char *dest);  // перевод числа из дестиричной системы в шестнадцетиричную
char *dexToHexBig(
    uint64_t num,
    char *dest);  // перевод числа из дестиричной системы в шестнадцетиричную
void printFlags(char *buffer, va_list ap,
                flag *num);  // запись в буфер целого числа
void printFlagsUnsigned(char *buffer, va_list ap,
                        flag *num);  // запись в буфер беззнакового целого числа
void printFlagsPointer(char *buffer, va_list ap,
                       flag *num);  // запись в буфер указателя
void printFlagsDouble(char *buffer, va_list ap,
                      flag *num);  // // запись в буфер числа c плавающей точкой
void flagWidth(char *fmt, flag *num);  // считывание ширины из форматной строки
void flagPrecision(char *fmt,
                   flag *num);  // считывание точности из форматной строки
void spec_n(char *buffer, va_list ap, flag *num);  // отработка спецификатора n
void charToBuffer(char *buffer, va_list ap, flag *num);  // запись в буфер char
void stringToBuffer(char *buffer, va_list ap,
                    flag *num);  // запись в буфер string
int s21_sprintf(char *str, char *fmt, ...);

#endif  // SRC_S21_SPRINTF_H