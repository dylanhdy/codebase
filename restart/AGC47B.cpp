#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#define LL long long
#define rint register int
#define MAXN 1000005
using namespace std;

int n, tot, t[MAXN][26], num[MAXN][26], a[MAXN], b[26];
LL ans;
string s[200005];

bool CMP(string x, string y)
{
    return x.length()>y.length();
}

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) cin>>s[i];
    sort(s+1, s+n+1, CMP);
    for(rint i=1; i<=n; ++i)
    {
        reverse(s[i].begin(), s[i].end());
        int p=0, len=s[i].length();
        a[len]=0;
        for(rint j=len-1; j>=0; --j)
        {
            int ch=s[i][j]-'a';
            a[j]=a[j+1]|(1<<ch);
        }
        for(rint j=0; j<len; ++j)
        {
            int ch=s[i][j]-'a';
            if(j==len-1) ans+=num[p][ch];
            for(rint k=0; k<26; ++k)
                if(a[j]&(1<<k)) num[p][k]++;
            if(!t[p][ch]) t[p][ch]=++tot;
            p=t[p][ch];
        }
    }
    printf("%lld\n", ans);
    return 0;
}