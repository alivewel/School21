#include <check.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
// #include "s21_string.c" // зачем он здесь?
#include "s21_sprintf.h"
#include "s21_string.h"
#define SIZE 100

START_TEST(s21_strlen_test) {
  char *src[] = {"aboba",
                 "",
                 "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                 "              \t\n\\\\\\\fsewdwf",
                 "123456787654310",
                 "\0'\0\0",
                 "......................H"};

  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(s21_strlen(src[i]), strlen(src[i]));
  }
}
END_TEST

START_TEST(s21_strspn_test) {
  char *src[] = {"aboba",
                 "",
                 "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                 "              \t\n\\\\\\\fsewdwf",
                 "123456787654310",
                 "\0'\0\0",
                 "......................H",
                 "This is FUN!"};
  char *sym[] = {"a", "", "87523", "\t \n", "754321", "\0'", "H.", "sad"};

  for (int i = 0; i < 8; i++) {
    ck_assert_int_eq(s21_strspn(src[i], sym[i]), strspn(src[i], sym[i]));
    ck_assert_int_eq(s21_strspn(src[i], sym[7 - i]),
                     strspn(src[i], sym[7 - i]));
    ck_assert_int_eq(s21_strspn(src[7 - i], sym[i]),
                     strspn(src[7 - i], sym[i]));
  }
}
END_TEST

START_TEST(s21_strcspn_test) {
  char *src[] = {"aboba",
                 "",
                 "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                 "              \t\n\\\\\\\fsewdwf",
                 "123456787654310",
                 "\0'\0\0",
                 "......................H",
                 "This is FUN!"};
  char *sym[] = {"a", "", "87523", "\t \n", "754321", "\0'", "H.", "sad"};

  for (int i = 0; i < 8; i++) {
    ck_assert_int_eq(s21_strcspn(src[i], sym[i]), strcspn(src[i], sym[i]));
    ck_assert_int_eq(s21_strcspn(src[i], sym[7 - i]),
                     strcspn(src[i], sym[7 - i]));
    ck_assert_int_eq(s21_strcspn(src[7 - i], sym[i]),
                     strcspn(src[7 - i], sym[i]));
  }
}
END_TEST

START_TEST(s21_memcmp_test) {
  char *str1[] = {"abob",
                  "",
                  "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                  "              \t\n\\\\\\\fsewdwf",
                  "123456787654310",
                  "\0'\0\0",
                  "......................H",
                  "This is FUN!",
                  "HI"};
  char *str2[] = {"aboba",
                  " ",
                  "4785ty46h3w7854hgiutmrlkfem,rgwleorjlthey",
                  "              \t\n\\\\\\\fsewdwgvbhf",
                  "123456787654310.",
                  "\0'\0\0",
                  "......................H",
                  "This is FUn!!",
                  "Hi"};

  for (int i = 0; i < 8; i++) {
    ck_assert_int_eq(s21_memcmp(str1[i], str2[i], s21_strlen(str1[i])),
                     memcmp(str1[i], str2[i], s21_strlen(str1[i])));
    ck_assert_int_eq(s21_memcmp(str1[i], str2[i], s21_strlen(str1[i]) / 2),
                     memcmp(str1[i], str2[i], s21_strlen(str1[i]) / 2));
    ck_assert_int_eq(s21_memcmp(str1[i], str2[i], 0),
                     memcmp(str1[i], str2[i], 0));
    ck_assert_int_eq(s21_memcmp(str1[7 - i], str2[i], 0),
                     memcmp(str1[i], str2[i], 0));
    ck_assert_int_eq(s21_memcmp(str1[i], str2[7 - i], 0),
                     memcmp(str1[i], str2[i], 0));
  }
}
END_TEST

