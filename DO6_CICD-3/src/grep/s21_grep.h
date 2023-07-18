#ifndef SRC_GREP_S21_CAT_H_
#define SRC_GREP_S21_CAT_H_

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int amount_patterns;
  int amount_Files;
} flag;

typedef struct {
  char word[100];
} key;

void printPattern(flag *num, key *patterns);
void printFiles(int argc, char **argv);
void parseFlag(flag *num, int argc, char **argv);  // парсинг флагов
int checkCurrentTextFile(char **argv,
                         int numb);  // проверка аргумента на текстовый файл
int checkArgFlagF(int argc, char **argv,
                  int numb);  // проверка наличия флага F в текущем аргументе
int match(char *string, flag *num, key *patterns,
          int regFlag);  // проверка регулярного выражения
void openFile(flag *num, char *file_name, key *patterns);  // обработка флагов
int printFlagF(flag *num, int retval, char *buffer,
               int amountPrint);  // печать флага F
int flagC(flag *num, int retval, int countFlagC, int countFlagL);  // флаг C
int flagL(char *file_name, flag *num, int retval, int countFlagL);  // флаг L
int flagN(char *file_name, flag *num, int retval, char *buffer, int lines_count,
          int amountPrint);  // флаг N
void flagNO(char *file_name, flag *num, int retval, int lines_count,
            int amountPrint);  // флаг N и O
int flagV(char *file_name, flag *num, int retval, char *buffer,
          int amountPrint);  // флаг V
int flagE(char *file_name, flag *num, int retval, char *buffer,
          int amountPrint);                                       // флаг E
int flagH(flag *num, int retval, char *buffer, int amountPrint);  // флаг H
int flagS(flag *num, int retval, char *buffer, int amountPrint);  // флаг S
int flagI(flag *num, int retval, char *buffer, int amountPrint);  // флаг I
void flagF(char *file_name, flag *num, key *patterns);            // флаг F
void flagO(char *string, flag *num, key *patternschar,
           char *file_name);  // флаг О
void printFlagC(char *file_name, flag *num, int countFlagC, int countFlagL);
void amountFiles(int argc, char **argv,
                 flag *num);  // количество текстовых файлов
void checkFlags(flag *num);  // проверка флагов
void callOpenFile(
    int argc, char **argv, flag *num,
    key *patterns);  // запись паттернов и вызов функции обработки флагов

#endif  // SRC_GREP_S21_CAT_H_