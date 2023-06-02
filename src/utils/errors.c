//
// Created by laura on 31-5-23.
//

#include "../../include/utils.h"
#include <unistd.h>

void phi_error(char *error)
{
    int len;

    len = phi_strlen(error);
    write(2, error, len);
}