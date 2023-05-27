#include <iostream>
using namespace std;

int t,m,n,q,s,a[25][25],b[25][3],c[11][2];

void h(int x,int y)
{
    for(int i=1;i<=n;++i)
    {
        a[x+s][i]=y;
    }

}

void l(int x,int y)
{
    for(int i=1;i<=m;++i)
    {
        a[i+s][x]=y;
    }

}

int main()
{
    cin>>t;int tx=t;
    while(tx!=0)
    {
        cin>>m>>n>>q;
    for(int i=1;i<=q;++i)
        {
        for(int j=1;j<=3;++j)
            {
            cin>>b[i][j];
            }
        if(b[i][1]==0)
            h(b[i][2],b[i][3]);
        else
            l(b[i][2],b[i][3]);
        }
        c[tx][1]=m;c[tx][2]=n;
        s+=m;
        tx-=1;

    }
    while(t!=0)
    {
        for(int i=1+c[t+1][1];i<=c[t-1][1]+c[t][1];++i)
        {
        for(int j=1;j<=c[t][2];++j)
            {
            cout<<a[i][j]<<" ";

            }
        cout<<endl;
        }
        t-=1;
    }

    for(int i=6;i<=8;++i)
        {
        for(int j=1;j<=c[t+1][2];++j)
            {
            cout<<a[i][j]<<" ";

            }
        cout<<endl;
        }
return 0;
}
