#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,a[N][N],m,x,y;
string st;
void priNt(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<(char)(a[i][j]+'0');
		cout<<endl;
	}
}
void rotAte(int x,int y){
	if(y==0)return;
	rotAte(x,y-1);
	int t;
	for(int i=x;i<n-x+1;i++){
		t=a[i][n-x+1];
		a[i][n-x+1]=a[x][i];
		a[x][i]=a[n-i+1][x];
		a[n-i+1][x]=a[n-x+1][n-i+1];
		a[n-x+1][n-i+1]=t;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st;
		for(int j=0;j<n;j++)a[i][j+1]=st[j]-'0';
	}
	cin>>m;
	while(m--){
		cin>>st;
		if(st[0]=='P'){
			priNt();
			continue;
		}
		cin>>x>>y;
		if(st[0]=='L')y=(4-y%4)%4;
        y=y%4;
		rotAte(x,y);
	}
}