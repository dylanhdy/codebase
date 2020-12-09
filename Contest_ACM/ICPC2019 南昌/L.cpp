#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define LL long long
#define LD long double
#define MAXN 105
#define MAXM
#define P
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;

int n, sco[MAXN][MAXN], val1[MAXN], val2[MAXN], max1=-INF, max2=-INF;

vector<int> vec1, vec2;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) scanf("%d", &sco[i][j]);
    for(int i=1; i<=n; ++i)
        for(int j=i+1; j<=n; ++j)
        {
            if(sco[i][j]==sco[j][i]) val1[i]++, val1[j]++;
            if(sco[i][j]>sco[j][i])
            {
                val1[i]+=3;
                val2[i]+=sco[i][j]-sco[j][i];
                val2[j]+=sco[j][i]-sco[i][j];
            }
            if(sco[j][i]>sco[i][j])
            {
                val1[j]+=3;
                val2[i]+=sco[i][j]-sco[j][i];
                val2[j]+=sco[j][i]-sco[i][j];
            }
        }
    for(int i=1; i<=n; ++i)
    {
        if(val1[i]>max1)
        {
            max1=val1[i];
            vec1.clear();
        }
        if(val1[i]==max1) vec1.pb(i);
        
    }
    if(vec1.size()==1) printf("%d\n", vec1[0]);
    if(vec1.size()>1)
    {
        for(int i=0; i<vec1.size(); ++i)
        {
            if(val2[vec1[i]]>max2)
            {
                vec2.clear();
                max2=val2[vec1[i]];
            }
            if(max2==val2[vec1[i]]) vec2.pb(vec1[i]);
        }
        if(vec2.size()==1) printf("%d\n", vec2[0]);
        else printf("play-offs\n");
    }
    return 0;
}