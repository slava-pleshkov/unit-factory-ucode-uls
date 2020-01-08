#include "uls.h"

char *mx_ls_get_acl_inf(const char *file) {
    acl_t acl_file;
    char *str = NULL;

    if (file) {
        acl_file = acl_get_file(file, ACL_TYPE_ACCESS);
        str = acl_to_text(acl_file, NULL);
        acl_free(acl_file);
        return str;
    }
    else
    	return NULL;
}
