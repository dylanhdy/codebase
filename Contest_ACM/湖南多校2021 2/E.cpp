#include <bits/stdc++.h>
#define PB push_back
#define MAXN 10000005
#define MAXM 25005
#define INF 0x3f3f3f3f
using namespace std;

const int del[20]={2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1};
unordered_map<string, int> mp;
int n, ans=INF, num[MAXN], scale[20][20], vis1[MAXM], vis2[20][MAXM];
string s;

char gc()
{
  static char buf[1 << 16 | 1];
  static size_t bc, be;
  if (bc>=be) {
    buf[0]=0, bc=0;
    be=fread(buf, 1, sizeof(buf), stdin);
  }
  return buf[bc++];
}

void init()
{
    mp["Do"] = 0;
    mp["Do#"] = 1;
    mp["Re"] = 2;
    mp["Re#"] = 3;
    mp["Mi"] = 4;
    mp["Fa"] = 5;
    mp["Fa#"] = 6;
    mp["Sol"] = 7;
    mp["Sol#"] = 8;
    mp["La"] = 9;
    mp["La#"] = 10;
    mp["Si"] = 11;
    for(int i=0; i<7; ++i) {
        int temp=-1;
        for(int j=0; j<6; ++j) {
            temp+=del[i+j];
            scale[i][temp]=1;
        }
    }
    for(int sta=0; sta<(1<<11); ++sta) {
        vector<int> vec;
        for(int i=0; i<=10; ++i)
            if((sta>>i)&1) vec.PB(i);
        for(int i=0; i<7; ++i) {
            int flag=1;
            for(int j=0; j<vec.size(); ++j)
                if(!scale[i][vec[j]]) flag=0;
            vis1[sta]|=flag;
            vis2[i][sta]|=flag;
        }
    }
}

int main()
{
    init();
    cin>>n;
    for(int i=1; i<=n; ++i) {
        s="";
        char ch;
        while((ch=gc())!='\n') s+=ch;
        num[i]=mp[s];
    }
    for(int i=0; i<7; ++i) {
        int l=1, r=n, sta=0, val=1, head=num[1];
        for(; l<=n; l++) {
            if(num[l]==head) continue;
            int temp=(1<<((num[l]-head+11)%12));
            if(!vis2[i][sta|temp]) break;
            sta|=temp;
        }
        if(l==n+1) {
            printf("1\n");
            return 0;
        }
        for(; r>=l; r--) {
            if(num[r]==head) continue;
            int temp=(1<<((num[r]-head+11)%12));
            if(!vis2[i][sta|temp]) break;
            sta|=temp;
        }
        sta=0, head=num[l];
        for(int j=l+1; j<=r; ++j) {
            if(num[j]==head) continue;
            int temp=(1<<((num[j]-head+11)%12));
            if(vis1[sta|temp]) sta|=temp;
            else val++, head=num[j], sta=0;
        }
        val++;
        ans=min(ans, val);
    }
    cout<<ans<<'\n';
}