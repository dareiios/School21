#include "struct.h"

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    struct flag flags = {0};
    char res;
    char **forPattern = InitArray();
    char **files = InitArray();
    int value_e_array = 0;
    int value_f_array = 0;
    FILE *f = 0;
    char *line = NULL;
    size_t len = 0;
    int status = 0;
    int cflags = 0;
    int commonCount = 0;
    int flagForC = 0;
    int commonCountForN = 0;
    int filesCountForPrint = 0;
    int cForV = 0;
    int fs = 0;
    int forl = 0;
    int check = 0;
    while ((res = getopt_long(argc, argv, "e:ivclnf:hso", long_options,
                              NULL)) != -1) {
      if (SelectionFlag(&flags, res, &forPattern, optarg, &value_e_array, f,
                        line, &len) == 1) {
        check = 1;
        fprintf(stderr, "Неверный флаг\n");
      }
    }
    if (!check) {
      Extra(flags, &cflags, &forPattern, &optind, &value_e_array, argv, argc,
            &files, &value_f_array);
      MainPart(value_f_array, f, files, flags, filesCountForPrint, forPattern,
               cflags, line, value_e_array, &cForV, fs, &commonCountForN,
               &commonCount, &flagForC, &forl, len, status);
    }
    memory(value_e_array, forPattern, value_f_array, files);
  } else {
    printf("kaka");
  }
  return 0;
}

void memory(int value_e_array, char **forPattern, int value_f_array,
            char **files) {
  for (int i = 0; i < value_e_array; i++) {
    free(forPattern[i]);
  }
  free(forPattern);
  for (int i = 0; i < value_f_array; i++) {
    free(files[i]);
  }
  free(files);
}

void MasAdd(char ***array, char *string, int *value) {
  int n = strlen(string);
  (*array) = realloc((*array), ((*value) + 1) * sizeof(char *));
  (*array)[*value] = (char *)calloc(n + 1, sizeof(char));
  strcpy((*array)[*value], string);
  (*value)++;
}

char **InitArray(void) {
  char **array = calloc(0, sizeof(char *));
  return array;
}

void FlagV(struct flag f, int stat, int *cforv, int countprint, char *l,
           char **filess, int i) {
  if (f.v == 1) {
    if (stat != 0) {
      (*cforv)++;
      if (f.c == 0) {
        if (countprint == 1 && f.h == 0) {
          printf("%s:", filess[i]);
          // o=1;
        }
        printf("%s", l);
      }
      if (!strchr(l, '\n')) {
        O(1);
        // o=1;
      }
    }
  }
}

void O(int o) {
  if (o == 1) {
    printf("\n");
  }
}

int FlagF(struct flag f, int stat, int countprint, char *l, char **filess,
          int i) {
  int _break = 0;
  if (f.f == 1 && f.o == 0 && f.n == 0) {
    if (stat == 0) {
      if (countprint == 1 && f.h == 0) {
        printf("%s:", filess[i]);
      }
      printf("%s", l);
      _break = 1;
    }
  }
  return _break;
}

int FlagS(struct flag f, int stat, int ffs, char *l) {
  int _break = 0;
  if (f.s == 1) {
    if (ffs == 1) {
      _break = 1;
    } else {
      if (stat == 0) {
        printf("%s", l);
      }
    }
  }
  return _break;
}

int FlagN(struct flag f, int stat, int *countN, int countprint, char *l,
          char **filess, int i) {
  int _break = 0;
  if (f.n == 1 || (f.n == 1 && f.f == 1)) {
    (*countN)++;
    if (stat == 0 && f.o == 0) {
      if (countprint == 1 && f.h == 0) {
        printf("%s:", filess[i]);
      }
      printf("%d:%s", *countN, l);
      _break = 1;
    }
  }
  return _break;
}

int FlafE(struct flag f, int stat, int countprint, char *l, char **filess,
          int i) {
  int _break = 0;
  if (f.e == 1 && f.l == 0) {
    if (stat == 0 && f.c == 0 && f.v == 0 && f.n == 0 && f.o == 0) {
      if (countprint == 1 && f.h == 0) {
        printf("%s:", filess[i]);
      }
      printf("%s", l);
      _break = 1;
    }
  }
  return _break;
}

