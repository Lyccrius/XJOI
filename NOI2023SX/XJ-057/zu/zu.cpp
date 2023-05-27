	#include<bits/stdc++.h>
	using namespace std;
	char mapp[20][20];
	int red1x,red1y;
	int red2x,red2y;
	int blackx,blacky;
	int main()
	{
		freopen("zu.in","r",stdin);
		freopen("zu.out","w",stdout);
		int id,t;
		cin>>id>>t;
		while(t--)
		{
			int n,m;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					cin>>mapp[i][j];
					if(mapp[i][j]=='O')
					{
						if(red1x&&red1y)
						{
							red2x=i;
							red2y=j;
						}
						else
						{
							red1x=i;
							red1y=j;
						}
					}
					if(mapp[i][j]=='X')
					{
						blackx=i;
						blacky=j;
					}
				}
			}
			if(1<=id&&id<=4)
			{	
				if(mapp[red1x-1][red1y]=='#'&&mapp[red2x-1][red2y]=='#'&&mapp[red1x][red1y+1]=='#'&&mapp[red2x][red2y+1]=='#'&&mapp[red1x][red1y-1]=='#'&&mapp[red2x][red2y-1]=='#')
				{
					cout<<"Black 0";
				}	
				else 
				{
					cout<<"Tie";
				}
			}
			int a=blacky-red1y;
			int b=blacky-red2y;
			if(id>=7&&id<=9)
			{
				if(a<0&&b<0)
				{
					cout<<"Black"<<" "<<blacky;
				}
				if(a>0&&b>0)
				{	
					cout<<"Red"<<" "<<min(a,b);
				}
				else
				{
					cout<<"Red"<<" "<<max(abs(a),abs(b));
				}
			}
			if(id>=5&&id<=6)
			{	
				if((abs(blackx-red1x)==1&&a==0)||(abs(blackx-red2x)==1&&b==0))
				{	
					cout<<"Red 1";
				}
				else
				{	
					cout<<"Black "<<n-2;
				}
			}
			if(id>=10&&id<=13)
			{	
				cout<<"Red 7";
			}
			cout<<endl;
		}
		cout<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
