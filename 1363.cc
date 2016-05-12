#include<stdio.h>
int main()
{int i,j,k,t,n,l[1002],s[1002];
	while(scanf("%d",&n),n){
		while(scanf("%d",&l[0]),l[0]){
			s[j]=k=j=0;
			for(i=1;i<n;i++)
				scanf("%d",&l[i]);
			for(i=0;i<n;i++){
				while(1){
					if(l[i]==s[j]){
						j--;
						break;
					}else {
						j++;
						k++;
						s[j]=k;
						if(k>n)
							break;
					}
				}
				if(k>n)break;
			}
			if(j==0)
				printf("Yes\n");
			else 
				printf("No\n");
		}
		printf("\n");
	}
}