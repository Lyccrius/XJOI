#include<bits/stdc++.h>
using namespace std;
int x,c,a[10010][10010],opt;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int  t,n,m,q,my,i,j=1,dx,dy;
    cin>>t;
    for(my=1;my<=t;my++)
    {
        cin>>n>>m>>q;
        for(i=1;i<=q;i++)
        {
            cin>>opt>>x>>c;
            if(opt==0)
            {
                while(j<=n)
                {
                    a[x][j++]=c;
                }
            }
            else if(opt==1)
            {
                while(j<=m)
                {
                    a[j++][x]=c;
                }
            }
            j=1;
        }
        for(dx=1;dx<=n;dx++)
        {
            for(dy=1;dy<=m;dy++)
            {
                cout<<a[dx][dy]<<" ";
                a[dx][dy]=0;
            }
            
            cout<<endl;
        }

    }
    return 0;

}