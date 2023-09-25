#include "./s21_string.h"

#if defined __linux__
#define MinCount -1
#define MaxCount 134
#define UnknownError "Unknown error: %d"
static const char *ErrorsMas[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel num out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link num out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#elif defined __APPLE__
#define MinCount -1
#define MaxCount 106
#define UnknownError "Unknown error: %d"
static const char *ErrorsMas[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full",
    "Unknown error"};
#endif

char *s21_strcpy(char *dest, const char *src) {
  unsigned int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

int compare(const char *haystack, const char *needle) {
  while (*haystack && *needle) {
    if (*haystack != *needle) {
      return 0;
    }
    haystack++;
    needle++;
  }

  return (*needle == '\0');
}

char *s21_strstr(const char *haystack, const char *needle) {
  const char *a;
  const char *b;

  b = needle;

  if (*b == 0) {
    return (char *)haystack;
  }

  for (; *haystack != 0; haystack += 1) {
    if (*haystack != *b) {
      continue;
    }

    a = haystack;
    while (1) {
      if (*b == 0) {
        return (char *)haystack;
      }
      if (*a++ != *b++) {
        break;
      }
    }
    b = needle;
  }

  return s21_NULL;
}

char *s21_find_last_separator(char *str, const char *delim) {
  int flag = 0;
  char *res = str;
  char *str1 = str;
  for (long unsigned int i = 0; i < s21_strlen(str1) && flag == 0; i++) {
    int next = 0;
    for (long unsigned int j = 0;
         j < s21_strlen(delim) && flag == 0 && next == 0; j++) {
      if (str[i] == delim[j]) {
        str[i] = '\0';
        str1 = &str[i + 1];
        next = 1;
      } else if (j == s21_strlen(delim) - 1) {
        flag = 1;
        res = &str[i];
      }
    }
  }
  if (flag == 0) res = 0;

  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static int next_null, tok;
  static size_t ind;
  static char *max_ptr;
  static char *addr;
  if (str) {
    tok = 1;
    ind = 0, next_null = 0;
    addr = str + s21_strspn(str, delim);
    max_ptr = str + s21_strlen(str);
  }
  char *res = NULL;
  if (!(addr >= max_ptr || next_null)) {
    int non_delim = 1;
    for (int i = 0; addr[i]; i++) {
      size_t step = s21_strspn(addr + i, delim);
      if (step != 0) {
        non_delim = 0;
        for (size_t j = i; j < i + step; j++) addr[j] = '\0';
        ind = step + i;
        break;
      }
    }
    if (tok == 1 && non_delim) next_null = 1;
    res = addr;
    addr += ind;
  }
  ++tok;
  return res;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)str;
  unsigned char *isCharFind = s21_NULL;
  while ((str != s21_NULL) && (n--)) {
    if (*p != (unsigned char)c) {
      p++;
    } else {
      isCharFind = p;
      break;
    }
  }
  return isCharFind;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *pszDest = (char *)dest;
  const char *pszSource = (const char *)src;
  if ((pszDest != s21_NULL) && (pszSource != s21_NULL)) {
    while (n) {
      *(pszDest++) = *(pszSource++);
      --n;
    }
  }
  return dest;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *ptr1 = (unsigned char *)str1;
  unsigned char *ptr2 = (unsigned char *)str2;
  int flag_memcmp = 0, flag_of_end = 0;
  while (!flag_of_end && (n--) && ptr1 && ptr2) {
    if (*ptr1 != *ptr2) {
      flag_memcmp = (*ptr1) - (*ptr2);
      flag_of_end = 1;
    }
    ptr1++;
    ptr2++;
  }
  return flag_memcmp;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *pDest = (char *)dest;
  const char *pSrc = (const char *)src;
  char *tmp = (char *)malloc(sizeof(char) * n);
  if (s21_NULL == tmp) {
    return s21_NULL;
  } else {
    unsigned int i = 0;
    for (i = 0; i < n; ++i) {
      *(tmp + i) = *(pSrc + i);
    }
    for (i = 0; i < n; ++i) {
      *(pDest + i) = *(tmp + i);
    }
    free(tmp);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *s = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    s[i] = c;
  }
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  int dest_len = s21_strlen(dest);
  int i = 0;

  for (; src[i]; i++) {
    dest[dest_len + i] = src[i];
  }

  dest[dest_len + i] = '\0';

  return dest;
}

char *s21_strncat(char *str1, const char *src, s21_size_t n) {
  if ((str1 == s21_NULL) && (src == s21_NULL)) return s21_NULL;
  char *dest = str1;
  while (*dest != '\0') {
    dest++;
  }
  char *p = dest + s21_strlen(dest);
  while (*src != '\0' && n--) {
    *p++ = *src++;
  }
  *p = '\0';

  return str1;
}

char *s21_strchr(const char *str, int c) {
  char *isCharFind = s21_NULL;
  if (str != s21_NULL) {
    do {
      if (*str == (char)c) {
        isCharFind = (char *)str;
        break;
      }
    } while (*str++);
  }
  return isCharFind;
}

int s21_strcmp(const char *str1, const char *str2) {
  int charCompareStatus = 0;
  for (int i = 0; str1[i] || str2[i]; i++) {
    if (str1[i] != str2[i]) {
      charCompareStatus = str1[i] - str2[i];
      break;
    }
  }
  return charCompareStatus;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  while (n--) {
    if (*str1 != *str2) {
      result = *str1 - *str2;
    } else {
      ++str1;
      ++str2;
    }
  }
  return result;
}

void *s21_to_upper(const char *str) {
  char *temporaryString;
  s21_size_t length = s21_strlen(str) + 1;
  if (str == s21_NULL) {
    temporaryString = s21_NULL;
  } else {
    temporaryString = calloc(length, sizeof(char));
    for (s21_size_t i = 0; i < length; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        temporaryString[i] = str[i] - 'a' + 'A';
      } else {
        temporaryString[i] = str[i];
      }
    }
  }
  return temporaryString;
}

