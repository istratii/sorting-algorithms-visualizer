
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>

#define MODE_BOTH (0x3)
#define MODE_ASC (0x1)
#define MODE_DES (0x2)
#define PRED_ASC(Mode) ((Mode) & (MODE_ASC))
#define PRED_DES(Mode) ((Mode) & (MODE_DES))

int check(void (*sort)(int *, int, int (*cmp)(int, int)), int mode);

#endif /* ! UTILS_H */
