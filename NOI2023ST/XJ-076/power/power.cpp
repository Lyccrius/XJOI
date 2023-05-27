		#include<bits/stdc++.h>
		using namespace std;
		int line[100000000];
		int main()
		{
			freopen("power.in","r",stdin);
			freopen("power.out","w",stdout);
			unsigned long long int k,a=1,n,all=0;
			cin>>n>>k;
			while(1)
			{
				unsigned long long int ans=a;
				for(unsigned long long int i=1;i<k;i++)
				{
					ans=ans*a;
				}
				if(ans>n)
				{
					if(a==2||k>100)
					{
						break;
					}
					k++;
					a=1;
				}
				if(line[ans]==0&&ans<=n)
				{
					all++;
				}
				line[ans]=1;
				a++;
			}
			cout<<all;
			cout<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
