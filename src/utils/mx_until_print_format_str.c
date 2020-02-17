#include "uls.h"

static void print_symbol(char symbol, int number) {
	for (int i = 0; i < number; i++)
		mx_printchar(symbol);
}

void mx_until_print_format_str(char *str, char local, char symbol, int size) {
    int len = mx_strlen(str);

    switch (local) {
        case 'c': print_symbol(symbol, (size - len) / 2); break;
        case 'r': print_symbol(symbol, size - len); break;
    }

    mx_printstr(str);

    switch (local) {
        case 'c': print_symbol(symbol, size - len - (size - len) / 2); break;
        case 'l': print_symbol(symbol, size - len); break;
    }
}

void mx_until_print_format_l(t_ls *file, t_main *main, int size) {
    int len = mx_strlen(file->print_name);
    char name = 'l';

    switch (name) {
        case 'c': print_symbol(' ', (size - len) / 2); break;
        case 'r': print_symbol(' ', size - len); break;
    }

    mx_ls_print_color(file, main->color);

    switch (name) {
        case 'c': print_symbol(' ', size - len - (size - len) / 2); break;
        case 'l': print_symbol(' ', size - len); break;
    }
}
