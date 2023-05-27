#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int m,n,q,maps[N][N];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);

    int T;cin>>T;
    while(T--)
    {
        memset(maps,0,sizeof(maps));
        cin>>n>>m>>q;
        while(q--)
        {
            int op,x,c;
            cin>>op>>x>>c;
            if(!op)
                for(int i=1;i<=n;i++)
                    maps[x][i]=c;
            else
                for(int i=1;i<=m;i++)
                    maps[i][x]=c;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<maps[i][j]<<' ';   
            cout<<endl;       
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}