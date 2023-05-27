#include<bits/stdc++.h>
using namespace std;
int main()
int q,cnt;
{

    freopen("power.in","r",stdin)
    freopen("power.out","w",stdout)
    long long n,m;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if (q==0)
            {
                cnt++;
            }
        }
    }
    cout<<cnt;

    fclose(stdin)
    fclose(stdout)
    return 0;
}
