#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#define rint register int
#define MAXN 200005
using namespace std;

int t, len, ans;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    for(rint i=1; i<=t; ++i)
    {
        scanf("%s", s+1);
        len=strlen(s+1), ans=0;
        for(rint dgt=0; dgt<=9; ++dgt)
        {
            int temp=0;
            for(rint j=1; j<=len; ++j)
                if(s[j]=='0'+dgt) temp++;
            ans=max(ans, temp);
        }
        for(rint dgt1=0; dgt1<=9; ++dgt1)
            for(rint dgt2=0; dgt2<=9; ++dgt2)
            {
                if(dgt1==dgt2) continue;
                int qwq=0, temp=0;
                for(rint j=1; j<=len; ++j)
                {
                    if(qwq==0 && s[j]=='0'+dgt1) temp++, qwq=1;
                    if(qwq==1 && s[j]=='0'+dgt2) temp++, qwq=0;
                }
                ans=max(ans, temp-qwq);
            }
        printf("%d\n", len-ans);
    }
    return 0;
}