#include "s21_sprintf.h"

void resetFlags(flag *num) {
  num->amountNull = 0;
  num->width = 0;
  num->precision = 0;
  num->flagNull = 0;
  num->flagMinus = 0;
  num->flagPlus = 0;
  num->flagWidth = 0;
  num->flagPrecision = 0;
  num->flagSharp = 0;
  num->spec_e = 0;
  num->spec_E = 0;
  num->spec_g = 0;
  num->spec_g_low = 0;
  num->spec_G = 0;
  num->spec_o = 0;
  num->spec_x = 0;
  num->spec_X = 0;
  num->spec_p = 0;
  num->length_h = 0;
  num->length_l = 0;
  num->length_L = 0;
  num->degree_spec_e = 0;
  num->process = 0;
  num->amountСharNumbG = 0;
}

int s21_atoi(char *number) {
  int a = 0, b = 0, res = 0, length = s21_strlen(number);
  while (length--) {
    a = number[b++] - '0';
    res += a;
    if (length != 0) res *= 10;
  }
  return res;
}

void flagNull(char *fmt, flag *num) {
  char ch[40] = {'\0'};
  int i = 0, numbNull = 0;  // numbNull количество нулей
  if (!num->flagWidth && !num->flagNull &&
      !num->flagPrecision) {  // !num->flagNull чтобы 1 раз войти в функцию
    while ((*fmt > 47 && *fmt < 58) ||
           *fmt == '#') {  // для случая "|%0#15.10g|"
      if (*fmt > 47 && *fmt < 58) {
        ch[i] = *fmt;
        i++;
      }
      fmt++;
    }
    numbNull = s21_atoi(ch);
    num->amountNull = numbNull;
    num->flagNull = 1;
  }
}

int countСharacterNumb(
    long long int numb) {  // функция для счета количества знаков в числе %d
  int count = 1;
  if (numb < 0) {
    count++;  // берем в расчет минус перед числом
    numb = numb * -1;  // переводим число в положительное
  }
  while (numb > 9) {
    numb = numb / 10;
    count++;
  }
  return count;
}

int countСharSpecG(double numb) {  //  функция для счета количества знаков целой
                                   //  части в числе %g
  int count = 0, left = 0;
  if (numb < 0) {
    numb *= -1;  // переводим число в положительное
  }
  left = (int)numb;  // отбрасываем дробную часть
  while (left > 0) {
    left = left / 10;
    count++;
  }
  return count;
}

int countСharSpecE(double *numb) {  // функция для счета количества знаков в
                                    // целой части double при спецификаторе e
  int count = 0;
  if (*numb < 0) {
    *numb = *numb * -1;  // переводим число в положительное
  }
  if (*numb > 1) {
    while (*numb > 9) {
      *numb = *numb / 10;
      count++;
    }
  } else {
    while (*numb < 1) {
      *numb = *numb * 10;
      count--;
    }
  }
  return count;
}

char *intToChar(int64_t n, char *dest) {  // перевод int в char
  char *c = dest;
  int v = 0;  // количество цифр в числе n
  char t;
  if (n < 0) n = n * -1;
  while (n > 9) {
    c[v++] = (n % 10) + '0';
    n = n / 10;
  }  // разбиваем на отдельные символы число n
  c[v++] = n + '0';
  c[v] = '\0';

  for (int i = 0; i < v / 2;
       i++) {  // проходимся от последнего к первому элементу массива
    t = c[i];  // инвертируем массив символов
    c[i] = c[v - 1 - i];
    c[v - 1 - i] = t;
  }
  //  v = 0; // печать числа в char формате
  // while (c[v] != '\0')
  //     printf("%c", c[v++]);
  // printf("\n");
  return c;
}

char *intToCharUnsigned(uint64_t n,
                        char *dest) {  // перевод unsigned int в char
  char *c = dest;
  int v = 0;  // количество цифр в числе n
  char t;
  while (n > 9) {
    c[v++] = (n % 10) + '0';
    n = n / 10;
  }  // разбиваем на отдельные символы число n
  c[v++] = n + '0';
  c[v] = '\0';

  for (int i = 0; i < v / 2;
       i++) {  // проходимся от последнего к первому элементу массива
    t = c[i];  // инвертируем массив символов
    c[i] = c[v - 1 - i];
    c[v - 1 - i] = t;
  }
  //  v = 0; // печать числа в char формате
  // while (c[v] != '\0')
  //     printf("%c", c[v++]);
  // printf("\n");
  return c;
}

