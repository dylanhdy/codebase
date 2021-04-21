#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define MAXN
#define MAXM
#define P
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define dbg(a...) fprintf(stderr, a)
using namespace std;

int T, n, q, sta;

vector<int> vec;
vector<int>::iterator it;

int main()
{
    scanf("%d%d%d", &T, &n, &q);
    while(T--) {
        vec.clear();
        vec.PB(1); vec.PB(2);
        for(int i=3; i<=n; ++i) {
            int l=0, r=vec.size()-1;
            while(l<r) {
                int mid1=l+(r-l)/3, mid2=r-(r-l)/3, midnum;
                printf("%d %d %d\n", i, vec[mid1], vec[mid2]);
                fflush(stdout);
                scanf("%d", &midnum);
                if(midnum==i) l=mid1+1, r=mid2;
                if(midnum==vec[mid1]) r=mid1;
                if(midnum==vec[mid2]) l=mid2+1;
            }
            if(l==r && l>0) {
                int midnum;
                printf("%d %d %d\n", i, vec[l-1], vec[l]);
                fflush(stdout);
                scanf("%d", &midnum);
                if(midnum==vec[l]) l++;
            }
            vec.resize(vec.size()+1);
            for(int i=vec.size()-1; i>l; --i) vec[i]=vec[i-1];
            vec[l]=i;
        }
        for(int i=0; i<n; ++i) printf("%d ", vec[i]);
        printf("\n");
        fflush(stdout);
        scanf("%d", &sta);
        if(sta==-1) return 0;
    }
    return 0;
}
/*
python runner.py python tool.py 0 -- D.exe
*/