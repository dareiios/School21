#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

typedef struct test_s {
  uint32_t origO1, mineO1;
  char origC1, mineC1;
  void *origP1;
  void *mineP1;
  int origRes, mineRes;
  int origD1, mineD1;
  int origD2, mineD2;
  short int origSD1, mineSD1;
  long int origLD1, mineLD1;
  long int origLD2, mineLD2;
  float origF1, mineF1;
  float origF2, mineF2;
  float origF3, mineF3;
  float origF4, mineF4;
  float origF5, mineF5;
  long long int origLLD1, mineLLD1;
  char origS1[100], mineS1[100];
  char origC2, mineC2;
  wchar_t origWC1[10], mineWC1[10];
  unsigned int origU1, mineU1;
  unsigned int origU2, mineU2;
  unsigned long int origUL1, mineUL1;
  unsigned long long int origULL1, mineULL1;
  signed char origSC1, mineSC1;
  long double origLF1, mineLF1;
  long double origLF2, mineLF2;
  long double origLF3, mineLF3;
  long double origLF4, mineLF4;
  long double origLF5, mineLF5;
} test;

char string1[15] = "hello world\0";
char string2[15] = "1234567890";
char string3[0];
char cmp_str1[15] = "HELLO WORLD\0";
char cmp_str2[15] = "0987654321";
char cmp_str3[0];

#define size 512
char str_1[size] = {'\0'}, str_2[size] = {'\0'};
int int_test1 = 0, int_test2 = 0;

int n = 2100, n1 = 0, n2 = -21;
long int lg = 12345678912345, lg1 = -12345678912345;
short sh = 123, sh1 = -123;

void free_two(char *arr_1, char *arr_2) {
  int len_1 = strlen(arr_1);
  int len_2 = strlen(arr_2);

  if (len_1 < len_2) len_1 = len_2;

  for (int i = 0; i < len_1; i++) {
    arr_1[i] = '\0';
    arr_2[i] = '\0';
  }
}

char char_test1 = 'T', char_test2 = 'Z';

START_TEST(s21_memchr_test) {
  ck_assert_ptr_eq(s21_memchr(string1, 'o', 10), memchr(string1, 'o', 10));
  ck_assert_ptr_eq(s21_memchr(string2, '7', 10), memchr(string2, '7', 10));
  ck_assert_ptr_eq(s21_memchr(string3, '7', 10), memchr(string3, '7', 10));
}
END_TEST

START_TEST(s21_memcmp_test) {
  ck_assert_int_eq(s21_memcmp(string1, cmp_str1, 1),
                   memcmp(string1, cmp_str1, 1));
  ck_assert_int_eq(s21_memcmp(string2, cmp_str2, 10),
                   memcmp(string2, cmp_str2, 10));
  ck_assert_int_eq(s21_memcmp(string3, cmp_str3, 0),
                   memcmp(string3, cmp_str3, 0));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char dest1[100] = "Test_1_memcpy ";
  char dest2[100] = "Test_1_memcpy ";
  s21_memcpy(dest1, string1, 11);
  memcpy(dest2, string1, 11);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_memcpy ";
  char dest4[100] = "Test_2_memcpy ";
  s21_memcpy(dest3, string2, 10);
  memcpy(dest4, string2, 10);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_memcpy ";
  char dest6[100] = "Test_3_memcpy ";
  char string1_1[10] = "\0";
  s21_memcpy(dest5, string1_1, 2);
  memcpy(dest6, string1_1, 2);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_memmove_test) {
  char dest1[100] = "Test_1_memmove ";
  char dest2[100] = "Test_1_memmove ";

  s21_memmove(dest1, string1, 11);
  memmove(dest2, string1, 11);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_memmove ";
  char dest4[100] = "Test_2_memmove ";
  s21_memmove(dest3, string2, 10);
  memmove(dest4, string2, 10);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_memmove ";
  char dest6[100] = "Test_3_memmove ";
  s21_memmove(dest5, string3, 0);
  memmove(dest6, string3, 0);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_memset_test) {
  ck_assert_str_eq(s21_memset(string1, 'H', 10), memset(string1, 'H', 10));
  ck_assert_str_eq(s21_memset(string2, '7', 10), memset(string2, '7', 10));
  ck_assert_str_eq(s21_memset(cmp_str2, '0', 10), memset(cmp_str2, '0', 10));
}
END_TEST

START_TEST(s21_strcat_test) {
  char dest1[100] = "Test_1_strcat ";
  char dest2[100] = "Test_1_strcat ";

  s21_strcat(dest1, string1);
  strcat(dest2, string1);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_strcat ";
  char dest4[100] = "Test_2_strcat ";
  s21_strcat(dest3, string2);
  strcat(dest4, string2);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_strcat ";
  char dest6[100] = "Test_3_strcat ";
  s21_strcat(dest5, string3);
  strcat(dest6, string3);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_strncat_test) {
  char dest1[100] = "Test_1_strncat ";
  char dest2[100] = "Test_1_strncat ";

  s21_strncat(dest1, string1, 5);
  strncat(dest2, string1, 5);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_strncat ";
  char dest4[100] = "Test_2_strncat ";
  s21_strncat(dest3, string2, 5);
  strncat(dest4, string2, 5);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_strncat ";
  char dest6[100] = "Test_3_strncat ";
  s21_strncat(dest5, string3, 0);
  strncat(dest6, string3, 0);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_strchr_test) {
  ck_assert_msg(s21_strchr(string1, 'w') == strchr(string1, 'w'),
                "s21_strchr 1");
  ck_assert_msg(s21_strchr(string2, '7') == strchr(string2, '7'),
                "s21_strchr 2");
}
END_TEST

START_TEST(s21_strcmp_test) {
  ck_assert_int_eq(s21_strcmp(string1, cmp_str1), strcmp(string1, cmp_str1));
  ck_assert_int_eq(s21_strcmp(string2, cmp_str2), strcmp(string2, cmp_str2));
  ck_assert_int_eq(s21_strcmp(string3, cmp_str3), strcmp(string3, cmp_str3));
  char *str1 = " ";
  char *str2 = "-";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strncmp_test) {
  ck_assert_int_eq(s21_strncmp(string1, cmp_str1, 6),
                   strncmp(string1, cmp_str1, 6));
  ck_assert_int_eq(s21_strncmp(string2, cmp_str2, 10),
                   strncmp(string2, cmp_str2, 10));
  ck_assert_int_eq(s21_strncmp(string3, cmp_str3, 0),
                   strncmp(string3, cmp_str3, 0));
  char toCompare[20] = "Hell0 man";
  char test1_1[20] = "Hell0 world\0";
  char test2_2[20] = "Hell0 world\n\0";
  ck_assert_int_eq(s21_strncmp(test1_1, toCompare, 6),
                   strncmp(test1_1, toCompare, 6));
  ck_assert_int_eq(s21_strncmp(test2_2, toCompare, 6),
                   strncmp(test2_2, toCompare, 6));
}
END_TEST