int roundInt(int numb,
             int charRound) {  // charRound - до какого числа округлять
  int lastChar = 0, temp = numb;  // lastChar - последний знак
  int countChar = 0,
      countDiff = 0;  // количество знаков в числе, разница в количестве знаков
  if (numb < 0) {
    numb *= -1;  // переводим число в положительное
  }
  while (temp > 0) {
    temp = temp / 10;
    countChar++;  // считаем количество знаков в числе
  }
  if (countChar > charRound) {
    countDiff = countChar - charRound;  // разница в количестве знаков
    while (countDiff) {
      if (countDiff == 1) {
        lastChar = numb % 10;  // записываем последний знак
      }
      numb /= 10;  // отбрасываем лишнюю часть
      countDiff--;
    }
  }
  if (lastChar > 4) {
    numb += 1;  // округление числа, если последний знак больше 4
  }
  if (charRound < countChar) {
    countDiff = countChar - charRound;
    while (countDiff) {
      numb *= 10;
      countDiff--;
    }
  }
  return numb;
}

char *doubleToChar(double numb, char *dest,
                   flag *num) {  // перевод double в char
  char *c = dest;                // , n = 0
  int v = 0, numZero = 6, n = 0;  // v - количество цифр в числе n | numZero -
                                  // количество нулей | n - костыль для флага g
  long double right = 0, left = 0, rRight = 0;
  long long int leftInt = 0, rightInt = 0;
  left = (long int)numb;
  right = numb - (long int)numb;
  if (num->flagPrecision) {
    if (num->spec_g_low) {
      n = -1;
    } else if ((num->spec_g || num->spec_G) && !num->spec_e &&
               !num->spec_E) {  //  && num->precision < 8 в случае
                                //  %#+34.10g|\n", 25.3456); мешает это условие
      n = -2;
    } else if ((num->spec_g || num->spec_G) && (num->spec_e || num->spec_E)) {
      n = -1;
    }
    for (int i = 0; i < num->precision + n;
         i++) {  // && i < 11 условие проверить long doulbe ломается при большем
                 // условии
      right *= 10;
    }
  } else if (!num->flagPrecision) {
    for (int i = 0; i < numZero; i++) {
      right *= 10;
    }
  }
  rRight = round(right);
  if (numb < 0) {  // избавляемся от минуса, он будет добавлен в функции
                   // printFlagsDouble
    rRight *= -1;
    left *= -1;
  }
  leftInt = (long int)left;
  rightInt = (long long int)rRight;
  if ((num->spec_G || num->spec_g) && num->amountСharNumbG > 6 &&
      !num->flagPrecision) {
    rightInt = roundInt(rightInt, 5);
    rightInt /= 10;
  }
  int amount = countСharacterNumb(rightInt);
  int copyAmount = amount;
  if ((num->spec_g || num->spec_G) && !num->flagPrecision &&
      num->amountСharNumbG < 7 &&
      num->amountСharNumbG >= 1) {  // убираем лишние нули в конце
    int count = num->amountСharNumbG;  // для случая "|%15G|\n", 123431.43242);
    while (count) {  // полностью избавляемся от right
      rightInt /= 10;
      count--;
    }
  } else if (((num->spec_g || num->spec_G) && !num->spec_e &&
              !num->flagPrecision && num->amountСharNumbG != 0) ||
             (num->spec_g_low &&
              !num->flagPrecision)) {  // убираем лишние нули в конце
    while (rightInt % 10 == 0 && copyAmount) {
      rightInt /= 10;
      copyAmount--;  // защита от бесконечного цикла
    }
  } else if ((num->spec_g || num->spec_G) && num->flagPrecision &&
             (num->amountСharNumbG + amount) > num->precision && !num->spec_e &&
             !num->spec_E) {  // убираем лишние нули в конце
    int count = num->amountСharNumbG + amount -
                num->precision;  // для случая "|%0#15.10g|\n", 324234.234);
    while (count) {              // rightInt % 10 == 0 && count
      rightInt /= 10;  // и для случая "|%+10.6g|\n", 2345.4234);
      count--;         // защита от бесконечного цикла
    }
  } else if ((num->spec_g || num->spec_G) && num->spec_g_low &&
             !num->flagPrecision) {  // убираем лишние нули в конце
    while (rightInt % 10 == 0 && copyAmount) {
      rightInt /= 10;  // и для случая "|%+10.6g|\n", 2345.4234);
      copyAmount--;    // защита от бесконечного цикла
    }
  } else if ((num->spec_g || num->spec_G) && num->spec_g_low &&
             num->flagPrecision &&
             !num->flagSharp) {  // для случая |%*g|\n", 25, 0.000000342);
    while (rightInt % 10 == 0 && copyAmount) {
      rightInt /= 10;  // и для случая "|%+10.6g|\n", 2345.4234);
      copyAmount--;    // защита от бесконечного цикла
    }
  }
  if (rightInt == 0) {  // запись дробной части, если она равна нулю
    if (((num->spec_g_low || num->spec_g || num->spec_G) && num->flagSharp)) {
      int b = 6;  // запись дробной части, если она равна нулю
      if (num->flagPrecision) {
        b = num->precision - amount;
      } else if ((num->spec_g_low || num->spec_g || num->spec_G) &&
                 num->flagSharp) {  // дробная часть которых начинается с нулей
        b = 4;
      } else if (num->spec_g_low && copyAmount == 0) {
        b = 0;
      }
      if (b > 0) {  // сега выходит при отрицательном числе
        while (b--) {
          c[v++] = '0';  // '0'
        }
      }
    }
  } else {  // запись дробной части, если она не равна нулю
    if ((!num->spec_g && !num->spec_G && num->flagPrecision &&
         amount != num->precision && !num->spec_g_low) ||
        (!num->spec_g && !num->spec_G &&
         !(amount == numZero && num->spec_g_low))) {
      int d = 0;  // запись урезанных нулей
      if (amount != numZero &&
          !(num->flagPrecision && !num->spec_g &&
            !num->spec_G)) {  // дробная часть которых начинается с нулей
        d = numZero - amount;
      } else if (num->spec_g_low && !num->flagPrecision) {
        d = 5;
      }
      while (d--) {
        c[v++] = '0';
      }
    }
    while (rightInt > 9) {
      c[v++] = (rightInt % 10) + '0';
      rightInt = rightInt / 10;
    }
    if (!(num->spec_g_low && rightInt == 0) &&
        !(num->spec_g && rightInt == 0) &&
        !(num->spec_G && rightInt == 0)) {  // if (!num->spec_g_low)
      c[v++] = rightInt + '0';
    }
    if (num->flagPrecision && !num->spec_g &&
        !num->spec_G) {  // сравнение количества знаков числа
      int n = num->precision - amount;  // полезно для чисел типа 2.001200
      while (n--) {
        c[v++] = '0';
      }
    }
  }
  if ((!(num->flagPrecision && num->precision == 0 && !num->flagSharp) &&
       !(num->amountСharNumbG == 6 && (num->spec_g || num->spec_G)) &&
       num->precision != 1)  // для случая "|%25G|\n", 123432.43242);
      || (!(num->flagPrecision && num->precision == 0 && !num->flagSharp) &&
          !(num->spec_g || num->spec_G))  // для всех остальных случаев
      || ((num->spec_g_low || num->spec_g || num->spec_E) && rightInt == 0 &&
          num->flagSharp) ||
      (num->spec_g && num->flagPrecision &&
       num->amountСharNumbG < num->precision)) {
    c[v++] = '.';
  }
  while (leftInt > 9) {
    c[v++] = (leftInt % 10) + '0';
    leftInt = leftInt / 10;
  }
  c[v++] = leftInt + '0';
  c[v] = '\0';
  char t;
  for (int i = 0; i < v / 2; i++) {
    t = c[i];  //инвертируем массив символов
    c[i] = c[v - 1 - i];
    c[v - 1 - i] = t;
  }
  return c;
}

