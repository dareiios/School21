#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_PI 3.1415926535897932
#define s21_NAN 0.0 / 0.0
#define s21_inf_plus +1.0 / 0.0
#define s21_inf_minus -1.0 / 0.0
#define s21_INF 1.0 / 0.0
#define s21_EPS 1e-17
#define s21_DBL_MAX 1.7976931348623157E+308
#define s21exp 2.71828182845904

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == s21_inf_minus || x == s21_inf_plus)
#define s21_MAX_double 1.79769313486231570e+308

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H_2
