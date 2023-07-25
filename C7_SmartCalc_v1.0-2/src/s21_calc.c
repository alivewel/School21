#include "s21_calc.h"

void pushStack(Node **head, double value) {
  Node *new_node =
      (Node *)malloc(sizeof(Node));  // Выделяем память для нового элемента
  new_node->value = value;  // Заполняем значение элемента
  new_node->next =
      *head;  // Указатель на следующий элемент - текущий верхний элемент
  *head = new_node;  // Обновляем указатель на верхний элемент
}

void pushStackType(Node **head, int type) {
  Node *new_node =
      (Node *)malloc(sizeof(Node));  // Выделяем память для нового элемента
  new_node->type = type;  // Заполняем значение элемента
  new_node->value = 0;    // чтобы мусор не записывался
  new_node->next =
      *head;  // Указатель на следующий элемент - текущий верхний элемент
  *head = new_node;  // Обновляем указатель на верхний элемент
}

double popStack(Node **top) {
  double value = 0;
  if (*top != NULL) {  // Проверка на пустой стек
    Node *temp =
        *top;  // Сохранение указателя на вершину стека во временной переменной
    value =
        temp->value;  // Сохранение значения вершины стека в переменной value
    *top = (*top)->next;  // Обновление вершины стека
    free(temp);  // Освобождение памяти, выделенной для узла
  }
  return value;  // Возвращение значения, сохраненного в переменной value
}

int popStackType(Node **top) {
  int type = 0;
  if (*top != NULL) {  // Проверка на пустой стек
    Node *temp =
        *top;  // Сохранение указателя на вершину стека во временной переменной
    type = temp->type;  // Сохранение значения вершины стека в переменной value
    *top = (*top)->next;  // Обновление вершины стека
    free(temp);  // Освобождение памяти, выделенной для узла
  }
  return type;  // Возвращение значения, сохраненного в переменной value
}

void print_stack(Node *head) {
  printf("Stack contents:\n");
  int num = 1;
  while (head != NULL) {
    printf("%d: %lf %d\n", num++, head->value, head->type);
    head = head->next;
  }
}

int searchNumber(char *str, double *value) {
  int i = 0;
  char number_s[256] = {'\0'};
  double number = 0;
  while ((*str >= '0' && *str <= '9') || (*str == '.')) {
    number_s[i] = *str;
    i++;
    str++;
  }
  if (sscanf(number_s, "%lf", &number) == 1) {
    *value = number;
    memset(number_s, 0, sizeof(number_s));
  }
  return i;  // вернуть количество символов, на которые нужно сдвинуть *str
}

int type_operator(char str) {
  int result = 0;
  if (str == '+') {
    result = PLUS;
  } else if (str == '-') {
    result = MINUS;
  } else if (str == '*') {
    result = MULT;
  } else if (str == '/') {
    result = DIV;
  } else if (str == '^') {
    result = POW;
  } else if (str == '(') {
    result = BKT_OPEN;
  } else if (str == ')') {
    result = BKT_CLOSE;
  }
  return result;
}

void func_reverse_stack(Node **head_outstring, Node **reverse_stack) {
  while (*head_outstring != NULL) {
    Node *current_node = *head_outstring;
    *head_outstring = (*head_outstring)->next;
    current_node->next = *reverse_stack;
    *reverse_stack = current_node;
  }
}

void clean_stack(Node *stack) {
  Node *current = stack;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
}

double unaryOperation(double num1, int oper) {
  double result = 0;
  if (oper == SIN) {
    result = sin(num1);
  } else if (oper == COS) {
    result = cos(num1);
  } else if (oper == TAN) {
    result = tan(num1);
  } else if (oper == ASIN) {
    result = asin(num1);
  } else if (oper == ACOS) {
    result = acos(num1);
  } else if (oper == ATAN) {
    result = atan(num1);
  } else if (oper == LN) {
    result = log(num1);
  } else if (oper == LOG) {
    result = log10(num1);
  } else if (oper == SQRT) {
    result = sqrt(num1);
  }
  return result;
}

double binaryOperation(double num1, double num2, int oper) {
  double result = 0;
  if (oper == PLUS) {
    result = num1 + num2;
  } else if (oper == MINUS) {
    result = num2 - num1;
  } else if (oper == MULT) {
    result = num1 * num2;
  } else if (oper == DIV) {
    result = num2 / num1;
  } else if (oper == MOD) {
    result = fmod(num2, num1);
  } else if (oper == POW) {
    result = pow(num2, num1);
  }
  return result;
}

