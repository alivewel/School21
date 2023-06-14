#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

typedef struct {
  int b;
  int n;
  int s;
  int e;
  int t;
  int v;
  int T;
  int E;
} flag;

void catVoid();
int searchCountName(int argc, char **argv);
void parseFlag(flag *num, int argc, char **argv);
void parseDoubleFlag(flag *num, int argc, char **argv);
void openFile(char *file_name, flag *num);
void callOpenFile(int argc, char **argv, flag *num);

#endif  // SRC_CAT_S21_CAT_H_