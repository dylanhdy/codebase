#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#define LL long long
#define rint register int
using namespace std;

int main()
{
    printf("534\n");
    printf("+ 0 1 4\n");
    printf("< 3 4 4\n");
    printf("+ 0 4 0\n");
    printf("+ 1 4 1\n");
    for(rint i=1; i<=10; ++i) printf("+ %d 4 %d\n", i-1+10, i+10);
    for(rint i=1; i<=10; ++i) printf("< %d 0 %d\n", i+10, i+20);
    for(rint i=1; i<=10; ++i) printf("< %d 1 %d\n", i+10, i+30);
    for(rint i=1; i<=10; ++i)
        for(rint j=1; j<=10; ++j)
        {
            printf("< 3 %d 5\n", i+20);
            printf("< 3 %d 6\n", j+30);
            printf("+ 5 6 7\n");
            printf("< 4 7 7\n");
            printf("+ 2 7 2\n");
        }
    return 0;
}