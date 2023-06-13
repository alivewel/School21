#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; *str != '\0'; str++, len++)
    ;
  return len;
}

s21_size_t s21_strspn(const char *str, const char *sym) {
  s21_size_t len = 0;
  while (*str && s21_strchr(sym, *str++)) {
    len++;
  }
  return len;
}

s21_size_t s21_strcspn(const char *str, const char *sym) {
  s21_size_t len = 0;
  while (*str) {
    if (s21_strchr(sym, *str)) {
      break;
    } else {
      str++;
      len++;
    }
  }
  return len;
}

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0, s1 = s21_strlen(str1), s2 = s21_strlen(str2);
  for (int i = 0; (i < s1 || i < s2) && !res; i++) {
    res = str1[i] - str2[i];
  }
  return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (int i = 0; (str1[i] != '\0' || str2[i] != '\0') && i < (int)n && !res;
       i++) {
    res = str1[i] - str2[i];
  }
  return res;
}

char *s21_strcpy(char *dest, const char *src) {
  char *p = dest;
  for (; (*dest = *src); src++, dest++)
    ;
  return p;
}

char *s21_strcat(char *dest, const char *src) {
  char *p = dest + s21_strlen(dest);
  for (; *src; p++, src++) *p = *src;
  *p = '\0';
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_memset(dest, '\0', n);
  int i = 0;
  for (i = 0; i < (int)n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *p = s21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      p = (char *)(str + i);
      break;
    }
  }
  return p;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag_main = 0, flag_sec = 0;
  char *p = s21_NULL;
  for (; *str1 != '\0' && !flag_main; str1++) {
    for (int i = 0; i < (int)s21_strlen(str2) && !flag_sec; i++) {
      if (*str1 == str2[i]) flag_sec++;
    }
    if (flag_sec) {
      p = (char *)str1;
      flag_main++;
    }
  }
  return p;
}

