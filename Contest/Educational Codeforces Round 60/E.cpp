#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 10005
#define P 998244353
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int len, pos[MAXN];
char s[MAXN], t[MAXN], ans[MAXN];

void print1()
{
    printf("? ");
    for(rint i=0; ; i++)
        for(rint j=0; j<26; j++)
            for(rint k=0; k<26; k++)
            {
                if(i*676+j*26+k==len)
                {
                    printf("\n");
                    fflush(stdout);
                    return;
                }
                printf("%c", 'a'+k);
            }
    
}

void print2()
{
    printf("? ");
    for(rint i=0; ; i++)
        for(rint j=0; j<26; j++)
            for(rint k=0; k<26; k++)
            {
                if(i*676+j*26+k==len)
                {
                    printf("\n");
                    fflush(stdout);
                    return;
                }
                printf("%c", 'a'+j);
            }
}

void print3()
{
    printf("? ");
    for(rint i=0; ; i++)
        for(rint j=0; j<26; j++)
            for(rint k=0; k<26; k++)
            {
                if(i*676+j*26+k==len)
                {
                    printf("\n");
                    fflush(stdout);
                    return;
                }
                printf("%c", 'a'+i);
            }
}

int main()
{
    scanf("%s", s);
    len=strlen(s);
    print1();
    scanf("%s", t);
    for(rint i=0; i<len; ++i) pos[i]=t[i]-'a';
    print2();
    scanf("%s", t);
    for(rint i=0; i<len; ++i) pos[i]+=(t[i]-'a')*26;
    print3();
    scanf("%s", t);
    for(rint i=0; i<len; ++i) pos[i]+=(t[i]-'a')*676;
    printf("! ");
    for(rint i=0; i<len; ++i) ans[pos[i]]=s[i];
    printf("%s\n", ans);
    return 0;
}