uint64_t dexToOctal(uint64_t numb) {
  uint64_t currentChar = 0, res = 0;
  int k = 1;
  while (numb > 0) {
    currentChar = numb % 8;
    numb /= 8;
    res += currentChar * pow(10, k++ - 1);
  }
  return res;
}

char *dexToHexLow(uint64_t num, char *dest) {
  char *c = dest;
  int arr[30], i = 0;
  uint64_t currentChar = 0;
  while (num > 15) {
    arr[i] = num % 16;
    currentChar = num / 16;
    num = currentChar;
    i++;
  }
  arr[i] = num;
  for (int j = i, k = 0; j >= 0; j--, k++) {
    if (arr[j] == 1) {
      c[k] = '1';
    } else if (arr[j] == 2) {
      c[k] = '2';
    } else if (arr[j] == 3) {
      c[k] = '3';
    } else if (arr[j] == 4) {
      c[k] = '4';
    } else if (arr[j] == 5) {
      c[k] = '5';
    } else if (arr[j] == 6) {
      c[k] = '6';
    } else if (arr[j] == 7) {
      c[k] = '7';
    } else if (arr[j] == 8) {
      c[k] = '8';
    } else if (arr[j] == 9) {
      c[k] = '9';
    } else if (arr[j] == 10) {
      c[k] = 'a';
    } else if (arr[j] == 11) {
      c[k] = 'b';
    } else if (arr[j] == 12) {
      c[k] = 'c';
    } else if (arr[j] == 13) {
      c[k] = 'd';
    } else if (arr[j] == 14) {
      c[k] = 'e';
    } else if (arr[j] == 15) {
      c[k] = 'f';
    } else if (arr[j] == 0) {
      c[k] = '0';
    }
  }
  return c;
}

