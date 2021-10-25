#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <iostream>
#include <iomanip>
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

string s;
string t[4]={"ATK Rate", "ATK", "Crit DMG Rate", "Crit Rate"};
double val[4];

int main()
{
    val[2]=50, val[3]=5;
    for(int i=1; i<=25; ++i) {
        getline(cin, s);
        for(int j=0; j<4; ++j)
            if(s.find(t[j])==0) {
                int st=t[j].length()+1;
                int len=s.length()-t[j].length()-1-(j!=1);
                val[j]+=stof(s.substr(st, len));
                break;
            }
    }
    val[3]=min(100.0, val[3]);
    double atk=1500*(1+val[0]/100)+val[1];
    cout<<fixed<<setprecision(10)<<atk+atk*val[3]*val[2]/10000<<'\n';
    return 0;
}
/*
ATK+10.00
ATK Rate+10%
Crit Rate+10.00%
HP+10.00
DEF Rate+10.00%
Energy Recharge Rate+10.00%
ATK+10.00
Crit Rate+10.00%
Crit DMG Rate+10.00%
DEF Rate+10%
ATK+10.00
ATK Rate+10.00%
Elemental DMG Rate+10%
Crit DMG Rate+10.00%
Crit Rate+10.00%
Crit DMG Rate+10.00%
ATK Rate+10%
Healing Bonus Rate+10.00%
HP+10
DEF Rate+10.00%
ATK+10
ATK Rate+10%
HP Rate+10.00%
HP+10
DEF Rate+10.00%
*/