#include "uls.h"

void mx_ls_sort_flag_big_s(t_ls **arr, int size) {
    t_ls *temp;

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if ((arr[i]->size < arr[j]->size)) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
