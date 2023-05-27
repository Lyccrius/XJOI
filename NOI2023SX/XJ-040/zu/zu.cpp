#include <iostream>
#include <cmath>
using namespace std;
int m,n,map[30][30],x,id,y,x1[2],yy[2],ans,cnt;
void dfs(int a,int b)
{
    if(id<=4&&id>0)
    {
        if(map[x1[1]+1][yy[1]]==0&&map[x1[1]-1][yy[1]]==0&&map[x1[1]][yy[1]-1]==0&&map[x1[1]][yy[1]+1]==0&&map[x1[2]-1][yy[2]]==0&&map[x1[2]+1][yy[2]]==0&&map[x1[2]][yy[2]+1]==0&&map[x1[2]][yy[2]-1]==0)
            ans=0;
        else ans=2;
        return ;
    }
    if(id>=7&&id<=9)
    {
        if(x<x1[0]&&x<x1[1])
        {
            ans=2;
            cnt=(x-1)*2;
            return ;
        }
        if(x1[1]==a+1||x1[1]==a-1||x1[0]==a+1||x1[0]==a-1)
        {
            ans=1;
            cnt=1;
            return ;
        }
        if(min(abs(x1[1]-x),abs(x1[2]-x))%2==1);
        {
            ans=1;
            //if(cnt=min(abs(x1[1]-x),abs(x1[2]-x));
        }
    }
}
int main()
{
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    int t;
    cin>>id>>t;
    for(int q=1;q<=t;q++)
    {
        ans=0;
        cnt=0;
        int b=0;
        cin>>m>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char a;
                cin>>a;
                if(a=='.') map[i][j]=1;
                if(a=='#') map[i][j]=0;
                if(a=='X') map[i][j]=1,x=i,y=j;
                if(a=='O') map[i][j]=1,x1[b]=i,yy[b]=j,b++;
            }
        }
        dfs(x,y);
        if(ans=0) cout<<"Tie"<<endl;
        if(ans=1) cout<<"Red "<<cnt<<endl;
        if(ans=2) cout<<"Black "<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}