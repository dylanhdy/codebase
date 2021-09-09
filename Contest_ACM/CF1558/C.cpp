#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#define LL long long
#define LD long double
#define MAXN 2025
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, a[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        vector<int> vec;
        int flag=1;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            if((a[i]&1)!=(i&1)) flag=0;
        }
        if(!flag) {
            printf("-1\n");
            continue;
        }
        for(int i=2; i<=n; i+=2) {
            int pos1, pos2;
            for(int j=1; j<=n; ++j)
                if(a[j]==i-1) pos1=j;
            vec.PB(pos1);
            reverse(a+1, a+pos1+1);
            for(int j=1; j<=n; ++j)
                if(a[j]==i) pos2=j;
            vec.PB(pos2-1);
            reverse(a+1, a+pos2);
            vec.PB(pos2+1);
            reverse(a+1, a+pos2+2);
            vec.PB(3);
            swap(a[1], a[3]);
            vec.PB(n-i+2);
            reverse(a+1, a+n-i+3);
            // for(int j=1; j<=n; ++j) printf("%d ", a[j]);
            // printf("\n");
        }
        vec.PB(n);
        printf("%d\n", vec.size());
        for(int e: vec) printf("%d ", e);
        printf("\n");
    }
    return 0;
}