char *dexToHexBig(uint64_t num, char *dest) {
  char *c = dest;
  int arr[30], i = 0;
  uint64_t currentChar = 0;
  while (num > 15) {
    arr[i] = num % 16;
    currentChar = num / 16;
    num = currentChar;
    i++;
  }
  arr[i] = num;
  for (int j = i, k = 0; j >= 0; j--, k++) {
    if (arr[j] == 1) {
      c[k] = '1';
    } else if (arr[j] == 2) {
      c[k] = '2';
    } else if (arr[j] == 3) {
      c[k] = '3';
    } else if (arr[j] == 4) {
      c[k] = '4';
    } else if (arr[j] == 5) {
      c[k] = '5';
    } else if (arr[j] == 6) {
      c[k] = '6';
    } else if (arr[j] == 7) {
      c[k] = '7';
    } else if (arr[j] == 8) {
      c[k] = '8';
    } else if (arr[j] == 9) {
      c[k] = '9';
    } else if (arr[j] == 10) {
      c[k] = 'A';
    } else if (arr[j] == 11) {
      c[k] = 'B';
    } else if (arr[j] == 12) {
      c[k] = 'C';
    } else if (arr[j] == 13) {
      c[k] = 'D';
    } else if (arr[j] == 14) {
      c[k] = 'E';
    } else if (arr[j] == 15) {
      c[k] = 'F';
    } else if (arr[j] == 0) {
      c[k] = '0';
    }
  }
  return c;
}

void printFlags(char *buffer, va_list ap, flag *num) {
  long long int numb = 0;
  if (num->length_l == 1) {
    numb = va_arg(ap, long int);
  } else if (num->length_l == 2) {
    numb = va_arg(ap, long long int);
  } else if (num->length_h == 1) {
    numb = va_arg(ap, int);
  } else {
    numb = va_arg(ap, int);
  }
  int k = 0, addNull = 0, addSpace = 0, addNullPoint = 0;
  char number[30] = {'\0'};  // записали int в char
  intToChar(numb, number);   // перевод числа из int в char
  if (num->flagPlus) k = 1;
  if (num->precision >
      (int)s21_strlen(number))  // addNullPoint может стать  отрицательным
    addNullPoint =
        num->precision -
        (int)s21_strlen(number);  // защита от отрицательного значения
  addSpace = num->width - (int)s21_strlen(number) - k - addNullPoint;
  addNull = num->amountNull - (int)s21_strlen(number) - k;
  if (num->flagWidth && !num->flagNull && !num->flagMinus &&
      (int)s21_strlen(number) <
          num->width) {  // сдвинуть функцию вниз под флаг Плюс
    for (int i = 0; i < addSpace; i++) {
      buffer[num->posBuff++] = ' ';
    }
  }
  if (numb >= 0 && num->flagPlus) {
    buffer[num->posBuff++] = '+';
  } else if (numb < 0) {
    buffer[num->posBuff++] = '-';
  }
  if ((int)s21_strlen(number) < num->amountNull) {
    for (int i = 0; i < addNull; i++) {
      buffer[num->posBuff++] = '0';
    }
  }
  if ((int)s21_strlen(number) < num->precision) {
    for (int i = 0; i < addNullPoint; i++) {
      buffer[num->posBuff++] = '0';
    }
  }
  if (num->spec_o && num->flagSharp) {
    buffer[num->posBuff++] = '0';
  }
  for (int i = 0; i < (int)s21_strlen(number); i++) {
    buffer[num->posBuff++] = number[i];
  }
  if (num->flagMinus && (int)s21_strlen(number) < num->width) {
    for (int i = 0; i < addSpace; i++) {
      buffer[num->posBuff++] = ' ';
    }
  }
  num->flagReset = 1;
}

