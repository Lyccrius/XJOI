#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct node{
    int x,y;
}pos[3],posb;
int cnt,id,T,n,m,flag1;
char a[15][15],vis[15][15];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void check(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int fx=x+dx[i],fy=y+dy[i];
        if(a[fx][fy]=='.'&&fx<n&&fy<m&&fx>=0&&fy>=0)  flag1=1;
    }
}
int main()
{
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    while(T--)
    {
        flag1=0,cnt=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='O')
                {
                    pos[++cnt].x=i,pos[cnt].y=j;
                }
                else if(a[i][j]=='X')
                {
                    posb.x=i,posb.y=j;
                }  
            }
        }
        for(int i=1;i<=2;i++)
        {
            check(pos[i].x,pos[i].y);
        }
        
        if(flag1==1)
        {
            cout<<"Tie"<<endl;
            continue;
        }
        else 
        {
            cout<<"Black 0"<<endl;
            continue;
        }
    }
}