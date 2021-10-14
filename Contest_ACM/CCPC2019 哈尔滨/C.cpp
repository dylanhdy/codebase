#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
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

struct Frac {
    LL x, y;
    
    Frac(__int128 _x=0, __int128 _y=1) {
        __int128 d=__gcd(_x, _y);
        x=_x/d, y=_y/d;
    }

    void operator += (Frac a) {
        *this=Frac((__int128)x*a.y+y*a.x, (__int128)y*a.y);
    }

} mw[MAXN], gw[MAXN];

int T, n, m, a[20], vis[MAXN], cnt[MAXN], mp[MAXN], gp[MAXN];

vector<int> op[MAXN];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i) {
            gp[i]=mp[i]=cnt[i]=0;
            op[i].clear();
        }
        for(int i=1; i<=m; ++i) scanf("%d", &a[i]);
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) vis[j]=0;
            for(int j=1; j<=a[i]; ++j) {
                int p1, p2, w1, w2, d;
                scanf("%d%d%d%d%d", &p1, &p2, &w1, &w2, &d);
                vis[p1]=vis[p2]=1;
                if(w1>w2) mp[p1]+=3;
                if(w1==w2) mp[p1]++, mp[p2]++;
                if(w2>w1) mp[p2]+=3;
                gp[p1]+=w1*3+d, gp[p2]+=w2*3+d;
                cnt[p1]+=w1+w2+d, cnt[p2]+=w1+w2+d;
                op[p1].PB(p2); op[p2].PB(p1);
            }
            for(int j=1; j<=n; ++j) {
                if(!vis[j]) mp[j]+=3, gp[j]+=6, cnt[j]+=2;
                if(mp[j]<i) mw[j]={1, 3};
                else mw[j]=Frac(mp[j], 3*i);
                if(!cnt[j] || gp[j]<cnt[j]) gw[j]={1, 3};
                else gw[j]=Frac(gp[j], cnt[j]*3);
            }
            printf("Round %d\n", i);
            for(int j=1; j<=n; ++j) {
                Frac tmp(0, 1);
                for(int e: op[j]) tmp+=mw[e];
                if(!op[j].size()) tmp={1, 3};
                else tmp=Frac(tmp.x, tmp.y*op[j].size());
                printf("%d %lld/%lld %lld/%lld ", mp[j], tmp.x, tmp.y, gw[j].x, gw[j].y);
                tmp={0, 1};
                for(int e: op[j]) tmp+=gw[e];
                if(!op[j].size()) tmp={1, 3};
                else tmp=Frac(tmp.x, tmp.y*op[j].size());
                printf("%lld/%lld\n", tmp.x, tmp.y);
            }
        }
    }
    return 0;
}