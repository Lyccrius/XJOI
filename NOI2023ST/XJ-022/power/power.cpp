#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        a[i]=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0&& i/j>=m)
            {
                a[i]++;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0)
        {
            sum++;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}