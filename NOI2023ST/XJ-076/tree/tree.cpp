	#include<bits/stdc++.h>
	using namespace std;
	float num[10100][3];
	int used[10100];
	float dis(float x1,float x2,float y1,float y2)
	{
			return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	}	
	int main()
	{
		freopen("tree.in","r",stdin);
		freopen("tree.out","w",stdout);
		int n,may=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>num[i][1]>>num[i][2];
			if(num[i][2]>num[may][2])
			{
				may=i;
			}	
		}
		cout<<may<<" ";
		int need=n;
		while((need--)!=1)
		{
			used[may]=1;
			float per=0;
			float diss=100000000000000000;
			for(int i=1;i<=n;i++)
			{
	//			cout<<"!";
				if(used[i]==0)
				{
	//				cout<<":";
	//				cout<<may<<"><"<<i<<":"<<dis(num[may][1],num[i][1],num[may][2],num[i][2])<<" ";
					if(dis(num[may][1],num[i][1],num[may][2],num[i][2])<diss)
					{
						diss=dis(num[may][1],num[i][1],num[may][2],num[i][2]);
	//					cout<<diss<<":";
						per=i;
	//					cout<<i<<">";
					}
				}
			}
			cout<<per<<" ";
			may=per;
		}
		cout<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
