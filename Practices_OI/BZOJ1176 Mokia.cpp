//
//  main.cpp
//  BZOJ1176 Mokia
//
//  Created by 黄道煜 on 2018/8/26.
//  Copyright © 2018年 黄道煜. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500005
#define MAXM 2000005
#define LL long long
using namespace std;

int s, w, op, cnt1, cnt2, ans[MAXN], t[MAXM];

void add(int x, int y)
{
    for(; x<=w+1; x+=(x&-x)) t[x]+=y;
}

int query(int x)
{
    int sum=0;
    for(; x; x-=(x&-x)) sum+=t[x];
    return sum;
}

struct Ask {int x, y, w, op, id;} a[MAXN], b[MAXN];

bool CMP (Ask a, Ask b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

void cdq(int l, int r)
{
    if(l==r) return ;
    int mid=(l+r)>>1;
    cdq(l, mid); cdq(mid+1, r);
    
    int j=l;
    for(int i=mid+1; i<=r; i++)
    {
        if(a[i].op==1) continue;
        while(j<=mid && a[j].x<=a[i].x)
        {
            if(a[j].op==1) add(a[j].y, a[j].w);
            j++;
        }
        if(a[i].op==2) ans[a[i].id]+=query(a[i].y);
        if(a[i].op==3) ans[a[i].id]-=query(a[i].y);
    }
    for(int i=l; i<j; i++) if(a[i].op==1) add(a[i].y, -a[i].w);
    
    merge(a+l, a+mid+1, a+mid+1, a+r+1, b+l, CMP);
    for(int i=l; i<=r; i++) a[i]=b[i];
}

int main()
{
    scanf("%d%d", &s, &w);
    while(scanf("%d", &op) && op!=3)
    {
        if(op==1)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            a[++cnt1].x=x; a[cnt1].y=y; a[cnt1].w=z; a[cnt1].op=1;
        }
        if(op==2)
        {
            int x1, y1, x2, y2; cnt2++;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            a[++cnt1].x=x1-1; a[cnt1].y=y1-1; a[cnt1].op=2; a[cnt1].id=cnt2;
            a[++cnt1].x=x1-1; a[cnt1].y=y2; a[cnt1].op=3; a[cnt1].id=cnt2;
            a[++cnt1].x=x2; a[cnt1].y=y2; a[cnt1].op=2; a[cnt1].id=cnt2;
            a[++cnt1].x=x2; a[cnt1].y=y1-1; a[cnt1].op=3; a[cnt1].id=cnt2;
        }
    }
    cdq(1, cnt1);
    for(int i=1; i<=cnt2; i++) printf("%d\n", ans[i]);
}
