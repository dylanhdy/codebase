#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN 10005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, ans, val1[MAXN], val2[MAXN];
LD num1[MAXN], num2[MAXN], s[MAXN], q[MAXN];
char str[105][MAXN];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &T, &n);
    for(int Case=1; Case<=T; ++Case) {
        double maxn=0;
        for(int i=1; i<=10000; ++i) val1[i]=val2[i]=0;
        for(int i=1; i<=100; ++i) {
            scanf("%s", str[i]+1);
            for(int j=1; j<=10000; ++j)
                if(str[i][j]=='1') val1[i]++, val2[j]++;
        }
        for(int i=1; i<=100; ++i) s[i]=6.0*val1[i]/10000-3;
        for(int i=1; i<=10000; ++i) q[i]=3-6.0*val2[i]/100;
        for(int i=1; i<=100; ++i) {
            for(int j=1; j<=10000; ++j) {
                if(1/(1+exp(q[j]-s[i]))<0.5 && str[i][j]=='1') num1[i]++;
                if(1/(1+exp(q[j]-s[i]))>0.5 && str[i][j]=='0') num1[i]++;
                num2[i]+=min(1/(1+exp(q[j]-s[i])), 1-1/(1+exp(q[j]-s[i])));
            }
            //printf("%Lf %LF %Lf\n", num1[i], num2[i], num1[i]/num2[i]);
            if(num1[i]/num2[i]>maxn) maxn=num1[i]/num2[i], ans=i;
        }
        printf("Case #%d: %d\n", Case, ans);
    }
    return 0;
}