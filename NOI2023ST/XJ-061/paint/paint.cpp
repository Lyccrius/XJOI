#include<iostream>
#include<cstring>
using namespace std;
int mp[100005][100005];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    int T,n,m,q;
    cin>>T;
    while(T--)
    {
        memset(mp,0,sizeof(mp));
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++)
        {
            int opt,x,c;
            cin>>opt>>x>>c;
            if(opt==1)
            {
                for(int j=1;j<=n;j++)
                {
                    mp[j][x]=c;
                }
            }
            else
            {
                for(int j=1;j<=m;j++)
                {
                    mp[x][j]=c;
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
