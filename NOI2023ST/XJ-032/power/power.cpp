#include<bits/stdc++.h>
using namespace std;
int power(int x,int y)
{
    int a=1,i;
    for(i=1;i<=y;i++)
    {
        a*=x;
    }
    return a;
}
int main()
{
    int n,k,i,j,q,sum=0,f[100005]={0};
    cin>>n>>k;
    if(k==1)
    {
        cout<<n;
        return 0;
    }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=sqrt(i)+1;j++)
        {
            for(q=k;q<=sqrt(i)+1;q++)
            {
                if(i==power(j,q)&&f[i]==0)
                {
                    sum++;
                    f[i]=1;
                    break;
                }
            }
        }
    }
    cout<<sum+1;
    return 0;
}