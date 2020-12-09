#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#define LL long long
#define LD long double
#define MAXN 300005
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, m, f[MAXN], a[MAXN];
LL ans;

vector<int> vec[MAXN];
map<int, int> mp[MAXN], t[MAXN];
map<int, int>::iterator it;


void init()
{
    for(int i=2; i<=2e5; ++i)
        for(int j=1; j*j<=i; ++j)
            if(i%j==0)
            {
                int temp=i^j;
                if(temp<=2e5 && __gcd(i, temp)==j) vec[i].PB(temp);
                if(j*j==i) continue;
                temp=i^(i/j);
                if(temp<=2e5 && __gcd(i, temp)==(i/j)) vec[i].PB(temp);
            }
}

int find(int x)
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    init();
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        t[i][a[i]]++;
        for(int j=0; j<vec[a[i]].size(); ++j) mp[i][vec[a[i]][j]]++;
    }
    for(int i=1; i<=n+m; ++i) f[i]=i;
    for(int i=1; i<=m; ++i)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(op==1)
        {
            a[x]=y;
            for(int j=0; j<vec[y].size(); ++j) mp[x][vec[y][j]]++;
            t[x][y]++;
        }
        if(op==2)
        {
            int fx=find(x), fy=find(y);
            if(fx==fy)
            {
                printf("%lld\n", ans);
                continue;
            }
            if(mp[fx].size()>mp[fy].size())
            {
                f[fy]=fx;
                for(it=t[fy].begin(); it!=t[fy].end(); ++it)
                {
                    t[fx][it->first]+=it->second;
                    if(mp[fx].find(it->first)!=mp[fx].end())
                        ans+=1LL*mp[fx][it->first]*it->second;
                }
                for(it=mp[fy].begin(); it!=mp[fy].end(); ++it)
                    mp[fx][it->first]+=it->second;
            }
            else
            {
                f[fx]=fy;
                for(it=t[fx].begin(); it!=t[fx].end(); ++it)
                {
                    t[fy][it->first]+=it->second;
                    if(mp[fy].find(it->first)!=mp[fy].end())
                        ans+=1LL*mp[fy][it->first]*it->second;
                }
                for(it=mp[fx].begin(); it!=mp[fx].end(); ++it)
                    mp[fy][it->first]+=it->second;
            }
        }
        if(op==3)
        {
            int fx=find(x);
            t[fx][a[x]]--, t[fx][y]++;
            ans-=mp[fx][a[x]];
            for(int j=0; j<vec[a[x]].size(); ++j) mp[fx][vec[a[x]][j]]--;
            for(int j=0; j<vec[y].size(); ++j) mp[fx][vec[y][j]]++;
            ans+=mp[fx][y];
            a[x]=y;
        }
        printf("%lld\n", ans);
    }
    return 0;
}