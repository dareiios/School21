#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(abs_test) {
  ck_assert_double_eq(abs(-7), s21_abs(-7));
  ck_assert_double_eq(abs(-98), s21_abs(-98));
  ck_assert_double_eq(abs(123), s21_abs(123));
  ck_assert_double_eq(abs(10009), s21_abs(10009));
  ck_assert_double_eq(abs(-10009), s21_abs(-10009));
  ck_assert_double_eq(abs(0), s21_abs(0));
  ck_assert_double_eq(abs(-1), s21_abs(-1));
}
END_TEST

START_TEST(acos_test) {
  ck_assert_int_eq(acos(-13.54), s21_acos(-13.54));
  ck_assert_int_eq(acos(13.54), s21_acos(13.54));
  ck_assert_int_eq(acos(2.2343), s21_acos(2.2343));
  ck_assert_float_eq(acos(0.1234), s21_acos(0.1234));
  ck_assert_float_eq(acos(0), s21_acos(0));
  ck_assert_float_eq(acos(1), s21_acos(1));
  ck_assert_float_eq(acos(-1), s21_acos(-1));
  ck_assert_float_eq(acos(0.5), s21_acos(0.5));
  ck_assert_float_eq(acos(-0.5), s21_acos(-0.5));
  ck_assert_int_eq(acos(0.43), s21_acos(0.43));
  ck_assert_int_eq(acos(-1), s21_acos(-1));
  ck_assert_int_eq(acos(-0.999), s21_acos(-0.999));
  for (double i = -10; i < 10; i += 1) {
    ck_assert_int_eq(acos(i), s21_acos(i));
  }
  for (double i = -1; i < 1; i += 1) {
    ck_assert_int_eq(acos(i), s21_acos(i));
  }
}
END_TEST

