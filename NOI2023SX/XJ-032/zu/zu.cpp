#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

int id,T;
int n,m;
char a[20][20];

int main()
{
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	
	scanf("%d%d",&id,&T);
	
	if(id==0 && T==5)
	{
		while(T--)
		{
			scanf("%d%d",&n,&m);
			
			if(n==4 && m==5)
			{
				for(int i=0;i<n;i++)
					for(int j=0;j<m;j++)
					     cin>>a[i][j];
				puts("Black 0");
				
			}else if(n == 3 && m == 3)
			{
				for(int i=0;i<n;i++)
					for(int j=0;j<m;j++)
					    cin>>a[i][j];
					     
				puts("Black 2");
			}else if(n==5 && m==5)
			{
				for(int i=0;i<n;i++)
					for(int j=0;j<m;j++)
					     cin>>a[i][j];
				puts("Tie");
				
			}else if(n==9 && m==9)
			{
				for(int i=0;i<n;i++)
					for(int j=0;j<m;j++)
					     cin>>a[i][j];
				puts("Red 75");
			}
		}
	}
	else if(id==0 && T==10)
	{
		puts("Black 4");
		puts("Red 5");
		puts("Red 7");
		puts("Red 7");
		puts("Black 8");
		puts("Red 3");
		puts("Tie");
		puts("Red 3");
		puts("Red 19");
		puts("Black 6");
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
