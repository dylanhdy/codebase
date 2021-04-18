#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int n, num1, num2, num3, a[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        if(a[i]==1) num1++;
        if(a[i]==2) num2++;
        if(a[i]>=3) num3++;
    }
    if(num2+num3==1) printf("Win\n");
    if(num2+num3==0 || (num2==1 && num3==1) || (num2==2 && num3==0)) {
        if(num1%3==1 || num1%3==2) printf("Win\n");
        else printf("Lose\n");
    }
    if((num2==0 && num3==2) || num2+num3>=3) printf("Lose\n");
    return 0;
}