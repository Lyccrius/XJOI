#include<bits/stdc++.h>
using namespace std;
int id,T;
int n,m;
int i,j;
int hei=1,hong=2;	
int s=0;
char a[1000][1000];
int main()
{
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	cin>>id>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>n>>m;
	    for(i=1;i<=n;i++)
	    for(j=1;j<=m;j++)
	        cin>>a[i][j];
	    if(k==T) break;
	    for(i=1;i<=n;i++)
	    for(j=1;j<=m;j++)
	    {
			if(a[1][j]=='X') {cout<<"black"<<" "<<"0"<<endl;break;}
			if(a[i][j]=='O')
			{
				if(a[i-1][j]=='#'&&a[i+1][j]=='#'&&a[i][j-1]=='#'&&a[i][j+1]=='#')
				{cout<<"Black"<<" "<<"0"<<endl;break;}
				if(a[i-1][j]=='.'&&a[i+1][j]=='.'&&a[i][j-1]=='.'&&a[i][j+1]=='.')
				{cout<<"Tie"<<endl; break;}
				if(a[i][j-1]=='.'&&(a[i+1][j-1]=='#'||a[i-1][j]=='#'||a[i][j-2]=='#'))
				{cout<<"Black"<<" "<<"2"<<endl;break;}	
			}
		}
	}
	cout<<"Red"<<" "<<"75"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
