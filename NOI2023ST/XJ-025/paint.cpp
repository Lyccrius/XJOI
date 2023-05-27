#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    while(x!=0)
    {
        int n,m,q,a[100005][100005]={0};
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++)
        {
            int o,b,c;
            cin>>o>>b>>c;
            if(o==0)
            {
                for(int j=1;j<=m;j++)
                    {a[b][j]=c;}
            }
            else
            {
                for(int j=1;j<=n;j++)
                    {a[j][b]=c;}
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<+m;j++)
            {cout<<a[i][j];}
        }
        x--;
    }
    return 0;
}
