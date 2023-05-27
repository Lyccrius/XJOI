#include <bis/stdc++/h>
using namespace std;
int t,n,k,c1[50010],c=1000000000,suo[50010][50010],amax=-1,amin=1000000000;
int main()
{
    freopen("lock.in""r",stdin);
    freopen("lock.out""w",stdout);
    cin>>t>>k;
    for(int s=1;s<=t;s++)
    {
        cin>>n;
        for(int j=1;j<=k;j++)
        {
            for(int p=1;p<=n;p++)
            {
                cin>>suo[j][p];
            }
        }
        c=1000000000;
        for(int i=1;i<=k;i++)
        {
            amax=-1;
            amin=1000000000;
            for(int j=1;j<=n;j++)
            {
                amax=max(amax,suo[i][j]);
                amin=min(amin,suo[i][j]);
            }
            c1[i]=amax-amin;
            c=min(c,c1[i]);
        }
        cout<<c<<endl;
    }
    return 0;
}
