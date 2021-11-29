#include <bits/stdc++.h>
#define MAXN 5005
#define P 998244353
using namespace std;

int A, B, cnt, x[MAXN*2], f[MAXN][MAXN];
vector<int> vec;

int main()
{
    scanf("%d%d", &A, &B);
    for(int i=1; i<=A+B; ++i) {
        scanf("%d", &x[i]);
        if(x[i]==1) vec.push_back(++cnt);
        else vec.pop_back();
    }
    for(int i=0; i<=cnt; ++i) f[0][i]=1;
    for(int i=1; i<=A-B; ++i) {
        for(int j=i; j<=vec[i-1]; ++j) f[i][j]=f[i-1][j-1];
        for(int j=1; j<=cnt; ++j) f[i][j]=(f[i][j-1]+f[i][j])%P;
    }
    printf("%d\n", f[A-B][cnt]);
}