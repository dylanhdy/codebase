#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long
#define rint register int
#define MAXN 
#define P 
using namespace std;
 
int t;
 
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int num=0;
        for(int i=1; i<=4; ++i)
        {
            int temp;
            scanf("%d", &temp);
            if(temp>0) num++;
        }
        if(num==0) printf("Typically Otaku\n");
        if(num==1) printf("Eye-opener\n");
        if(num==2) printf("Young Traveller\n");
        if(num==3) printf("Excellent Traveller\n");
        if(num==4) printf("Contemporary Xu Xiake\n");
    }
    return 0;
}