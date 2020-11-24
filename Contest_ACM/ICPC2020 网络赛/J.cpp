#include <cstdio>
#include <algorithm>
#include <cmath>
#define INF 1e18
using namespace std;
 
int t, n, m, k;
 
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        if((n+m)%2!=k%2)
        {
            printf("NO\n");
            continue;
        }
        if(k<n+m || k>(n+1)*(m+1)-1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int x=0, y=0;
        for(; k; k--)
        {
            if(k==(n+m-x-y))
            {
                for(++y; y<=m; ++y) printf("E");
                for(++x; x<=n; ++x) printf("S");
                break;
            }
            if(y==m-1 && m%2==1)
            {
                while(k--)
                {
                    if(y==m-1 && x%2==0) y++, printf("E");
                    else if(y==m && x%2==0) x++, printf("S");
                    else if(y==m && x%2==1) y--, printf("W");
                    else x++, printf("S");
                    if(k==(n+m-x-y))
                    {
                        for(++x; x<=n; ++x) printf("S");
                        for(++y; y<=m; ++y) printf("E");
                        break;
                    }
                }
                break;
            }
            if(x==n && y%2==0) y++, printf("E");
            else if(x==n && y%2==1) x--, printf("N");
            else if(x==0 && y%2==0) x++, printf("S");
            else if(x==0 && y%2==1) y++, printf("E");
            else if(x>0 && x<n && y%2==1) x--, printf("N");
            else x++, printf("S");
        }
        printf("\n");
    }
}