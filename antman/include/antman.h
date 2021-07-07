/*
** EPITECH PROJECT, 2021
** antman
** File description:
** header file
*/

#ifndef _ANTMAN_H_
#define _ANTMAN_H_

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define XBREAK(x) if (x == 15) break
#define CMPINITSTART(x, y, z) x = 4; y = 4; z = 0
#define CMPINITLOW(x, y) x = 0; y = 0
#define CMPINITMID(x, y, a, b) x = a - b; y = a
#define CMPINITDMID(w, x, y, z) w = y; x = z
#define SHIFTED (cmp.pointer_pos << 4)
#define CMPINITUPN(x) x = SHIFTED | (cmp.len - 1); cmp.bak = (cmp.pos - 1)
#define CMPINITUPN_TWO(x) x = SHIFTED | cmp.len; cmp.bak = cmp.pos
#define LAST_ASSIGNEMENT(x) *((unsigned int *) ((x) + cmp.comp)) \
    = cmp.out; \
    cmp.comp = cmp.comp + 2; \
    *(compressed_text + cmp.comp++) = *(uncompressed_text + cmp.bak); \
    cmp.out_len = cmp.out_len + 3
#define INTER_LEN(x) CMPINITDMID(x, \
    cmp.len, cmp.buf_pos, cmp.buf_len); XBREAK(cmp.len)
#define GLOBAL_FOR *((unsigned int *) compressed_text) \
    = uncompressed_size; \
    cmp.pos < uncompressed_size; \
    ++cmp.pos
#define NESTED_FOR_ONE cmp.buf_pos = 1; \
    (cmp.buf_pos < MAX_BUF) && (cmp.buf_pos <= cmp.pos); \
    ++cmp.buf_pos
#define NESTED_FOR_TWO cmp.buf_len = 0; \
    uncompressed_text[cmp.go_head++] == uncompressed_text[cmp.go_back++]; \
    ++cmp.buf_len
#define FOR_NESTED(x) for (NESTED_FOR_TWO) XBREAK(x)
static const int MAX_BUF = 4096;

typedef struct {
    unsigned char len;
    unsigned char buf_len;
    unsigned short int pointer_pos;
    unsigned short int buf_pos;
    unsigned short int out;
    unsigned int comp;
    unsigned int out_len;
    unsigned int pos;
    unsigned int bak;
    unsigned int go_back;
    unsigned int go_head;
} compress_t;

#endif /* !_ANTMAN_H_ */
