#include "struct.h"

int main(int argc, char *argv[]) {
  if (argc > 1) {
    FILE *fl = NULL;
    struct flag flags = {0};
    //чтобы не печатался файл после ошибки
    if (ReadFlags(argc, argv, &flags) == 1) {
      fprintf(stdout, "Неверный флаг");
    } else {
      MainPart(argc, argv, fl, flags);
    }

  } else {
    FilePrint(stdin, stdout);
  }
  return 0;
}

// changeFlags
int SelectionFlag(struct flag *f, char c) {
  int check = 0;
  if (c == 'b') {
    f->b = 1;
  } else if (c == 'e') {
    f->e = 1;
    f->v = 1;
  } else if (c == 'E') {
    f->e = 1;
  } else if (c == 'T') {
    f->t = 1;
  } else if (c == 'n') {
    f->n = 1;
  } else if (c == 's') {
    f->s = 1;
  } else if (c == 't') {
    f->t = 1;
    f->v = 1;
  } else if (c == 'v') {
    f->v = 1;
  } else {
    //неверный флаг
    check = 1;
  }
  return check;
}

// parser
int ReadFlags(int argc, char *argv[], struct flag *f) {
  int res;
  int _default = 0;
  while ((res = getopt_long(argc, argv, "+benstvET", long_options, NULL)) !=
         -1) {
    if (SelectionFlag(f, res) == 1) {
      _default = 1;
    }
  }
  return _default;
}

// filecopy
void FilePrint(FILE *ifp, FILE *ofp) {
  int c;
  while ((c = getc(ifp)) != EOF) {
    putc(c, ofp);
  }
}

// catFunction главная чвсть реализации кэт
void MainPart(int argc, char *argv[], FILE *fl, struct flag f) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      if ((fl = fopen(argv[i], "r")) == NULL) {
        fprintf(stderr, "%s: No such file or directory\n", argv[0]);
      } else {
        AllFlags(f, fl);
      }
    }
  }
}
// formatter
void AllFlags(struct flag f, FILE *fl) {
  char c = '\n';
  char memory = '\n';
  int countEnter = 0;
  int count_lines = 0;
  int start = 0;
  while ((c = getc(fl)) != EOF) {
    //нужно обнуление именно для каждого символа
    int flagForS = 0;

    if (sFlag(f, &flagForS, memory, c, &countEnter) == 1) {
      continue;
    }
    bFlag(f, flagForS, &count_lines, &start, c);
    nFlag(f, &count_lines, &start, memory);
    eFlag(f, c);
    if (tFlag(f, c) == 1) {
      continue;
    }
    if (vFlag(f, c) == 1) {
      continue;
    }
    //нужно чтобы обнулилось в любом случае(если флаг не сработает, то
    //переменная останется  равная 1)
    if (c == '\n') {
      start = 0;
    }
    putchar(c);
    memory = c;
  }
  fclose(fl);
}

int sFlag(struct flag f, int *flagForS, char memory, char c, int *countEnter) {
  int _continue = 0;
  if (f.s == 1) {
    if (memory == '\n' && c == '\n') {
      (*countEnter)++;
      *flagForS = 1;
    } else {
      (*countEnter) = 0;
    }
    if (*countEnter > 1 && *flagForS) {
      _continue = 1;
    }
  }
  return _continue;
}

void bFlag(struct flag f, int flagForS, int *count_lines, int *start, char c) {
  if (f.b == 1 && !flagForS) {
    if (c != '\n') {
      if (*start == 0) {
        (*count_lines)++;
        printf("%6d\t", *count_lines);
        *start = 1;
      }
    } else {
      *start = 0;
    }
  }
}
void nFlag(struct flag f, int *count_lines, int *start, char memory) {
  if (f.n == 1 && f.b == 0) {
    if (memory == '\n') {
      if (*start == 0) {
        (*count_lines)++;
        printf("%6d\t", *count_lines);
        *start = 1;
      }
    } else {
      *start = 0;
    }
  }
}

void eFlag(struct flag f, char c) {
  if (f.e == 1) {
    if (c == '\n') {
      putchar('$');
    }
  }
}

int tFlag(struct flag f, char c) {
  int _continue = 0;
  if (f.t == 1) {
    if (c == '\t') {
      printf("^I");
      _continue = 1;
    }
  }
  return _continue;
}

int vFlag(struct flag f, char c) {
  int _continue = 0;
  if (f.v == 1) {
    if ((c >= 0 && c <= 31) && (c != 10) && (c != 9)) {
      printf("^%c", c + 64);
      _continue = 1;
    } else if (c == 127) {
      printf("^?");
      _continue = 1;
    }
  }
  return _continue;
}
