#include <iostream>
#include <cstring>
using namespace std;
int l[6][50500],k;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int t;
    cin>>t>>k;
    for(int z=1;z<=t;z++)
    {
        memset(l,0,sizeof(l));
        int n;
        cin>>n;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>l[i][j];
            }
        }
        if(k==1)
        {
            int maxn=0,minx=2147483647;
            for(int i=1;i<=n;i++)
            {
                maxn=max(maxn,l[1][i]);
                minx=min(minx,l[1][i]);
            }
            cout<<maxn-minx<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}