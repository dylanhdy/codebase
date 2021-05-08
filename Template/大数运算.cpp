#include <bits/stdc++.h>
#define MAXL 2005
using namespace std;

string add(string a, string b)//只限两个非负整数相加  
{  
    string ans;  
    int na[MAXL]={0}, nb[MAXL]={0};  
    int la=a.size(), lb=b.size();  
    for(int i=0; i<la; i++) na[la-1-i]=a[i]-'0';  
    for(int i=0; i<lb; i++) nb[lb-1-i]=b[i]-'0';  
    int lmax=la>lb?la:lb;  
    for(int i=0; i<lmax; i++) na[i]+=nb[i], na[i+1]+=na[i]/10, na[i]%=10;  
    if(na[lmax]) lmax++;  
    for(int i=lmax-1; i>=0; i--) ans+=na[i]+'0';  
    return ans;  
}  

string sub(string a, string b)//只限大的非负整数减小的非负整数  
{  
    string ans;  
    int na[MAXL]={0}, nb[MAXL]={0};  
    int la=a.size(), lb=b.size();  
    for(int i=0; i<la; i++) na[la-1-i]=a[i]-'0';  
    for(int i=0; i<lb; i++) nb[lb-1-i]=b[i]-'0';  
    int lmax=la>lb?la:lb;  
    for(int i=0; i<lmax; i++)  
    {  
        na[i]-=nb[i];  
        if(na[i]<0) na[i]+=10, na[i+1]--;  
    }  
    while(!na[--lmax]&&lmax>0)  ;lmax++;  
    for(int i=lmax-1; i>=0; i--) ans+=na[i]+'0';
    return ans;  
}   

string mul(string a, string b)//高精度乘法 a, b 均为非负整数  
{  
    string ans;  
    int na[MAXL]={0}, nb[MAXL]={0}, nc[MAXL]={0}, La=a.size(), Lb=b.size();//na存储被乘数，nb存储乘数，nc存储积
    for(int i=La-1; i>=0; i--) na[La-i]=a[i]-'0';//将字符串表示的大整形数转成i整形数组表示的大整形数  
    for(int i=Lb-1; i>=0; i--) nb[Lb-i]=b[i]-'0';  
    for(int i=1; i<=La; i++)  
        for(int j=1; j<=Lb; j++)  
        nc[i+j-1]+=na[i]*nb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）  
    for(int i=1; i<=La+Lb; i++)  
        nc[i+1]+=nc[i]/10, nc[i]%=10;//统一处理进位  
    if(nc[La+Lb]) ans+=nc[La+Lb]+'0';//判断第i+j位上的数字是不是0  
    for(int i=La+Lb-1; i>=1; i--)  
        ans+=nc[i]+'0';//将整形数组转成字符串  
    return ans;  
}  

string div(string a, int b)//高精度a除以单精度b  
{  
    string r, ans;  
    int d=0;  
    for(int i=0; i<a.size(); i++)  
    {  
        r+=(d*10+a[i]-'0')/b+'0';//求出商  
        d=(d*10+(a[i]-'0'))%b;//求出余数  
    }  
    int p=0;  
    for(int i=0; i<r.size(); i++)  
        if(r[i]!='0') {p=i; break;}  
    return r.substr(p);  
}

int main()
{
    string a, b;
    cin>>a>>b;
    cout<<mul(a, b)<<endl;
}