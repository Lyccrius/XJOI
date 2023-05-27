#include<bits/stdc++.h>
using namespace std;
int T,k;
int a[40001][40001];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>T>>k;
    while(T--)
    {
        int n,ans=0-0x3f3f3f3f;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                cin>>a[i][j];
                ans=max(a[i][j],ans);
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}