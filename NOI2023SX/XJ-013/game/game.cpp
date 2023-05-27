#include <bits/stdc++.h>
#define N 101
using namespace std;
int a[N],s[N][N],b[N],t[N][N],fb[N*N][N],nb[N*N],ap[N*N][N],bp[N*N][N];
int main()
{
    int T;
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        memset(fb,0,sizeof fb);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            for(int j=1;j<=a[i];j++)
            {
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            for(int j=1;j<=b[i];j++)
            {
                cin>>t[i][j];
            }
        }
        int cnta=1,cntb=1;
        for(int i=1;i<=n;i++)
        {
            cnta*=a[i];
            cntb*=a[i];
        }
            for(int i=1;i<=cnta;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    ap[i][j]=s[i][1];
                }
            }
            for(int i=1;i<=n;i++)
        {
            cnta*=a[i];
            cntb*=a[i];
        }
            for(int i=1;i<=cnta;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    ap[i][j]=s[i][1];
                }
            }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=b[i];j++)
            {
                bp[cntb][i]=t[i][j];
                 for(int aa=1;aa<=i;aa++)
                    {
                        bp[cnta][aa]=bp[cnta-1][aa];
                    }
            }

        }
        for(int i=1;i<=cntb;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(fb[i][j]!=0) {
                    nb[i]=1;break;
                }
                fb[i][j]=1;
            }
            for(int j=1;j<=n;j++)
            {
                fb[i][j]=0;
            }
        }
        int check=0,ans=0x3f3f3f3f,final=-1;
        for(int i=1;i<=cnta;i++)
        {
            ans=0x3f3f3f3f;
            for(int j=1;j<=cntb;j++)
            {
                check=0;
                if(nb[j]==1) continue;
                for(int k=1;k<=n;k++)
                {
                    if(ap[i][k]==bp[i][k])    check++;
                }
                ans=min(check,ans);
            }
            final=max(ans,final);
        }
        if(ans==0x3f3f3f3f) cout<<"-1"<<endl;
        else  cout<<final<<endl;
    }
    return 0;
}