void *s21_to_lower(const char *str) {
  char *temporaryString;
  s21_size_t length = s21_strlen(str) + 1;
  if (str == s21_NULL) {
    temporaryString = s21_NULL;
  } else {
    temporaryString = calloc(length, sizeof(char));
    for (s21_size_t i = 0; i < length; i++) {
      if (str[i] < 'A' || str[i] > 'Z') {
        temporaryString[i] = str[i];
      } else {
        temporaryString[i] = str[i] + 32;
      }
    }
  }
  return temporaryString;
}
s21_size_t s21_strlen(const char *str) {
  const char *end = str;

  while (*end != '\0') {
    ++end;
  }

  return end - str;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (n != 0) {
    char *d = dest;
    const char *s = src;
    do {
      if ((*d++ = *s++) == 0) {
        while (--n > 0) *d++ = 0;

        break;
      }
    } while (--n > 0);
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int len1 = s21_strlen(str2);
  int count = 0;
  int flag = 0;
  char *str11 = (char *)str1;
  while (*str11 != '\0') {
    for (int i = 0; i < len1; i++) {
      if ((*str11) == str2[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
    str11++;
    count++;
  }

  return count;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *newMas = NULL;
  int len2 = s21_strlen(str2);
  int flag = 0;
  char *res = NULL;
  if (str1 != NULL && len2 > 0) {
    newMas = (char *)str1;
    while (*newMas != '\0' && flag == 0) {
      for (int k = 0; k < len2; k++) {
        if ((*newMas) == str2[k]) {
          res = newMas;
          flag = 1;
        }
      }
      newMas++;
    }
  }
  return res;
}

char *s21_strerror(int errnum) {
  char *buf = s21_NULL;
  static char str[100] = {'\0'};
  if (errnum >= MinCount && errnum <= MaxCount) {
    buf = (char *)ErrorsMas[errnum];
  } else {
    s21_sprintf(str, UnknownError, errnum);
    buf = str;
  }
  return buf;
}

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  do {
    if (*str == (char)c) {
      res = (char *)str;
    }
  } while (*str++);
  return res;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  char *newMas = (char *)str1;
  int len = s21_strlen(str2);
  int flag = 0;
  int count = 0;
  int i = 0;
  while (*newMas != '\0' && flag == 0) {
    i = 0;
    while (i < len) {
      if ((*newMas) == str2[i]) {
        count++;
        break;
      }
      i++;
      if (i == len) {
        flag = 1;
      }
    }
    newMas++;
  }
  return count;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (src && str && start_index <= (s21_strlen(src))) {
    result =
        (char *)calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    if (result) {
      s21_strncpy(result, src, start_index);
      s21_strcat(result, str);
      s21_strcat(result, src + start_index);
    }
  }
  return result;
}

int check_edges(const char *src, const char *totrim, int edge) {
  int res = 0;
  int size = s21_strlen(totrim);
  for (int i = 0; i < size; i++) {
    if (src[edge] == totrim[i]) res = 1;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      res = calloc(s21_strlen(src) + 1, sizeof(char));
      int start = 0, end = s21_strlen(src);
      while (check_edges(src, trim_chars, start)) start++;
      if (start != end) {
        while (check_edges(src, trim_chars, end - 1)) end--;
        for (int i = 0; start < end; i++) {
          res[i] = src[start];
          start++;
        }
      } else {
        res[0] = '\0';
      }
    } else {
      res = s21_trim(src, "\t\n ");
    }
  }
  return res;
}

void s21_char_to_int(int *num, char ch) {
  *num *= 10;
  *num += (int)(ch - '0');
}

void s21_check_star(FORMAT *s_format, int *pres_or_width, int *num, char f_ch) {
  if (f_ch == '*') {
    if (*pres_or_width) {
      s_format->error = 1;
    } else {
      *pres_or_width = '*';
      s_format->star = 1;
    }
  } else {
    if (*pres_or_width == '*') {
      s_format->error = 1;
    } else {
      s21_char_to_int(num, f_ch);
    }
  }
}

int s21_parser(int ptr_f, const char *format, FORMAT *s_format) {
  ptr_f++;
  int num_p = 0;
  int num_w = 0;
  int count = 0;
  while (!s_format->spec) {
    if (s21_IS_SPEC(format[ptr_f])) {
      s_format->spec = format[ptr_f];
    } else if (s21_IS_LENGTH(format[ptr_f])) {
      if (!count) {
        s_format->length = format[ptr_f];
        count++;
      } else {
        if (s_format->length != format[ptr_f]) {
          s_format->error = 1;
        } else {
          s_format->double_len = 1;
        }
      }
    } else if (format[ptr_f] == '.') {
      s_format->point = 1;
    } else if (format[ptr_f] == '0' && !num_w && !s_format->point) {
      s_format->zero = 1;
    } else if (s_format->point && s21_IS_NUMERIC(format[ptr_f])) {
      s21_check_star(s_format, &s_format->precision, &num_p, format[ptr_f]);
    } else if (s21_IS_NUMERIC(format[ptr_f])) {
      s21_check_star(s_format, &s_format->width, &num_w, format[ptr_f]);
    } else if (format[ptr_f] == '-') {
      s_format->minus = 1;
    } else if (format[ptr_f] == '+') {
      s_format->plus = 1;
    } else if (format[ptr_f] == ' ') {
      s_format->space = 1;
    } else if (format[ptr_f] == '#') {
      s_format->sharp = 1;
    }
    ptr_f++;
  }
  if (s_format->precision != 42) s_format->precision = num_p;
  if (s_format->width != 42) s_format->width = num_w;

  return ptr_f;
}

void s21_reverse_string(char *str, int i) {
  str[i] = '\0';
  int left = 0;
  int right = i - 1;
  char temp;
  while (left < right) {
    temp = str[left];
    str[left++] = str[right];
    str[right--] = temp;
  }
}

void s21_un_to_char(FORMAT s_format, unsigned long long int num, char *buf,
                    int *i) {
  int flag = 1;
  while (flag) {
    int digit = 0;
    if (num >= 10) {
      digit = num % 10;
      num = (num - digit) / 10;
    } else {
      digit = num;
      flag = 0;
    }
    buf[*i] = (char)(digit + '0');
    (*i)++;
  }
  if (s_format.precision == 0 && num == 0 && s_format.point) buf[0] = '\0';
  buf[*i] = '\0';
}

void s21_int_to_char(FORMAT s_format, unsigned long long int num, char *buf,
                     int *i) {
  int flag = 1;
  if (num == 0 && s_format.spec != 'f' && !s_format.point) buf[*i] = '0';
  while (flag) {
    int digit = 0;
    if (num >= 10) {
      digit = num % 10;
      num = (num - digit) / 10;
    } else {
      digit = (int)num;
      flag = 0;
    }
    buf[*i] = (char)(digit + '0');
    (*i)++;
  }
  if (s_format.spec != 'f' && s_format.precision == 0 && num == 0 &&
      s_format.point)
    buf[0] = '\0';
  buf[*i] = '\0';
}

void s21_precision_int(FORMAT s_format, char *buf, int *i) {
  if (s_format.precision > 0) {
    while (*i < s_format.precision) {
      buf[*i] = '0';
      (*i)++;
    }
  }
}

void s21_make_width(FORMAT s_format, char *buf, int is_negative) {
  int len = 0;
  len = s21_strlen(buf);
  len += s_format.error;
  int edge = 0;
  int flag = 1;

  if ((s_format.spec != 'f' && s_format.point) ||
      (s_format.space && !s_format.zero))
    flag = 0;

  if (s_format.width > len) {
    buf[s_format.width + 1] = '\0';
    if (!s21_strchr("scuo\%", s_format.spec) && is_negative < 2) {
      if (flag && s_format.zero) {
        if (is_negative == 1 || s_format.plus || s_format.space) {
          edge++;
        }
      }
    }
    while (len >= edge) {
      buf[s_format.width--] = buf[len--];
    }
    for (; edge <= s_format.width; edge++) {
      if (s21_strchr("diuo", s_format.spec)) {
        if (s_format.zero && !s_format.point) {
          buf[edge] = '0';
        } else {
          buf[edge] = ' ';
        }
      }
      if (s21_strchr("fcs", s_format.spec) && is_negative < 3) {
        if (s_format.zero) {
          buf[edge] = '0';
        } else {
          buf[edge] = ' ';
        }
      }
      if (is_negative > 1) {
        buf[edge] = ' ';
      }
    }
  }
}

void s21_move_string(char *buf) {
  int pos = 0;
  pos = s21_strlen(buf);
  buf[pos + 1] = '\0';
  while (pos > 0) {
    buf[pos] = buf[pos - 1];
    pos--;
  }
}

void s21_make_flags(int is_negative, FORMAT s_format, char *buf) {
  int i = 0;
  if (!s21_strchr("scuo\%", s_format.spec)) {
    if (is_negative == 1 || is_negative == 4) {
      s21_move_string(buf);
      buf[i++] = '-';
    } else if (s_format.plus) {
      s21_move_string(buf);
      buf[i] = '+';
    } else if (s_format.space) {
      s21_move_string(buf);
      buf[i] = ' ';
    }
  }
  if (s_format.minus) {
    i = s21_strlen(buf);
    while (i < s_format.width) {
      buf[i++] = ' ';
    }
  }
}

void s21_int_to_string(char *buf, FORMAT s_format, long long int num) {
  int i = 0;
  int is_negative = 0;
  if (num < 0) {
    is_negative = 1;
    num *= -1;
  }
  s21_int_to_char(s_format, num, buf, &i);
  s21_precision_int(s_format, buf, &i);
  s21_reverse_string(buf, i);
  s21_make_flags(is_negative, s_format, buf);
  s21_make_width(s_format, buf, is_negative);
}

void s21_d_format(FORMAT s_format, va_list arg_list, char *buf) {
  if (!s_format.length) {
    int num = (int)va_arg(arg_list, int);
    s21_int_to_string(buf, s_format, num);
  } else if (s_format.length == 'l') {
    if (s_format.double_len) {
      long long int ll_num = va_arg(arg_list, long long int);
      s21_int_to_string(buf, s_format, ll_num);
    } else {
      long int l_num = (long int)va_arg(arg_list, long int);
      s21_int_to_string(buf, s_format, l_num);
    }
  } else if (s_format.length == 'h') {
    if (s_format.double_len) {
      signed char hh_num = (signed char)va_arg(arg_list, int);
      s21_int_to_string(buf, s_format, hh_num);
    } else {
      short int h_num = (short int)va_arg(arg_list, int);
      s21_int_to_string(buf, s_format, h_num);
    }
  }
}

void s21_c_format(va_list arg_list, FORMAT *s_format, char *buf) {
  if (s_format->length == 'l') {
    wchar_t wch = va_arg(arg_list, wchar_t);
    if (wch > 255) {
      s_format->wchar_error = -1;
    } else {
      buf[0] = wch;
    }
  } else {
    buf[0] = va_arg(arg_list, int);
  }
  buf[1] = '\0';
  if (!s21_strlen(buf)) {
    s_format->error++;
  }
  s21_make_flags(0, *s_format, buf);
  s21_make_width(*s_format, buf, 0);
}

void s21_s_format(FORMAT *s_format, va_list arg_list, char *buf) {
  if (s_format->length == 'l') {
    wchar_t *w_buf = va_arg(arg_list, wchar_t *);
    if (w_buf) {
      wcstombs(buf, w_buf, 512);
      if (*w_buf > 255) {
        s_format->wchar_error = -1;
      }
    } else {
      buf = s21_strcat(buf, "(null)");
    }
  } else {
    char *c_buf = va_arg(arg_list, char *);
    if (c_buf) {
      buf = s21_strcat(buf, c_buf);
    } else {
      buf = s21_strcat(buf, "(null)");
    }
  }
  int accuracy = 0;
  if (s_format->point) {
    accuracy = s_format->precision;
  } else {
    accuracy = s21_strlen(buf);
  }
  int i = 0;
  for (; i < accuracy; i++) {
    ;
  }
  while (buf[i] != '\0') {
    buf[i] = '\0';
    i++;
  }
  s21_make_flags(0, *s_format, buf);
  s21_make_width(*s_format, buf, 0);
}

void s21_percent_format(FORMAT s_format, char *buf) {
  s21_strcat(buf, "%");
  s21_make_flags(0, s_format, buf);
  s21_make_width(s_format, buf, 0);
}

void s21_ol_to_str(char *buf, unsigned long long num, FORMAT s_format) {
  int flag = 1;
  int i = 0;
  while (flag) {
    unsigned int digit;
    if (num > 7) {
      digit = num % 8;
      num = (num - digit) / 8;
    } else {
      digit = num;
      flag = 0;
    }
    buf[i++] = (char)(digit + '0');
  }
  if (s_format.sharp == 1) buf[i++] = '0';
  buf[i] = '\0';
  s21_precision_int(s_format, buf, &i);
  s21_reverse_string(buf, i);
  s21_make_flags(0, s_format, buf);
  s21_make_width(s_format, buf, 0);
}

void s21_o_format(FORMAT s_format, va_list input, char *str) {
  unsigned long int ld_num = 0;
  unsigned short int sd_num = 0;
  unsigned int num = 0;

  switch (s_format.length) {
    case 'h':
      sd_num = (unsigned short int)va_arg(input, unsigned int);
      s21_ol_to_str(str, sd_num, s_format);
      break;
    case 'l':
      ld_num = (unsigned long int)va_arg(input, unsigned long int);
      s21_ol_to_str(str, ld_num, s_format);
      break;
    default:
      num = va_arg(input, unsigned int);
      s21_ol_to_str(str, num, s_format);
      break;
  }
}

void s21_f_to_str(long double num, FORMAT s_format, char *buf) {
  int is_negative = 0;
  if (num < 0) {
    is_negative = 1;
    num *= -1;
  }
  if (num == s21_INF) {
    if (is_negative) {
      is_negative = 4;
    } else {
      is_negative = 3;
    }
    buf = s21_strcat(buf, "inf");
  } else if (num != num) {
    is_negative = 2;
    buf = s21_strcat(buf, "nan");
    s_format.spec = 's';
  } else {
    int i = 0;
    int accuracy = 0;
    if (s_format.point && s_format.precision >= 0) {
      accuracy = s_format.precision;
    } else {
      accuracy = 6;
    }
    if (num < 0) {
      is_negative = 1;
      num *= -1;
    }
    char buf_dec[256] = {0};
    long double pos_int = 0, dec = 0;
    long double p = pow(10, (accuracy));
    num = rintl(num * p) / p;
    dec = modfl(num, &pos_int);
    s21_int_to_char(s_format, rintl(pos_int), buf, &i);
    s21_reverse_string(buf, i);
    for (; buf[i]; i++) {
      ;
    }
    if (s_format.sharp || accuracy > 0) buf[i++] = '.';
    for (int i = 0; i < accuracy; i++) dec *= 10;
    i = 0;
    if (accuracy > 0) s21_int_to_char(s_format, rintl(dec), buf_dec, &i);
    s21_reverse_string(buf_dec, i);
    i = s21_strlen(buf_dec);
    for (int j = 0; i < accuracy; j++, i++) {
      s21_move_string(buf_dec);
      buf_dec[j] = '0';
    }
    buf_dec[i] = '\0';
    buf = s21_strcat(buf, buf_dec);
  }
  s21_make_flags(is_negative, s_format, buf);
  s21_make_width(s_format, buf, is_negative);
}

void s21_f_format(FORMAT s_format, va_list arg_list, char *buf) {
  if ((s_format.length == 'l' && s_format.double_len) ||
      s_format.length == 'L') {
    long double ld_num = (long double)va_arg(arg_list, long double);
    s21_f_to_str(ld_num, s_format, buf);
  } else {
    double d_num = (double)va_arg(arg_list, double);
    s21_f_to_str(d_num, s_format, buf);
  }
}

void s21_u_to_str(char *buf, FORMAT s_format, unsigned long long int num) {
  int i = 0;
  s21_un_to_char(s_format, num, buf, &i);
  s21_precision_int(s_format, buf, &i);
  s21_reverse_string(buf, i);
  s21_make_flags(0, s_format, buf);
  s21_make_width(s_format, buf, 0);
}

void s21_u_format(FORMAT s_format, va_list arg_list, char *buf) {
  if (!s_format.length) {
    unsigned int u_num = (unsigned int)va_arg(arg_list, unsigned int);
    s21_u_to_str(buf, s_format, u_num);
  } else if (s_format.length == 'l') {
    if (s_format.double_len) {
      unsigned long long int ull_num = va_arg(arg_list, unsigned long long int);
      s21_u_to_str(buf, s_format, ull_num);
    } else {
      unsigned long ul_num = (unsigned long)va_arg(arg_list, unsigned long int);
      s21_u_to_str(buf, s_format, ul_num);
    }
  } else if (s_format.length == 'h') {
    if (s_format.double_len) {
      unsigned char uc_num = (unsigned char)va_arg(arg_list, unsigned int);
      s21_u_to_str(buf, s_format, uc_num);
    } else {
      unsigned short us_num = (unsigned short)va_arg(arg_list, unsigned int);
      s21_u_to_str(buf, s_format, us_num);
    }
  }
}

void s21_reset_format(FORMAT *s_format) {
  s_format->spec = 0;
  s_format->space = 0;
  s_format->minus = 0;
  s_format->plus = 0;
  s_format->point = 0;
  s_format->width = 0;
  s_format->length = 0;
  s_format->double_len = 0;
  s_format->precision = 0;
  s_format->zero = 0;
  s_format->sharp = 0;
  s_format->star = 0;
}

void s21_format_string(FORMAT *s_format, va_list arg_list, char *buf) {
  switch (s_format->spec) {
    case 'c':
      s21_c_format(arg_list, s_format, buf);
      break;
    case 'i':
    case 'd':
      s21_d_format(*s_format, arg_list, buf);
      break;
    case 'f':
      s21_f_format(*s_format, arg_list, buf);
      break;
    case 's':
      s21_s_format(s_format, arg_list, buf);
      break;
    case 'u':
      s21_u_format(*s_format, arg_list, buf);
      break;
    case 'o':
      s21_o_format(*s_format, arg_list, buf);
      break;
    case '%':
      s21_percent_format(*s_format, buf);
      break;
    default:
      break;
  }
}

void s21_star_into_num(FORMAT *s_format, int *pres_or_width, va_list arg_list) {
  if (*pres_or_width == '*') {
    *pres_or_width = va_arg(arg_list, int);
    if (s_format->width < 0) {
      s_format->width *= -1;
      s_format->minus = 1;
    }
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg_list = {0};
  va_start(arg_list, format);
  int ptr_str = 0;
  int ptr_f = 0;
  int edge = 0;
  int flag = 0;
  s21_strcpy(str, "");
  FORMAT s_format = {0};
  while (format[ptr_f]) {
    if (format[ptr_f] == '%') {
      char *buf = s21_NULL;
      buf = calloc(1000, sizeof(char));
      if (buf) {
        s21_reset_format(&s_format);
        ptr_f = s21_parser(ptr_f, format, &s_format);
        if (s_format.spec) {
          s21_star_into_num(&s_format, &s_format.width, arg_list);
          s21_star_into_num(&s_format, &s_format.precision, arg_list);
          s21_format_string(&s_format, arg_list, buf);
          str = s21_strcat(str, buf);
          ptr_str = s21_strlen(str);
          if (s_format.error == 1 && !flag) {
            if ((!s_format.zero && s_format.width > 1 && !s_format.minus) ||
                (s_format.zero && !s_format.minus) || !s_format.width) {
              edge = ptr_str;
            }
            flag++;
          }
        }
      }
      free(buf);
    } else {
      str[ptr_str++] = format[ptr_f++];
    }
    str[ptr_str] = '\0';
  }
  va_end(arg_list);
  int bytes = s21_strlen(str);
  if (!(s_format.minus && s_format.width)) {
    bytes += s_format.error;
  }
  if (s_format.wchar_error < 0) {
    s_format.error = 1;
    edge = 0;
    bytes = s_format.wchar_error;
  }
  if (s_format.error) {
    while (ptr_str > edge) {
      str[edge++] = '\0';
    }
  }
  return bytes;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  s21_size_t n_buffer = s21_strlen(str);

  int *num;
  int count = 0;
  long length;
  int star_flag = 0;
  while (*format) {
    int h = 0;
    int l = 0;
    int L = 0;

    length = -1;
    star_flag = 0;

    if (*format == '%') {
      format++;

      if (*format >= '0' && *format <= '9') {
        format = get_int((char *)format, &length, -1);  //
      } else if (*format == '*') {
        star_flag = 1;
        format++;
      }

      if (*format == 'h') {
        h = 1;
        format++;
      } else if (*format == 'l') {
        l = 1;
        format++;
      } else if (*format == 'L') {
        L = 1;
        format++;
      }

      switch (*format) {
        case 'c':
          if (star_flag) {
            int tmp;
            get_char((char **)&str, &tmp, length);
          } else {
            get_char((char **)&str, va_arg(args, int *), length);
          }
          count++;
          break;
        case 's':
          skip_spaces((char **)&str);
          if (star_flag) {
            char *tmp = malloc(sizeof(char));
            get_string((char **)&str, tmp, length);
            free(tmp);
          } else if (l == 1) {
            string_to_wchar((char **)&str, va_arg(args, wchar_t *), length);
          } else {
            get_string((char **)&str, va_arg(args, char *), length);
          }
          count++;
          break;
        case 'i':
          skip_spaces((char **)&str);
          if (star_flag) {
            long tmp;
            custom_atoi((char **)&str, &tmp, length);
          } else {
            custom_atoi((char **)&str, (long *)(va_arg(args, int *)), length);
          }
          count++;
          break;
        case 'u':
        case 'd':
          skip_spaces((char **)&str);
          if (star_flag) {
            long tmp;
            str = get_int((char *)str, &tmp, length);
          } else {
            str = get_int((char *)str, (long *)(va_arg(args, short *)), length);
          }
          count++;
          break;
        case 'E':
        case 'e':
        case 'g':
        case 'G':
        case 'f':
          skip_spaces((char **)&str);
          if (star_flag) {
            double tmp;
            get_float((char **)&str, &tmp, length);
          } else if (l == 1 || h == 1 || L == 1) {
            get_float((char **)&str, va_arg(args, double *), length);
          } else {
            float *l = va_arg(args, float *);
            double tmp;
            get_float((char **)&str, &tmp, length);
            *l = (float)tmp;
          }

          count++;
          break;
        case 'o':
          skip_spaces((char **)&str);
          if (star_flag) {
            unsigned long tmp;
            get_octa((char **)&str, &tmp, length);
          } else {
            get_octa((char **)&str, va_arg(args, unsigned long *), length);
          }
          count++;
          break;
        case 'x':
        case 'X':
          skip_spaces((char **)&str);
          if (star_flag) {
            unsigned long tmp;
            get_hexa((char **)&str, &tmp, length);
          } else {
            get_hexa((char **)&str, va_arg(args, unsigned long *), length);
          }

          count++;
          break;
        case 'n':
          if (!star_flag) {
            num = va_arg(args, int *);
            *num = s21_strlen(str) - n_buffer;
            *num *= -1;
            count++;
          }
          break;
        case 'p':
          skip_spaces((char **)&str);
          if (star_flag) {
            void *tmp;
            get_ptr((char **)&str, &tmp, length);
          } else {
            get_ptr((char **)&str, va_arg(args, void **), length);
          }
          count++;
          break;
      }
    }
    format++;
  }
  va_end(args);
  return count;
}

void get_string(char **src, char *dest, int length) {
  char *q = *src;
  s21_size_t i = 0;
  if (length == -1)
    length = s21_strlen(*src);
  else if (length == 0)
    return;
  while (*q != ' ' && *q != '\0' && length != 0) {
    dest[i] = *q;
    i++;
    q++;
    length--;
  }
  dest[i] = '\0';
  *src = q;
}

void get_char(char **src, int *c, int length) {
  if (length == 0) return;
  char *q = *src;
  *c = q[0];
  q++;
  *src = q;
}

char *get_int(char *src, long *num, int length) {
  int minus = 0;
  if (length == -1) {
    length = s21_strlen(src);
  } else if (length == 0) {
    return src;
  }
  if (*src == '-') {
    minus = 1;
    src++;
    length--;
  } else if (*src == '+') {
    src++;
    length--;
  }

  if (length > 0) {
    *num = 0;
  }

  *num = 0;  // added by doz

  while (*src >= '0' && *src <= '9' && length > 0) {
    *num *= 10;
    *num += *src - 48;
    src++;
    length--;
  }

  if (minus == 1) *num *= -1;

  return src;
}

void custom_atoi(char **src, long *num, int length) {
  int minus = 0;
  char *q = *src;
  if (length == -1)
    length = s21_strlen(*src);
  else if (length == 0)
    return;
  if (*q == '-') {
    minus = 1;
    q++;
    length--;
  } else if (*q == '+') {
    q++;
    length--;
  }
  if (*q == '0') {
    q++;
    length--;
    // int n;
    int len = 0;
    if (*q == 'x') {
      q++;
      length--;
      char *blank = "0123456789ABCDEF";
      if (length > 0) *num = 0;
      while (get_character_index(blank, *q) != -1 && length > 0) {
        len++;
        q++;
        length--;
      }
      q -= len;
      for (; len > 0; len--) {
        *num += get_character_index(blank, *q) * pow(16, len - 1);
        q++;
      }
    } else {
      char *blank = "01234567";
      if (length > 0) *num = 0;
      while (get_character_index(blank, *q) != -1 && length > 0) {
        len++;
        q++;
        length--;
      }
      q -= len;
      for (; len > 0; len--) {
        *num += get_character_index(blank, *q) * pow(8, len - 1);
        q++;
      }
    }
  } else {
    if (length > 0) *num = 0;
    while (*q >= '0' && *q <= '9' && length > 0) {
      *num *= 10;
      *num += *q - 48;
      q++;
      length--;
    }
  }
  *src = q;
  if (minus == 1) *num *= -1;
}

int get_character_index(char *src, char c) {
  int index = -1;
  for (int i = 0; i < (long long)s21_strlen(src); i++) {
    if (src[i] == c) {
      index = i;
      break;
    }
  }
  return index;
}

void get_float(char **src, double *num, int length) {
  char *q = *src;
  int digital_after_dot = 1;
  int minus = 0;
  if (length == -1)
    length = s21_strlen(*src);
  else if (length <= 0)
    *num = 0;
  if (*q == '-') {
    minus = 1;
    q++;
    length--;
  } else if (*q == '+') {
    q++;
    length--;
  }

  if (length > 0) *num = 0;

  while (*q >= '0' && *q <= '9' && length > 0) {
    *num *= 10;
    *num += *q - 48;
    q++;
    length--;
  }

  if (*q == '.') {
    q++;
    length--;
    while (*q >= '0' && *q <= '9' && length > 0) {
      *num += (*q - 48) * pow(10, -digital_after_dot);
      q++;
      length--;
      digital_after_dot++;
    }
  }
  if (*q == 'e' || *q == 'E') {
    q++;
    length--;
    long count = 0;
    q = get_int(q, &count, length);
    if (count != 0) *num *= pow(10, count);
  }
  *src = q;
  if (minus == 1) *num *= -1;
}

void get_octa(char **src, unsigned long *num, int length) {
  char *q = *src;
  int minus = 0;
  if (length == -1)
    length = s21_strlen(*src);
  else if (length == 0)
    return;
  if (*q == '-') {
    minus = 1;
    q++;
    length--;
  } else if (*q == '+') {
    q++;
    length--;
  }
  int len = 0;
  char *blank = "01234567";
  if (length > 0) *num = 0;
  while (get_character_index(blank, *q) != -1 && length > 0) {
    len++;
    q++;
    length--;
  }
  q -= len;
  for (; len > 0; len--) {
    *num += get_character_index(blank, *q) * pow(8, len - 1);
    q++;
  }
  if (minus == 1) *num *= -1;
  *src = q;
}

void get_hexa(char **src, unsigned long *num, int length) {
  char *q = *src;
  int minus = 0;

  if (length == -1)
    length = s21_strlen(*src);
  else if (length == 0)
    return;
  if (*q == '-') {
    minus = 1;
    q++;
    length--;
  } else if (*q == '+') {
    q++;
    length--;
  }

  int len = 0;
  char *upper_blank = "0123456789ABCDEF";
  char *lower_blank = "0123456789abcdef";
  if (length > 0) *num = 0;
  while (get_character_index(upper_blank, *q) != -1 &&
         (length > 0 || get_character_index(lower_blank, *q) != -1) &&
         length > 0) {
    len++;
    q++;
    length--;
  }
  q -= len;
  for (; len > 0; len--) {
    if (*q >= 'a' && *q <= 'f')
      *num += get_character_index(lower_blank, *q) * pow(16, len - 1);
    else
      *num += get_character_index(upper_blank, *q) * pow(16, len - 1);
    q++;
  }
  *src = q;
  if (minus == 1) *num *= -1;
}

void skip_spaces(char **str) {
  char *q = *str;
  while (*q == ' ') {
    q++;
  }

  *str = q;
}

void string_to_wchar(char **src, wchar_t *str, int length) {
  char *tmp = malloc(sizeof(char));
  get_string(src, tmp, length);

  int len = 0;
  while (*tmp) {
    *str = *tmp;
    str++;
    tmp++;
    len++;
  }
  *str = '\0';
  str -= len;
  free(tmp);
}

void get_ptr(char **src, void **ptr, int length) {
  unsigned long buffer;
  get_hexa(src, &buffer, length);
  *((int *)ptr) = buffer;
}

// int main(void) {
//  char arr1[200];
//   char arr2[200];
//   double a1 = -123.123213, a2;
//   int r1, r2;
//   r1 = s21_sprintf(arr1,"%-+  0.*f", -20, a1);
//   r2 = sprintf(arr2,"%-+  0.*f", -20, a1);
//   printf("%s\n%s\n", arr1, arr2);
//   printf("%d\n%d\n", r1, r2);
// void  Std_Lib = sscanf("12345", "%ld", &ld1);
//  Our_Lib = s21_sscanf("12345", "%ld", &ld2);
// }