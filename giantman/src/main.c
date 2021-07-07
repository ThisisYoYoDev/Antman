/*
** EPITECH PROJECT, 2021
** main
** File description:
** main for giantman
*/

#include "giantman.h"

unsigned int my_decompression(unsigned char *compressed_text,
    unsigned char *uncompressed_text)
{
    decompress_t dcmp;

    dcmp.uncompressed_size = *((unsigned int *) compressed_text);
    dcmp.comp = 4;
    for (dcmp.pos = 0; dcmp.pos < dcmp.uncompressed_size; ++dcmp.pos)
    {
        dcmp.input_pointer = *((unsigned int *) (compressed_text + dcmp.comp));
        dcmp.comp = dcmp.comp + 2;
        dcmp.pointer_pos = dcmp.input_pointer >> 4;
        dcmp.len = dcmp.input_pointer & 15;
        if (dcmp.pointer_pos)
            for (dcmp.pointer_offset = dcmp.pos - dcmp.pointer_pos;
                dcmp.len > 0; --dcmp.len)
                    uncompressed_text[dcmp.pos++] =
                        uncompressed_text[dcmp.pointer_offset++];
        *(uncompressed_text + dcmp.pos) = *(compressed_text + dcmp.comp++);
    }
    return dcmp.pos;
}

long int find_size_dec(const char *file_name)
{
    struct stat st;

    if (stat(file_name, &st) == 0)
        return st.st_size;
    else
        return -1;
}

int my_decomp(char *in)
{
    int fd = open(in, O_RDONLY);
    long int size = find_size_dec(in);
    if (size == -1)
        return 84;
    char *compressed_text = malloc(sizeof(char) * size);
    char *uncompressed_text = malloc(sizeof(char) * size * 15);
    unsigned int decompress_size;

    if (compressed_text == NULL || uncompressed_text == NULL || size == -1)
        return 84;
    if (read(fd, compressed_text, size) == -1)
        return 84;
    decompress_size = my_decompression(compressed_text, uncompressed_text);
    write(1, uncompressed_text, decompress_size);
    close(fd);
    free(compressed_text);
    free(uncompressed_text);
    return decompress_size;
}

int my_getnbr_dec(char const *str)
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
    if (my_getnbr_dec(av[2]) <= 0 || my_getnbr_dec(av[2]) > 3)
        return 84;
    in = open(av[1], O_RDONLY);
    if (stat(av[1], &st) == -1)
        return 84;
    if (in < 0 || S_ISDIR(st.st_mode)) {
        write(2, "Can't open !\n", 13);
        return 84;
    }
    if (my_decomp(av[1]) == 84)
        return 84;
    close(in);
    return 0;
}