START_TEST(s21_strcpy_test) {
  char dest1[100] = "Test_1_strcpy ";
  char dest2[100] = "Test_1_strcpy ";
  s21_strcpy(dest1, string1);
  strcpy(dest2, string1);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_strcpy ";
  char dest4[100] = "Test_2_strcpy ";
  s21_strcpy(dest3, string2);
  strcpy(dest4, string2);
  ck_assert_str_eq(dest3, dest4);

  char dest5[100] = "Test_3_strcpy ";
  char dest6[100] = "Test_3_strcpy ";
  s21_strcpy(dest5, string3);
  strcpy(dest6, string3);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(s21_strncpy_test) {
  char dest1[100] = "Test_1_strncpy ";
  char dest2[100] = "Test_1_strncpy ";

  s21_strncpy(dest1, string1, 7);
  strncpy(dest2, string1, 7);
  ck_assert_str_eq(dest1, dest2);

  char dest3[100] = "Test_2_strncpy ";
  char dest4[100] = "Test_2_strncpy ";
  s21_strncpy(dest3, string2, 5);
  strncpy(dest4, string2, 5);
  ck_assert_str_eq(dest3, dest4);
}
END_TEST

START_TEST(s21_strcspn_test) {
  char string_cmp1[10] = "Hello";
  char string_cmp2[4] = "1234";
  ck_assert_int_eq(s21_strcspn(string1, string_cmp1),
                   strcspn(string1, string_cmp1));
  ck_assert_int_eq(s21_strcspn(string2, string_cmp2),
                   strcspn(string2, string_cmp2));
  ck_assert_int_eq(s21_strcspn(string3, cmp_str3), strcspn(string3, cmp_str3));
}
END_TEST

START_TEST(s21_strerror_test) {
  for (int index = 0; index <= 133; index++) {
    char *tester = s21_strerror(index);
    ck_assert_str_eq(tester, strerror(index));
    // free(tester);
  }
}
END_TEST

START_TEST(s21_strlen_test) {
  ck_assert_int_eq(s21_strlen(string1), strlen(string1));
  ck_assert_int_eq(s21_strlen(string2), strlen(string2));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char *str = "This is the road to hell";
  char *empty = "";
  char *empty2 = "T";
  char *empty3 = "l";

  ck_assert(s21_strpbrk(str, empty) == s21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty2),
                    (unsigned long)strpbrk(str, empty2));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty3),
                    (unsigned long)strpbrk(str, empty3));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char str_strrchr[15] = "123123123";
  ck_assert_msg(s21_strrchr(string1, 'l') == strrchr(string1, 'l'),
                "s21_strrchr 1");
  ck_assert_msg(s21_strrchr(str_strrchr, '2') == strrchr(str_strrchr, '2'),
                "s21_strrchr 2");
}
END_TEST

START_TEST(s21_strspn_test) {
  char str_strspn1[10] = "elloH";
  char str_strspn2[10] = "210";
  ck_assert_int_eq(s21_strspn(string1, str_strspn1),
                   strspn(string1, str_strspn1));
  ck_assert_int_eq(s21_strspn(string2, str_strspn2),
                   strspn(string2, str_strspn2));
}
END_TEST

START_TEST(s21_strstr_test) {
  char str1[4] = "ell";
  char str2[4] = "345";
  char *result, *result2;

  result = s21_strstr(string1, str1);
  result2 = strstr(string1, str1);
  ck_assert_msg(result == result2, "s21_strstr 1");

  result = s21_strstr(string2, str2);
  result2 = strstr(string2, str2);
  ck_assert_msg(result == result2, "s21_strstr 2");
}
END_TEST

START_TEST(s21_strtok_test) {
  char str1_1[100] = "test1/test2/test3/test4";
  char str1[100] = "test1/test2/test3/test4";
  char delim1[4] = "/";
  char *result, *result2;

  result = s21_strtok(str1_1, delim1);
  result2 = strtok(str1, delim1);
  ck_assert_str_eq(result, result2);
  ck_assert_str_eq(s21_strtok(NULL, delim1), strtok(NULL, delim1));
  ck_assert_str_eq(s21_strtok(NULL, delim1), strtok(NULL, delim1));
  // ck_assert_str_eq(s21_strtok(NULL, delim1), strtok(NULL, delim1));

  char str2_1[100] = "Moscow - Kazan - Arsk - Samara - Ufa";
  char str2[100] = "Moscow - Kazan - Arsk - Samara - Ufa";
  char delim2[10] = " - ";
  char *result3, *result4;

  result3 = s21_strtok(str2_1, delim2);
  result4 = strtok(str2, delim2);
  ck_assert_str_eq(result3, result4);
  ck_assert_str_eq(s21_strtok(s21_NULL, delim2), strtok(NULL, delim2));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim2), strtok(NULL, delim2));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim2), strtok(NULL, delim2));

  char str3_1[100] = "Moscow - Kazan - Arsk - Samara - Ufa";
  char str3[100] = "Moscow - Kazan - Arsk - Samara - Ufa";
  char delim3[10] = " ";
  char *result5, *result6;

  result5 = s21_strtok(str3_1, delim3);
  result6 = strtok(str3, delim3);
  ck_assert_str_eq(result5, result6);
  ck_assert_str_eq(s21_strtok(s21_NULL, delim3), strtok(NULL, delim3));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim3), strtok(NULL, delim3));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim3), strtok(NULL, delim3));
  // char dest[] = "Hell0 world\0";
  // char orig[] = "Hell0 world\0";
  // ck_assert_str_eq(s21_strtok(dest, " "), strtok(orig, " "));
  // char dest2[] = "Hell0 world\n\0";
  // char orig2[] = "Hell0 world\n\0";
  // ck_assert_str_eq(s21_strtok(dest2, " "), strtok(orig2, " "));
  // // char dest3[] = "a\n\0";
  // // char orig3[] = "a\n\0";
  // // ck_assert_str_eq(s21_strtok(dest3, " "), strtok(orig3, " "));
  // char dest4[] = " s\0";
  // char orig4[] = " s\0";
  // ck_assert_str_eq(s21_strtok(dest4, " "), strtok(orig4, " "));
  // char dest5[] = " \0";
  // char orig5[] = " \0";
  // ck_assert_ptr_eq(s21_strtok(dest5, " "), strtok(orig5, " "));
  // char dest6[] = "\n\0";
  // char orig6[] = "\n\0";
  // ck_assert_str_eq(s21_strtok(dest6, " "), strtok(orig6, " "));
  // char dest7[] = "\0";
  // char orig7[] = "\0";
  // ck_assert_ptr_eq(s21_strtok(dest7, " "), strtok(orig7, " "));
  // char dest8[] = "test1/test2/test3/test4";
  // char orig8[] = "test1/test2/test3/test4";
  // ck_assert_str_eq(s21_strtok(dest8, "/"), strtok(orig8, "/"));
  // ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  // ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  // ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  // ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  // char dest9[] = "test1/test2/test3///";
  // char orig9[] = "test1/test2/test3///";
  // ck_assert_str_eq(s21_strtok(dest9, "/"), strtok(orig9, "/"));
  // ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  // ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  // ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  // char dest10[] = "///test1///test2/test3/";
  // char orig10[] = "///test1///test2/test3/";
  // ck_assert_str_eq(s21_strtok(dest10, "/"), strtok(orig10, "/"));
  // ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  // ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  // ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
}
END_TEST

START_TEST(s21_to_upper_test) {
  char *temp;

  temp = s21_to_upper("test");
  ck_assert_str_eq(temp, "TEST");
  free(temp);

  temp = s21_to_upper("777test777");
  ck_assert_str_eq(temp, "777TEST777");
  free(temp);

  temp = s21_to_upper("!@#$");
  ck_assert_str_eq(temp, "!@#$");
  free(temp);

  temp = s21_to_upper(" ");
  ck_assert_str_eq(temp, " ");
  free(temp);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char *temp = s21_to_lower(cmp_str1);
  ck_assert_str_eq(temp, "hello world\0");
  free(temp);

  temp = s21_to_lower("TEST");
  ck_assert_str_eq(temp, "test");
  free(temp);

  temp = s21_to_lower("777TEST777");
  ck_assert_str_eq(temp, "777test777");
  free(temp);

  temp = s21_to_lower("!@#$");
  ck_assert_str_eq(temp, "!@#$");
  free(temp);
  temp = s21_to_lower(" ");
  ck_assert_str_eq(temp, " ");
  free(temp);
}
END_TEST