double arithmetic(Node **head_stack) {
  Node *head_numbers = NULL;
  int type = 0, operator= 0;
  double currentValue = 0, result = 0, num1 = 0, num2 = 0, resultTemp = 0;
  while (*head_stack != NULL) {
    type = (int)(*head_stack)->type;
    if (type == 1) {
      currentValue = popStack(head_stack);
      pushStack(&head_numbers, currentValue);
    } else {
      if ((type >= PLUS && type <= POW) || type == MOD) {
        num1 = popStack(&head_numbers);
        num2 = popStack(&head_numbers);
        operator= popStackType(head_stack);  // вытаскиваем из стека оператор
        resultTemp = binaryOperation(num1, num2, operator);
        pushStack(&head_numbers, resultTemp);
        head_numbers->type = VALUE;
      } else {
        num1 = popStack(&head_numbers);
        operator= popStackType(head_stack);  // вытаскиваем из стека оператор
        resultTemp = unaryOperation(num1, operator);
        pushStack(&head_numbers, resultTemp);
        head_numbers->type = VALUE;
      }
    }
  }
  result = head_numbers->value;
  clean_stack(head_numbers);
  clean_stack(*head_stack);
  return result;
}

int priority(int type) {
  int prior = 0;
  if (type >= SIN && type <= LN) {
    prior = 4;
  } else if (type == SQRT || type == POW) {
    prior = 5;
  } else if (type == MULT || type == DIV || type == MOD) {
    prior = 3;
  } else if (type == PLUS || type == MINUS) {
    prior = 2;
  } else if (type == BKT_OPEN) {
    prior = 1;
  }
  return prior;
}

int type_function(char *str) {
  int result = 0;
  if (strcmp(str, "sin") == 0) {
    result = SIN;
  } else if (strcmp(str, "cos") == 0) {
    result = COS;
  } else if (strcmp(str, "tan") == 0) {
    result = TAN;
  } else if (strcmp(str, "asin") == 0) {
    result = ASIN;
  } else if (strcmp(str, "acos") == 0) {
    result = ACOS;
  } else if (strcmp(str, "atan") == 0) {
    result = ATAN;
  } else if (strcmp(str, "sqrt") == 0) {
    result = SQRT;
  } else if (strcmp(str, "ln") == 0) {
    result = LN;
  } else if (strcmp(str, "mod") == 0) {
    result = MOD;
  }
  return result;
}

int parser_function(char *str, int *type) {
  int i = 0;
  char func[256] = {'\0'};
  while (*str >= 'a' && *str <= 'z') {
    func[i] = *str;
    i++;
    str++;
  }
  *type = type_function(func);
  return i;
}

