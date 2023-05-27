#include<bits/stdc++.h>
#include<vector>
#define LL long long
using namespace std;
LL n,ans=1;
int k;
bool flag=true;
LL pows[123123123],cnt;

bool check(LL a)
{
	for(int i=1;i<=cnt;i++)
		if(a==pows[i])
			return false;
	return true;
}

int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);

    cin>>n>>k;
    if(k==1)
    {
        cout<<n<<endl;  
        return 0;      
    }

    for(int i=2;i*i<=n&&flag;i++)
    {
		LL a=i;

		for(int j=1;j<k&&flag;j++)
		{
			a*=i;
			if(a>n)
				flag=0;
		}
		while(flag)
		{
			if(check(a))
			{
				pows[++cnt]=a;
				//cout<<a<<' ';
				ans++;
			}
			a*=i;
			if(a>n)
			{
				flag=0;break;				
			}
		}
		flag=1;
	}

    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
