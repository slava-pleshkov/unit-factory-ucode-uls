#include "uls.h"

static bool check_symbol(char *print_name);
static void recursive(t_ls **files, t_main *main);

void mx_ls_loop(char **files_name, t_main *main) {
    main->file_n = mx_until_get_size_arr(files_name);
    t_ls **files = mx_ls_create_struct_arr(main->file_n);

    for (int i = 0; files_name[i]; i++){
        free(files[i]);
        files[i] = mx_get_lstat(files_name[i]);
    }
    
    mx_ls_sort(files, main->flags);
    mx_ls_print(files, main);  
    recursive(files, main);
    mx_untill_del_tls(&files);
}

static void recursive(t_ls **files, t_main *main) {
    char **memory = NULL;
    ino_t dev_fd = mx_get_ino_dev_fd();

    for (int i = 0; files[i]; i++) {
        if (files[i]->type == 'd' && mx_ls_check_flag(main->flags, 'R')) {
            if (mx_ls_check_flag(main->flags, 'a') 
                && !check_symbol(files[i]->print_name))
                continue;
            mx_printstr("\n");
            mx_printstr(files[i]->name);
            mx_printstr(":\n");
            if (files[i]->ino == dev_fd)
                continue;
            memory = mx_read_dir(files[i]->name, mx_ls_get_hidden(main->flags));
            if (!memory) {
                mx_ls_error(ERR_EACCES, files[i]->print_name);
                continue;
            }
            mx_ls_loop(memory, main);
            mx_del_strarr(&memory);
        }
    }
}

static bool check_symbol(char *print_name) {
    if (!mx_strcmp(print_name, ".") || !mx_strcmp(print_name, ".."))
        return false;
    else
        return true;
}