START_TEST(s21_strcmp_test) {
  char *str1[] = {"aboba",
                  " ",
                  "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                  "              \t\n\\\\\\\fsewdwf",
                  "123456787654310",
                  "\0'\0\0",
                  "......................H",
                  "This is FUN!"};
  char *str2[] = {"abob",
                  "",
                  "4785ty46h3w7854hgiutmrlkfem,rgwleorjlthey",
                  "              \t\n\\\\\\\fsewdwgvbhf",
                  "123456787654310.",
                  "\0'\0\0",
                  "",
                  "This is FU"};
  int res_0 = 0, res_1 = 0;

  for (int i = 0; i < 8; i++) {
    res_0 = 0, res_1 = 0;
    if (s21_strcmp(str1[i], str2[i]) >= 1) res_0 = 1;
    if (s21_strcmp(str1[i], str2[i]) <= -1) res_0 = -1;
    if (strcmp(str1[i], str2[i]) >= 1) res_1 = 1;
    if (strcmp(str1[i], str2[i]) <= -1) res_1 = -1;
    ck_assert_int_eq(res_0, res_1);

    res_0 = 0, res_1 = 0;
    if (s21_strcmp(str1[7 - i], str2[i]) >= 1) res_0 = 1;
    if (s21_strcmp(str1[7 - i], str2[i]) <= -1) res_0 = -1;
    if (strcmp(str1[7 - i], str2[i]) >= 1) res_1 = 1;
    if (strcmp(str1[7 - i], str2[i]) <= -1) res_1 = -1;
    ck_assert_int_eq(res_0, res_1);

    res_0 = 0, res_1 = 0;
    if (s21_strcmp(str1[i], str2[7 - i]) >= 1) res_0 = 1;
    if (s21_strcmp(str1[i], str2[7 - i]) <= -1) res_0 = -1;
    if (strcmp(str1[i], str2[7 - i]) >= 1) res_1 = 1;
    if (strcmp(str1[i], str2[7 - i]) <= -1) res_1 = -1;
    ck_assert_int_eq(res_0, res_1);
  }
}
END_TEST

START_TEST(s21_strncmp_test) {
  char *str1[] = {"aboba",
                  "abiba",
                  "",
                  "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                  "              \t\n\\\\\\\fsewdwf",
                  "123456787654310",
                  "\0'\0\0",
                  "......................H",
                  "This is FUN!",
                  "HI"};
  char *str2[] = {"abiba",
                  "aboba",
                  " ",
                  "4785ty46h3w7854hgiutmrlkfem,rgwleorjlthey",
                  "              \t\n\\\\\\\fsewdwgvbhf",
                  "123456787654310.",
                  "\0'\0\0",
                  "......................H",
                  "This is FUn!!",
                  "Hi"};

  int res_0 = 0, res_1 = 0;
  for (int i = 0; i < 10; i++) {
    res_0 = 0, res_1 = 0;
    int len = s21_strlen(str1[i]);
    if (s21_strncmp(str1[i], str2[i], len) >= 1) res_0 = 1;
    if (s21_strncmp(str1[i], str2[i], len) <= -1) res_0 = -1;
    if (strncmp(str1[i], str2[i], len) >= 1) res_1 = 1;
    if (strncmp(str1[i], str2[i], len) <= -1) res_1 = -1;
    ck_assert_int_eq(res_0, res_1);
  }
}
END_TEST

START_TEST(s21_strcpy_test) {
  char *src[] = {"abob",
                 "",
                 "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                 "              \t\n\\\\\\\fsewdwf",
                 "123456787654310",
                 "\0'\0\0",
                 "......................H",
                 "This is FUN!",
                 "HI"};

  char buf_1[SIZE] = {'\0'}, buf_2[SIZE] = {'\0'};
  for (int i = 0; i < 9; i++) {
    s21_strcpy(buf_1, src[i]);
    strcpy(buf_2, src[i]);
    ck_assert_str_eq(buf_1, buf_2);
  }
}
END_TEST

START_TEST(s21_strncpy_test) {
  const char *src[] = {"abob",
                       "",
                       "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                       "              \t\n\\\\\\\fsewdwf",
                       "123456787654310",
                       "\0'\0\0",
                       "......................H",
                       "This is FUN!",
                       "HI"};

  char buf_1[SIZE] = {'\0'}, buf_2[SIZE] = {'\0'};

  int len = 0;
  for (int i = 0; i < 8; i++) {
    len = s21_strlen(src[i]);
    for (int j = 0; j < len; j++) {
      s21_strncpy(buf_1, src[i], j);
      strncpy(buf_2, src[i], j);
      ck_assert_str_eq(buf_1, buf_2);
    }
  }
}
END_TEST

START_TEST(s21_memcpy_test) {
  const char *src[] = {"abob",
                       "",
                       "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                       "              \t\n\\\\\\\fsewdwf",
                       "123456787654310",
                       "\0'\0\0",
                       "......................H",
                       "This is FUN!",
                       "HI"};

  char buf_1[SIZE] = {'\0'}, buf_2[SIZE] = {'\0'};

  int len = 0;
  for (int i = 0; i < 8; i++) {
    len = s21_strlen(src[i]);
    for (int j = 0; j < len; j++) {
      s21_memcpy(buf_1, src[i], j);
      memcpy(buf_2, src[i], j);
      ck_assert_str_eq(buf_1, buf_2);
    }
  }
}
END_TEST