void FlagC(struct flag f, int stat, int *comCount, int *fForC) {
  if (f.c == 1) {
    if (stat == 0) {
      (*comCount)++;
    }
    *fForC = 1;
  }
}

void ExtraFlagForC(struct flag f, int countprint, char **filess, int comCount,
                   int forV, int i) {
  if (f.v == 0) {
    if (countprint == 1 && f.h == 0) {
      printf("%s:", filess[i]);
    }
    printf("%d\n", comCount);
  } else {
    if (countprint == 1 && f.h == 0) {
      printf("%s:", filess[i]);
    }
    printf("%d\n", forV);
  }
}

void FlagL(struct flag f, int stat, int *forL) {
  if (f.l == 1) {
    if (stat == 0) {
      // y=1;
      if (f.v == 0 || f.i == 0) {
        *forL = 1;
      }
    }
  }
}

void FlagH(struct flag f, int stat, char *l) {
  if (f.h == 1 && f.v == 0 && f.c == 0 && f.n == 0 && f.o == 0) {
    if (stat == 0) {
      printf("%s", l);
    }
  }
}

void WithNoFlags(struct flag f, int stat, char *l, int countprint,
                 char **filess, int i) {
  if (f.e == 0 && f.i == 0 && f.v == 0 && f.c == 0 && f.l == 0 && f.n == 0 &&
      f.h == 0 && f.f == 0 && f.s == 0 && f.o == 0) {
    if (stat == 0) {
      if (countprint == 1) {
        printf("%s:", filess[i]);
      }
      printf("%s", l);
    }
  }
}
void FlagO(struct flag f, char *l, int countprint, int i, int comN,
           char **files, regex_t ress) {
  regmatch_t pmatch[1];
  const size_t nmatch = 1;
  if (f.o == 1 && f.v == 0) {
    int start = 0;
    char *str = l;
    while (regexec(&ress, str, nmatch, pmatch, 0) == 0) {
      if (countprint == 1 && f.h == 0 && l == str) {
        printf("%s:", files[i]);
      }
      start = pmatch[0].rm_eo;
      for (int k = pmatch[0].rm_so; k < pmatch[0].rm_eo; k++) {
        if (f.n == 1) {
          printf("%d:%c", comN, str[k]);
        } else
          printf("%c", str[k]);
      }
      printf("\n");
      str += start;
    }
  }
}

int checkk(int value_f_array, struct flag flags) {
  int proverka = 0;
  if (value_f_array > 1) {
    if (flags.l == 0 ||
        (flags.l == 1 && (flags.e == 1 || flags.i == 1 || flags.v == 1 ||
                          flags.c == 1 || flags.n == 1 || flags.h == 1 ||
                          flags.f == 1 || flags.s == 1 || flags.o == 1)))
      proverka = 1;
  }
  return proverka;
}

int func(struct flag flags, int filesCountForPrint, char **files, int i,
         char *line, int status, regex_t *ress, int fs, int *commonCountForN) {
  int _break = 0;
  if (FlagF(flags, status, filesCountForPrint, line, files, i) == 1) {
    regfree(ress);
    _break = 1;
  }
  if (FlagS(flags, status, fs, line) == 1) {
    regfree(ress);
    _break = 1;
  }
  if (FlagN(flags, status, commonCountForN, filesCountForPrint, line, files,
            i) == 1) {
    regfree(ress);
    _break = 1;
  }
  if (FlafE(flags, status, filesCountForPrint, line, files, i) == 1) {
    regfree(ress);
    _break = 1;
  }
  return _break;
}
void AllFlags(int value_f_array, struct flag flags, int filesCountForPrint,
              char **forPattern, int cflags, char *line, FILE *f,
              int value_e_array, int *cForV, char **files, int i, int fs,
              int *commonCountForN, int *commonCount, int *flagForC, int *forl,
              size_t len, int status) {
  regmatch_t pmatch[1];
  const size_t nmatch = 1;
  regex_t ress;
  ssize_t read = 0;
  if (checkk(value_f_array, flags) == 1) {
    filesCountForPrint = 1;
  }
  while ((read = getline(&line, &len, f)) != -1) {
    for (int j = 0; j < value_e_array; j++) {
      regcomp(&ress, forPattern[j], cflags);
      status = regexec(&ress, line, nmatch, pmatch, 0);
      FlagV(flags, status, cForV, filesCountForPrint, line, files, i);
      if (func(flags, filesCountForPrint, files, i, line, status, &ress, fs,
               commonCountForN) == 1)
        break;
      FlafI(flags, status, filesCountForPrint, line, files, i);
      FlagC(flags, status, commonCount, flagForC);
      FlagL(flags, status, forl);
      FlagH(flags, status, line);
      FlagO(flags, line, filesCountForPrint, i, *commonCountForN, files, ress);
      WithNoFlags(flags, status, line, filesCountForPrint, files, i);
      regfree(&ress);
    }
  }
  free(line);
  if (*flagForC == 1)
    ExtraFlagForC(flags, filesCountForPrint, files, *commonCount, *cForV, i);
  if (*forl == 1) {
    printf("%s\n", files[i]);
  }
  Dopolnenie(commonCountForN, commonCount, cForV, forl);
  fclose(f);
}

