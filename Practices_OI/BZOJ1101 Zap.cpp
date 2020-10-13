//
//  main.cpp
//  BZOJ1101 Zap
//
//  Created by 黄道煜 on 2018/8/6.
//  Copyright © 2018年 黄道煜. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#define MAXN 500005
#define LL long long
using namespace std;

int n, a, b, d, cnt, pri[MAXN], tag[MAXN], mob[MAXN];

void init()
{
    mob[1]=1;
    for(int i=2; i<=50000; i++)
    {
        if(!tag[i]) pri[++cnt]=i, mob[i]=-1;
        for(int j=1; j<=cnt && pri[j]*i<=50000; j++)
        {
            tag[i*pri[j]]=1;
            if(i%pri[j]==0) {mob[i*pri[j]]=0; break;}
            else mob[i*pri[j]]=-mob[i];
        }
    }
}

int main()
{
    init();
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int ans=0;
        scanf("%d%d%d", &a, &b, &d);
        a/=d; b/=d;
        for(int i=1; i<=min(a, b); i++) ans+=mob[i]*(a/i)*(b/i);
        printf("%d\n", ans);
    }
}
