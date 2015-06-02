#include "cutils.h"
#include <stdio.h>

int test_trim()
{
        char *expect = "hello world";
        char input[] = "  hello world    ";
        c_trim(input);
        return 0 == strcmp(expect, input);
}

int test_split()
{
        char *expect[] = {
                "hello",
                "system",
                "programming"
        };
        char s[] = "hello system programming";
        char *arr[4] = {0};
        c_split(s, ' ', arr);

        /* check result */
        int i = 0;
        for (i = 0; i < 3; ++i) {
                if (strcmp(expect[i], arr[i]))
                        return 0;
        }

        return arr[i] == NULL;
}

int test_join()
{
        char *expect = "hello system programming";

        char *input[] = {
                "hello",
                "system",
                "programming"
        };

        char buf[128] = {0};
        c_join(' ', input, buf);
        return 0 == strcmp(expect, buf);
}

int main(int argc, char *argv[])
{
        printf("begin test_trim()\n");
        assert (1 == test_trim());
        printf("end test_trim()\n\n");

        printf("begin test_split()\n");
        assert (1 == test_split());
        printf("end test_split()\n\n");

        printf("begin test_join()\n");
        assert (1 == test_join());
        printf("end test_join()\n");

        return 0;
}
