#include <string.h>

void *memchr(const void *s, int c, size_t n)
{
    const unsigned char *p = s;
    while (n-- > 0)
    {
        if (*p == (unsigned char)c)
        {
            return (void *)p;
        }
        p++;
    }
    return NULL;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1 = s1, *p2 = s2;
    while (n-- > 0)
    {
        if (*p1 != *p2)
        {
            return *p1 - *p2;
        }
        p1++;
        p2++;
    }
    return 0;
}

void *memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *p1 = dest;
    const unsigned char *p2 = src;
    while (n-- > 0)
    {
        *p1++ = *p2++;
    }
    return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char *p1 = dest;
    const unsigned char *p2 = src;
    if (p2 < p1 && p1 < p2 + n)
    {
        p2 += n;
        p1 += n;
        while (n-- > 0)
        {
            *--p1 = *--p2;
        }
    }
    else
    {
        while (n-- > 0)
        {
            *p1++ = *p2++;
        }
    }
    return dest;
}

void *memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    while (n-- > 0)
    {
        *p++ = (unsigned char)c;
    }
    return s;
}

char *strcat(char *dest, const char *src)
{
    char *p = dest;
    while (*p != '\0')
    {
        p++;
    }
    while ((*p++ = *src++) != '\0')
        ;
    return dest;
}

char *strchr(const char *s, int c)
{
    while (*s != (char)c)
    {
        if (*s == '\0')
        {
            return NULL;
        }
        s++;
    }
    return (char *)s;
}

int strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strcoll(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

size_t strcspn(const char *s1, const char *s2)
{
    size_t ret = 0;
    while (*s1 != '\0')
    {
        if (strchr(s2, *s1) == NULL)
        {
            ret++;
        }
        else
        {
            return ret;
        }
        s1++;
    }
    return ret;
}

char *strerror(int errnum)
{
    static char buffer[1024];
    snprintf(buffer, sizeof(buffer), "Error %d", errnum);
    return buffer;
}

size_t strlen(const char *s)
{
    size_t ret = 0;
    while (*s++ != '\0')
    {
        ret++;
    }
    return ret;
}

char *strncat(char *dest, const char *src, size_t n)
{
    char *p = dest;
    while (*p != '\0')
    {
        p++;
    }
    while (n-- > 0 && (*p++ = *src++) != '\0')
        ;
    if (*(p - 1) == '\0')
    {
        *(p - 1) = '\0';
    }
    return dest;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    while (n-- > 0)
    {
        if (*s1 != *s2)
        {
            return *(unsigned char *)s1 - *(unsigned char *)s2;
        }
        else if (*s1 == '\0')
        {
            return 0;
        }
        s1++;
        s2++;
    }
    return 0;
}

char *strncpy(char *dest, const char *src, size_t n)
{
    char *p = dest;
    while (n-- > 0 && (*p++ = *src++) != '\0')
        ;
    while (n-- > 0)
    {
        *p++ = '\0';
    }
    return dest;
}

char *strpbrk(const char *s1, const char *s2)
{
    while (*s1 != '\0')
    {
        if (strchr(s2, *s1) != NULL)
        {
            return (char *)s1;
        }
        s1++;
    }
    return NULL;
}

char *strrchr(const char *s, int c)
{
    size_t len = strlen(s);
    s += len;
    while (len-- > 0)
    {
        if (*s == (char)c)
        {
            return (char *)s;
        }
        s--;
    }
    return NULL;
}

size_t strspn(const char *s1, const char *s2)
{
    size_t ret = 0;
    while (*s1 != '\0')
    {
        if (strchr(s2, *s1) == NULL)
        {
            return ret;
        }
        ret++;
        s1++;
    }
    return ret;
}

char *strstr(const char *haystack, const char *needle)
{
    size_t needle_len = strlen(needle);
    if (needle_len == 0)
    {
        return (char *)haystack;
    }
    while (*haystack != '\0')
    {
        if (*haystack == *needle)
        {
            if (strncmp(haystack, needle, needle_len) == 0)
            {
                return (char *)haystack;
            }
        }
        haystack++;
    }
    return NULL;
}

char *strtok(char *str, const char *delim)
{
    static char *last;
    if (str == NULL)
    {
        str = last;
    }
    if (*str == '\0')
    {
        return NULL;
    }
    str += strspn(str, delim);
    if (*str == '\0')
    {
        return NULL;
    }
    char *end = str + strcspn(str, delim);
    if (*end == '\0')
    {
        last = end;
        return str;
    }
    *end = '\0';
    last = end + 1;
    return str;
}

size_t strxfrm(char *dest, const char *src, size_t n)
{
    size_t src_len = strlen(src);
    if (n > 0)
    {
        size_t copy_len = (src_len < n - 1) ? src_len : n - 1;
        memcpy(dest, src, copy_len);
        dest[copy_len] = '\0';
    }
    return src_len;
}