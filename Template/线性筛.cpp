#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 100005
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, t, cnt, pri[MAXN], vis[MAXN];
int mu[MAXN], phi[MAXN]; //莫比乌斯函数和欧拉函数

void sieve(int lim)
{
    //phi[1]=mu[1]=1;
    for(int i=2; i<=lim; ++i) {
        if(!vis[i]) pri[++cnt]=i; // phi[i]=i-1, mu[i]=-1;
        for(int j=1; j<=cnt && pri[j]*i<=lim; ++j) {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
            /*
            if(i%pri[j]==0) {
                mu[pri[j]*i]=0;
                phi[i*pri[j]]=pri[j]*phi[i];
                break;
            }
            mu[pri[j]*i]=-mu[i];
            phi[i*pri[j]]=(pri[j]-1)*phi[i];
            */ 
        }
    }
}

int main()
{
    sieve(1000000); //筛 1e6 以内素数
}