#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int nm=1e5+5;
int t;
int n,m,q;
int opt,x,c;
int mp[10005][10005];

int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    
    while(t--)
    {
        cin>>n>>m>>q;
        memset(mp,0,sizeof(mp));
        while(q--)
        {
            cin>>opt>>x>>c;
            if(opt==1)
            {
                for(int i=1;i<=n;i++)
                {
                    mp[i][x]=c;
                }
            }
            else
            {
                for(int i=1;i<=m;i++)
                {
                    mp[x][i]=c;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<mp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}