void my_opn(char *a, double *result) {
  Node *operators = NULL;
  Node *head_outstring = NULL;
  double value = 0;
  int length = strlen(a);
  int type = 0, k = 0, flag_un_minus = 0, flag_un_plus = 0;
  /* с каждой итерацией буду занулять type */
  /* с каждой итерацией буду текущий символ отправлять в parser_function и
   * type_operator */
  /* если не равно нулю значит текущий символ функция или оператор */
  /* и уже на входе в обработке функций и операторов буду смотреть символ это
   * или оператор */
  while (k < length) {
    /* обработка унарного минуса */
    if (a[k] == '-' && (k == 0 || a[k - 1] == '(') && a[k + 1] >= '0' &&
        a[k + 1] <= '9') {
      flag_un_minus = 1;
    }
    /* обработка унарного плюса */
    if (a[k] == '+' && (k == 0 || a[k - 1] == '(') && a[k + 1] >= '0' &&
        a[k + 1] <= '9') {
      flag_un_plus = 1;
    }
    /* если текущий символ оператор узнаем его тип */
    if ((a[k] == '+' || a[k] == '-' || a[k] == '/' || a[k] == '*' ||
         a[k] == '^' || a[k] == '(' || a[k] == ')') &&
        !flag_un_minus && !flag_un_plus) {
      type = type_operator(a[k]);
    }
    if (a[k] == ')') {
      while (operators != NULL && (*operators).type != BKT_OPEN) {
        int typeOperator = popStackType(&operators);
        pushStackType(&head_outstring, typeOperator);
      }
      /* Удаляем из стека саму откpывающую скобку */
      popStack(&operators);
    }
    /* если текущий функция оператор узнаем его тип */
    /* Если очеpедной символ - буква , то */
    if (a[k] >= 'a' && a[k] <= 'z') {
      /* пеpеписываем её в выходную стpоку */
      int temp = parser_function(a + k, &type);
      k += temp - 1;
    }
    /* Если очеpедной символ - цифра , то */
    if (a[k] >= '0' && a[k] <= '9') {
      int temp = searchNumber(a + k, &value);
      if (flag_un_minus) {
        value *= -1;
        flag_un_minus = 0;
      } else if (flag_un_plus) {
        flag_un_plus = 0;
      }
      pushStack(&head_outstring, value);
      (*head_outstring).type = VALUE;
      k += temp - 1;
    }
    if (a[k] == '(') {
      pushStackType(&operators, BKT_OPEN);
    }
    /* если type = 0 значит текущий символ число */
    if (type != 0 && type != BKT_OPEN && type != BKT_CLOSE) {
      /* Если следующий символ - знак опеpации , то: */
      /* если стек пуст */
      if (operators == NULL) {
        /* заталкиваем поступившую опеpацию на стек */
        pushStackType(&operators, type);
      } else { /* если пpиоpитет меньше */
        if (priority((*operators).type) < priority(type)) {
          pushStackType(&operators, type);
        } else {
          while ((operators != NULL) &&
                 (priority((*operators).type) >= priority(type))) {
            /* пеpеписываем в выходную стpоку все опеpации
                                с большим или pавным пpиоpитетом */
            /* вытаскиваем из стека оператор и записываем его type */
            int typeOperator = popStackType(&operators);  //
            pushStackType(&head_outstring, typeOperator);
          }
          /* записываем в стек поступившую  опеpацию */
          pushStackType(&operators, type);
        }
      }
    }
    type = 0;
    /* Пеpеход к следующему символу входной стpоки */
    k++;
    // print_stack(head_outstring);
  }
  /* после pассмотpения всего выpажения */
  while (operators != NULL) {
    /* Пеpеписываем все опеpации из */
    /* стека в выходную стpоку */
    int typeOperator = popStackType(&operators);
    pushStackType(&head_outstring, typeOperator);
  }
  clean_stack(operators);
  Node *reverse_stack = NULL;
  func_reverse_stack(&head_outstring, &reverse_stack);
  clean_stack(head_outstring);
  *result = arithmetic(&reverse_stack);
  clean_stack(reverse_stack);
}

void prepareString(char *str) {
  int i, j;
  for (i = 0, j = 0; str[i] != '\0'; i++) {
    if (str[i] != ' ') {
      if (str[i] == ',') {
        str[j++] = '.';
      } else {
        str[j++] = tolower(str[i]);
      }
    }
  }
  str[j] = '\0';
}

int checkOperatorOrDot(char ch) {
  int status = 0;
  if (ch == '*' || ch == '/' || ch == '^' || ch == '+' || ch == '-' ||
      ch == '.') {
    status = 1;
  }
  return status;
}

int validation(char *str) {
  int error = 0;
  if (str == NULL || str[0] == '\0' || strlen(str) > 255) {
    error = 1;
  } else {
    int length = strlen(str), i = 0, brackOpen = 0, brackClose = 0;
    while (i < length) {
      if (str[i] == '(')
        brackOpen++;
      else if (str[i] == ')')
        brackClose++;
      if (i == length - 1 && brackOpen != brackClose) error = 1;
      if (str[i] == '(' && (str[i + 1] == '*' || str[i + 1] == '/' ||
                            str[i + 1] == '^' || str[i + 1] == 'm'))
        error = 1;
      if (i == 0 && (str[i] == '*' || str[i] == '/' || str[i] == '^' ||
                     str[i] == 'm' || str[i] == '.'))
        error = 1;
      if (checkOperatorOrDot(str[i]) && checkOperatorOrDot(str[i + 1]) &&
          i != length - 1)
        error = 1;
      if (i != 0 && str[i] == '.' &&
          (!(isdigit(str[i - 1])) || !(isdigit(str[i + 1]))) && i != length - 1)
        error = 1;
      if (i != length - 1 && str[i] == '(' && str[i + 1] == ')') error = 1;
      i++;
    }
  }
  return error;
}

int calculator(char *str, double *result) {
  int error = 0;
  /* создается копия строки, чтобы была возможность ее изменять */
  char copyStr[strlen(str) + 1];
  strcpy(copyStr, str);
  prepareString(copyStr);
  error = validation(copyStr);
  if (error == 0) {
    my_opn(copyStr, result);
  }
  return error;
}
