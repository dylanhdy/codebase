#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 105
#define MAXM
#define P
#define eps 1e-4
#define INF 0x3f3f3f3f
using namespace std;

int n;
double a[MAXN][MAXN], b[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) scanf("%lf", &a[i][j]);
        scanf("%lf", &b[i]);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
            if(fabs(a[j][i])>eps)
            {
                for(int k=1; k<=n; k++) swap(a[j][k], a[i][k]); 
                swap(b[j], b[i]);
            }
    	for(int j=1; j<=n; j++)
            if(i!=j)
            {
                double rate=a[j][i]/a[i][i];
                for(int k=i; k<=n; k++) a[j][k]-=a[i][k]*rate;
                b[j]-=b[i]*rate;	
            }
    }
    for(int i=1; i<=n; i++)
        if(fabs(a[i][i])<eps || fabs(b[i]/a[i][i])<eps)
        {
            printf("No Solution\n");
            return 0;
        }
    for(int i=1; i<=n; i++) printf("%.2lf\n", b[i]/a[i][i]);
    return 0;
}