char *s21_strrchr(const char *str, int c) {
  char *p = s21_NULL;
  s21_size_t i = 0;
  for (; i < s21_strlen(str) + 1; i++) {
    if (str[i] == c) p = (char *)(str + i);
  }
  return p;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *p = s21_NULL;
  int range = s21_strlen(haystack) - s21_strlen(needle);
  if (range >= 0) {
    int flag = 1;
    for (int i = 0; i <= range; i++) {
      flag = 1;
      for (int j = i, k = 0; needle[k]; k++, j++) {
        if (haystack[j] != needle[k]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        p = (char *)haystack + i;
        break;
      }
    }
  }
  return p;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest;
  for (; *dest != '\0'; dest++, p++)
    ;
  for (int i = 0; *src != '\0' && i < (int)n; src++, p++, i++) *p = *src;
  *p = '\0';
  return p;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  const unsigned char *p1 = str1, *p2 = str2;
  for (s21_size_t i = 0; i < n && !res; i++) {
    res = p1[i] - p2[i];
  }
  return res;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int flag = 0;
  char *p = (char *)str, *res = s21_NULL;
  for (int i = 0; *p != '\0' && i < (int)n && !flag; i++, p++) {
    if (*p == c) {
      res = p;
      flag++;
    }
  }
  return (void *)res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *p1 = (char *)dest, *p2 = (char *)src;
  if (p1 == s21_NULL && p2 == s21_NULL)
    ;
  else
    for (int i = 0; i < (int)n; i++) *(p1 + i) = *(p2 + i);
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *p1 = (char *)dest, *p2 = (char *)src;
  char tmp[n];
  for (int i = 0; i < (int)n; i++) {
    *(tmp + i) = *(p2 + i);
    *(p1 + i) = *(tmp + i);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *p = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    p[i] = c;
  }
  return str;
}

void *s21_to_upper(const char *str) {
  char *p = s21_NULL;
  p = (char *)malloc(s21_strlen(str) + 1);
  if (str[0] != '\0') {
    if (p != s21_NULL) {
      int i = 0;
      for (i = 0; str[i] != '\0'; i++) {
        if (97 <= str[i] && str[i] <= 122)
          p[i] = str[i] - 32;
        else
          p[i] = str[i];
      }
      p[i] = '\0';
    }
  } else
    p[0] = '\0';
  return (void *)p;
}

void *s21_to_lower(const char *str) {
  char *p = s21_NULL;
  p = (char *)malloc(s21_strlen(str) + 1);
  if (str[0] != '\0') {
    if (p != s21_NULL) {
      int i = 0;
      for (i = 0; str[i] != '\0'; i++) {
        if (65 <= str[i] && str[i] <= 90)
          p[i] = str[i] + 32;
        else
          p[i] = str[i];
      }
      p[i] = '\0';
    }
  } else
    p[0] = '\0';
  return (void *)p;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t size = s21_strlen(str) + s21_strlen(src) + 1;
  char *ret = s21_NULL;
  if ((src != s21_NULL && str != s21_NULL) && start_index <= s21_strlen(src)) {
    ret = (char *)calloc(size, sizeof(char));
    if (ret != s21_NULL) {
      for (s21_size_t i = 0; i < start_index; i++) ret[i] = src[i];
      for (s21_size_t i = 0; i < s21_strlen(str); i++)
        ret[i + start_index] = str[i];
      for (s21_size_t i = 0; i < s21_strlen(src) - start_index; i++)
        ret[i + start_index + s21_strlen(str)] = src[i + start_index];
      ret[size - 1] = '\0';
    }
  }
  return ret;
}

s21_size_t s21_trim_strspn_reverse(const char *str1, const char *trim_chars) {
  int flag = 0, res = 0;
  for (int i = s21_strlen(str1) - 1; i > -1 && !flag; i--) {
    int inner_res = 0;
    for (s21_size_t j = 0; j < s21_strlen(trim_chars) && !inner_res; j++) {
      if (str1[i] == trim_chars[j]) inner_res++;
    }
    if (!inner_res) {
      flag++;
      res--;
    }
    res++;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *trimmed = s21_NULL;
  if (src != s21_NULL) {
    s21_size_t len = s21_strlen(src);
    if (trim_chars == s21_NULL) {
      trim_chars = " ";
    }
    s21_size_t start = s21_strspn(src, trim_chars);
    s21_size_t end = s21_trim_strspn_reverse(src, trim_chars);
    if (len != start) {
      trimmed = calloc(len - start - end + 1, sizeof(char));
    } else {
      trimmed = calloc(1, sizeof(char));
    }
    if (trimmed != s21_NULL) {
      if (len != start) {
        for (s21_size_t i = 0; i < len - start - end; i++) {
          trimmed[i] = src[i + start];
        }
        trimmed[len - start - end] = '\0';
      } else {
        trimmed[0] = '\0';
      }
    }
  }
  return trimmed;
}

char *s21_strerror(int errnum) {
  static char *error_list[] = ERRLIST;
  char *error_text = s21_NULL;
  static char unknown[42];

  if (errnum >= 0 && errnum < ERRLIST_LEN &&
      s21_strcmp(error_list[errnum], "(null)") != 0) {
    error_text = (char *)error_list[errnum];
  } else {
#if defined(__APPLE__)
    s21_strcpy(unknown, "Unknown error: ");
#elif defined(__linux__)
    s21_strcpy(unknown, "Unknown error ");
#endif
    char unknown_err_num[21];
    s21_int_to_str(errnum, unknown_err_num);
    s21_strcat(unknown, unknown_err_num);
    error_text = unknown;
  }
  return error_text;
}

void s21_int_to_str(int n, char *dest) {
  char *c = dest;
  int v = 0;
  int flag = 0;
  if (n < 0) {
    flag++;
    n = n * -1;
  }
  while (n > 9) {
    c[v++] = (n % 10) + '0';
    n = n / 10;
  }
  c[v++] = n + '0';
  if (flag) c[v++] = '-';
  c[v] = '\0';
  char t;
  for (int i = 0; i < v / 2; i++) {
    t = c[i];
    c[i] = c[v - 1 - i];
    c[v - 1 - i] = t;
  }
}

char *s21_strtok(char *str, const char *delim) {
  static char *tmp = s21_NULL;
  if (str != s21_NULL) tmp = str;
  if (tmp != s21_NULL) {
    str = tmp + s21_strspn(tmp, delim);
    tmp = str + s21_strcspn(str, delim);
    if (*tmp != '\0') {
      *tmp = '\0';
      ++tmp;
    }
  }
  return *str != '\0' ? str : s21_NULL;
}
