#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}



int     if_square(const char *array)
{
    int count;

    if (*array)
        return (-1);
    count = 0;
    while (array[count])
    {
        if (array[count] != '\n' && count % 4 == 0)
            return (0);
        count++;
    }
    return (count == 21);
}
int     if_four_blocks(const char *array)
{
    int count;

    if (!*array)
        return (-1);
    count = 0;
    while (*array)
    {
        if (*array == '#')
        {
            count++;
        }
        (array)++;
    }
    return (count == 4);
}

int     if_invalid_char(const char *array)
{
    if (!*array)
        return (-1);
    while (*array)
    {
        if (*array != '#' || *array != '.' || *array != '\n')
            return (0);
        array++;
    }
    return (1);
}

int     if_valid_attachment(const char *array)
{
    int i;
    int res;

    if (!*array)
        return (-1);
    i = 0;
    res = 0;
    while (i < 21)
    {
        if (array[i] == '#')
        {
            if (array[i + 5] == '#' && i + 5 < 19)
                res++;
            if (array[i + 1] == '#' && i + 1 < 19)
                res++;
            if (array[i - 1] == '#' && i - 1 > -1)
                res++;
            if (array[i - 5] == '#' && i - 5 > -1)
                res++;
        }
        i++;
    }
    return (res == 6 || res == 8);
}
