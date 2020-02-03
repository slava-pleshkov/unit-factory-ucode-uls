#include "uls.h"

static bool mx_check_color(char *flags){
    if (mx_ls_check_flag(flags, 'G'))
        return true;
    return false;
}

t_main *mx_create_main(int argc, char **argv){
    t_main *main = malloc(sizeof(t_main));
    char *flags = mx_create_flags_str(argv, argc);
    char **files = mx_create_param_arr(argv, argc);
    int str_size = mx_until_get_size_arr(files);
    
    main->files = files;
    main->files_struct = mx_ls_create_struct_arr(str_size);
    main->flags = flags;
    main->color = mx_check_color(flags);
    main->str_size = str_size;
    return main;
}