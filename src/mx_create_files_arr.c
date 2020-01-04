#include "uls.h"

char **mx_create_files_arr(char **argv, int argc) {
    char **files = mx_create_char_arr(argc);
    int k = 0;
    int j = 0;

    for (k = 1; k < argc; k++)
        if (argv[k][0] != '-')
            break;

    for (int i = k; i < argc; i++) {
        files[j] = mx_strdup(argv[i]);
        j++;
    }
    return files;
}
