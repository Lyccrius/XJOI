#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
	int t;
    scanf("%d",&t);
    int n,m,q;
    int opt,x,c;
    int ans[100010][100010]={0};
    for(int z=0;z<t;z++)
    {
        scanf("%d%d%d",&n,&m,&q);
        for(int k=0;k<q;k++)
        {
            scanf("%d%d%d",&opt,&x,&c);
            if(opt==1)
            {
                for(int a=0;a<m;a++)
                {
                    ans[x][a]=c;
                }
            }
            if(opt==0)
            {
                for(int a=0;a<n;a++)
                ans[a][x]=c;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
}