void printFlagsUnsigned(char *buffer, va_list ap, flag *num) {
  uint64_t numb = va_arg(ap, uint64_t);
  if (num->length_h) {
    numb = (uint16_t)numb;
  } else if (num->length_l) {
    numb = (uint64_t)numb;
  } else if (num->spec_o) {
    numb = (uint64_t)numb;
  } else {
    numb = (uint32_t)numb;
  }
  int k = 0, addNull = 0, addSpace = 0, addNullPoint = 0, prefix = 0;
  char number[15] = {'\0'};  // записали int в char
  if (num->spec_o) {
    numb = dexToOctal(numb);
    intToCharUnsigned(numb, number);
  } else if (num->spec_x) {
    dexToHexLow(numb, number);
  } else if (num->spec_X) {
    dexToHexBig(numb, number);
  } else {
    intToCharUnsigned(numb, number);
  }
  if (num->flagPlus) k = 1;
  if (num->flagSharp && num->spec_o) {
    prefix = 1;  // количество знаков при спецификаторами o и # (перед числом
                 // вставляется 0)
  } else {
    prefix = 2;  // количество знаков при спецификаторами x или X и # (перед
                 // числом вставляется 0x или 0X)
  }

  if (num->flagSharp && num->spec_o &&
      num->precision > (int)s21_strlen(number) + k) {
    addNullPoint = num->precision - k - (int)s21_strlen(number) -
                   prefix;  // 1 - это добавочный нуль при flagSharp
  } else if (num->precision > (int)s21_strlen(number)) {
    addNullPoint = num->precision - (int)s21_strlen(number) - k;
  }

  if (num->flagSharp && (num->spec_o || num->spec_X || num->spec_x)) {
    addSpace = num->width - (int)s21_strlen(number) - k - prefix -
               addNullPoint;  // 1 - это добавочный нуль при flagSharp
  } else {
    addSpace = num->width - (int)s21_strlen(number) - k - addNullPoint;
  }
  addNull = num->amountNull - (int)s21_strlen(number) - k;
  if (num->flagWidth && !num->flagNull && !num->flagMinus &&
      (int)s21_strlen(number) <
          num->width) {  // сдвинуть функцию вниз под флаг Плюс
    for (int i = 0; i < addSpace; i++) {
      buffer[num->posBuff++] = ' ';
    }
  }
  if (num->flagPlus) {
    buffer[num->posBuff++] = '+';
  }
  if (num->spec_x && num->flagSharp) {
    buffer[num->posBuff++] = '0';
    buffer[num->posBuff++] = 'x';
  }
  if (num->spec_X && num->flagSharp) {
    buffer[num->posBuff++] = '0';
    buffer[num->posBuff++] = 'X';
  }
  if ((int)s21_strlen(number) < num->amountNull) {
    for (int i = 0; i < addNull; i++) {
      buffer[num->posBuff++] = '0';
    }
  }
  if ((int)s21_strlen(number) < num->precision) {
    for (int i = 0; i < addNullPoint; i++) {
      buffer[num->posBuff++] = '0';
    }
  }
  if (num->spec_o && num->flagSharp) {
    buffer[num->posBuff++] = '0';
  }
  for (int i = 0; i < (int)s21_strlen(number); i++) {
    buffer[num->posBuff++] = number[i];
  }
  if (num->flagMinus && (int)s21_strlen(number) < num->width) {
    for (int i = 0; i < addSpace; i++) {
      buffer[num->posBuff++] = ' ';
    }
  }
  num->flagReset = 1;
}

void printFlagsPointer(char *buffer, va_list ap, flag *num) {
  int addSpace = 0;
  char number[50] = {'\0'};  // записали int в char
  void *numb = va_arg(ap, void *);
  dexToHexLow((uint64_t)numb, number);
  addSpace = num->width - (int)s21_strlen(number) - 2;
  if (num->flagWidth && !num->flagNull && !num->flagMinus &&
      (int)s21_strlen(number) + 2 < num->width) {
    for (int i = 0; i < addSpace; i++) {
      buffer[num->posBuff++] = ' ';
    }
  }
  buffer[num->posBuff++] = '0';
  buffer[num->posBuff++] = 'x';
  for (int i = 0; i < (int)s21_strlen(number); i++) {
    buffer[num->posBuff++] = number[i];
  }
  if (num->flagMinus && (int)s21_strlen(number) + 2 < num->width) {
    for (int i = 0; i < addSpace; i++) {
      buffer[num->posBuff++] = ' ';
    }
  }
  num->flagReset = 1;
}

