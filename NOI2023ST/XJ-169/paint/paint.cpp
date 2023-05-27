#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,m,q;
        cin>>n>>m>>q;
        int a[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a[i][j]=0;
            }
        }
        for(int Q=0;Q<q;Q++)
        {
            int opt,x,c;
            cin>>opt>>x>>c;
            x--;
            if(opt==0)
            {
                for(int i=0;i<m;i++)
                {
                    a[x][i]=c;
                }
            }
            if(opt==1)
            {
                for(int i=0;i<n;i++)
                {
                    a[i][x]=c;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                printf("%d ",a[i][j]);
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}