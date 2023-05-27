#include<bits/stdc++.h>
using namespace std;
struct aa
{
	double x;
	double y;
}a[1005];
double grah[1005][1005];
double answers[1005];
int t=0;
int n;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].x>>a[i].y;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			grah[i][j]=grah[j][i]=sqrt(pow((a[i].x-a[j].x),2)+pow((a[i].y-a[j].y),2));
		}
	}
	int maxx=INT_MIN,tk;
	for(int i=0;i<n;i++)
	{
		if(a[i].y>maxx)
		{
			tk=i;
			maxx=a[i].y;
		}
	}
	
	int i=tk;
	int l=1;
	cout<<i+1<<' ';
	while(l!=n)
	{
		double minn=INT_MAX;
		int t;
		for(int j=0;j<n;j++)
			if(minn>grah[i][j]&&grah[i][j]!=0)
			{
				minn=grah[i][j];
				t=j;
				grah[i][j]=grah[j][i];
			}
		for(int j=0;j<n;j++)
		{
			grah[i][j]=grah[j][i]=0;
		}
			
		cout<<t+1<<' ';
		i=t;
		l++;
	}
	
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
