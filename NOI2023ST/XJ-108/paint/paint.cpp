#include<iostream>
#include<cstring>
using namespace std;
int n,m,T,q;
int opt,c,x;
int a[1000010],b[100010];
int fa[100010],fb[100010];
int main()
{
    cin>>T;
    while(T--)
    {
        freopen("paint.in","r",stdin);
        freopen("paint.out","w",stdout);
        cin>>n>>m>>q;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(fa,0,sizeof(fa));
        memset(fb,0,sizeof(fb));
        for(int i=1;i<=q;i++)
        {
            cin>>opt>>x>>c;
            if(opt==0)
            {
                a[x]=c;
                fa[x]=i;
            }
            if(opt==1)
            {
                b[x]=c;
                fb[x]=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(fa[i]>fb[j])cout<<a[i]<<" ";
                if(fb[j]>fa[i])cout<<b[j]<<" ";
                else if(fa[i]==fb[j]&&fa[i]==0)cout<<0<<" ";
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
}