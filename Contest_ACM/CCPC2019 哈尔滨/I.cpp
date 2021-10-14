#include "bits/stdc++.h"
#define P 1000000007
#define MAXN 100005
using namespace std;

int T, n, a[MAXN], fac[MAXN], ifac[MAXN];

void init(int lim)
{
  ifac[0]=ifac[1]=fac[0]=fac[1]=1;
  for(int i=2; i<=lim; ++i) ifac[i]=1LL*ifac[P%i]*(P-P/i)%P;
  for(int i=2; i<=lim; ++i) {
    ifac[i]=1LL*ifac[i-1]*ifac[i]%P;
    fac[i]=1LL*fac[i-1]*i%P;
  }
}

int comb(int x, int y)
{
  return 1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int main()
{
  init(1e5);
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
    int flag=1;
    for(int i=0; i<n; ++i) {
      if(a[i]<i) flag=0;
      if(i && a[i]<a[i-1]) flag=0;
    }
    if(a[0]!=0 || a[n-1]!=n-1) flag=0;
    if(!flag) {
      printf("0\n");
      continue;
    }
    int ans=1;
    for(int i=n-1; i>=1; --i)
      if(a[i]>a[i-1]) ans=1LL*ans*2*fac[a[i]-i]%P*ifac[a[i-1]+1-i]%P;
    printf("%d\n", ans);
  }
}
