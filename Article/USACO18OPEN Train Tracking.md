### 问题描述

简单来说就是限制空间，给你一个大小为 $5500$ 的数组，除该数组外不能调用其他储存。

然后有一辆长度为 $n$ 的火车，第 $i$ 节车厢上有编号 $c_i$，你需要按顺序输出每 $k$ 节车厢中的最小编号。

### 输入 & 输出

因为交互题，内容较多，详细内容见链接 [Train Tracking 题面](http://usaco.org/index.php?page=viewproblem2&cpid=841 "Train Tracking 题面")。

### 思路

我们设 $f_i​$ 为 从 $i-k+1​$ 到 $i​$ 中最小值的下标，对于 $f​$ 不难想到用单调队列去优化，但是显然是不能将所有元素加入队列中，这时我们就可以利用分块。我们设 $siz​$ 为块的大小，第一遍扫过去时只计算 $f_{x*siz+k}​$，这样就只需要把每一个块中的最小值放入队列中，并记录下 $f_{x*siz+k}​$ 给第二遍的时候用。

第二遍时我们就需要根据 $f_{x*siz+k}$ 计算出所有的 $f$。我首先可以先忽略掉下标小于 $f_0$ 的元素，然后用一个大小同为 $siz​$ 的单调队列维护最前的一段，后面的只需要记录下最小值就行了。如果当前扫到的位置是所在块的最小值，那么就可以先输出这一块之前的答案，并建立新的单调队列。


### 代码

```cpp
#include "grader.h"
/*
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, curcar, curpas, sub[5505], a[1000006];

int get(int id)
{
    return sub[id];
}

void set(int id, int val)
{
    sub[id]=val;
}

void shoutMinimum(int x)
{
    printf("%d\n", x);
}

int getTrainLength()
{
    return n;
}

int getWindowLength()
{
    return k;
}

int getCurrentCarIndex()
{
    return curcar;
}

int getCurrentPassIndex()
{
    return curpas;
}*/

void helpBessie(int val)
{
    int op=getCurrentPassIndex();
    int k=getWindowLength();
    int n=getTrainLength();
    int i=getCurrentCarIndex();
    int siz=1000, QWQ=4400, INF=0x3f3f3f3f;
    if(!op)
    {
        if(i==0) set(0, 0), set(1, -1);
        int head=get(1), tail=get(0);
        if(i%siz==0 || (i>=k && (i-k)%siz==0))
        {
            while(head>=tail && get(2*head+3)>=val) head--;
            head++;
            set(2*head+2, i);
            set(2*head+3, val);
        }
        else
        {
            int headval=get(head*2+3);
            if(val<=headval)
            {
                while(head>=tail && get(2*head+3)>=val) head--;
                head++;
                set(2*head+2, i);
                set(2*head+3, val);
            }
        }
        if(i>=k-1 && (i+1-k)%siz==0)
        {
            while(head>=tail && get(tail*2+2)<=i-k) tail++;
            set(QWQ+(i+1-k)/siz, get(tail*2+2));
        }
        set(0, tail), set(1, head);
    }
    else
    {
        if(i<get(QWQ)) return;
        if(i==get(QWQ))
        {
            set(0, 0), set(1, -1);
            set(QWQ-1, 1);
            set(QWQ-2, INF);
            set(QWQ-3, 0);
        }
        int block=get(QWQ-1), l=get(QWQ-3);
        int head=get(1), tail=get(0);
        if(i-get(QWQ+block-1)<=siz)
        {
            while(head>=tail && get(2*head+3)>=val) head--;
            head++;
            set(2*head+2, i);
            set(2*head+3, val);
        }
        else
        {
            int minnum=get(QWQ-2);
            if(val<minnum) set(QWQ-2, val);
        }
        if(l+k-1==i)
        {
            while(head>=tail && get(tail*2+2)<l) tail++;
            int a=get(QWQ-2), b=get(2*tail+3);
            shoutMinimum(a<b?a:b);
            l++;
        }
        while(siz*block+k-1<n && get(QWQ+block)==i)
        {
            while(l<=siz*block)
            {
                while(head>=tail && get(tail*2+2)<l) tail++;
                int a=get(QWQ-2), b=get(2*tail+3);
                shoutMinimum(a<b?a:b);
                l++;
            }
            block++;
            set(QWQ-2, INF);
            head=tail=0;
            set(2*head+2, i);
            set(2*head+3, val);
        }
        set(QWQ-1, block), set(QWQ-3, l);
        set(0, tail), set(1, head);
    }
}

/*
int main()
{
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
        curcar=i, curpas=0;
        helpBessie(a[i]);
    }
    for(int i=0; i<n; ++i)
    {
        curcar=i, curpas=1;
        helpBessie(a[i]);
    }
}*/

```