START_TEST(s21_insert_test) {
  char *src = "Regular!";
  char *str = ", brainfucker";
  char *new_str = {0};
  new_str = s21_insert(src, str, 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brainfucker!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 9);
  ck_assert(new_str == s21_NULL);
  free(new_str);

  new_str = s21_insert("Regular!", ", brainfucker!!", 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brainfucker!!!");
    free(new_str);
  }

  new_str = s21_insert("Regular!", ", brainfucker!!", 35);
  ck_assert(new_str == s21_NULL);
  free(new_str);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }

  char *src1 = "1";
  char *str1 = "1";
  char *new_str2 = s21_insert(src1, str1, 1);
  if (new_str2) {
    ck_assert_str_eq(new_str2, "11");
    free(new_str2);
  }

  // char src1[50] = "Hello";
  // char str1[50] = ", team!";
  // ck_assert_str_eq(s21_insert(src1, str1, 5), "Hello, team!");

  // char src2[50] = "team!";
  // char str2[50] = "Dream";
  // char *temp = s21_insert(src2, str2, 0);
  // ck_assert_str_eq(temp, "Dreamteam!");
  // free(temp);

  // char src3[50] = "VR";
  // char str3[50] = "erte";
  // temp = s21_insert(src3, str3, 1);
  // ck_assert_str_eq(temp, "VerteR");
  // free(temp);

  // char src4[50] = "";
  // char str4[50] = " ";
  // temp = s21_insert(src4, str4, 0);
  // ck_assert_str_eq(temp, " ");
  // free(temp);
}
END_TEST

START_TEST(s21_trim_test) {
  char src1[50] = "***Hello***";
  char trim_chars1[50] = "*";
  char *temp = s21_trim(src1, trim_chars1);
  ck_assert_str_eq(temp, "Hello");
  free(temp);

  // char src2[50] = " Dreamteam! ";
  // char trim_chars2[50] = " ";
  // temp = s21_trim(src2, trim_chars2);
  // ck_assert_str_eq(temp, "Dreamteam!");
  // free(temp);

  char src3[50] = "DELETEtestDELETE";
  char trim_chars3[50] = "DELETE";
  temp = s21_trim(src3, trim_chars3);
  ck_assert_str_eq(temp, "test");
  free(temp);
}
END_TEST

// START_TEST(s21_sprintf_test) {
// char c[255] = {}, d[255] = {}, x1 = 't';
// int n = 2100, n1 = 0, n2 = -21;
// short sh = 123, sh1 = -123;
// float f = 21.21, f1 = -21.21;
// long int lg = 12345678912345, lg1 = -12345678912345;
// s21_sprintf(c, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg,
// lg1,
//             lg1);
// sprintf(d, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
//         lg1);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n,
// 212121,
//             2121, n2, n, 21, 55, -55);
// sprintf(d, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n, 212121,
//         2121, n2, n, 21, 55, -55);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
// sprintf(d, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
// ck_assert_str_eq(c, d);
// s21_sprintf(c,
//             "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d
//             %.0d", 10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
// sprintf(d, "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d
// %.0d",
//         10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX,
// SHRT_MIN,
//             USHRT_MAX, LONG_MAX, LONG_MIN);
// sprintf(d, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX, SHRT_MIN,
//         USHRT_MAX, LONG_MAX, LONG_MIN);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%c %10c %-10c", '!', 'a', 'b');
// sprintf(d, "%c %10c %-10c", '!', 'a', 'b');
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
// sprintf(d, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello",
// "hello",
//             "hello", "hello", "hello", "hello");
// sprintf(d, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
//         "hello", "hello", "hello", "hello");
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello",
// L"hello",
//             L"hello", L"hello", L"hello", L"hello", L"hello");
// sprintf(d, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
//         L"hello", L"hello", L"hello", L"hello", L"hello");
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%u %lu", UINT_MAX, ULONG_MAX);
// sprintf(d, "%u %lu", UINT_MAX, ULONG_MAX);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "hello %n", &n);
// sprintf(d, "hello %n", &n1);
// ck_assert_msg(c, d, "error");
// s21_sprintf(c, "%-10o %lo %lo %o %o %o %10o %#10o %0#10o", 21, lg, lg1, n,
// 0,
//             n2, 0, 21, 42);
// sprintf(d, "%-10o %lo %lo %o %o %o %10o %#10o %0#10o", 21, lg, lg1, n, 0,
// n2,
//         0, 21, 42);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%#o %#o %#10o %0#10o %.10o %.0o %#5.10o", n, n2, 0, 0, n,
// 0,
//             123);
// sprintf(d, "%#o %#o %#10o %0#10o %.10o %.0o %#5.10o", n, n2, 0, 0, n, 0,
// 123); ck_assert_str_eq(c, d); s21_sprintf(c, "%x %x %x %10x %-10x %.10x
// %.0x %#5.10x", n, n1, n2, 0, 21, n,
//             0, 123);
// sprintf(d, "%x %x %x %10x %-10x %.10x %.0x %#5.10x", n, n1, n2, 0, 21, n,
// 0,
//         123);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
// n,
//             n2, 21, 0, 42, 21, 0, -65, lg, lg1);
// sprintf(d, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx", n,
// n2,
//         21, 0, 42, 21, 0, -65, lg, lg1);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
// sprintf(d, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42,
// 0,
//             4221, n1);
// sprintf(d, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42, 0,
// 4221,
//         n1);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f, f1,
//             21.21, -21.21, 42.42, -42.42, f, f1);
// sprintf(d, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f,
// f1, 21.21,
//         -21.21, 42.42, -42.42, f, f1);
// ck_assert_str_eq(c, d);
// s21_sprintf(c, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
//             21.21, 0.0, 21.21, 21., 0.0, 21.21);
// sprintf(d, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f,
// f1, 21., 21.21,
//         0.0, 21.21, 21., 0.0, 21.21);
// ck_assert_str_eq(c, d);
// ck_assert_int_eq(
//     s21_sprintf(c, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f,
//     f1, 21.,
//                 21.21, 0.0, 21.21, 21., 0.0, 21.21),
//     sprintf(d, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
//             21.21, 0.0, 21.21, 21., 0.0, 21.21));
// ck_assert_int_eq(
//     s21_sprintf(c, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx
//     %lx",
//                 n, n2, 21, 0, 42, 21, 0, -65, lg, lg1),
//     sprintf(d, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
//     n,
//             n2, 21, 0, 42, 21, 0, -65, lg, lg1));
// }

