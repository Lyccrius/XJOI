#include<stdio.h>
#include<string.h>
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T;//次数
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int opt[204848],x[204848];
        long long c[204848];
        memset(opt,0,sizeof(opt));
        memset(x,0,sizeof(x));
        memset(c,0,sizeof(c));
        int n,m,q;//行数，列数，操作数
        scanf("%d %d %d",&n,&m,&q);
        for(int i=1;i<=q;i++)
        {
            scanf("%d %d %lld",&opt[i],&x[i],&c[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                bool flag=false;
                for(int k=q;k>=1;k--)
                {
                    /*
                    opt==0，第x行涂成ci。
                    opt==1，第xi.涂成ci。
                    */
                    if(opt[k]==0)
                    {
                        if(x[k]==i)
                        {
                            printf("%lld ",c[k]);
                            flag=true;
                            break;
                        }
                    }
                    else if(opt[k]==1)
                    {
                        if(x[k]==j)
                        {
                            printf("%lld ",c[k]);
                            flag=true;
                            break;
                        }
                    }
                }
                if(flag==false)
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}