#include "s21_math.h"

#define S21_IS_NAN(x) (x != x)

int s21_abs(int x) {
  if (x < 0) x *= -1;
  return x;
}

long double s21_factorial(int x) {
  long double res = 0;
  if (x < 0) {
    res = x;
  } else if (x == 0) {
    res = 1;
  } else {
    res = x * s21_factorial(x - 1);
  }
  return res;
}

long double s21_cos(double x) {
  long double res = 0;
  if (x != x || x == s21_inf_plus || x == s21_inf_minus) {
    res = s21_NAN;
  } else {
    if (s21_fabs(x) > 2 * s21_PI) x = s21_fmod(x, 2 * s21_PI);
    for (int i = 0; i < 15; i++) {
      res += (s21_pow(-1.0, i) * s21_pow(x, 2.0 * i)) /
             (s21_factorial(2 * i) * 1.0);
    }
  }
  return res;
}

long double s21_sin(double x) {
  long double res = 0;
  x = s21_fmod(x, 2 * s21_PI);
  for (int i = 0; i < 15; i++) {
    res += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / s21_factorial(1 + 2 * i);
  }
  return res;
}

long double s21_exp(double x) {
  long double res = 1;
  long double add = 1;
  long double i = 1;
  int flag = 0;

  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(add) > s21_EPS) {
    add *= x / i;
    i += 1;
    res += add;
    if (res > s21_DBL_MAX) {
      res = s21_inf_plus;
      break;
    }
  }
  res = flag == 1 ? res > s21_DBL_MAX ? 0 : 1. / res : res;
  return res = res > s21_DBL_MAX ? s21_INF : res;
}

long double s21_fabs(double x) {
  long double res = 0;
  if (x == s21_inf_minus)
    res = s21_inf_plus;
  else if (x == 0.0)
    res = 0.0;
  else if (x != x)
    res = s21_NAN;
  else if (x < 0)
    res = -x;
  else
    res = x;
  return res;
}

long double s21_floor(double x) {
  long int res = x;

  if (x == s21_inf_plus) {
    x = s21_inf_plus;
  } else if (x == s21_inf_minus) {
    x = s21_inf_minus;
  } else if (x != x) {
    x = s21_NAN;

  } else if (x - (int)x == 0) {
    x = x;
  } else if (x >= 0)
    x = (long double)res;
  else
    x = (long double)res - 1.0;
  return x;
}

long double s21_tan(double x) {
  x = s21_fmod(x, s21_PI);
  long double res_cos = s21_cos(x);
  long double res = 0;
  if (res_cos != 0)
    res = (s21_sin(x) / s21_cos(x));
  else
    res = s21_NAN;
  return res;
}

long double s21_max(double x, double y) {
  long double max = 0;
  if (x > y) {
    max = x;
  } else {
    max = y;
  }
  return max;
}

long double s21_sqrt(double x) {
  long double res = s21_pow(x, 0.5);
  if (x == s21_inf_minus) res = s21_NAN;
  return res;
}

long double s21_pow(double base, double exp) {
  long double res;
  long double copy = base;
  if ((base == 0) && (exp == 0)) {
    res = 1;
  } else {
    if ((base == 1) || (exp == 0)) {
      res = 1;
    } else {
      if (base == -1 && (exp == s21_inf_minus || exp == s21_inf_plus)) {
        res = 1;
      } else if ((base < 0) && (s21_floor(exp) != exp)) {
        res = s21_NAN;
      } else {
        if (copy < 0) {
          copy = -copy;
          res = s21_exp(exp * s21_log(copy));
          if (base < 0 && (exp == s21_inf_minus || exp == s21_inf_plus)) {
            res = -res;
          }
          if (s21_fmod(exp, 2) != 0) {
            res = -res;
          }
        } else {
          res = s21_exp(exp * s21_log(base));
        }
      }
    }
  }
  return res;
}

long double s21_atan(double x) {
  long double sum = 0;
  if (x == 1)
    return 0.785398163;
  else if (x == -1)
    return -0.785398163;
  else if (x == s21_inf_plus)
    sum = s21_PI / 2;
  else if (x == s21_inf_minus)
    sum = -s21_PI / 2;

  else if (x > -1 && x < 1) {
    for (int i = 0; i < 1000; i++) {
      sum += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + 2 * i);
    }
  } else {
    for (int i = 0; i < 1000; i++) {
      sum += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + 2 * i);
    }
    sum = (s21_PI * s21_sqrt(s21_pow(x, 2)) / (2 * x)) - sum;
  }

  return sum;
}

long double s21_asin(double x) {
  long double res = 0;
  if (x > -1 && x < 1)
    res = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
  else if (x == 1 || x == -1)
    res = s21_PI / (2 * x);
  else
    res = s21_NAN;
  return res;
}

long double s21_acos(double x) {
  long double res = 0;

  if (x >= 0 && x < 1) {
    res = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else if (x == 1)
    res = 0;
  else
    res = s21_PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);

  return res;
}

long double s21_ceil(double x) {
  long double res = s21_NAN;

  if (x == s21_inf_minus || x == s21_inf_plus)
    res = x;
  else if (x != (int)x && x > 0)
    res = (int)x +
          1;  // если целая часть(res) не является исходным целочисленным числом
  else if (x < 0)
    res = (int)x;
  else
    res = x;

  return res;
}

long double s21_fmod(double x, double y) {
  long long int mod = 0;
  mod = x / y;
  long double res = (long double)x - mod * (long double)y;
  if (y == 0) {
    res = s21_NAN;
  } else if (y == s21_inf_minus) {
    if (x == s21_inf_plus || x == s21_inf_minus) {
      res = s21_NAN;
    } else {
      res = x;
    }
  } else if (y == s21_inf_plus) {
    if (x == s21_inf_plus || x == s21_inf_minus) {
      res = s21_NAN;
    } else {
      res = x;
    }
  }
  return res;
}

long double s21_log(double x) {
  int k = 0;
  double result = 0;
  double copy = 0;
  if (x == 0) {
    result = s21_inf_minus;
  } else {
    if (x < 0) {
      result = s21_NAN;
    } else {
      if (x == s21_inf_plus) {
        result = s21_inf_plus;
      } else {
        for (; x >= s21exp; x /= s21exp, k++) continue;
        for (int i = 0; i < 100; i++) {
          copy = result;
          result = copy + 2 * (x - s21_exp(copy)) / (x + s21_exp(copy));
        }
      }
    }
  }
  return (result + k);
}
