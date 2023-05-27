#include<stdio.h>
int a[10001][10001];
int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int T;
    int m, n, q;
    scanf("%d", &T);
    while(T --){
        scanf("%d %d %d", &n, &m, &q);

        for(int i = 1; i <= n; i ++)//gui1 0
            for(int  j = 1; j <= m; j ++)
                a[i][j] = 0;
        
        while(q --){
            int otp, x, c;
            scanf("%d %d %d", &otp, &x, &c);
            if(otp == 0){//hang
                for(int j = 1; j <= m; j ++)
                    a[x][j] = c;
                }
            else{//lie
                for(int i = 1; i <= n; i ++)
                    a[i][x] = c;
                }
            }
        for(int i = 1; i <= n; i ++){//shuchu
            for(int  j = 1; j <= m; j ++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}