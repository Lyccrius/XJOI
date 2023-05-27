#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int k;
    long long n,s=0,a;
    cin>>n>>k;
    if(k==1)
    {
        cout<<n;
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++)
    {
		a=k;
		while(pow(i,a++)<=n) s++;
	}
    cout<<s;
    return 0;
}
