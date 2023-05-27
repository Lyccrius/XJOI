#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=10010;
int T,n,m,q;
int opt,x,c;
int a[N][N];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++)
        {
            cin>>opt>>x>>c;
            if(opt==1)
            {
                for(int i=1;i<=n;i++)
                {
                    a[i][x]=c;
                    //cout<<i<<" "<<x<<endl;
                }
            }
            else if(opt==0)
            {
                for(int i=1;i<=m;i++)
                {
                    a[x][i]=c;
                    //cout<<x<<" "<<i<<endl;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[i][j]<<" ";
                a[i][j]=0;
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}