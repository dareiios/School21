#ifndef S21_STRING_H
#define S21_STRING_H

#include <float.h>
#include <inttypes.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>

#define s21_IS_SPEC(ch)                                                       \
  ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'f' || (ch) == 's' || \
   (ch) == 'u' || (ch) == '%' || (ch) == 'x' || (ch) == 'X' || (ch) == 'o' || \
   (ch) == 'p' || (ch) == 'n' || (ch) == 'e' || (ch) == 'E' || (ch) == 'g' || \
   (ch) == 'G')
#define s21_IS_LENGTH(ch) ((ch) == 'l' || (ch) == 'h' || (ch) == 'L')
#define s21_IS_NUMERIC(ch) (((ch) <= '9' && (ch) >= '0') || (ch) == '*')
#define s21_IS_FLAG(ch) \
  ((ch) == ' ' || (ch) == '+' || (ch) == '-' || (ch) == '#' || (ch) == '0')

#define s21_NULL ((void *)0)
#define s21_INF 1.0 / 0.0

typedef long unsigned int s21_size_t;
typedef struct {
  int spec;
  int length;
  int width;
  int star;
  int space;
  int minus;
  int plus;
  int sharp;
  int zero;
  int point;
  int precision;
  int double_len;
  int error;
  int wchar_error;
} FORMAT;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *array1, const void *array2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strcpy(char *dest, const char *src);
char *s21_strtok(char *str, const char *delim);
char *s21_strstr(const char *haystack, const char *needle);
s21_size_t s21_strcspn(const char *str1, const char *str2);
int check_edges(const char *src, const char *totrim, int edge);

int s21_sprintf(char *str, const char *format, ...);
void s21_char_to_int(int *num, char ch);
int s21_parser(int ptr_f, const char *format, FORMAT *s_format);
void s21_set_zeroes(FORMAT *s_format);
void s21_format_string(FORMAT *s_format, va_list arg_list, char *str);
int s21_is_negative(long double *num);
char *s21_int_format(FORMAT s_format, va_list arg_list);
void s21_u_format(FORMAT s_format, va_list arg_list, char *buf);
void s21_f_format(FORMAT s_format, va_list arg_list, char *buf);
void s21_f_to_str(long double num, FORMAT s_format, char *buf);
void s21_precision_int(FORMAT s_format, char *buf, int *i);
void s21_width_int(FORMAT s_format, char *buf, int is_negative);
void s21_percent_format(FORMAT s_format, char *buf);
void s21_negative(int is_negative, FORMAT s_format, char *buf);
void s21_int_to_string(char *buf, FORMAT s_format, long long int num);
void s21_d_format(FORMAT s_format, va_list arg_list, char *str);
void s21_c_format(va_list arg_list, FORMAT *s_format, char *buf);
void s21_s_format(FORMAT *s_format, va_list arg_list, char *buf);
void s21_reset_format(FORMAT *s_format);
void s21_int_to_char(FORMAT s_format, unsigned long long int num, char *buf,
                     int *i);
void s21_reverse_string(char *str, int i);
void s21_check_star(FORMAT *s_format, int *pres_or_width, int *num, char f_ch);
void s21_star_into_num(FORMAT *s_format, int *pres_or_width, va_list arg_list);

int s21_sscanf(const char *str, const char *format, ...);
void get_string(char **src, char *dest, int length);
void get_char(char **src, int *c, int length);
char *get_int(char *src, long *num, int length);
void custom_atoi(char **src, long *num, int length);
int get_character_index(char *src, char c);
void get_double(char **src, float *num);
void get_octa(char **src, unsigned long *num, int length);
void get_hexa(char **src, unsigned long *num, int length);
void skip_spaces(char **str);
void double_to_float(char **src, double *num);
void string_to_wchar(char **src, wchar_t *str, int length);
void get_ptr(char **src, void **ptr, int length);
void get_float(char **src, double *num, int length);

#endif  // SRC_S21_STRING_H_
