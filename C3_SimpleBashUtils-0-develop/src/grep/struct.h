#ifndef SRC_STRUCT_H_
#define SRC_STRUCT_H_
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
struct flag {
    int e;
    int i;
    int c;
    int l;
    int v;
    int n;
    
    int h;
    int s;
    int f;
    int o;
};
struct option long_options[] = {};


void MasAdd(char ***array,  char *string, int* value);
char **InitArray(void);
void memory(int value_e_array, char** forPattern, int value_f_array, char** files);
void FlagV(struct flag f, int stat, int* cforv, int countprint, char* l, char** filess, int i);
void O(int o);
int FlagF(struct flag f, int stat,int countprint, char* l, char** filess, int i);
int FlagS(struct flag f, int stat, int ffs, char* l );
int FlagN(struct flag f, int stat, int* countN,int countprint,char* l, char** filess, int i );
int FlafE(struct flag f, int stat,int countprint,char* l, char** filess, int i );
void FlafI(struct flag f, int stat,int countprint,char* l, char** filess, int i);
void FlagC(struct flag f, int stat, int* comCount, int *fForC);
void ExtraFlagForC(struct flag f,int countprint, char** filess , int comCount, int forV, int i);
void FlagL(struct flag f, int stat, int* forL);
void FlagH(struct flag f, int stat, char* l);
void WithNoFlags(struct flag f, int stat, char* l, int countprint, char** filess, int i);
void FlagO(struct flag f, char* l, int countprint, int i, int comN, char** files, regex_t ress);
void AllFlags(int value_f_array, struct flag flags, int filesCountForPrint, char** forPattern, int cflags,  char* line, FILE* f, int value_e_array, int* cForV, char** files, int i, int fs, int* commonCountForN, int* commonCount, int* flagForC, int* forl, size_t len, int status);
int func(struct flag flags, int filesCountForPrint,char **files, int i,char *line, int status, regex_t *ress,int fs, int *commonCountForN);
int checkk(int value_f_array, struct flag flags);
void Dopolnenie(int *commonCountForN, int *commonCount,int *cForV,  int *forl);
void MainPart(int value_f_array, FILE* f, char** files, struct flag flags, int filesCountForPrint, char** forPattern, int cflags,  char* line,int value_e_array, int* cForV, int fs, int* commonCountForN, int* commonCount, int* flagForC, int* forl, size_t len, int status);
void Extra(struct flag flags, int* cflags, char*** forPattern, int* optind, int* value_e_array, char* argv[], int argc, char*** files, int* value_f_array );
int SelectionFlag(struct flag* flags, char res, char*** paterns, char* optarg, int* value_e_array, FILE* f, char* line, size_t* len);
#endif  // SRC_STRUCT_H_
