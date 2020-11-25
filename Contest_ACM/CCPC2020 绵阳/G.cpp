#include <cstdio>
#include <algorithm>
using namespace std;

int T, c0, c1, c2, c3;

int main()
{
	scanf("%d", &T);
	for(int qwq=1; qwq<=T; ++qwq)
	{
		scanf("%d%d%d%d", &c0, &c1, &c2, &c3);
		if(c1+c2+c3==0)
		{
			if(c0%2 || c0==0) printf("Case #%d: Horse\n", qwq);
			else printf("Case #%d: Rabbit\n", qwq);
			continue;
		}
        if(c0%2)
        {
            if(c2==0)
		    {
		    	if(c1%3==2) printf("Case #%d: Horse\n", qwq);
		    	else printf("Case #%d: Rabbit\n", qwq);
		    }
            else if(c2==1)
            {
                if(c1%3==0) printf("Case #%d: Rabbit\n", qwq);
                else printf("Case #%d: Horse\n", qwq);
            }
            else
            {
                if(c1%3==1) printf("Case #%d: Horse\n", qwq);
                else printf("Case #%d: Rabbit\n", qwq);
            }
        }
        else
        {
            if(c2==0)
		    {
		    	if(c1%3==2) printf("Case #%d: Rabbit\n", qwq);
		    	else printf("Case #%d: Horse\n", qwq);
		    }
		    else
		    {
		    	if(c1%3==0) printf("Case #%d: Horse\n", qwq);
		    	else printf("Case #%d: Rabbit\n", qwq);
		    }
        }
	}
}