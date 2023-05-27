#include <bits/stdc++.h>
using namespace std;
int T;
int mp[10005][10005];
int n,m,q;
void p0(int n2,int cl)
{
	for(int i=1;i<=m;++i)
	{
		mp[n2][i]=cl;
		}
}
void p1(int n2,int cl)
{
	for(int i=1;i<=n;++i)
	{
		mp[i][n2]=cl;
		}
}
void ot()
{
	for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j)
					cout<<mp[i][j]<<" ";
	cout<<"\n";
	}
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>q;			
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=q;++i){

			int op,x,c;
			cin>>op>>x>>c;
			if(op==0){
				p0(x,c);
				//ot();
				//cout<<endl;
			}
			else if(op==1)
			{	
				p1(x,c);
				//ot();
				//cout<<endl;
				}
			}
			ot();
			//cout<<endl;
	}
	return 0;
}
