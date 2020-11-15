#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 55
#define MAXM
#define P
#define INF 0x3f3f3f3f
using namespace std;

int n, tag, l, r, a[MAXN], pos[MAXN];

vector<int> ans[MAXN], vec[MAXN];

void solve(int num)
{
    int now=1;
    for(int i=0; i<ans[num].size(); ++i)
    {
        vec[i].clear();
        for(int j=0; j<ans[num][i]; ++j)
        {
            
            vec[i].push_back(a[now]);
            now++;
        }
    }
    now=1;
    for(int i=ans[num].size()-1; i>=0; --i)
        for(int j=0; j<ans[num][i]; ++j)
        {
            //printf("%d ", vec[i][j]);
            a[now]=vec[i][j];
            pos[a[now]]=now;
            now++;
        }//printf("\n");
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        pos[a[i]]=i;
    }
    l=r=pos[1];
    for(int i=1; i<n; ++i)
    {
        
        if(pos[i+1]<l)
        {
            if(pos[i+1]>1)
                ans[i].push_back(pos[i+1]-1);
            ans[i].push_back(l-pos[i+1]);
            if(!tag)
                ans[i].push_back(i);
            else
            {
                for(int j=1; j<=i; ++j)
                    ans[i].push_back(1);
                tag=0;
            }
            if(n>r)
                ans[i].push_back(n-r);
            swap(l, r);
            l=n-l+1, r=n-r+2;
        }
        else
        {
            if(l>1)
                ans[i].push_back(l-1);
            if(tag)
                ans[i].push_back(i);
            else
            {
                for(int j=1; j<=i; ++j)
                    ans[i].push_back(1);
                tag=1;
            }
            ans[i].push_back(pos[i+1]-r);
            if(n>pos[i+1])
                ans[i].push_back(n-pos[i+1]);
            swap(l, r);
            l=n-l, r=n-r+1;
        }
        //printf("%d %d\n", l, r);
        solve(i);
    }
    if(tag)
    {
        printf("%d\n", n);
        for(int i=1; i<n; ++i)
        {
            printf("%d ", ans[i].size());
            for(int j=0; j<ans[i].size(); ++j)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
        printf("%d ", n);
        for(int i=1; i<=n; ++i)
            printf("1 ");
        printf("\n");
    }
    else
    {
        printf("%d\n", n-1);
        for(int i=1; i<n; ++i)
        {
            printf("%d ", ans[i].size());
            for(int j=0; j<ans[i].size(); ++j)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}