START_TEST(Sprintf_Test_s) {
  s21_sprintf(str_1, "%s", "Hello");
  sprintf(str_2, "%s", "Hello");
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%.1s", "Hello");
  sprintf(str_2, "%.1s", "Hello");
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%7s", "Hello");
  sprintf(str_2, "%7s", "Hello");
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-10s", "Hello");
  sprintf(str_2, "%-10s", "Hello");
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "qwerty %s qwe", "qwerty");
  sprintf(str_2, "qwerty %s qwe", "qwerty");
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%s", "");
  int_test2 = sprintf(str_2, "%s", "");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%23s", "aboba");
  int_test2 = sprintf(str_2, "%23s", "aboba");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-15s", "helloworld");
  int_test2 = sprintf(str_2, "%-15s", "helloworld");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%10.s", "ABOBA");
  int_test2 = sprintf(str_2, "%10.s", "ABOBA");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%15.2s", "ABOBBAAA");
  int_test2 = sprintf(str_2, "%15.2s", "ABOBBAAA");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%16.*s", 10, "QWERTY");
  int_test2 = sprintf(str_2, "%16.*s", 10, "QWERTY");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%*.*s", 15, 4, "AAAAABOOOOOBAAA");
  int_test2 = sprintf(str_2, "%*.*s", 15, 4, "AAAAABOOOOOBAAA");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%*s", 10, "ABOBAAAAA");
  int_test2 = sprintf(str_2, "%*s", 10, "ABOBAAAAA");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%s %10s", "hello", "hello");
  int_test2 = sprintf(str_2, "%s %10s", "hello", "hello");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%.s %.3s %.10s", "hello", "hello", "hello");
  int_test2 = sprintf(str_2, "%.s %.3s %.10s", "hello", "hello", "hello");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-10s %-3s", "hello", "hello");
  int_test2 = sprintf(str_2, "%-10s %-3s", "hello", "hello");
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);
}
END_TEST

START_TEST(Sprintf_Test_c) {
  s21_sprintf(str_1, "%10c", 'a');
  sprintf(str_2, "%10c", 'a');
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-10c", 'e');
  sprintf(str_2, "%-10c", 'e');
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%25c", 'f');
  sprintf(str_2, "%25c", 'f');
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-30c", 'R');
  sprintf(str_2, "%-30c", 'R');
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%25c", 'Q');
  sprintf(str_2, "%25c", 'Q');
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%*c", 10, 'P');
  sprintf(str_2, "%*c", 10, 'P');
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%2c", 'L');
  sprintf(str_2, "%2c", 'L');
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%*c", 20, 'x');
  sprintf(str_2, "%*c", 20, 'x');
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%lc", char_test1);
  sprintf(str_2, "%lc", char_test1);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%c", CHAR_MAX);
  sprintf(str_2, "%c", CHAR_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%c", CHAR_MIN);
  sprintf(str_2, "%c", CHAR_MIN);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%c", UCHAR_MAX);
  sprintf(str_2, "%c", UCHAR_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  sprintf(str_2, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-50lc", char_test2);
  sprintf(str_2, "%-50lc", char_test2);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a', 'e', 'f',
              'R', 'Q', 10, 'P', 'L', 20, 'x', char_test1, char_test2);
  sprintf(str_2, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a', 'e', 'f', 'R',
          'Q', 10, 'P', 'L', 20, 'x', char_test1, char_test2);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(
      str_1, "%10c%-10cdsad%25c%-30c  %25c%*c%2c%*csadasaaaWWW%lc%-50lc", 'a',
      'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', char_test1, char_test2);
  sprintf(str_2, "%10c%-10cdsad%25c%-30c  %25c%*c%2c%*csadasaaaWWW%lc%-50lc",
          'a', 'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', char_test1,
          char_test2);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%c", '!');
  sprintf(str_2, "%c", '!');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%10c", 'a');
  sprintf(str_2, "%10c", 'a');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-10c", 'b');
  sprintf(str_2, "%-10c", 'b');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%c %10c %-10c", '!', 'a', 'b');
  sprintf(str_2, "%c %10c %-10c", '!', 'a', 'b');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%1c %c", 'H', 'z');
  sprintf(str_2, "%1c %c", 'H', 'z');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%10c %2c", 'H', 'z');
  sprintf(str_2, "%10c %2c", 'H', 'z');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-1c %-c", 'H', 'z');
  sprintf(str_2, "%-1c %-c", 'H', 'z');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %3c abc", '*');
  sprintf(str_2, "abc %3c abc", '*');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %-3c abc", '*');
  sprintf(str_2, "abc %-3c abc", '*');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "qwerty %c %-5c %15c", '$', '/', '!');
  sprintf(str_2, "qwerty %c %-5c %15c", '$', '/', '!');
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);
}
END_TEST

