#include <string.h>
#include <assert.h>
#include "global.h"

void bzero(void *base, unsigned int size)
{
    assert(size >= 0);
    memset(base, 0, size);
}

void m_tolower(char *str)
{
    assert(str != NULL);

    int i, len;

    len = strlen(str);

    for (i = 0; i < len; ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = 'a' + str[i] - 'A';
        }
    }
}
