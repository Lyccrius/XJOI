#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,k,n,a[10005],maxx=-1,minn=10000000;
    cin>>t>>k;
    if(k==1)
    {
        while(t--)
        {
            memset(a,0,sizeof(a));
            cin>>n;
            for(int i=1;i<=k;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    cin>>a[j];
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(a[i]>maxx)maxx=a[i];
                if(a[i]<minn)minn=a[i];
            }
            cout<<maxx-minn;
        }   
    }
    else{
        cout<<0;
    }
    return 0;
}