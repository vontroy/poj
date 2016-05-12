#include<stdio.h>
#include<memory.h>
#include<algorithm>
#define MAX 200002
using namespace std;
struct node{
    int right,left,count;
    int start,end,mid,area;
}tree[MAX];
struct event{
    int x,y1,y2;
    bool flag;
    bool friend operator <(const event &a,const event &b)
    {
        return a.x<b.x;
    }    
}e[2002];    
void construct(int s,int e,int d)
{
    tree[d].start=s;tree[d].end=e;tree[d].mid=(s+e)/2;
    if(s+1==e)return;
    construct(s,(s+e)/2,d*2+1),construct((s+e)/2,e,d*2+2);
}
void init()
{
    int i;
    for(i=0;i<MAX;i++)
        tree[i].right=tree[i].left=tree[i].count=tree[i].area=0;
}
int give(int s,int e,int d)
{
    if(tree[d].start>=s&&tree[d].end<=e)tree[d].count++;
    else
    {
        if(tree[d].mid>s)tree[d].left=give(s,e,d*2+1);
        if(tree[d].mid<e)tree[d].right=give(s,e,d*2+2);
    }
    if(tree[d].count)tree[d].area=tree[d].end-tree[d].start;
    else tree[d].area=tree[d].left+tree[d].right;
    return tree[d].area;
}
int del(int s,int e,int d)
{
    if(tree[d].start>=s&&tree[d].end<=e)tree[d].count--;
    else
    {
        if(tree[d].mid>s)tree[d].left=del(s,e,d*2+1);
        if(tree[d].mid<e)tree[d].right=del(s,e,d*2+2);
    }
    if(tree[d].count)tree[d].area=tree[d].end-tree[d].start;
    else tree[d].area=tree[d].left+tree[d].right;
    return tree[d].area;
}           
int main()
{
    int i,j,x1,y1,x2,y2,n,xt,lt;
    int sum;
    construct(0,50000,0);
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2),x1!=-1&&y1!=-1&&x2!=-1&&y2!=-1)
    {
        init();
        n=0;sum=0;
        do
        {
            if(y1>y2)swap(y1,y2);
            e[n].x=x1;e[n].y1=y1;e[n].y2=y2;e[n].flag=0;n++;
            e[n].x=x2;e[n].y1=y1;e[n].y2=y2;e[n].flag=1;n++;
        }    
        while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2),x1!=-1&&y1!=-1&&x2!=-1&&y2!=-1);
        sort(e,e+n);
        //for(i=0;i<n;i++)printf("%d %d %d %d %d\n",i,e[i].flag,e[i].x,e[i].y1,e[i].y2);

        give(e[0].y1,e[0].y2,0);
        xt=e[0].x;lt=tree[0].area;
        for(i=1;i<n;i++)
        {
            if(e[i].flag)del(e[i].y1,e[i].y2,0);
            else give(e[i].y1,e[i].y2,0);
            sum+=(e[i].x-xt)*lt;
            xt=e[i].x,lt=tree[0].area;
        }    
        printf("%d\n",sum);
    }    
    return 0;
} 