#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;
static void (*atexit_funcs[ATEXIT_MAX])(void);
static int atexit_func_count = 0;

__attribute__((__noreturn__)) void abort(void)
{
#ifdef __is_libk
    kprintf("kernel: panic: abort()\n");
#else
    fprintf(stderr, "abort()\n");
#endif
    while (1)
    {
    }
    __builtin_unreachable();
}

int atexit(void (*func)(void))
{
    if (atexit_func_count >= ATEXIT_MAX)
    {
        return -1;
    }
    atexit_funcs[atexit_func_count++] = func;
    return 0;
}

__attribute__((__noreturn__)) void exit(int status)
{
    while (atexit_func_count > 0)
    {
        atexit_funcs[--atexit_func_count]();
    }
    _Exit(status);
}

__attribute__((__noreturn__)) void _Exit(int status)
{
    __builtin_exit(status);
}

char *getenv(const char *name)
{
    extern char **environ;
    size_t name_len = strlen(name);
    for (char **env = environ; *env; ++env)
    {
        if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
        {
            return *env + name_len + 1;
        }
    }
    return NULL;
}

int system(const char *string)
{
    (void)string;
    return -1;
}

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
    if (nmemb == 0 || size == 0)
    {
        return NULL;
    }
    const char *p = base;
    size_t l = 0;
    size_t r = nmemb - 1;
    while (l <= r)
    {
        size_t m = l + (r - l) / 2;
        int cmp = compar(key, p + m * size);
        if (cmp == 0)
        {
            return (void *)(p + m * size);
        }
        if (cmp < 0)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return NULL;
}

void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
    if (nmemb > 1)
    {
        size_t pivot_idx = nmemb / 2;
        char *pivot_ptr = (char *)base + pivot_idx * size;
        char *left_ptr = (char *)base;
        char *right_ptr = (char *)base + (nmemb - 1) * size;
        while (left_ptr < right_ptr)
        {
            while (compar(left_ptr, pivot_ptr) < 0)
            {
                left_ptr += size;
            }
            while (compar(right_ptr, pivot_ptr) > 0)
            {
                right_ptr -= size;
            }
            if (left_ptr < right_ptr)
            {
                char tmp[size];
                memcpy(tmp, left_ptr, size);
                memcpy(left_ptr, right_ptr, size);
                memcpy(right_ptr, tmp, size);
                left_ptr += size;
                right_ptr -= size;
            }
        }
        size_t left_size = (left_ptr - (char *)base) / size;
        size_t right_size = (nmemb - left_size - 1);
        qsort(base, left_size, size, compar);
        qsort(left_ptr, right_size, size, compar);
    }
}

int abs(int x)
{
    return (x < 0) ? -x : x;
}

long labs(long x)
{
    return (x < 0) ? -x : x;
}

long long llabs(long long x)
{
    return (x < 0) ? -x : x;
}

div_t div(int numer, int denom)
{
    div_t result;
    result.quot = numer / denom;
    result.rem = numer % denom;
    return result;
}

ldiv_t ldiv(long numer, long denom)
{
    ldiv_t result;
    result.quot = numer / denom;
    result.rem = numer % denom;
    return result;
}

lldiv_t lldiv(long long numer, long long denom)
{
    lldiv_t result;
    result.quot = numer / denom;
    result.rem = numer % denom;
    return result;
}

int mblen(const char *s, size_t n)
{
    if (s == NULL || *s == '\0')
    {
        return 0;
    }
    return 1;
}

int mbtowc(wchar_t *pwc, const char *s, size_t n)
{
    if (s == NULL)
    {
        return 0;
    }
    if (n < 1)
    {
        return -1;
    }
    if (pwc != NULL)
    {
        *pwc = (wchar_t)*s;
    }
    return 1;
}

int wctomb(char *s, wchar_t wc)
{
    if (s == NULL)
    {
        return 0;
    }
    *s = (char)wc;
    return 1;
}

size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n)
{
    size_t count = 0;
    if (pwcs == NULL)
    {
        return strlen(s);
    }
    while (n > 0 && *s != '\0')
    {
        *pwcs = (wchar_t)*s;
        pwcs++;
        s++;
        count++;
        n--;
    }
    return count;
}

size_t wcstombs(char *s, const wchar_t *pwcs, size_t n)
{
    size_t count = 0;
    if (s == NULL)
    {
        while (*pwcs != L'\0')
        {
            pwcs++;
            count++;
        }
        return count;
    }
    while (n > 0 && *pwcs != L'\0')
    {
        *s = (char)*pwcs;
        s++;
        pwcs++;
        count++;
        n--;
    }
    return count;
}
