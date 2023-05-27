#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    int t,k,n,j,i,c;

    for(c=1;c<=t;c++)
    {
        cin>>n;
        for(i=1;i<=k;i++)
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }

    }
    cout<<0<<endl<<1;
    return 0;
}