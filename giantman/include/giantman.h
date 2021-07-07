/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** header file
*/

#ifndef _GIANTMAN_H_
#define _GIANTMAN_H_

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    unsigned char len;
    unsigned short int input_pointer;
    unsigned short int pointer_pos;
    unsigned int comp;
    unsigned int pos;
    unsigned int pointer_offset;
    unsigned int uncompressed_size;
} decompress_t;

#endif /* !_GIANTMAN_H_ */
