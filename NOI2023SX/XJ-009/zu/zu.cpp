#include <bits/stdc++.h>
using namespace std;
int n,m;
char mp[15][15];
int vis[15][15];
int R1x,R1y,R2x,R2y;
int Bx,By;
bool Ro;
void solve1()
{
    printf("Tie\n");
}
void solve2()
{
    
}
void solve3()
{
    int Rh,Rl;
    bool flag1=true,flag2=true,flag3=true,flag4=true;
    for(int i=1;i<=Bx;i++)
        if(mp[i][1]=='#')flag1=false;
    if(Bx>R1x+1&&Bx>R2x+1&&flag1)
    {
        printf("Black %d\n",2*Bx-2);
        return;
    }
    for(int i=min(Bx,R1x);i<=max(Bx,R1x);i++)
        if(mp[i][1]=='#')flag2=false;
    for(int i=min(Bx,R2x);i<=max(Bx,R2x);i++)
        if(mp[i][1]=='#')flag3=false;
    if(!flag1&&!flag2&&!flag3)
    {
        printf("Tie\n");
        return;
    }
    if(R1x>R2x)
    {
        Rh=R1x;
        Rl=R2x;
    }
    else
    {
        Rh=R2x;
        Rl=R1x;
    }
    if(flag2&&flag3)
    {
        int ans=2*(Rh-Rl-1-3);
        if(ans>1)ans--;
        printf("Red %d\n",ans+2);
        return;
    }
    if(!flag2&&mp[R1x+1][1]=='#'&&mp[R1x-1][1]=='#')flag4=false;
    if(!flag3&&mp[R2x+1][1]=='#'&&mp[R2x-1][1]=='#')flag4=false;
    if(!flag4)
    {
        
    }
} 
void solve4()
{

}
int main()
{
    int id,T;
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    scanf("%d%d",&id,&T);
    while(T--)
    {
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%s",mp[i]+1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mp[i][j]=='O'&&!Ro)
                {
                    R1x=i;
                    R1y=j;
                    Ro=true;
                }
                if(mp[i][j]=='O'&&Ro)
                {
                    R2x=i;
                    R2y=j;
                }
                if(mp[i][j]=='X')
                {
                    Bx=i;
                    By=j;
                }
            }
        }
        for(int i=0;i<=m+1;i++)
            mp[0][i]=mp[n+1][i]='#';
        for(int i=0;i<=n+1;i++)
            mp[i][0]=mp[m+1][0]='#';
        if(R1x==Bx&&abs(R1y-By)==1||R2x==Bx&&abs(R2y-By)==1)
        {
            printf("Red 1\n");
            continue;
        }
        if(R1y==By&&abs(R1x-Bx)==1||R2y==By&&abs(R2x-Bx)==1)
        {
            printf("Red 1\n");
            continue;
        }
        if(Bx==1)
        {
            printf("Black 0\n");
            continue;
        }
        if(mp[R1x][R1y+1]=='#'&&mp[R1x][R1y-1]=='#'&&mp[R1x+1][R1y]=='#'&&mp[R1x-1][R1y]=='#'
         &&mp[R2x][R2y+1]=='#'&&mp[R2x][R2y-1]=='#'&&mp[R2x+1][R2y]=='#'&&mp[R2x-1][R2y]=='#')
        {
            printf("Black 0\n");
            continue;
        }
        if(id<=4)solve1();
        if(id>=5&&id<=6)solve2();
        if(id>=7&&id<=9)solve3();
        if(id>=10&&id<=13)solve4();
    }
    return 0;
}