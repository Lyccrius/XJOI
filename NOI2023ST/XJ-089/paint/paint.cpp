#include<bits/stdc++.h>
using namespace std;
int a[1000][1000]={0};
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        int n1,m,p;
        cin>>n1>>m>>p;
        for(int i=1;i<=p;i++)
        {
            int u,v,w;
            cin>>u>>v>>w; 
            memset(a,0,sizeof(a));
            if(u==1)
            {
                for(int j;j<=n1;j++)
                {
                    a[j][v]=w;
               }
            }
            else{
                for(int j;j<=m;j++)
                {
                    a[v][j]=w;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
        
    }
    return 0;
}
