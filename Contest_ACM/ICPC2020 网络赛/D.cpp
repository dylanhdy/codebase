#include <bits/stdc++.h>
#define MAXN 3005
using namespace std;
 
int t, hp1, hp2, w;
double p, f[MAXN][MAXN];
 
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        memset(f, 0, sizeof(f));
        scanf("%d%d%d%lf", &hp1, &hp2, &w, &p);
        for(int i=1; i<=hp1; ++i)
            for(int j=1; j<=hp2; ++j)
            {
                if(i<=w && j<=w) f[i][j]=1;
                if(i<=w && j>w) f[i][j]=1+p*f[i][j-w];
                if(i>w && j<=w) f[i][j]=1+(1-p)*f[i-w][j];
                if(i>w && j>w) f[i][j]=1+(1-p)*f[i-w][j]+p*f[i][j-w];
            }
        printf("%.6lf\n", f[hp1][hp2]);
    }
    return 0;
}