void printFlagsDouble(char *buffer, va_list ap, flag *num) {
  long double numb = 0;
  if (num->length_L) {
    numb = va_arg(ap, long double);
  } else {
    numb = va_arg(ap, double);
  }
  num->amountСharNumbG =
      countСharSpecG(numb);  // количество знаков распечатываемого числа
  int addNull = 0, addSpace = 0, flagNegative = 0, k = 0;
  char number[100] = {'\0'};  // записали int в char
  if (num->spec_g && numb < 0.0001 && numb > 0) {
    num->spec_e = 1;
    num->spec_g_low = 1;  // маленькое число при флаге G
  } else if (num->spec_G && numb < 0.0001 && numb > 0) {
    num->spec_E = 1;
    num->spec_g_low = 1;  // маленькое число при флаге G
  } else if (num->spec_g && num->amountСharNumbG > 6 && !num->flagPrecision) {
    num->spec_e = 1;
  } else if (num->spec_g && num->amountСharNumbG > num->precision &&
             num->flagPrecision) {
    num->spec_e = 1;
  } else if (num->spec_G && num->amountСharNumbG > 6 && !num->flagPrecision) {
    num->spec_E = 1;
  } else if (num->spec_G && num->amountСharNumbG > num->precision &&
             num->flagPrecision) {
    num->spec_E = 1;
  }
  if (numb < 0) {
    flagNegative = 1;
    k = 1;
  }
  if ((num->spec_g || num->spec_G || num->spec_g_low) && num->flagPrecision &&
      num->precision < 2) {
    num->spec_e = 1;
  }
  if (num->spec_e || num->spec_E) {
    double numbSpecE = numb;
    num->degree_spec_e = countСharSpecE(&numbSpecE);
    if (num->flagPrecision &&
        num->precision == 0) {  // для случая %.E, где не указана точность
      int temp =
          (int)(numbSpecE *
                10);  // умножаем на 10 для переноса из дробной части в целую
      temp = roundInt(temp, 1) / 10;  // округляем и снова делим на 10
      number[0] =
          temp + '0';  // при флаге %.E и 2.54E+01 нужно преобразовать в 3E+01
      if (num->flagSharp) number[1] = '.';
    } else {
      doubleToChar(numbSpecE, number, num);
    }
  } else {
    doubleToChar(numb, number, num);  // перевод числа из double в char для %f
  }
  if (num->flagPlus && !(numb < 0)) k += 1;
  if ((num->spec_e || num->spec_E)) {  // костыль для флага E, чтобы учитывал
                                       // символы e+07 в 4.e+07
    addSpace = num->width - (int)s21_strlen(number) - k - 4;
  } else {
    addSpace = num->width - (int)s21_strlen(number) - k;
  }
  if (num->spec_e || num->spec_E) {  // костыль для флага E, чтобы учитывал
                                     // символы e+07 в 4.e+07
    addNull = num->amountNull - (int)s21_strlen(number) - k - 4;
  } else if ((num->spec_g || num->spec_G) && num->amountСharNumbG < 7 &&
             num->amountСharNumbG >= 1 && !num->flagPrecision) {
    addNull =
        num->amountNull - 7 -
        k;  // 7 - количество печатаемых символов для чисел от 1 до 6 знаков
  } else {
    addNull = num->amountNull - (int)s21_strlen(number) - k;
  }
  if (num->flagWidth && !num->flagNull &&
      !num->flagMinus) {  // сдвинуть функцию вниз под флаг Плюс
    if ((int)s21_strlen(number) + k < num->width) {
      for (int i = 0; i < addSpace; i++) {
        buffer[num->posBuff++] = ' ';
      }
    }
  }
  if (numb >= 0 && num->flagPlus) {
    buffer[num->posBuff++] = '+';
  } else if (numb < 0 || flagNegative) {
    buffer[num->posBuff++] = '-';
  }
  if (0 < num->amountNull) {  // (int)s21_strlen(number) + k < num->amountNull
    for (int i = 0; i < addNull; i++) {
      buffer[num->posBuff++] = '0';
    }
  }
  if (!num->spec_e && !num->spec_E && !num->spec_g &&
      !num->spec_G) {  // запись числа для спецификатора f
    for (int i = 0; i < (int)s21_strlen(number); i++) {
      buffer[num->posBuff++] = number[i];
    }
  }
  if ((num->spec_g || num->spec_G) && !num->spec_e &&
      !num->spec_E) {  // запись числа при флаге g
    int count = (int)s21_strlen(number);
    if (count > 7 && !num->flagPrecision && num->amountСharNumbG != 0) {
      count = 7;
    } else if (num->flagPrecision &&
               (int)s21_strlen(number) >
                   num->precision) {  // (int)s21_strlen(number) >
                                      // num->precision
                                      // - защита от того, чтобы не идти по
                                      // пустому массиву
      count = num->precision + 1;  //  для случая "%#.5g", 2.234);
    }
    for (int i = 0; i < count; i++) {  // i < 7
      buffer[num->posBuff++] = number[i];
      if (!num->flagSharp && num->amountСharNumbG == 6 && i == 5 &&
          num->precision < 7) {
        i++;  // не печатать последний символ '.' при 6-значном числе
      }  // условие num->precision < 7 для случая "|%-10.10g|\n", 234567.43242);
    }
  }
  if (num->spec_e || num->spec_E) {
    int amount = (int)s21_strlen(number);  // я забыл для чего это условие
    if ((num->spec_g || num->spec_G) && num->amountСharNumbG > 6 &&
        !num->flagPrecision &&
        (int)s21_strlen(number) > 7) {  // это для печать большого числа 1e+06
      amount = 7;  // нужно условие для печети маленького 1e-06
    } else if ((num->spec_g || num->spec_G) && num->flagPrecision &&
               !num->flagSharp && (int)s21_strlen(number) > num->precision &&
               !num->spec_g_low) {
      amount = num->precision;
    } else if ((num->spec_g || num->spec_G) && num->flagPrecision &&
               num->flagSharp && (int)s21_strlen(number) > num->precision) {
      amount =
          num->precision + 1;  // + 1 чтобы точка попадала в цикл для печати
      if (num->precision == 0)  // для случая типа |2.e+04|
        amount = 2;  // для случая |%#*.g|\n", 5, 23456.4324);
    }
    for (int i = 0; i < amount;
         i++) {  // i < amount || i < (int)s21_strlen(number)
      buffer[num->posBuff++] = number[i];
    }
    if (num->spec_E) {
      buffer[num->posBuff++] = 'E';
    } else if (num->spec_e) {
      buffer[num->posBuff++] = 'e';
    }
    if (num->degree_spec_e >= 0) {
      buffer[num->posBuff++] = '+';
      if (num->degree_spec_e < 10) {
        buffer[num->posBuff++] = '0';
      }
    } else {
      num->degree_spec_e *= -1;
      buffer[num->posBuff++] = '-';
      if (num->degree_spec_e < 10) {
        buffer[num->posBuff++] = '0';
      }
    }
    buffer[num->posBuff++] = num->degree_spec_e + '0';
  }
  if (num->flagMinus && addSpace < num->width) {
    for (int i = 0; i < addSpace; i++) {
      buffer[num->posBuff++] = ' ';
    }
  }
  num->flagReset = 1;
}

