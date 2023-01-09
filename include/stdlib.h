#ifndef LIBC_STDLIB_H
#define LIBC_STDLIB_H

#include <types.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define ATEXIT_MAX 32

#ifdef __cplusplus
extern "C" {
#endif

void abort(void) __attribute__((__noreturn__));
int atexit(void (*func)(void));
void exit(int status) __attribute__((__noreturn__));
void _Exit(int status) __attribute__((__noreturn__));
char *getenv(const char *name);
int system(const char *string);

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

int abs(int j);
long int labs(long int j);
long long int llabs(long long int j);

div_t div(int numer, int denom);
ldiv_t ldiv(long int numer, long int denom);
lldiv_t lldiv(long long int numer, long long int denom);

int mblen(const char *s, size_t n);
int mbtowc(wchar_t *pwc, const char *s, size_t n);
int wctomb(char *s, wchar_t wc);
size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n);
size_t wcstombs(char *s, const wchar_t *pwcs, size_t n);

#ifdef __cplusplus
}
#endif

#endif // LIBC_STDLIB_H