START_TEST(Sprintf_Test_f) {
  s21_sprintf(str_1, "abc %+.4f abc", 166.087);
  sprintf(str_2, "abc %+.4f abc", 166.087);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %-12.3f abc", 166.87);
  sprintf(str_2, "abc %-12.3f abc", 166.87);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %f abc", -166.87);
  sprintf(str_2, "abc %f abc", -166.87);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%f", 100000.4);
  sprintf(str_2, "%f", 100000.4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%0f", 100000.4);
  sprintf(str_2, "%0f", 100000.4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%f", -100000.4);
  sprintf(str_2, "%f", -100000.4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%+f %+f", -100000.4, 1000.231);
  sprintf(str_2, "%+f %+f", -100000.4, 1000.231);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-20f", 100000.4);
  sprintf(str_2, "%-20f", 100000.4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %Lf", (long double)58787.878958);
  sprintf(str_2, "abc %Lf", (long double)58787.878958);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %.lf", 58787.878958);
  sprintf(str_2, "abc %.lf", 58787.878958);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %.10f", 587.00089);
  sprintf(str_2, "abc %.10f", 587.00089);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-+20f", 100000.4);
  sprintf(str_2, "%-+20f", 100000.4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-20f", -100000.4);
  sprintf(str_2, "%-20f", -100000.4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%+20f", 100000.4);
  sprintf(str_2, "%+20f", 100000.4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%+20f", -100000.4);
  sprintf(str_2, "%+20f", -100000.4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  float key = 10000;
  s21_sprintf(str_1, "%+20f", key);
  sprintf(str_2, "%+20f", key);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%+-10.5f", 2546.4324);
  int_test2 = sprintf(str_2, "%+-10.5f", 2546.4324);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%+10.2f", 3452.4325);
  int_test2 = sprintf(str_2, "%+10.2f", 3452.4325);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%15.15f", 5678.43256);
  int_test2 = sprintf(str_2, "%15.15f", 5678.43256);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%+*.10f", 25, 456789.243242);
  int_test2 = sprintf(str_2, "%+*.10f", 25, 456789.243242);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%*.15f", 10, 3456789123.43245);
  int_test2 = sprintf(str_2, "%*.15f", 10, 3456789123.43245);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-10.*f", 2, 12345.6788);
  int_test2 = sprintf(str_2, "%-10.*f", 2, 12345.6788);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%25.*f", 1, 34.4325432);
  int_test2 = sprintf(str_2, "%25.*f", 1, 34.4325432);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%25.f", 4325678.43242);
  int_test2 = sprintf(str_2, "%25.f", 4325678.43242);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%#+10.f", 34567.2345432);
  int_test2 = sprintf(str_2, "%#+10.f", 34567.2345432);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%*.*f", 10, 2, 34567.43244);
  int_test2 = sprintf(str_2, "%*.*f", 10, 2, 34567.43244);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%f", (double)UINT_MAX);
  int_test2 = sprintf(str_2, "%f", (double)UINT_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%f", (double)INT_MAX);
  int_test2 = sprintf(str_2, "%f", (double)INT_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%f", (double)INT_MIN);
  int_test2 = sprintf(str_2, "%f", (double)INT_MIN);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%f", (double)SHRT_MAX);
  int_test2 = sprintf(str_2, "%f", (double)SHRT_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%f", (double)SHRT_MIN);
  int_test2 = sprintf(str_2, "%f", (double)SHRT_MIN);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%f", (double)LONG_MIN);
  int_test2 = sprintf(str_2, "%f", (double)LONG_MIN);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%f", (double)USHRT_MAX);
  int_test2 = sprintf(str_2, "%f", (double)USHRT_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%f", (double)LONG_MAX);
  int_test2 = sprintf(str_2, "%f", (double)LONG_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(
      str_1,
      "%+-10.5f%+10.2f%15.15f%+*.10f%*.15f%-10.*f%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  int_test2 = sprintf(
      str_2,
      "%+-10.5f%+10.2f%15.15f%+*.10f%*.15f%-10.*f%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(
      str_1,
      "%+-10.5f  "
      "%+10.2f%15.16dasdf%+*.10f%*.16f%-10.*fdsad%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 567843256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  int_test2 = sprintf(
      str_2,
      "%+-10.5f  "
      "%+10.2f%15.16dasdf%+*.10f%*.16f%-10.*fdsad%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 567843256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);
}
END_TEST

START_TEST(Sprintf_Test_d) {
  s21_sprintf(str_1, "%-10d", 21);
  sprintf(str_2, "%-10d", 21);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%010d %010d", -21, 2100);
  sprintf(str_2, "%010d %010d", -21, 2100);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%*d %2d", -5, n2, n);
  sprintf(str_2, "%*d %2d", -5, n2, n);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %d abc", -166);
  sprintf(str_2, "abc %d abc", -166);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%d%%\n", 4);
  sprintf(str_2, "%d%%\n", 4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%.10d%%\n", 4);
  sprintf(str_2, "%.10d%%\n", 4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %010d", 50);
  sprintf(str_2, "abc %010d", 50);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%0d%%\n", -4);
  sprintf(str_2, "%0d%%\n", -4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-+10d%%\n", 4);
  sprintf(str_2, "%-+10d%%\n", 4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-10d%%\n", -4);
  sprintf(str_2, "%-10d%%\n", -4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%+10d%%\n", 4);
  sprintf(str_2, "%+10d%%\n", 4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%.2d", 4);
  sprintf(str_2, "%.2d", 4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%+10d%%\n", -4);
  sprintf(str_2, "%+10d%%\n", -4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%.*d %3.10d %.d", 10, n, n2, 42);
  int_test2 = sprintf(str_2, "%.*d %3.10d %.d", 10, n, n2, 42);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-+.5d %-+10.5d", 21, 10);
  int_test2 = sprintf(str_2, "%-+.5d %-+10.5d", 21, 10);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%+010d %+-10d", n2, n);
  int_test2 = sprintf(str_2, "%+010d %+-10d", n2, n);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "% -10d %-10d %-10d", 21, 55, -55);
  int_test2 = sprintf(str_2, "% -10d %-10d %-10d", 21, 55, -55);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%.10d %.10d", n, n2);
  int_test2 = sprintf(str_2, "%.10d %.10d", n, n2);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 =
      s21_sprintf(str_1, "%2.2d %.d % d %.0d", -21, char_test1, 21, -42);
  int_test2 = sprintf(str_2, "%2.2d %.d % d %.0d", -21, char_test1, 21, -42);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%hd %hd", sh, sh1);
  int_test2 = sprintf(str_2, "%hd %hd", sh, sh1);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%ld %ld", lg, lg1);
  int_test2 = sprintf(str_2, "%ld %ld", lg, lg1);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%10ld", lg1);
  int_test2 = sprintf(str_2, "%10ld", lg1);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%+10.5d%%\n", -4);
  sprintf(str_2, "%+10.5d%%\n", -4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  long int var_long = 100;
  s21_sprintf(str_1, "%ld%%\n", var_long);
  sprintf(str_2, "%ld%%\n", var_long);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  short var_short = 123;
  s21_sprintf(str_1, "%hd%%\n", var_short);
  sprintf(str_2, "%hd%%\n", var_short);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %ld", 58787878958);
  sprintf(str_2, "abc %ld", 58787878958);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %d", 87878958);
  sprintf(str_2, "abc %d", 87878958);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %hd", 87878958);
  sprintf(str_2, "abc %hd", (short)87878958);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %*d", 5, 4);
  sprintf(str_2, "abc %*d", 5, 4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%d%d", INT_MIN, INT_MAX);
  int_test2 = sprintf(str_2, "%d%d", INT_MIN, INT_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%d%d", SHRT_MAX, SHRT_MIN);
  int_test2 = sprintf(str_2, "%d%d", SHRT_MAX, SHRT_MIN);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%d %d", SHRT_MIN, USHRT_MAX);
  int_test2 = sprintf(str_2, "%d %d", SHRT_MIN, USHRT_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%ld", LONG_MAX);
  int_test2 = sprintf(str_2, "%ld", LONG_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%ld", LONG_MIN);
  int_test2 = sprintf(str_2, "%ld", LONG_MIN);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%ld", -9223372036854775807 - 1);
  int_test2 = sprintf(str_2, "%ld", -9223372036854775807 - 1);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-25.10d", 253);
  int_test2 = sprintf(str_2, "%-25.10d", 253);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-30.2d", 335);
  int_test2 = sprintf(str_2, "%-30.2d", 335);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%10.12d", 1234);
  int_test2 = sprintf(str_2, "%10.12d", 1234);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%11d", 34);
  int_test2 = sprintf(str_2, "%11d", 34);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%*d", 10, 25);
  int_test2 = sprintf(str_2, "%*d", 10, 25);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%*.*d", 5, 15, 345);
  int_test2 = sprintf(str_2, "%*.*d", 5, 15, 345);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%+-25.*d", 5, 15);
  int_test2 = sprintf(str_2, "%+-25.*d", 5, 15);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%+-25.*d", 45, 5);
  int_test2 = sprintf(str_2, "%+-25.*d", 45, 5);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%+10.2ld", 456789l);
  int_test2 = sprintf(str_2, "%+10.2ld", 456789l);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-11.*hd", 5, sh);
  int_test2 = sprintf(str_2, "%-11.*hd", 5, sh);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(
      str_1, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
      335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, sh);
  int_test2 = sprintf(
      str_2, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
      335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, sh);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);
}
END_TEST

START_TEST(Sprintf_Test_u) {
  s21_sprintf(str_1, "abc %u abc", 166);
  sprintf(str_2, "abc %u abc", 166);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%2.5u%%\n", 4);
  sprintf(str_2, "%2.5u%%\n", 4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%2.5u%%\n", -4);
  sprintf(str_2, "%2.5u%%\n", -4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%10.5u%%\n", 4);
  sprintf(str_2, "%10.5u%%\n", 4);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "%-10u%%\n", 421);
  sprintf(str_2, "%-10u%%\n", 421);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  short unsigned key_h = 421;
  s21_sprintf(str_1, "%-10hu%%\n", key_h);
  sprintf(str_2, "%-10hu%%\n", key_h);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  long unsigned key_l = 421;
  s21_sprintf(str_1, "%-10lu%%\n", key_l);
  sprintf(str_2, "%-10lu%%\n", key_l);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %hu", 17);
  sprintf(str_2, "abc %hu", (unsigned short)17);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %lu", 17123121);
  sprintf(str_2, "abc %lu", (long unsigned int)17123121);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%u", 4321u);
  int_test2 = sprintf(str_2, "%u", 4321u);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%15u", 34567u);
  int_test2 = sprintf(str_2, "%15u", 34567u);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-20u", 2342u);
  int_test2 = sprintf(str_2, "%-20u", 2342u);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%010u", 12346u);
  int_test2 = sprintf(str_2, "%010u", 12346u);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-15.10u", 234542u);
  int_test2 = sprintf(str_2, "%-15.10u", 234542u);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%20.*u", 10, 234523u);
  int_test2 = sprintf(str_2, "%20.*u", 10, 234523u);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%*.*u", 10, 5, 2345u);
  int_test2 = sprintf(str_2, "%*.*u", 10, 5, 2345u);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%*.10u", 20, 2432u);
  int_test2 = sprintf(str_2, "%*.10u", 20, 2432u);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%-20.12lu", lg);
  int_test2 = sprintf(str_2, "%-20.12lu", lg);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%19hu", sh);
  int_test2 = sprintf(str_2, "%19hu", sh);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%u", UINT_MAX);
  int_test2 = sprintf(str_2, "%u", UINT_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%lu", ULONG_MAX);
  int_test2 = sprintf(str_2, "%lu", ULONG_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "%u %lu", UINT_MAX, ULONG_MAX);
  int_test2 = sprintf(str_2, "%u %lu", UINT_MAX, ULONG_MAX);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(
      str_1, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu", 4321u,
      34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, lg,
      sh);
  int_test2 =
      sprintf(str_2, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
              4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u,
              20, 2432u, lg, sh);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1,
                          "%u%15uhhhh%-20u%010u  fsd  %-15.10u%20.*u sdss "
                          "%*.*u%*.10u%-20.12lu%19hu",
                          4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u,
                          10, 5, 2345u, 20, 2432u, lg, sh);
  int_test2 = sprintf(str_2,
                      "%u%15uhhhh%-20u%010u  fsd  %-15.10u%20.*u sdss "
                      "%*.*u%*.10u%-20.12lu%19hu",
                      4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5,
                      2345u, 20, 2432u, lg, sh);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);
}
END_TEST

START_TEST(Sprintf_Test_i) {
  s21_sprintf(str_1, "abc %-20i abc", 5);
  sprintf(str_2, "abc %-20i abc", 5);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %020i abc", 5);
  sprintf(str_2, "abc %020i abc", 5);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %.20i abc", 1234567890);
  sprintf(str_2, "abc %.20i abc", 1234567890);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %*i abc", 20, 1234567890);
  sprintf(str_2, "abc %*i abc", 20, 1234567890);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %.*i abc", 20, 1234567890);
  sprintf(str_2, "abc %.*i abc", 20, 1234567890);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc % 5i abc", 5);
  sprintf(str_2, "abc % 5i abc", 5);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  s21_sprintf(str_1, "abc %3i abc", 5);
  sprintf(str_2, "abc %3i abc", 5);
  ck_assert_str_eq(str_1, str_2);
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "abc %+i abc", 5);
  int_test2 = sprintf(str_2, "abc %+i abc", 5);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "abc %-.i abc", n);
  int_test2 = sprintf(str_2, "abc %-.i abc", n);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "abc %*.023i abc", 25, n);
  int_test2 = sprintf(str_2, "abc %*.023i abc", 25, n);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "abc %*hi abc", 33, (short)n);
  int_test2 = sprintf(str_2, "abc %*hi abc", 33, (short)n);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);

  int_test1 = s21_sprintf(str_1, "abc %-+i abc", n2);
  int_test2 = sprintf(str_2, "abc %-+i abc", n2);
  ck_assert_str_eq(str_1, str_2);
  ck_assert_int_eq(int_test1, int_test2);
  int_test1 = 0;
  int_test2 = 0;
  free_two(str_1, str_2);
}
END_TEST
START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three octal parameters
START_TEST(sprintf_2_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o GOD %+.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Test %-*o Test %*.*o TEST %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Simple extra test
START_TEST(sprintf_16_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o Test %- 15o sdasda %- 15o sdsad %- o";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sscanf_c_1) {
  char *str = "\0\0pomogite";
  char c = ' ';
  char cc = ' ';
  char *format = "\0%c\0";

  sscanf(str, format, &c, &c, &c);
  s21_sscanf(str, format, &cc, &cc, &cc);
  ck_assert_int_eq(c, cc);
}
END_TEST

START_TEST(test_s21_sscanf_flazhki_2) {
  char *str = "lzhe flag I";
  char c;
  char cc;
  char *format = "%k";
  int er, ero;
  ero = sscanf(str, format, &c, &c, &c);
  er = s21_sscanf(str, format, &cc, &cc, &cc);
  ck_assert_int_eq(ero, er);
}
END_TEST

START_TEST(test_s21_sscanf_d_1) {
  char *str = "0x333";
  unsigned int vv;
  char *format = "%d";
  int er;
  unsigned int v;
  int ero;
  ero = sscanf(str, format, &v);
  er = s21_sscanf(str, format, &vv);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(v, vv);
}
END_TEST

START_TEST(test_s21_sscanf_d_2) {
  char *str = "0x333";
  unsigned int vv;
  char *format = "%d";
  int er;
  unsigned int v;
  int ero;
  char c;
  ero = sscanf(str, format, &c, &c, &v);
  er = s21_sscanf(str, format, &c, &c, &vv);
  ck_assert_int_eq(ero, er);
}
END_TEST

START_TEST(test_s21_sscanf_d_3) {
  test t = {0};
  char *str = "334";
  char *format = "%d";
  t.origRes = sscanf(str, format, &t.origC1, &t.origC2, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineC1, &t.mineC2, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origC1, t.mineC1);
}
END_TEST

START_TEST(test_s21_sscanf_d_7) {
  test t = {0};
  char *str = "1234563123";
  char *format = "%5d";
  t.origRes = sscanf(str, format, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origD1, t.mineD1);
}
END_TEST

START_TEST(test_s21_sscanf_d_12) {
  test t = {0};
  char *str = "3333333333";
  char *format = "%ld";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

// tests flag i
START_TEST(test_s21_sscanf_i_0) {
  test t = {0};
  char *str = "033333";
  char *format = "%i";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_1) {
  test t = {0};
  char *str = "0xFF";
  char *format = "%i";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_3) {
  test t = {0};
  char *str = "0xFF0xAC";
  char *format = "%4i%i";
  t.origRes = sscanf(str, format, &t.origLD1, &t.origLD2);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1, &t.mineLD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
  ck_assert_int_eq(t.origLD2, t.mineLD2);
}
END_TEST

START_TEST(test_s21_sscanf_i_7) {
  test t = {0};
  char *str = "-0xLC 312";
  char *format = "%5li";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

// tests for flags_eEfgG
START_TEST(test_s21_sscanf_eEfgG_1) {
  test t = {0};
  char *str = "33 33 33 33 33";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_3) {
  test t = {0};
  char *str = "033 033 033 033 033";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_4) {
  test t = {0};
  char *str =
      "13.123456789 13.123456789 13.123456789 13.123456789 13.123456789";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_14) {
  test t = {0};
  char *str = "11ee";
  char *format = "%e";
  t.origRes = sscanf(str, format, &t.origF1);
  t.mineRes = s21_sscanf(str, format, &t.mineF1);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_15) {
  test t = {0};
  char *str = "11..231";
  char *format = "%e";
  t.origRes = sscanf(str, format, &t.origF1);
  t.mineRes = s21_sscanf(str, format, &t.mineF1);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

// tests for flag_o
START_TEST(test_s21_sscanf_o_0) {
  test t = {0};
  char *str = "77";
  char *format = "%o";
  t.origRes = sscanf(str, format, &t.origU1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
}
END_TEST

START_TEST(test_s21_sscanf_o_1) {
  test t = {0};
  char *str = "077 0373";
  char *format = "%o%o";
  t.origRes = sscanf(str, format, &t.origU1, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

START_TEST(test_s21_sscanf_o_3) {
  test t = {0};
  char *str = "0343";
  char *format = "%2o%o";
  t.origRes = sscanf(str, format, &t.origU1, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

START_TEST(test_s21_sscanf_o_4) {
  test t = {0};
  char *str = "0343a";
  char *format = "%o%c";
  t.origRes = sscanf(str, format, &t.origU1, &t.origC1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineC1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

// tests for %
START_TEST(test_s21_sscanf_o_5) {
  test t = {0};
  char *str = "034%3a";
  char *format = "%o%%%c";
  t.origRes = sscanf(str, format, &t.origU1, &t.origC1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineC1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

START_TEST(test_s21_sscanf_o_7) {
  test t = {0};
  char *str = "-034%3a";
  char *format = "%o%%%c";
  t.origRes = sscanf(str, format, &t.origU1, &t.origC1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineC1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

// tests for flag_s
START_TEST(test_s21_sscanf_s_0) {
  test t = {0};
  char *str = "probel space";
  char *format = "%s%s";
  char resOrig1[100] = {0};
  char resOrig2[100] = {0};
  char resMine1[100] = {0};
  char resMine2[100] = {0};
  t.origRes = sscanf(str, format, resOrig1, resOrig2);
  t.mineRes = s21_sscanf(str, format, resMine1, resMine2);
  ck_assert_str_eq(resOrig1, resMine1);
  ck_assert_str_eq(resOrig2, resMine2);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

// char test1[20] = "Hell0 world\0";
// char test2[20] = "Hell0 world\n\0";
// char test3[10] = "a\n\0";
// char test4[10] = " \n\0";
// char test5[10] = " \0";
// char test6[10] = "\n\0";
// char test7[10] = "\0";

// START_TEST(test_s21_sscanf) {
//     short int s21_num1 = 0;
//     short int num1 = 0;
//     s21_sscanf("123456", "%hd", &s21_num1);
//     sscanf("123456", "%hd", &num1);
//     ck_assert_int_eq(s21_num1, num1);

//     s21_sscanf("-123.5", "%d", &s21_num1);
//     sscanf("-123.5", "%hd", &num1);
//     ck_assert_int_eq(s21_num1, num1);

//     s21_sscanf("-0xA3", "%i", &s21_num1);
//     sscanf("-0xA3", "%hi", &num1);
//     ck_assert_int_eq(s21_num1, num1);

//     s21_sscanf("0115", "%i", &s21_num1);
//     sscanf("0115", "%hi", &num1);
//     ck_assert_int_eq(s21_num1, num1);

//     s21_sscanf("115", "%i", &s21_num1);
//     sscanf("115", "%hi", &num1);
//     ck_assert_int_eq(s21_num1, num1);

//     int s21_num;
//     int num;
//     s21_sscanf("115", "%d%n", &s21_num1, &s21_num);
//     sscanf("115", "%hd%n", &num1, &num);
//     ck_assert_int_eq(s21_num1, num1);
//     ck_assert_int_eq(s21_num, num);

//     double s21_num2 = 0;
//     double num2 = 0;
//     s21_sscanf("-115.6", "%le", &s21_num2);
//     sscanf("-115.6", "%le", &num2);
//     ck_assert_uint_eq(s21_num2, num2);

//     s21_sscanf("80", "%lE", &s21_num2);
//     sscanf("80", "%lE", &num2);
//     ck_assert_uint_eq(s21_num2, num2);

//     s21_sscanf("09.8", "%lf", &s21_num2);
//     sscanf("09.8", "%lf", &num2);
//     ck_assert_uint_eq(s21_num2, num2);

//     s21_sscanf("-12345", "%lG", &s21_num2);
//     sscanf("-12345", "%lG", &num2);
//     ck_assert_uint_eq(s21_num2, num2);

//     unsigned int s21_num3;
//     unsigned int num3;
//     s21_sscanf("1115", "%o", &s21_num3);
//     sscanf("1115", "%o", &num3);
//     ck_assert_int_eq(s21_num3, num3);

//     s21_sscanf("-1115.9", "%u", &s21_num3);
//     sscanf("-1115.9", "%u", &num3);
//     ck_assert_int_eq(s21_num3, num3);

//     s21_sscanf("B10CA", "%x", &s21_num3);
//     sscanf("B10CA", "%x", &num3);
//     ck_assert_int_eq(s21_num3, num3);

//     s21_sscanf("B10C76", "%X", &s21_num3);
//     sscanf("B10C76", "%X", &num3);
//     ck_assert_int_eq(s21_num3, num3);

//     char s21_num4;
//     char num4;
//     s21_sscanf("#", "%c", &s21_num4);
//     sscanf("#", "%c", &num4);
//     ck_assert_int_eq(s21_num4, num4);

//     char s21_num5[30];
//     char num5[30];
//     s21_sscanf("Hello world!", "%s", &s21_num5);
//     sscanf("Hello world!", "%s", num5);
//     ck_assert_str_eq(s21_num5, num5);

//     char s21_num6[30];
//     char num6[30];
//     s21_sscanf("Hello world!", "%s%s", s21_num5, s21_num6);
//     sscanf("Hello world!", "%s%s", num5, num6);
//     ck_assert_str_eq(s21_num5, num5);
//     ck_assert_str_eq(s21_num6, num6);

//     void* s21_num7 = s21_NULL;
//     void* num7 = s21_NULL;
//     s21_sscanf("A3B2", "%p", &s21_num7);
//     sscanf("A3B2", "%p", &num7);
//     fail_unless(s21_num7 == num7);

//     float e1 = 0;
//     float e2 = 0;
//     int r1 = 0, r2 = 0;

//     r1 = sscanf("123.345e-34", "%9e", &e1);
//     r2 = s21_sscanf("123.345e-34", "%9e", &e2);
//     ck_assert_msg(e1 == e2, "float not equals");
//     ck_assert_int_eq(r1, r2);
// }
// END_TEST

// Suite *s21_string_test_suite() {
//     Suite *s = suite_create("s21_string_test_suite");

//     TCase *s_sscanf = tcase_create("s_sscanf");
//     suite_add_tcase(s, s_sscanf);
//     tcase_add_test(s_sscanf, test_s21_sscanf);

//     return s;
// }

int main() {
  Suite *suite =
      suite_create("S21_TEST");  // создание наборов тестов и с именем S21_TEST
  SRunner *srunner = srunner_create(suite);

  TCase *sprintf_d_test = tcase_create("Sprnt_d");
  suite_add_tcase(suite, sprintf_d_test);
  tcase_add_test(sprintf_d_test, Sprintf_Test_d);

  TCase *sprintf_i_test = tcase_create("Sprnt_i");
  suite_add_tcase(suite, sprintf_i_test);
  tcase_add_test(sprintf_i_test, Sprintf_Test_i);

  TCase *sprintf_c_test = tcase_create("Sprnt_c");
  suite_add_tcase(suite, sprintf_c_test);
  tcase_add_test(sprintf_c_test, Sprintf_Test_c);

  TCase *sprintf_s_test = tcase_create("Sprnt_s");
  suite_add_tcase(suite, sprintf_s_test);
  tcase_add_test(sprintf_s_test, Sprintf_Test_s);

  TCase *sprintf_f = tcase_create("Sprnt_f");
  suite_add_tcase(suite, sprintf_f);
  tcase_add_test(sprintf_f, Sprintf_Test_f);

  TCase *sprintf_u_test = tcase_create("Sprnt_u");
  suite_add_tcase(suite, sprintf_u_test);
  tcase_add_test(sprintf_u_test, Sprintf_Test_u);

  TCase *sprintf_o_test = tcase_create("Sprnt_u");
  suite_add_tcase(suite, sprintf_o_test);
  tcase_add_test(sprintf_o_test, sprintf_1_octal);
  tcase_add_test(sprintf_o_test, sprintf_2_octal);
  tcase_add_test(sprintf_o_test, sprintf_3_octal);
  tcase_add_test(sprintf_o_test, sprintf_4_octal);
  tcase_add_test(sprintf_o_test, sprintf_5_octal);
  tcase_add_test(sprintf_o_test, sprintf_6_octal);
  tcase_add_test(sprintf_o_test, sprintf_7_octal);
  tcase_add_test(sprintf_o_test, sprintf_8_octal);
  tcase_add_test(sprintf_o_test, sprintf_9_octal);
  tcase_add_test(sprintf_o_test, sprintf_11_octal);
  tcase_add_test(sprintf_o_test, sprintf_12_octal);
  tcase_add_test(sprintf_o_test, sprintf_13_octal);
  tcase_add_test(sprintf_o_test, sprintf_14_octal);
  tcase_add_test(sprintf_o_test, sprintf_15_octal);
  tcase_add_test(sprintf_o_test, sprintf_16_octal);
  tcase_add_test(sprintf_o_test, sprintf_17_octal);
  // test 1
  TCase *s21_memchrCase = tcase_create("s21_memchrCase");
  suite_add_tcase(suite, s21_memchrCase);
  tcase_add_test(s21_memchrCase, s21_memchr_test);
  // test 2
  TCase *s21_memcmpCase = tcase_create("s21_memcmpCase");
  suite_add_tcase(suite, s21_memcmpCase);
  tcase_add_test(s21_memcmpCase, s21_memcmp_test);
  // test 3
  TCase *s21_memcpyCase = tcase_create("s21_memcpyCase");
  suite_add_tcase(suite, s21_memcpyCase);
  tcase_add_test(s21_memcpyCase, s21_memcpy_test);
  // test 4
  TCase *s21_memmoveCase = tcase_create("s21_memmoveCase");
  suite_add_tcase(suite, s21_memmoveCase);
  tcase_add_test(s21_memmoveCase, s21_memmove_test);
  // test 5
  TCase *s21_memsetCase = tcase_create("s21_memsetCase");
  suite_add_tcase(suite, s21_memsetCase);
  tcase_add_test(s21_memsetCase, s21_memset_test);
  // test 6
  TCase *s21_strcatCase = tcase_create("s21_strcatCase");
  suite_add_tcase(suite, s21_strcatCase);
  tcase_add_test(s21_strcatCase, s21_strcat_test);
  // test 7
  TCase *s21_strncatCase = tcase_create("s21_strncatCase");
  suite_add_tcase(suite, s21_strncatCase);
  tcase_add_test(s21_strncatCase, s21_strncat_test);
  // test 8
  TCase *s21_strchrCase = tcase_create("s21_strchrCase");
  suite_add_tcase(suite, s21_strchrCase);
  tcase_add_test(s21_strchrCase, s21_strchr_test);
  // test 9
  TCase *s21_strcmpCase = tcase_create("s21_strcmpCase");
  suite_add_tcase(suite, s21_strcmpCase);
  tcase_add_test(s21_strcmpCase, s21_strcmp_test);
  // test 10
  TCase *s21_strncmpCase = tcase_create("s21_strncmpCase");
  suite_add_tcase(suite, s21_strncmpCase);
  tcase_add_test(s21_strncmpCase, s21_strncmp_test);
  // test 11
  TCase *s21_strcpyCase = tcase_create("s21_strcpyCase");
  suite_add_tcase(suite, s21_strcpyCase);
  tcase_add_test(s21_strcpyCase, s21_strcpy_test);
  // test 12
  TCase *s21_strncpyCase = tcase_create("s21_strncpyCase");
  suite_add_tcase(suite, s21_strncpyCase);
  tcase_add_test(s21_strncpyCase, s21_strncpy_test);
  // test 13
  TCase *s21_strcspnCase = tcase_create("s21_strcspnCase");
  suite_add_tcase(suite, s21_strcspnCase);
  tcase_add_test(s21_strcspnCase, s21_strcspn_test);
  // test 14
  TCase *s21_strerrorCase = tcase_create("s21_strerrorCase");
  suite_add_tcase(suite, s21_strerrorCase);
  tcase_add_test(s21_strerrorCase, s21_strerror_test);
  // test 15
  TCase *s21_strlenCase = tcase_create("s21_strlenCase");
  suite_add_tcase(suite, s21_strlenCase);
  tcase_add_test(s21_strlenCase, s21_strlen_test);
  // test 16
  TCase *s21_strpbrkCase = tcase_create("s21_strpbrkCase");
  suite_add_tcase(suite, s21_strpbrkCase);
  tcase_add_test(s21_strpbrkCase, s21_strpbrk_test);
  // test 17
  TCase *s21_strrchrCase = tcase_create("s21_strrchrCase");
  suite_add_tcase(suite, s21_strrchrCase);
  tcase_add_test(s21_strrchrCase, s21_strrchr_test);
  // test 18
  TCase *s21_strspnCase = tcase_create("s21_strspnCase");
  suite_add_tcase(suite, s21_strspnCase);
  tcase_add_test(s21_strspnCase, s21_strspn_test);
  // test 19
  TCase *s21_strstrCase = tcase_create("s21_strstrCase");
  suite_add_tcase(suite, s21_strstrCase);
  tcase_add_test(s21_strstrCase, s21_strstr_test);
  // test 20
  TCase *s21_strtokCase = tcase_create("s21_strtokCase");
  suite_add_tcase(suite, s21_strtokCase);
  tcase_add_test(s21_strtokCase, s21_strtok_test);
  // bonus 1
  TCase *s21_to_upperCase = tcase_create("s21_to_upperCase");
  suite_add_tcase(suite, s21_to_upperCase);
  tcase_add_test(s21_to_upperCase, s21_to_upper_test);
  // bonus 2
  TCase *s21_to_lowerCase = tcase_create("s21_to_lowerCase");
  suite_add_tcase(suite, s21_to_lowerCase);
  tcase_add_test(s21_to_lowerCase, s21_to_lower_test);
  // bonus 3
  TCase *s21_insertCase = tcase_create("s21_insertCase");
  suite_add_tcase(suite, s21_insertCase);
  tcase_add_test(s21_insertCase, s21_insert_test);
  // bonus 4
  TCase *s21_trimCase = tcase_create("s21_trimCase");
  suite_add_tcase(suite, s21_trimCase);
  tcase_add_test(s21_trimCase, s21_trim_test);
  // s21_sprintf
  // s21_sscanf
  TCase *tc_scanf_c;
  TCase *tc_scanf_d;
  TCase *tc_scanf_i;
  TCase *tc_scanf_eEfgG;
  TCase *tc_scanf_o;
  TCase *tc_scanf_xX;
  TCase *tc_scanf_s;
  tc_scanf_c = tcase_create("flag_c");
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_1);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_flazhki_2);
  suite_add_tcase(suite, tc_scanf_c);

  tc_scanf_d = tcase_create("flag_d");
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_1);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_2);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_3);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_7);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_12);
  suite_add_tcase(suite, tc_scanf_d);

  tc_scanf_i = tcase_create("flag_i");
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_0);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_1);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_3);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_7);
  suite_add_tcase(suite, tc_scanf_i);

  tc_scanf_eEfgG = tcase_create("flags_eEfgG");
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_1);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_3);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_4);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_14);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_15);
  suite_add_tcase(suite, tc_scanf_eEfgG);

  tc_scanf_o = tcase_create("flag_o");
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_0);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_1);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_3);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_4);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_5);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_7);
  suite_add_tcase(suite, tc_scanf_o);

  tc_scanf_xX = tcase_create("flags_xX");
  suite_add_tcase(suite, tc_scanf_xX);

  tc_scanf_s = tcase_create("flags_s");
  tcase_add_test(tc_scanf_s, test_s21_sscanf_s_0);
  suite_add_tcase(suite, tc_scanf_s);
  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? 0 : 1;
}