void flagWidth(char *fmt, flag *num) {  // , flag *num
  if (!num->flagWidth && !num->flagNull && !num->flagPrecision && *fmt > 48 &&
      *fmt < 58) {  // чтобы 2 раза не заходил в функцию
    char ch[40] = {'\0'};
    int width = 0, i = 0;  // ширина
    while (*fmt > 47 && *fmt < 58) {
      ch[i] = *fmt;
      i++;
      fmt++;
    }
    width = s21_atoi(ch);
    num->width = width;
    num->flagWidth = 1;
  }
}

void flagPrecision(char *fmt, flag *num) {  // , flag *num
  char ch[40] = {'\0'};
  int i = 0, precision = 0;  // precision - количество точек
  if (*fmt++ != '*') {
    while (*fmt > 47 && *fmt < 58) {  //  && *fmt != '*'
      ch[i] = *fmt;
      i++;
      fmt++;
    }
  }
  precision = s21_atoi(ch);
  num->precision = precision;
  num->flagPrecision = 1;
}

void spec_n(char *buffer, va_list ap, flag *num) {
  int *n = va_arg(ap, int *);
  *n = (int)s21_strlen(buffer);
  num->flagReset = 1;
}

void charToBuffer(char *buffer, va_list ap, flag *num) {
  char c[6] = {'\0'};
  if (num->length_l) {
    wchar_t wh = va_arg(ap, wchar_t);
    wctomb(c, wh);
  } else {
    c[0] = (char)va_arg(ap, int);
  }
  int ind = num->posBuff, addSpace = 0;
  if (num->flagMinus) {
    buffer[ind] = c[0];
    num->posBuff++;
    ind++;
  }
  if (num->flagWidth) {
    addSpace = num->width - 1;
    for (int i = 0; i < addSpace; i++) {
      buffer[ind] = ' ';
      ind++;
      num->posBuff++;
    }
  }
  if (!num->flagMinus) {
    buffer[ind] = c[0];
    num->posBuff++;
  }
  num->flagReset = 1;
}

