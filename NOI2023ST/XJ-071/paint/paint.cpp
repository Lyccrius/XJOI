#include<bits/stdc++.h>
using namespace std;
int mapa[10000][10000];
int n,m,p;
void draw(int how,int xy,int color)
{
    if(how==1)
    {
        for(int i=1;i<=n;i++)
        {
            mapa[i][xy]=color;
        }
    }
    else
    if(how==0)
    {
        for(int i=1;i<=m;i++)
        {
            mapa[xy][i]=color;
        }
    }
}


int main()
{

    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int t;
    int oct,x,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&p);
        for(int i=1;i<=p;i++)
        {
            scanf("%d%d%d",&oct,&x,&c);
            draw(oct,x,c);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%d ",mapa[i][j]);
            }
            printf("\n");
        }
        memset(mapa,0,sizeof(mapa));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
    
}