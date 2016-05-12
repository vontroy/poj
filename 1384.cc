#include<stdio.h>
#include<memory.h>
int n,weight,v[501],w[501],wv[10001];
int main()
{
    int i,j,cn,e,f,t;
    scanf("%d",&cn);
    while(cn--)
    {
        memset(wv,0,sizeof(wv));
        scanf("%d %d",&e,&f);
        weight=f-e;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d %d",&v[i],&w[i]);
        for(i=1;i<=weight;i++)
        {
            for(j=0;j<n;j++)
            {
                t=i-w[j];
                if((t==0||t>0&&wv[t]>0)&&(wv[i]==0||wv[t]+v[j]<wv[i]))wv[i]=wv[t]+v[j];   
            }    
        }    
        if(wv[weight]==0&&weight)printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",wv[weight]);
    }    
    return 0;
}    