START_TEST(s21_memmove_test) {
  const char *src[] = {"abob",
                       "",
                       "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                       "              \t\n\\\\\\\fsewdwf",
                       "123456787654310",
                       "\0'\0\0",
                       "......................H",
                       "This is FUN!",
                       "HI"};

  char buf_1[SIZE] = {'\0'}, buf_2[SIZE] = {'\0'};

  int len = 0;
  for (int i = 0; i < 8; i++) {
    len = s21_strlen(src[i]);
    for (int j = 0; j < len; j++) {
      s21_memmove(buf_1, src[i], j);
      memmove(buf_2, src[i], j);
      ck_assert_str_eq(buf_1, buf_2);
    }
  }
}
END_TEST

START_TEST(s21_memset_test) {
  const char sym[] = {'\0', '1', '\n', '\\', 'A'};

  char buf_1[SIZE] = {'!'}, buf_2[SIZE] = {'!'};
  int minisize = SIZE / SIZE;
  for (int i = 0; i < 5; i++) {
    s21_memset(buf_1, sym[i], minisize);
    memset(buf_2, sym[i], minisize);
    ck_assert_str_eq(buf_1, buf_2);
  }
}
END_TEST

START_TEST(s21_memchr_test) {
  const char sym[] = {
      '\0', '1', '\n', '\\', 'A', ' ', '.',
  };
  const char *src1[] = {"abob",
                        "",
                        "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                        "              \t\n\\\\\\\fsewdwf",
                        "123456787654310",
                        "\0'\0\0",
                        "......................H",
                        "This is FUN!",
                        "HI"};

  const char *src2[] = {"abob",
                        "",
                        "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                        "              \t\n\\\\\\\fsewdwf",
                        "123456787654310",
                        "\0'\0\0",
                        "......................H",
                        "This is FUN!",
                        "HI"};

  int len = 0;
  for (int i = 0; i < 8; i++) {
    len = 7;
    for (int j = 0; j < len; j++) {
      s21_memchr(src1[i], sym[j], j);
      memchr(src2[i], sym[j], j);
      ck_assert_str_eq(src1[i], src2[i]);
    }
  }
}
END_TEST

START_TEST(s21_strchr_test) {
  const char sym[] = {
      '\0', '1', '\n', '\\', 'A', ' ', '.',
  };
  const char *src1[] = {"abob",
                        "",
                        "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                        "              \t\n\\\\\\\fsewdwf",
                        "123456787654310",
                        "\0'\0\0",
                        "......................H",
                        "This is FUN!",
                        "HI"};

  const char *src2[] = {"abob",
                        "",
                        "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                        "              \t\n\\\\\\\fsewdwf",
                        "123456787654310",
                        "\0'\0\0",
                        "......................H",
                        "This is FUN!",
                        "HI"};

  int len = 0;
  for (int i = 0; i < 8; i++) {
    len = 7;
    for (int j = 0; j < len; j++) {
      s21_strchr(src1[i], sym[j]);
      strchr(src2[i], sym[j]);
      ck_assert_str_eq(src1[i], src2[i]);
    }
  }
}
END_TEST

START_TEST(s21_strpbrk_test) {
  const char *sym[] = {"boa", "",   " ",   "\\",        "This FUN!",
                       "IH",  "\0", "\0'", "1234567890"};
  const char *src1[] = {"abob",
                        "",
                        "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                        "              \t\n\\\\\\\fsewdwf",
                        "123456787654310",
                        "\0'\0\0",
                        "......................H",
                        "This is FUN!",
                        "HI"};

  const char *src2[] = {"abob",
                        "",
                        "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                        "              \t\n\\\\\\\fsewdwf",
                        "123456787654310",
                        "\0'\0\0",
                        "......................H",
                        "This is FUN!",
                        "HI"};

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 9; j++) {
      s21_strpbrk(src1[i], sym[j]);
      strpbrk(src2[i], sym[j]);
      ck_assert_str_eq(src1[i], src2[i]);
    }
  }
}
END_TEST