START_TEST(asin_test) {
  ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-6);
  ck_assert_int_eq(asin(-13.54), s21_asin(-13.54));
  ck_assert_int_eq(asin(13.54), s21_asin(13.54));
  ck_assert_int_eq(asin(6.28), s21_asin(6.28));
  ck_assert_float_eq(asin(s21_EPS), s21_asin(s21_EPS));
  ck_assert_ldouble_nan(s21_asin(s21_inf_plus));
  ck_assert_ldouble_nan(s21_asin(s21_inf_minus));
  ck_assert_float_eq(asin(0.1234), s21_asin(0.1234));
  ck_assert_float_eq(asin(0), s21_asin(0));
  ck_assert_float_eq(asin(1), s21_asin(1));
  ck_assert_float_eq(asin(-1), s21_asin(-1));
  ck_assert_float_eq(asin(0.5), s21_asin(0.5));
  ck_assert_float_eq(asin(-0.5), s21_asin(-0.5));
  for (float k = -1; k <= 0; k += 0.0205) {
    double a = s21_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(atan_test) {
  ck_assert_int_eq(atan(-13.54), s21_atan(-13.54));
  ck_assert_float_eq(atan(13.54), s21_atan(13.54));
  ck_assert_float_eq(atan(3.14), s21_atan(3.14));
  ck_assert_float_eq(atan(6.28), s21_atan(6.28));
  ck_assert_float_eq(atan(2.2343), s21_atan(2.2343));
  ck_assert_float_eq(atan(0.1234), s21_atan(0.1234));
  ck_assert_float_eq(atan(0), s21_atan(0));
  ck_assert_float_eq(atan(1), s21_atan(1));
  ck_assert_float_eq(atan(-1), s21_atan(-1));
  ck_assert_float_eq(atan(3.5), s21_atan(3.5));
  ck_assert_float_eq(atan(-3.5), s21_atan(-3.5));
  for (double k = 1; k <= 10; k += 1) {
    long double a = s21_atan(k);
    double b = atan(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_int_eq(ceil(0), s21_ceil(0));
  ck_assert_double_eq(fabs(10009.0), s21_fabs(10009.0));
  ck_assert_double_eq(fabs(-10009.555), s21_fabs(-10009.555));
  ck_assert_double_eq(fabs(-0.10009), s21_fabs(-0.10009));
  ck_assert_double_eq(fabs(-1e23), s21_fabs(-1e23));
  ck_assert_double_eq(ceil(s21_inf_plus), s21_ceil(s21_inf_plus));
  ck_assert_double_eq(ceil(s21_inf_minus), s21_ceil(s21_inf_minus));
  ck_assert_double_nan(ceil(s21_NAN));
  ck_assert_double_nan(ceil(s21_NAN));
  for (double i = -M_PI / 2; i <= M_PI / 2; i += 0.25) {
    ck_assert_double_eq(ceil(i), s21_ceil(i));
  }
}
END_TEST

START_TEST(cos_test) {
  ck_assert_float_eq(cos(-13.54), s21_cos(-13.54));
  ck_assert_float_eq(cos(13.54), s21_cos(13.54));
  ck_assert_float_eq(cos(0.0), s21_cos(0.0));
  ck_assert_ldouble_eq_tol(cos(-0.0), s21_cos(-0.0), s21_EPS);
  ck_assert_float_eq(cos(1.0), s21_cos(1.0));
  ck_assert_float_eq(cos(s21_PI), s21_cos(s21_PI));
  ck_assert_ldouble_eq_tol(cos(12415.12415), s21_cos(12415.12415), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-124345.9999), s21_cos(-124345.9999), 1e-6);
  ck_assert_float_eq(cos(6.28), s21_cos(6.28));
  ck_assert_float_eq(cos(2.2343), s21_cos(2.2343));
  ck_assert_float_eq(cos(0.1234), s21_cos(0.1234));
  ck_assert_double_nan(s21_cos(-0.0 / 0.0));
  for (double i = -s21_PI; i < s21_PI; i += 0.01) {
    ck_assert_int_eq(s21_cos(i), cos(i));
  }
}
END_TEST

START_TEST(exp_test) {
  ck_assert_ldouble_eq_tol(s21_exp(0.0), (long double)exp(0.0), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(0.0), (long double)exp(0.0), s21_EPS);
  ck_assert_uint_eq(s21_exp(0), exp(0));
  ck_assert_uint_eq(s21_exp(5), exp(5));
  ck_assert_uint_eq(s21_exp(-2), exp(-2));
  ck_assert_uint_eq(s21_exp(1234567), exp(1234567));
  ck_assert_uint_eq(s21_exp(-1234567), exp(-1234567));
  ck_assert_int_eq(s21_exp(s21_NAN), exp(s21_NAN));
  ck_assert_float_eq(s21_exp(0), exp(0));
  for (double i = -10; i < 10; i++) {
    ck_assert_uint_eq(s21_exp(i), exp(i));
  }
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_int_eq(fabs(-13.21313), s21_fabs(-13.21313));
  ck_assert_int_eq(fabs(13.21313), s21_fabs(13.21313));
  ck_assert_int_eq(fabs(-1000.21313), s21_fabs(-1000.21313));
  ck_assert_int_eq(fabs(32346234.21313), s21_fabs(32346234.21313));
  ck_assert_int_eq(fabs(0.0), s21_fabs(0.0));
  ck_assert_double_nan(s21_fabs(s21_NAN));
  ck_assert_double_eq(fabs(s21_inf_plus), s21_fabs(s21_inf_plus));
  ck_assert_double_eq(fabs(s21_inf_minus), s21_fabs(s21_inf_minus));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_ldouble_eq(floor(-13.54), s21_floor(-13.54));
  ck_assert_ldouble_eq(floor(13.54), s21_floor(13.54));
  ck_assert_ldouble_eq(floor(-0.54), s21_floor(-0.54));
  ck_assert_ldouble_eq(floor(1000), s21_floor(1000));
  ck_assert_ldouble_eq(floor(102.0000002), s21_floor(102.0000002));
  ck_assert_ldouble_eq(floor(s21_inf_plus), s21_floor(s21_inf_plus));
  ck_assert_ldouble_eq(floor(s21_inf_minus), s21_floor(s21_inf_minus));
  ck_assert_ldouble_nan(floor(NAN));
  ck_assert_ldouble_nan(s21_floor(NAN));
}
END_TEST

START_TEST(fmod_test) {
  ck_assert_ldouble_eq(fmod(-13.21313, 2.5), s21_fmod(-13.21313, 2.5));
  ck_assert_ldouble_eq(fmod(13.21313, 2.5), s21_fmod(13.21313, 2.5));
  ck_assert_ldouble_eq(fmod(-1000.21313, 2.5), s21_fmod(-1000.21313, 2.5));
  ck_assert_ldouble_eq(fmod(32346234.21313, 2.5),
                       s21_fmod(32346234.21313, 2.5));
  ck_assert_ldouble_eq(fmod(0, 2.5), s21_fmod(0, 2.5));
  ck_assert_ldouble_eq(fmod(2.5, 2.5), s21_fmod(2.5, 2.5));
  ck_assert_double_nan(s21_fmod(0, s21_NAN));
  ck_assert_double_nan(fmod(0, s21_NAN));
  ck_assert_double_nan(s21_fmod(s21_NAN, s21_NAN));
  ck_assert_double_nan(fmod(s21_NAN, s21_NAN));
  ck_assert_ldouble_eq_tol(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7),
                           1e-7);
  ck_assert_ldouble_eq_tol(s21_fmod(36677.546546, 4.1), fmod(36677.546546, 4.1),
                           1e-7);
  ck_assert_ldouble_eq_tol(s21_fmod(23.456, -4.355), fmod(23.456, -4.355),
                           1e-7);
  // ck_assert_ldouble_eq(fmod(s21_inf_plus, s21_inf_minus),
  // s21_fmod(s21_inf_plus, s21_inf_minus));
}
END_TEST

START_TEST(log_test) {
  double res2 = s21_inf_plus;
  double res3 = s21_NAN;
  int nantest1 = isnan(log(res3));
  int nantest2 = isnan(s21_log(res3));
  ck_assert_double_eq((double)s21_log(res2), log(res2));
  ck_assert_int_eq(nantest1, nantest2);
  ck_assert_int_eq(s21_log(12356), log(12356));
  ck_assert_int_eq(s21_log(1.1), log(1.1));
  for (double i = -1.; i < 10; i += 0.1) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
  for (double i = 0.; i < 2; i += 0.01) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
}
END_TEST

START_TEST(pow_test) {
  ck_assert_int_eq(s21_pow(2.6, 3.45), pow(2.6, 3.45));
  ck_assert_int_eq(s21_pow(3.0, 14.0), pow(3.0, 14.0));
  ck_assert_int_eq(s21_pow(31.456, 4.3), pow(31.456, 4.3));
  ck_assert_int_eq(s21_pow(31.456, 0.3), pow(31.456, 0.3));
  ck_assert_int_eq(s21_pow(4.3, 4.3), pow(4.3, 4.3));
  ck_assert_int_eq(s21_pow(-1234, 4.3), pow(-1234, 4.3));
  ck_assert_int_eq(s21_pow(-1234, -4.3), pow(-1234, -4.3));
  ck_assert_int_eq(s21_pow(1234, -4.3), pow(1234, -4.3));
  ck_assert_int_eq(isnan(s21_pow(-15, 3.45)), 1);
  ck_assert_int_eq(isnan(s21_pow(-15, -3.45)), 1);
  ck_assert_ldouble_eq(s21_pow(-2.6, s21_inf_minus),
                       pow(-2.6, s21_inf_minus));  //-
  ck_assert_ldouble_eq(s21_pow(-2.6, s21_inf_plus),
                       pow(-2.6, s21_inf_plus));                           //-
  ck_assert_ldouble_eq(s21_pow(-1, s21_inf_plus), pow(-1, s21_inf_plus));  //-
  ck_assert_ldouble_eq(s21_pow(-0.123456, s21_inf_plus),
                       pow(-0.123456, s21_inf_plus));  //-
  ck_assert_int_eq(s21_pow(-2.6, 3.45) == s21_NAN, pow(-2.6, 3.45) == s21_NAN);
  ck_assert_double_eq_tol(s21_pow(1, 1), pow(1, 1), 1e-6);
}
END_TEST

START_TEST(sin_test) {
  ck_assert_float_eq(sin(-13.54), s21_sin(-13.54));
  ck_assert_float_eq(sin(13.54), s21_sin(13.54));
  ck_assert_float_eq(sin(0.0), s21_sin(0.0));
  ck_assert_float_eq(sin(1.0), s21_sin(1.0));
  ck_assert_float_eq(sin(3.14), s21_sin(3.14));
  ck_assert_ldouble_eq_tol(sin(6.28), s21_sin(6.28), 1e-6);
  ck_assert_float_eq(sin(2.2343), s21_sin(2.2343));
  ck_assert_float_eq(sin(0.1234), s21_sin(0.1234));
  ck_assert_int_eq(isnan(s21_sin(s21_NAN)), 1);
  ck_assert_double_nan(s21_sin(s21_INF));
}
END_TEST

START_TEST(sqrt_test) {
  ck_assert_float_eq(sqrt(0.0), s21_sqrt(0.0));
  ck_assert_float_eq(sqrt(1.0), s21_sqrt(1.0));
  ck_assert_float_eq(sqrt(3.14), s21_sqrt(3.14));
  ck_assert_float_eq(sqrt(6.28), s21_sqrt(6.28));
  ck_assert_float_eq(sqrt(2.2343), s21_sqrt(2.2343));
  ck_assert_int_eq(sqrt(-123), s21_sqrt(-123));
  ck_assert_float_eq(sqrt(0.9), s21_sqrt(0.9));
}
END_TEST

START_TEST(tan_test) {
  ck_assert_float_eq(tan(-13.54), s21_tan(-13.54));
  ck_assert_float_eq(tan(13.54), s21_tan(13.54));
  ck_assert_float_eq(tan(0), s21_tan(0));
  ck_assert_float_eq(tan(1), s21_tan(1));
  ck_assert_float_eq(tan(3.14), s21_tan(3.14));
  ck_assert_float_eq(tan(6.28), s21_tan(6.28));
  ck_assert_float_eq(tan(2.2343), s21_tan(2.2343));
  ck_assert_float_eq(tan(0.1234), s21_tan(0.1234));
  for (double i = -100; i < 100; i += 2) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *suite;

  suite = suite_create("s21_math");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, abs_test);
  tcase_add_test(tcase_core, acos_test);
  tcase_add_test(tcase_core, asin_test);
  tcase_add_test(tcase_core, atan_test);
  tcase_add_test(tcase_core, ceil_test);
  tcase_add_test(tcase_core, cos_test);
  tcase_add_test(tcase_core, exp_test);
  tcase_add_test(tcase_core, fabs_test);
  tcase_add_test(tcase_core, floor_test);
  tcase_add_test(tcase_core, fmod_test);
  tcase_add_test(tcase_core, log_test);
  tcase_add_test(tcase_core, pow_test);
  tcase_add_test(tcase_core, sin_test);
  tcase_add_test(tcase_core, sqrt_test);
  tcase_add_test(tcase_core, tan_test);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = s21_math_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
