/**
 * This file contains utility functions
 * for C null-terminated strings
 *
 */
#ifndef CUTILS_H
#define CUTILS_H
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

/**
 * Convert each letter in the string to uppercase in place.
 */
void c_toupper_inplace(char *s)
{
        assert (s != NULL);
        while (*s) {
                *s = toupper(*s);
                s++;
        }
}

/**
 * Convert each letter in the string to lowercase in place.
 */
void c_tolower_inplace(char *s)
{
        assert (s != NULL);
        while (*s) {
                *s = tolower(*s);
                s++;
        }
}

void c_toupper(const char *src, const char *dst)
{
}

void c_tolower(const char *src, const char *dst)
{
}

/**
 * Check if string is NULL or empty("")
 */
int c_isempty(const char *s)
{
        assert (s != NULL);
        return (NULL == s || 0 == strlen(s));
}

/**
 * Check if string only contains whitespace characters
 */
int c_isblank(const char *s)
{
        assert (s != NULL);
        int i, len = strlen(s);
        for (i = 0; i < len; ++i) {
                if (!isspace(s[i]))
                        return 0;
        }
        return 1;
}

/**
 * Trim leading and trailing whitespace in place
 */
void c_trim(char *s)
{
        assert (s != NULL);
        char *h = s;
        char *t = strrchr(s, '\0');
        if (!t)
                return;

        t -= 1;
        while (isspace(*h)) {
                h++;
        }
        while (isspace(*t)) {
                t--;
        }

        int count;
        if (h < t) {
                count = t - h + 1;
                /* memcpy() caused SIGSEGV, segmentation fault */
                /* memcpy(s, h, t - h + 1); */
                memmove(s, h, t - h + 1);
                *(s + count) = '\0';
        }
}

/**
 * Find the first present position of char c
 */
int c_indexof(const char *s, char c)
{
        assert (s != NULL);
        int i, len = strlen(s);
        for (i = 0; i < len; i++) {
                if (c == s[i])
                        return i;
        }
        return -1;
}

int c_contains(const char *s, char c)
{
        assert (s != NULL);
        return c_indexof(s, c) >= 0;
}

void c_substr(const char *s, int begin, int end, char *buf)
{
        assert (s != NULL);
        assert (begin < end);
        assert (end <= strlen(s));

}

void c_split(char *s, char delim, char **arr)
{
        assert (s != NULL);
        assert (arr != NULL);
        char *p = NULL;
        int i = 0;
        if (isspace(delim))
                c_trim(s);

        while ((p = strchr(s, delim))) {
                *p = '\0';
                arr[i++] = s;
                s = p + 1;
        }
        /* dont forget the last token */
        arr[i++] = s;
        arr[i] = NULL;
}

void c_join(char delim, char **arr, char *buf)
{
        assert (buf != NULL);
        assert (arr != NULL);
        int i = 0;
        int off = 0;
        char *dst = buf;
        while (arr[i]) {
                off = strlen(arr[i]);
                strncpy(dst, arr[i], off);
                if (arr[i + 1]) {
                        *(dst + off) = delim;
                        dst = dst + off + 1;
                } else {
                        dst = dst + off;
                }
                i++;
        }
        *dst = '\0';
}

static inline void c_swap(char *s, int i, int j)
{
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
}

void c_reverse_inplace(char *s)
{
        assert (s != NULL);
        int i = 0, j = strlen(s) - 1;
        for (; i < j; i++, j--) {
                c_swap(s, i, j);
        }
}

void c_reverse(const char *s, char *buf, int n)
{
        assert (s != NULL && buf != NULL);
        assert (n == strlen(s) + 1);
        int i = 0, j = strlen(s) - 1;
        for (; i < j; i++, j--) {
                buf[i] = s[j];
                buf[j] = s[i];
        }
        buf[n - 1] = '\0';
}



#endif

