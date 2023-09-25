#ifndef SRC_STRUCT_H_
#define SRC_STRUCT_H_
#include <stdio.h>
#include <getopt.h>
struct flag {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
};
struct option long_options[] = {
    {"number-nonblank", no_argument, 0, 'b'},
    {"number", no_argument, 0, 'n'},
    {"squeeze-blank", no_argument, 0, 's'},
    {"show-ends", no_argument, 0, 'E'},
    {"show-tabs", no_argument, 0, 'T'},
    {"show-nonprinting", no_argument, 0, 'v'}
    
};

int SelectionFlag(struct flag *f, char c);
int ReadFlags(int argc, char *argv[], struct flag *f);
void FilePrint(FILE *ifp, FILE *ofp);
void MainPart(int argc, char* argv[],  FILE* fl, struct flag f);
void AllFlags(struct flag f, FILE* fl);
int sFlag(struct flag f, int* flagForS, char memory, char c, int* countEnter );
void bFlag(struct flag f, int flagForS, int* count_lines, int* start, char c);
void nFlag(struct flag f, int* count_lines, int* start, char memory);
void eFlag(struct flag f, char c);
int tFlag(struct flag f, char c);
int vFlag(struct flag f, char c);
#endif  // SRC_STRUCT_H_