START_TEST(s21_strrchr_test) {
  const char sym[] = {'1', '\n', '\\', 'A', ' ', '.', 'b', 'H', '0'};
  const char *src1[] = {"abob",
                        "",
                        "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                        "              \t\n\\\\\\\fsewdwf",
                        "123456787654310",
                        "\0'\0\0",
                        "......................H",
                        "This is FUN!",
                        "HI"};

  const char *src2[] = {"abob",
                        "",
                        "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                        "              \t\n\\\\\\\fsewdwf",
                        "123456787654310",
                        "\0'\0\0",
                        "......................H",
                        "This is FUN!",
                        "HI"};
  char *tmp1 = s21_NULL, *tmp2 = s21_NULL;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 9; j++) {
      tmp1 = s21_strrchr(src1[i], sym[j]);
      tmp2 = strrchr(src2[i], sym[j]);
      ck_assert_pstr_eq(tmp1, tmp2);
    }
  }
}
END_TEST

START_TEST(s21_strstr_test) {
  const char *haystack[] = {"abob",
                            "",
                            "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                            "              \t\n\\\\\\\fsewdwf",
                            "1234567adsxjksalnmlfcsablcfdknc87654310",
                            "\0'\0\0",
                            "......................H",
                            "This is FUN!",
                            "HI"};

  const char *needle[] = {"ab",    "",
                          "they",  "              \t\n\\\\\\\fsewdwf",
                          "\t \n", "123456787654310",
                          "\0'",   "\0",
                          ".H",    "This !FUN",
                          "IH",    "ih",
                          "Ih",    " "};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 14; j++) {
      ck_assert_pstr_eq(s21_strstr(haystack[i], needle[j]),
                        s21_strstr(haystack[i], needle[j]));
    }
  }
}
END_TEST

START_TEST(s21_strcat_test) {
  char str1[100][100] = {"abob",
                         "",
                         "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                         "              \t\n\\\\\\\fsewdwf",
                         "123456787654310",
                         "\0'\0\0",
                         "......................H",
                         "This is FUN!",
                         "HI"};
  const char str2[100][100] = {
      "ba",        "  ",         "they", "              \t\n\\\\\\\fsewdwf",
      "d7654310.", "\0'sad\0\0", "",     "This is FU",
      "",          "YOBABY"};
  char str1c[100][100] = {"abob",
                          "",
                          "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                          "              \t\n\\\\\\\fsewdwf",
                          "123456787654310",
                          "\0'\0\0",
                          "......................H",
                          "This is FUN!",
                          "HI"};
  const char str2c[100][100] = {
      "ba",        "  ",         "they", "              \t\n\\\\\\\fsewdwf",
      "d7654310.", "\0'sad\0\0", "",     "This is FU",
      "",          "YOBABY"};
  s21_strcat(str1[0], str2[0]);
  strcat(str1c[0], str2c[0]);
  ck_assert_str_eq(str1[0], str1c[0]);

  for (int i = 0; i < 9; i++) {
    s21_strcat(str1[i], str2[i]);
    strcat(str1c[i], str2c[i]);
    ck_assert_str_eq(str1[i], str1c[i]);
    s21_strcat(str1[i], str2[8 - i]);
    strcat(str1c[i], str2c[8 - i]);
    ck_assert_str_eq(str1[i], str1c[i]);
    s21_strcat(str1[8 - i], str2[i]);
    strcat(str1c[8 - i], str2c[i]);
    ck_assert_str_eq(str1[i], str1c[i]);
  }
}
END_TEST

START_TEST(s21_strncat_test) {
  char str1[100][100] = {"abob",
                         "",
                         "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                         "              \t\n\\\\\\\fsewdwf",
                         "123456787654310",
                         "\0'\0\0",
                         "......................H",
                         "This is FUN!",
                         "HI"};
  const char str2[100][100] = {
      "ba",        "  ",         "they", "              \t\n\\\\\\\fsewdwf",
      "d7654310.", "\0'sad\0\0", "",     "This is FU",
      "",          "YOBABY"};
  char str1c[100][100] = {"abob",
                          "",
                          "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                          "              \t\n\\\\\\\fsewdwf",
                          "123456787654310",
                          "\0'\0\0",
                          "......................H",
                          "This is FUN!",
                          "HI"};
  const char str2c[100][100] = {
      "ba",        "  ",         "they", "              \t\n\\\\\\\fsewdwf",
      "d7654310.", "\0'sad\0\0", "",     "This is FU",
      "",          "YOBABY"};

  for (int i = 0; i < 9; i++) {
    s21_strncat(str1[i], str2[i], 0);
    strncat(str1c[i], str2c[i], 0);
    ck_assert_str_eq(str1[i], str1c[i]);
    s21_strncat(str1[i], str2[i], 2);
    strncat(str1c[i], str2c[i], 2);
    ck_assert_str_eq(str1[i], str1c[i]);
    s21_strncat(str1[i], str2[i], 10);
    strncat(str1c[i], str2c[i], 10);
    ck_assert_str_eq(str1[i], str1c[i]);
  }
}
END_TEST

