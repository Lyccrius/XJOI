#include<iostream>
using namespace std;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
      long long n,m,q;
      cin>>n>>m>>q;
      long long opt,x,c;
      int map[1000005][1000005];
      for(int i=0;i<q;i++)
      {
        cin>>opt>>x>>c;
        if(opt==0)
        {
          for(int y=1;y<=m;y++)
          {
            map[x][y]=c;
          }
         }
       else
       {
        for(int y=1;y<=n;y++)
        {
            map[y][x]=c;
        }
       }
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          cout<<map[i][j]<<" ";
          map[i][j]=0;
        }
        cout<<endl;
      }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}