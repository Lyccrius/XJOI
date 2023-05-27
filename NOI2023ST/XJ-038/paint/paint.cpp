#include<bits/stdc++.h>
using namespace std;

int T;
int n,m,q;
int a[40001][40001];

int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=q;i++)
        {
            int f,x,c;
            scanf("%d%d%d",&f,&x,&c);
            if(f==1)
            {
                for(int i=1;i<=m;i++)
                {
                    a[x][i]=c;
                }
            }
            if(f==0)
            {
                for(int i=1;i<=n;i++)
                {
                    a[i][x]=c;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%d ",a[j][i]);
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}