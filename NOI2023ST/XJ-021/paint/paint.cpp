#include<bits/stdc++.h>
using namespace std;
int T;
int a[10010][10010];
int n,m,q;
int opt,x,c;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>n>>m>>q;
        for(int j=0;j<q;j++)
        {
            cin>>opt>>x>>c;
            if(opt==0)                      
                for(int k=0;k<m;k++)
                    a[x-1][k]=c;
            if(opt==1)
                for(int k=0;k<n;k++)
                    a[k][x-1]=c;
        }
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
                cout<<a[j][k]<<" ";
            cout<<endl;
        }
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++)
                a[j][k]=0;
    }
    return 0;
}