void stringToBuffer(char *buffer, va_list ap, flag *num) {
  char temp[200] = {'\0'};
  char *s = temp;
  if (num->length_l) {
    wchar_t *wTemp = va_arg(ap, wchar_t *);
    wcstombs(temp, wTemp, sizeof(temp));
  } else {
    s = va_arg(ap, char *);
  }
  int ind = num->posBuff, addSpace = 0, length = s21_strlen(s);
  if (num->flagPrecision && length > num->precision) {  // !!
    length = num->precision;
  }
  if (num->flagMinus) {
    for (int i = 0; i < length; i++) {
      buffer[ind] = s[i];
      num->posBuff++;
      ind++;
    }
  }
  if (num->flagWidth) {
    addSpace = num->width - length;
    for (int i = 0; i < addSpace; i++) {
      buffer[ind] = ' ';
      ind++;
      num->posBuff++;
    }
  }
  if (!num->flagMinus) {
    for (int i = 0; i < length; i++) {
      buffer[ind] = s[i];
      num->posBuff++;
      ind++;
    }
  }
  num->flagReset = 1;
}

// int sprintf (char *s, const char *format, ...); вернуть s21_strlen buffer
int s21_sprintf(char *s, char *fmt, ...) {
  va_list ap;  // ap - указатель на аргументы argument pointer
  flag num = {0};
  int t = 0, star = 0, length = s21_strlen(fmt);
  char tmp[500] = {'\0'};  // , c = '\0'; // *s = {'\0'};
  va_start(ap, fmt);  // инициализация списка аргументов
  for (int j = 0; j < length; j++, fmt++) {  // проходимcя по всем символам fmt
    if (*fmt == '%') {
      num.process++;
    }
    if (num.process) {
      switch (*fmt) {
        case 'c':
          charToBuffer(tmp, ap, &num);
          break;
        case 'd':
          printFlags(tmp, ap, &num);
          break;
        case 'i':
          printFlagsUnsigned(tmp, ap, &num);
          break;
        case 'o':
          num.spec_o = 1;
          printFlagsUnsigned(tmp, ap, &num);
          break;
        case 'x':
          num.spec_x = 1;
          printFlagsUnsigned(tmp, ap, &num);
          break;
        case 'X':
          num.spec_X = 1;
          printFlagsUnsigned(tmp, ap, &num);
          break;
        case 'f':
          printFlagsDouble(tmp, ap, &num);
          break;
        case 'e':
          num.spec_e = 1;
          printFlagsDouble(tmp, ap, &num);
          break;
        case 'E':
          num.spec_E = 1;
          printFlagsDouble(tmp, ap, &num);
          break;
        case 'g':
          num.spec_g = 1;
          printFlagsDouble(tmp, ap, &num);
          break;
        case 'G':
          num.spec_G = 1;
          printFlagsDouble(tmp, ap, &num);
          break;
        case 's':
          stringToBuffer(tmp, ap, &num);
          break;
        case 'u':
          printFlagsUnsigned(tmp, ap, &num);
          break;
        case 'p':
          num.spec_p = 1;
          printFlagsPointer(tmp, ap, &num);
          break;
        case 'h':
          num.length_h++;
          break;
        case 'l':
          num.length_l++;
          break;
        case 'L':
          num.length_L++;
          break;
        case '+':
          num.flagPlus = 1;
          break;
        case '-':
          num.flagMinus = 1;
          break;
        case '0':
          flagNull(fmt, &num);
          break;
        case 'n':
          spec_n(tmp, ap, &num);
          break;
        case '*':
          star = va_arg(ap, int);
          if (num.flagPrecision) {
            num.precision = star;
          } else {
            num.flagWidth = 1;
            num.width = star;
          }
          break;
        case '.':
          flagPrecision(fmt, &num);
          break;
        case '#':
          num.flagSharp = 1;
          break;
        case ' ':  // если число отрицательное, пробел не ставится
          tmp[num.posBuff++] = ' ';  // Если знак не будет выведен, перед
                                     // значением вставляется пробел.
          break;
      }
      if (!num.flagPrecision) {
        flagWidth(fmt, &num);
      }
    }
    if ((*fmt != '\0' && *fmt != '%' && !num.process) || num.process == 2) {
      tmp[num.posBuff++] = *fmt;
      num.flagReset = 1;
    }
    if (num.flagReset) {
      resetFlags(&num);  // обнулить флаги в конце цикла
      num.flagReset = 0;  // это условие очень важно
    }
  }
  va_end(ap);  // конец обработки списка (стека) параметров
  int lengthStr = s21_strlen(tmp);
  while (lengthStr--) {
    s[t] = tmp[t];
    t++;
  }
  s[t] = '\0';
  return (int)s21_strlen(s);
}
