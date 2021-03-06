#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 200005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int a, b, k, num[MAXN];

int main() {
    scanf("%d%d%d", &a, &b, &k);
    if(b==1) {
        if(k==0) {
            printf("Yes\n");
            printf("1");
            for(int i=1; i<=a; ++i) printf("0");
            printf("\n");
            printf("1");
            for(int i=1; i<=a; ++i) printf("0");
            printf("\n");
        }
        else printf("No\n");
        return 0;
    }
    if(a==0) {
        if(k==0) {
            printf("Yes\n");
            for(int i=1; i<=b; ++i) printf("1");
            printf("\n");
            for(int i=1; i<=b; ++i) printf("1");
            printf("\n");
        }
        else printf("No\n");
        return 0;
    }
    if(k>a+b-2) {
        printf("No\n");
        return 0;
    }
    if(k==0) {
        printf("Yes\n");
        for(int i=1; i<=b; ++i) printf("1");
        for(int i=1; i<=a; ++i) printf("0");
        printf("\n");
        for(int i=1; i<=b; ++i) printf("1");
        for(int i=1; i<=a; ++i) printf("0");
        printf("\n");
        return 0;
    }
    printf("Yes\n");
    for(int i=1; i<=a-1; ++i) num[i]=0;
    for(int i=a; i<=a+b-3; ++i) num[i]=1;
    printf("11");
    for(int i=1; i<=k-1; ++i) printf("%d", num[i]);
    printf("0");
    for(int i=k; i<=a+b-3; ++i) printf("%d", num[i]);
    printf("\n");
    printf("10");
    for(int i=1; i<=k-1; ++i) printf("%d", num[i]);
    printf("1");
    for(int i=k; i<=a+b-3; ++i) printf("%d", num[i]);
    printf("\n");
    return 0;
}