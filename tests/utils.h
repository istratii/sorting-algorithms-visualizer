
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>

#define ASC_DES (0x3)
#define ASC (0x1)
#define DES (0x2)
#define CHECK_ASC(Mode) ((Mode)&ASC)
#define CHECK_DES(Mode) ((Mode)&DES)

int check(void (*sort)(int *, int, int (*comp)(int, int)), char *algname, int mode);

#endif /* ! UTILS_H */
