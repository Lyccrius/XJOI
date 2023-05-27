#include <bits/stdc++.h>
using namespace std;

int n;
struct node
{
	double x,y;
}a[10005];
double m[1005][1005],l,flag;
int k,f=0,o,p;
int main()
{
	freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++)
    {
		cin >> a[i].x >> a[i].y;
		if(a[i].y>flag)
		{
			flag=a[i].y;
			k=i;
		}
	}
	double aaa=pow(a[k].x-a[k+1].x,2)+pow(a[k].y-a[k+1].y,2);
	double bbb=pow(a[k].x-a[k-1].x,2)+pow(a[k].y-a[k-1].y,2);
	m[k][k+1]=sqrt(aaa);
	m[k][k-1]=sqrt(bbb);
	if(m[k][(k+1)%n]>m[k][k-1])
	{
		p=(k+1)%n;f=2;
	}
	else//xiangdenghaimeikaolv
	{
		p=k-1;f=1;
	}                                                                                                                                    
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double aa,bb;
			aa = pow(a[i].x-a[j].x,2);
			bb= pow(a[i].y-a[j].y,2);
			m[i][j] = sqrt(aa+bb);
			if(flag<m[i][j] && i+1!=k)
			{
				flag=m[i][j];
				o=i+1;
			}
		}
	}
	
	if(f==1)
	{
		o-=1;
	}
	//cout << k << "  " << o << " " << " "<< p << endl;
	if(f==2)
	{
		//cout << "wangyou" << endl;
		for(int i=k;i>=o;i--)
		{
			cout << i << " ";
		}
		for(int i=p;i<=(o-1);i++)
		{
			if(i==n+1) i=1;
			cout << i%(n+1) << " ";
		}
	}  
	else
	{
		//cout << "wangzuo" << endl;
		if(m[o][p]< m[o-1][o]+m[p][p-1])
		{
			for(int i=k;i>=o%(n+1);i=(i+1)%(n+1))
			{
				cout << i << " ";
			}
			for(int i=p;i>=o-1;i--)
			{
				cout << i << " ";
			}
		}
		else
		{
			for(int i=k,num=1;num<=n;num++,i++)
			{
				if(i==n+1) i=1;
				cout << i%(n+1) << " ";
			}
		}
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