START_TEST(s21_to_upper_test) {
  char *str[] = {"abob",
                 "",
                 "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                 "              \t\n\\\\\\\fsewdwf",
                 "123456787654310",
                 "\0'\0\0",
                 "......................h",
                 "This is FUN!",
                 "hi"};

  char *stru[] = {"ABOB",
                  "",
                  "4785TY46H3W7854HGIUTMRLKFERGWLEORJLTHEY",
                  "              \t\n\\\\\\\fSEWDWF",
                  "123456787654310",
                  "\0'\0\0",
                  "......................H",
                  "THIS IS FUN!",
                  "HI"};

  char *buf = s21_NULL;
  for (int i = 0; i < 9; i++) {
    buf = (char *)s21_to_upper(str[i]);
    ck_assert_str_eq(buf, stru[i]);
    free(buf);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  char *str[] = {"ABob",
                 "",
                 "4785TY46H3W7854hgIUTMRLKFERGwlEORJLTHEY",
                 "              \t\n\\\\\\\fSEWDWF",
                 "123456787654310",
                 "\0'\0\0",
                 "......................H",
                 "THis IS FUN!",
                 "hI"};
  char *strl[] = {"abob",
                  "",
                  "4785ty46h3w7854hgiutmrlkfergwleorjlthey",
                  "              \t\n\\\\\\\fsewdwf",
                  "123456787654310",
                  "\0'\0\0",
                  "......................h",
                  "this is fun!",
                  "hi"};

  char *buf = s21_NULL;
  for (int i = 0; i < 9; i++) {
    buf = (char *)s21_to_lower(str[i]);
    ck_assert_str_eq(buf, strl[i]);
    free(buf);
  }
}
END_TEST

START_TEST(s21_to_strerror_test) {
  char *t1 = s21_NULL, *t2 = s21_NULL;
  for (int i = -10; i < 140; i++) {
    t1 = strerror(i);
    t2 = s21_strerror(i);
    ck_assert_str_eq(t1, t2);
  }
}
END_TEST

START_TEST(s21_strtok_test) {
  char str1[50][50] = {
      "This is a test very test string", "This is a test very test string",
      "This is a test very test string", "",
      "This is a test very test string", "               \0 \0 \0 \0\0"};
  const char delim[6][6] = {" ", "test", "", "e", "\0"};
  char str2[50][50] = {
      "This is a test very test string", "This is a test very test string",
      "This is a test very test string", "",
      "This is a test very test string", "               \0 \0 \0 \0\0"};

  char *tmp1 = strtok(str1[0], delim[0]);
  char *tmp2 = s21_strtok(str2[0], delim[0]);
  ck_assert_pstr_eq(tmp1, tmp2);
  while (tmp1 != s21_NULL || tmp2 != s21_NULL) {
    ck_assert_str_eq(tmp1, tmp2);
    tmp1 = strtok(s21_NULL, delim[0]);
    tmp2 = s21_strtok(s21_NULL, delim[0]);
  }

  tmp1 = strtok(str1[1], delim[1]);
  tmp2 = s21_strtok(str2[1], delim[1]);
  ck_assert_pstr_eq(tmp1, tmp2);
  while (tmp1 != s21_NULL || tmp2 != s21_NULL) {
    ck_assert_str_eq(tmp1, tmp2);
    tmp1 = strtok(s21_NULL, delim[0]);
    tmp2 = s21_strtok(s21_NULL, delim[0]);
  }

  tmp1 = strtok(str1[2], delim[2]);
  tmp2 = s21_strtok(str2[2], delim[2]);
  ck_assert_pstr_eq(tmp1, tmp2);
  while (tmp1 != s21_NULL || tmp2 != s21_NULL) {
    ck_assert_str_eq(tmp1, tmp2);
    tmp1 = strtok(s21_NULL, delim[2]);
    tmp2 = s21_strtok(s21_NULL, delim[2]);
  }

  tmp1 = strtok(str1[3], delim[2]);
  tmp2 = s21_strtok(str2[3], delim[2]);
  ck_assert_pstr_eq(tmp1, tmp2);

  tmp1 = strtok(str1[4], delim[3]);
  tmp2 = s21_strtok(str2[4], delim[3]);
  ck_assert_pstr_eq(tmp1, tmp2);
  while (tmp1 != s21_NULL || tmp2 != s21_NULL) {
    ck_assert_pstr_eq(tmp1, tmp2);
    tmp1 = strtok(s21_NULL, delim[3]);
    tmp2 = s21_strtok(s21_NULL, delim[3]);
  }

  tmp1 = strtok(str1[5], delim[4]);
  tmp2 = s21_strtok(str2[5], delim[4]);
  ck_assert_pstr_eq(tmp1, tmp2);
  while (tmp1 != s21_NULL || tmp2 != s21_NULL) {
    ck_assert_pstr_eq(tmp1, tmp2);
    tmp1 = strtok(s21_NULL, delim[4]);
    tmp2 = s21_strtok(s21_NULL, delim[4]);
  }
}
END_TEST

START_TEST(s21_insert_test) {
  char *s1 = "dead inside";
  char *s2 = "EPARASATE";
  char *s3 = "smart";
  char *s4 = "sponge bob";
  char *s5 = "";
  char *res1 = s21_insert(s1, "NEVERMORE ", 5);
  char *res2 = s21_insert(s2, "SI", 7);
  char *res3 = s21_insert(s3, "stupid", 0);
  char *res4 = s21_insert(s4, " - squared pants", 10);
  char *res5 = s21_insert(s5, "", 1);
  char *res6 = s21_insert(s5, "", 0);
  ck_assert_str_eq(res1, "dead NEVERMORE inside");
  ck_assert_str_eq(res2, "EPARASASITE");
  ck_assert_str_eq(res3, "stupidsmart");
  ck_assert_str_eq(res4, "sponge bob - squared pants");
  ck_assert_pstr_eq(res5, s21_NULL);
  ck_assert_str_eq(res6, "");
  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  free(res6);
}
END_TEST

START_TEST(s21_trim_test) {
  char *res = s21_trim("testc", "c");
  ck_assert_str_eq(res, "test");
  free(res);

  res = s21_trim(" test ", " ");
  ck_assert_str_eq(res, "test");
  free(res);

  res = s21_trim(" ", " ");
  ck_assert_str_eq(res, "");
  free(res);

  res = s21_trim("*te*st*", "*");
  ck_assert_str_eq(res, "te*st");
  free(res);

  res = s21_trim(" te st001", " ");
  ck_assert_str_eq(res, "te st001");
  free(res);

  res = s21_trim(" /*()", ")(/ *");
  ck_assert_str_eq(res, "");
  free(res);

  res = s21_trim("test", s21_NULL);
  ck_assert_str_eq(res, "test");
  free(res);

  res = s21_trim("test", "");
  ck_assert_str_eq(res, "test");
  free(res);
}
END_TEST

START_TEST(s21_sprintf_test1) {
  char str1[100];
  char str2[100];
  void *p = (void *)0x3456;
  int n1, n2;
  int r1 = sprintf(str1, "%d%o%s%c%i%e%f%E%g%u%x%G%X%n%p%%%s", 25, 342, "aboba",
                   'a', 123, 25.34, 4325.23434, 0.0000000123, 2.12345, 12345u,
                   8342, 0.0000456, 1235, &n1, p, "hello my friend");
  int r2 =
      s21_sprintf(str2, "%d%o%s%c%i%e%f%E%g%u%x%G%X%n%p%%%s", 25, 342, "aboba",
                  'a', 123, 25.34, 4325.23434, 0.0000000123, 2.12345, 12345u,
                  8342, 0.0000456, 1235, &n2, p, "hello my friend");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test2) {
  char str1[100];
  char str2[100];
  int r1 = sprintf(str1, "%+-25.3d%25.15o%#10.f%015d", 252, 243, 256.34, 15);
  int r2 =
      s21_sprintf(str2, "%+-25.3d%25.15o%#10.f%015d", 252, 243, 256.34, 15);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test3) {
  char str1[100];
  char str2[100];
  int r1 = sprintf(str1, "%#+34.10g%#.10x%#15.1o%25.10s", 25.3456, 1234, 4567,
                   "HELLOMYDEARFRIEND");
  int r2 = s21_sprintf(str2, "%#+34.10g%#.10x%#15.1o%25.10s", 25.3456, 1234,
                       4567, "HELLOMYDEARFRIEND");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test4) {
  char str1[100];
  char str2[100];
  void *p = (void *)43252342;
  int r1 = sprintf(str1, "%#24.e%-15.20i%20p%020u", 43253242.4342, 4567899, p,
                   43252342u);
  int r2 = s21_sprintf(str2, "%#24.e%-15.20i%20p%020u", 43253242.4342, 4567899,
                       p, 43252342u);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
  char str3[50];
  char str4[100];
  int r3 = sprintf(str3, "%*.0f", 25, 25432.34345);
  int r4 = s21_sprintf(str4, "%*.0f", 25, 25432.34345);
  ck_assert_str_eq(str3, str4);
  ck_assert_int_eq(r3, r4);
}
END_TEST

START_TEST(s21_sprintf_test_d) {
  char str1[1000];
  char str2[1000];
  short h = 34;
  int r1 = sprintf(
      str1, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
      335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
  int r2 = s21_sprintf(
      str2, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
      335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_i) {
  char str1[1000];
  char str2[1000];
  short h = 34;
  long l = 2353423523424;
  int r1 = sprintf(str1, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                   34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
  int r2 =
      s21_sprintf(str2, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                  34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_c) {
  char str1[1000];
  char str2[1000];
  wint_t c1 = 'T', c2 = 'Z';
  int r1 = sprintf(str1, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a', 'e',
                   'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
  int r2 = s21_sprintf(str2, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a',
                       'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_e) {
  char str1[1000];
  char str2[1000];
  int r1 =
      sprintf(str1, "%+-20e%010.*e%-*.16e%#025.10e%*.*e%*.15e%#010.*e%25.16e",
              2543.43254, 10, 1012.34567, 15, -0.00123, 45678.342532, 10, 15,
              11111.22, 16, -3245.3425342, 16, -0.00123, 235423424.43252);
  int r2 = s21_sprintf(
      str2, "%+-20e%010.*e%-*.16e%#025.10e%*.*e%*.15e%#010.*e%25.16e",
      2543.43254, 10, 1012.34567, 15, -0.00123, 45678.342532, 10, 15, 11111.22,
      16, -3245.3425342, 16, -0.00123, 235423424.43252);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_E) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(str1, "%+-25.4E%25.*E%-*.10E%#02.E%*.*E%*.15E%*E%12.16E",
                   3456.4325, 10, 23452.43242, 5, -0.05234, 25.432523432, 10, 2,
                   53242.4242, 10, 456789.43242, 25, 1111122222.34567899,
                   2345678.23453242);
  int r2 = s21_sprintf(str2, "%+-25.4E%25.*E%-*.10E%#02.E%*.*E%*.15E%*E%12.16E",
                       3456.4325, 10, 23452.43242, 5, -0.05234, 25.432523432,
                       10, 2, 53242.4242, 10, 456789.43242, 25,
                       1111122222.34567899, 2345678.23453242);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_f) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(
      str1, "%+-10.5f%+10.2f%15.16f%+*.10f%*.16f%-10.*f%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  int r2 = s21_sprintf(
      str2, "%+-10.5f%+10.2f%15.16f%+*.10f%*.16f%-10.*f%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_o) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 253;
  unsigned long l = 4325234324242l;
  int r1 = sprintf(str1, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                   12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
  int r2 =
      s21_sprintf(str2, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                  12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_x) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 345;
  unsigned long l = 52342353242l;
  int r1 = sprintf(str1,
                   "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%20.*"
                   "x%#10.*x%*.5hx%10.25lx",
                   235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                   8, 23452, 10, 34254, 3, 33334, 10, h, l);
  int r2 = s21_sprintf(str2,
                       "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%"
                       "20.*x%#10.*x%*.5hx%10.25lx",
                       235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                       3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_X) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 234;
  unsigned long l = 4325243132l;
  int r1 = sprintf(str1,
                   "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%21.*X%"
                   "#12.*X%*.8hx%14.12lX",
                   235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                   8, 23452, 10, 34254, 3, 33334, 10, h, l);
  int r2 = s21_sprintf(str2,
                       "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%"
                       "21.*X%#12.*X%*.8hx%14.12lX",
                       235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                       3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_u) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 115;
  unsigned long l = 123325242342l;
  int r1 =
      sprintf(str1, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
              4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u,
              20, 2432u, l, h);
  int r2 = s21_sprintf(
      str2, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu", 4321u,
      34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, l,
      h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
  char str1[1000];
  char str2[1000];
  wchar_t s[10] = {'h', 'e', 'l', 'l', 'o'};
  // wchar_t s[10] = {'п', 'р', 'и', 'в', 'е', 'т'};
  int r1 = sprintf(str1, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                   "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                   "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
  int r2 =
      s21_sprintf(str2, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                  "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                  "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_p) {
  char str1[1000];
  char str2[1000];
  void *p1 = (void *)0x123456789;
  void *p2 = (void *)4325234;
  void *p3 = (void *)0x123f324b;
  void *p4 = (void *)432520;
  int r1 = sprintf(str1, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4, p2,
                   10, p3, p1, 10, p4);
  int r2 = s21_sprintf(str2, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4,
                       p2, 10, p3, p1, 10, p4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_percent) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(str1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  int r2 = s21_sprintf(str2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_g) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(
      str1, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
      2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
      2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
  int r2 = s21_sprintf(
      str2, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
      2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
      2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_G) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(
      str1,
      "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
      43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
      111.432534243243242, 4324.43242, 25, -3213.43242, 16, -43.43242353242342,
      111.24324242, 25, 5, 0.000000342);
  int r2 = s21_sprintf(
      str2,
      "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
      43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
      111.432534243243242, 4324.43242, 25, -3213.43242, 16, -43.43242353242342,
      111.24324242, 25, 5, 0.000000342);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  int nf;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, s21_strlen_test);
  tcase_add_test(tc1_1, s21_strspn_test);
  tcase_add_test(tc1_1, s21_strcspn_test);
  tcase_add_test(tc1_1, s21_memcmp_test);
  tcase_add_test(tc1_1, s21_strcmp_test);
  tcase_add_test(tc1_1, s21_strncmp_test);
  tcase_add_test(tc1_1, s21_strcpy_test);
  tcase_add_test(tc1_1, s21_strncpy_test);
  tcase_add_test(tc1_1, s21_memcpy_test);
  tcase_add_test(tc1_1, s21_memmove_test);
  tcase_add_test(tc1_1, s21_memset_test);
  tcase_add_test(tc1_1, s21_memchr_test);
  tcase_add_test(tc1_1, s21_strchr_test);
  tcase_add_test(tc1_1, s21_strpbrk_test);
  tcase_add_test(tc1_1, s21_strrchr_test);
  tcase_add_test(tc1_1, s21_strstr_test);
  tcase_add_test(tc1_1, s21_strcat_test);
  tcase_add_test(tc1_1, s21_strncat_test);
  tcase_add_test(tc1_1, s21_to_upper_test);
  tcase_add_test(tc1_1, s21_to_lower_test);
  tcase_add_test(tc1_1, s21_to_strerror_test);
  tcase_add_test(tc1_1, s21_strtok_test);
  tcase_add_test(tc1_1, s21_insert_test);
  tcase_add_test(tc1_1, s21_trim_test);
  tcase_add_test(tc1_1, s21_sprintf_test1);
  tcase_add_test(tc1_1, s21_sprintf_test2);
  tcase_add_test(tc1_1, s21_sprintf_test3);
  tcase_add_test(tc1_1, s21_sprintf_test4);
  tcase_add_test(tc1_1, s21_sprintf_test_d);
  tcase_add_test(tc1_1, s21_sprintf_test_i);
  tcase_add_test(tc1_1, s21_sprintf_test_c);
  tcase_add_test(tc1_1, s21_sprintf_test_e);
  tcase_add_test(tc1_1, s21_sprintf_test_E);
  tcase_add_test(tc1_1, s21_sprintf_test_f);
  tcase_add_test(tc1_1, s21_sprintf_test_o);
  tcase_add_test(tc1_1, s21_sprintf_test_x);
  tcase_add_test(tc1_1, s21_sprintf_test_X);
  tcase_add_test(tc1_1, s21_sprintf_test_u);
  tcase_add_test(tc1_1, s21_sprintf_test_s);
  tcase_add_test(tc1_1, s21_sprintf_test_p);
  tcase_add_test(tc1_1, s21_sprintf_test_percent);
  tcase_add_test(tc1_1, s21_sprintf_test_g);
  tcase_add_test(tc1_1, s21_sprintf_test_G);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}