void Dopolnenie(int *commonCountForN, int *commonCount, int *cForV, int *forl) {
  *commonCountForN = 0;
  *cForV = 0;
  *forl = 0;
  *commonCount = 0;
}

void FlafI(struct flag f, int stat, int countprint, char *l, char **filess,
           int i) {
  if (f.i == 1) {
    if (stat == 0 && f.v == 0 && f.c == 0 && f.l == 0 && f.n == 0 && f.h == 0 &&
        f.o == 0) {
      if (countprint == 1 && f.h == 0) {
        printf("%s:", filess[i]);
      }
      printf("%s", l);
      if (!strchr(l, '\n')) {
        O(1);
      }
    }
  }
}

void MainPart(int value_f_array, FILE *f, char **files, struct flag flags,
              int filesCountForPrint, char **forPattern, int cflags, char *line,
              int value_e_array, int *cForV, int fs, int *commonCountForN,
              int *commonCount, int *flagForC, int *forl, size_t len,
              int status) {
  for (int i = 0; i < value_f_array; i++) {
    if ((f = fopen(files[i], "r")) == NULL) {
      if (flags.s == 0) {
        fprintf(stderr, "grep: %s: No such file or directory\n", files[i]);
      }

    } else {
      AllFlags(value_f_array, flags, filesCountForPrint, forPattern, cflags,
               line, f, value_e_array, cForV, files, i, fs, commonCountForN,
               commonCount, flagForC, forl, len, status);
    }
  }
}

void Extra(struct flag flags, int *cflags, char ***forPattern, int *optind,
           int *value_e_array, char *argv[], int argc, char ***files,
           int *value_f_array) {
  if (flags.i == 1) {
    *cflags = REG_ICASE;
  }

  if (!flags.e && !flags.f) {
    MasAdd(forPattern, argv[*optind], value_e_array);
    (*optind)++;
  }

  for (int j = *optind; j < argc; j++) {
    MasAdd(files, argv[j], value_f_array);
  }
}

int SelectionFlag(struct flag *flags, char res, char ***paterns, char *optarg,
                  int *value_e_array, FILE *f, char *line, size_t *len) {
  int check = 0;
  ssize_t read = 0;
  if (res == 'e') {
    flags->e = 1;
    MasAdd(paterns, optarg, value_e_array);
  } else if (res == 'i') {
    flags->i = 1;
  } else if (res == 'v') {
    flags->v = 1;
  } else if (res == 'c') {
    flags->c = 1;
  } else if (res == 'l') {
    flags->l = 1;
  } else if (res == 'n') {
    flags->n = 1;
  } else if (res == 'f') {
    flags->f = 1;
    if ((f = fopen(optarg, "r")) == NULL) {
      fprintf(stderr, "%s: No such file or directory\n", optarg);
    } else {
      while ((read = getline(&line, len, f)) != -1) {
        MasAdd(paterns, line, value_e_array);
      }
      free(line);
    }
  } else if (res == 'h') {
    flags->h = 1;
  } else if (res == 's') {
    flags->s = 1;
  } else if (res == 'o') {
    flags->o = 1;
  } else {
    //неверный флаг
    check = 1;
  }
  return check;
}
