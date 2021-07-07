/*
** EPITECH PROJECT, 2021
** main
** File description:
** main for antman
*/

#include "antman.h"

static unsigned int my_compression(unsigned char *uncompressed_text,
    unsigned int uncompressed_size, unsigned char *compressed_text)
{
    compress_t cmp;

    CMPINITSTART(cmp.comp, cmp.out_len, cmp.pos);
    for (GLOBAL_FOR) {
            CMPINITLOW(cmp.pointer_pos, cmp.len);
        for (NESTED_FOR_ONE) {
            CMPINITMID(cmp.go_back, cmp.go_head, cmp.pos, cmp.buf_pos);
            FOR_NESTED(cmp.buf_len);
            if (cmp.buf_len > cmp.len) {
                INTER_LEN(cmp.pointer_pos);
            }
        }
        cmp.pos = cmp.pos + cmp.len;
        if (cmp.len && (cmp.pos == uncompressed_size)) {
            CMPINITUPN(cmp.out);
        } else {
            CMPINITUPN_TWO(cmp.out);
        }
        LAST_ASSIGNEMENT(compressed_text);
    }
    return cmp.out_len;
}

static long int find_size_cmp(const char *file_name)
{
    struct stat st;

    if (stat(file_name, &st) == 0)
        return st.st_size;
    else
        return -1;
}

static int my_comp(char *in)
{
    int fd = open(in, O_RDONLY);
    long int size = find_size_cmp(in);
    if (size == -1)
        return 84;
    char *uncompress_text = malloc(sizeof(char) * size);
    char *compressed_text = malloc(sizeof(char) * size * 2);
    unsigned int compress_size;

    if (uncompress_text == NULL || compressed_text == NULL || size == -1)
        return 84;
    if (read(fd, uncompress_text, size) == -1)
        return 84;
    compress_size = my_compression(uncompress_text, size, compressed_text);
    write(1, compressed_text, compress_size);
    close(fd);
    free(uncompress_text);
    free(compressed_text);
    return compress_size;
}

static int my_getnbr(char const *str)
{
    long negative_int = 1;
    long number = 0;
    long i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            negative_int = negative_int * (-1);
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        number = (10 * number) + (int)str[i] - '0';
        if (number > 2147483647 && negative_int == 1)
            return (0);
        else if (number > 2147483648)
            return (0);
        i++;
    }
    return (number * negative_int);
}

int main(int ac, char **av)
{
    int in;
    struct stat st;

    if (ac != 3)
        return 84;
    if (my_getnbr(av[2]) <= 0 || my_getnbr(av[2]) > 3)
        return 84;
    in = open(av[1], O_RDONLY);
    if (stat(av[1], &st) == -1)
        return 84;
    if (in < 0 || S_ISDIR(st.st_mode)) {
        write(2, "Can't open !\n", 13);
        return 84;
    }
    if (my_comp(av[1]) == 84)
        return 84;
    close(in);
    return 0;
}