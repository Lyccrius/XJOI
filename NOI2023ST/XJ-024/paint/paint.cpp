#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,opt,c,p[100005][100005];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>m>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>opt>>x>>c;
            if(opt==0)
            {
                for(int a=1;a<=m;a++) p[x][a]=c;
            }
            if(opt==1)
            {
                for(int a=1;a<=n;a++) p[a][x]=c;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<p[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}