#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int T;
int n, m, q;
int map[10010][10010];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                map[i][j] = 0;
        for (int i = 1; i <= q; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (a == 0)
            {
                for (int j = 1; j <= m; j++)
                    map[b][j] = c;
            }
            else
            {
                for (int j = 1; j <= m; j++)
                    map[j][b] = c;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}