//
// Created by laura on 31-5-23.
//

int phi_strlen(const char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}
