#include <bits/stdc++.h>
#define ll __int128
using namespace std;
const int M=1e7+1e3,N=1e7;
template<typename T> void read(T &x){
    char c=getchar();x=0;int f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int prime[M],cnt=0,t;
bitset<M> is_prime;
ll Sp[M],n,mo;
void pre() {
    is_prime.set();is_prime[0]=is_prime[1]=0;
    for(int i=2;i<=N;i++){
        Sp[i]=Sp[i-1];
        if (is_prime[i])prime[++cnt]=i,Sp[i]+=i;
        for(int j=1;j<=cnt;j++){
            int res=i*prime[j];
            if (res>N) break;
            is_prime[res]=false;
            if (!(i%prime[j])) break;
        }
    }
}
ll Sum(ll x) {return x*(x+1)/2-1;}
int tot=0;
ll sp(ll n, int m) {
    if (n<=N&&n<(ll)prime[m+1]*prime[m+1])return Sp[n];
    while(n<(ll)prime[m]*prime[m])m--;
    ll las=Sum(n);
    for (;m;--m)
        las-=(sp(n/prime[m],m-1)-Sp[prime[m]-1])*prime[m];
    return las;
}
int main () {
    pre();
    read(t);
    while(t--){
        read(n);read(mo);
        long long ans=(sp(n+1,cnt-1)+((n+3)*n/2)-4)%mo;
        cout<<ans<<endl;
    }
    return 0;
}