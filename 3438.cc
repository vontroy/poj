#include<stdio.h>
int main()
{
	int j,n;
	int a[30]={0};
	char num[1100];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",num);
		for(j=0;num[j]!='\0';j++)
		{
				a[num[j]-'0']++; 
			if(num[j+1]!=num[j])
			{
			  printf("%d%c",a[num[j]-'0'],num[j]);
			  a[num[j]-'0']=0;
			}
		}
		printf("\n");
	}
	return 0;
}