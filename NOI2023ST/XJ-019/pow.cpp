#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout);
    int n,k,sum=0;
    cin>>n>>k;
    if(k==1){cout<<n;return 0;}
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=sqrt(i)+1;j++)
        {
            for(int l=k;pow(j,l)<=i;l++)
            {
                if(i==pow(j,l)){sum++;j=sqrt(i)+1;l=2;}
            }
        }
    }
    cout<<sum+1;
    return 0;
}