#include<bits/stdc++.h>
using namespace std;
int hang[100005][2],lie[100005][2];
int main()
{
    int t,n,m,q,i,x,c,j;
    bool ti;
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        memset(hang,0,sizeof(hang));
        memset(lie,0,sizeof(lie));
        for(i=1;i<=q;i++)
        {
            cin>>ti>>x>>c;
            if(ti) 
            {
                lie[x][0]=c;
                lie[x][1]=i;
            }
            else
            {
                hang[x][0]=c;
                hang[x][1]=i;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(hang[i][1]>lie[j][1])
                {
                    cout<<hang[i][0]<<" ";
                }
                else cout<<lie[j][0]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
