#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define P 1000000007
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int a, b, c, d, la, lb;
char A[MAXN], B[MAXN];

namespace Task1
{
    int ans, tot, num[1000];
    void solve()
    {
        int l=0, r=0;
        for(rint i=0; i<la; ++i) l=l*2+A[i]-'0';
        for(rint i=0; i<lb; ++i) r=r*2+B[i]-'0';
        for(rint i=l; i<=r; ++i)
        {
            int tot=0, ca=0, cb=0, cc=0, cd=0, temp=i;
            while(temp) num[++tot]=temp%2, temp/=2;
            for(rint j=tot; j>=2; --j)
            {
                if(num[j]==0 && num[j-1]==0) ca++;
                if(num[j]==0 && num[j-1]==1) cb++;
                if(num[j]==1 && num[j-1]==0) cc++;
                if(num[j]==1 && num[j-1]==1) cd++;
            }
            if(ca==a && cb==b && cc==c && cd==d) ans++;
        }
        printf("%d\n", ans);
    }
}

namespace Task2
{
    int ans, fac[MAXN*2], inv[MAXN*2];

    void init(int n)
    {
        inv[0]=inv[1]=fac[0]=fac[1]=1;
        for(rint i=2; i<=n; ++i) inv[i]=1LL*inv[P%i]*(P-P/i)%P;
        for(rint i=2; i<=n; ++i)
        {
            fac[i]=1LL*fac[i-1]*i%P;
            inv[i]=1LL*inv[i-1]*inv[i]%P;
        }
    }

    int comb(int x, int y)
    {
        return 1LL*fac[x]*inv[y]%P*inv[x-y]%P;
    }

    int work(int a, int b, int c, int d, int len)
    {
        if(c<b || c>b+1 || a<0 || b<0 || c<0 || d<0) return 0;
        
        if(c==0) return a==0;
        return 1LL*comb(b+d, b)*comb(c+a-1, c-1)%P;
    }

    int cal(char *num, int len)
    {
        int ta=a, tb=b, tc=c, td=d, ans=0;
        for(rint i=1; i<len; ++i)
        {
            if(num[i]=='0')
            {
                if(num[i-1]=='0') ans=(ans+work(ta, tb-1, tc, td, len-i))%P;
                else ans=(ans+work(ta, tb, tc, td-1, len-i))%P;
            }
            if(num[i]=='0' && num[i-1]=='0') ta--;
            if(num[i]=='1' && num[i-1]=='0') tb--;
            if(num[i]=='0' && num[i-1]=='1') tc--;
            if(num[i]=='1' && num[i-1]=='1') td--;
        }
        if(ta==0 && tb==0 && tc==0 && td==0) ans++;
        return ans;
    }

    void solve()
    {
        int len=a+b+c+d+1;
        init(len*2);
        if(c<b || c>b+1 || lb<len || la>len) {printf("0\n"); return;}
        if(la<len)
        {
            A[0]='1';
            for(rint i=1; i<len; ++i) A[i]='0';
            ans+=cal(A, len);
        }
        if(la==len) ans=(ans+cal(A, len))%P;
        reverse(B, B+lb);
        B[0]++;
        for(rint i=0; B[i]>'1'; ++i)
        {
            B[i]='0', B[i+1]++;
            if(i==lb-1) lb++;
        }
        reverse(B, B+lb);
        if(lb==len) ans=(ans-cal(B, len)+P)%P;
        printf("%d\n", max(0, ans));
    }
}

int main()
{
    freopen("i.in", "r", stdin);
    freopen("i.out", "w", stdout);
    scanf("%s%s", A, B);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    la=strlen(A), lb=strlen(B);
    if(lb<=20) Task1::solve();
    else Task2::solve();
    return 0;
}