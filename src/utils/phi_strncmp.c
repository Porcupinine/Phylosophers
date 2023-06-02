//
// Created by laura on 31-5-23.
//

int phi_strcmp(const char *str1, const char *str2, int len)
{
    int count;

    count = 0;
    while (count < len)
    {
        if (str1[count] != str2[count])
            return (1);
        count++;
    }
}