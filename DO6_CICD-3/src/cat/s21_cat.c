#include "s21_cat.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    catVoid();
  } else {
    flag num = {0};
    if (searchCountName(argc, argv) == 1) {
      openFile(argv[1], &num);
    } else {
      parseFlag(&num, argc, argv);
      parseDoubleFlag(&num, argc, argv);
      callOpenFile(argc, argv, &num);
    }
  }
  return 0;
}

void catVoid() {
  char buffer[1000];
  while (fgets(buffer, 1000, stdin) != NULL) {
    printf("%s", buffer);
  }
}

int searchCountName(int argc, char **argv) {
  int countName = 1;
  for (int i = 1; argc > i; i++) {
    if (argv[i][0] != '-') {
      break;
    } else {
      countName++;
    }
  }
  return countName;
}

void parseFlag(flag *num, int argc, char **argv) {  // , char *name
  for (int i = 1; argc > i; i++) {
    if (argv[i][0] == '-' && argv[i][1] != '-') {
      int lenArg = strlen(argv[i]);
      int j = 1;
      while (j < lenArg) {
        if (argv[i][j] == 'b') {
          num->b = 1;
        } else if (argv[i][j] == 'n') {
          num->n = 1;
        } else if (argv[i][j] == 's') {
          num->s = 1;
        } else if (argv[i][j] == 'e') {
          num->e = 1;
          num->v = 1;
        } else if (argv[i][j] == 't') {
          num->t = 1;
          num->v = 1;
        } else if (argv[i][j] == 'v') {
          num->v = 1;
        } else if (argv[i][j] == 'T') {
          num->t = 1;
        } else if (argv[i][j] == 'E') {
          num->t = 1;
        } else {
          fprintf(
              stderr,
              "cat: illegal option - %c\nusage: cat [-benstuv] [file ...]\n",
              argv[1][0]);
          break;
        }
        j++;
      }
    }
  }
}

void parseDoubleFlag(flag *num, int argc, char **argv) {
  for (int i = 1; argc > i; i++) {
    if (argv[i][0] == '-' && argv[i][1] == '-') {
      if (strcmp(argv[i], "--number-nonblank") == 0) {
        num->b = 1;
      } else if (strcmp(argv[i], "--number") == 0) {
        num->n = 1;
      } else if (strcmp(argv[i], "--squezze-blank") == 0) {
        num->s = 1;
      } else {
        printf("cat: illegal option -- -\nusage: cat [-benstuv] [file ...]\n");
      }
    }
  }
}

void openFile(char *file_name, flag *num) {
  FILE *f;
  char ch;
  int countBefore = 0;
  int countFlagB = 1;
  int before = '\n';
  f = fopen(file_name, "r");
  if (f != NULL) {
    while ((ch = getc(f)) != EOF) {
      if (num->s && ch == '\n' && before == '\n') {
        countBefore++;
      } else {
        countBefore = 0;
      }
      if (countBefore < 2) {
        if (before == '\n' && num->n && !num->b) printf("%6d\t", countFlagB++);
        if (num->b && ch != '\n' && before == '\n')
          printf("%6d\t", countFlagB++);
        if (num->e && ch == '\n') putchar('$');
        if (num->t && ch == '\t') {
          putchar('^');
          ch = 'I';
        }
        if (num->v && ch != '\n') {
          if ((ch < 32 && ch > 10) || (ch < 9 && ch > -1))
            putchar('^'), ch = ch + 64;
          else if (ch == 127)
            putchar('^'), ch = ch - 64;
        }
        printf("%c", ch);
      }
      before = ch;
    }
  }
  fclose(f);
}

void callOpenFile(int argc, char **argv, flag *num) {
  for (int i = 1; argc > i; i++) {
    if (argv[i][0] != '-') {
      openFile(argv[i], num);
    }
  }
}
