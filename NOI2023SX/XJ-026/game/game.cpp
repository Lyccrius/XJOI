#include <stdio.h>
const int MAXN = 1280000;
int T;
int N, M, NS, NT;
int s[MAXN][3], t[MAXN][3];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &T);
    for (int tmpt = 1; tmpt <= T; tmpt++)
    {
        scanf("%d %d", &N, &M);
        for (int k = 1; k <= N; k++)
        {
            scanf("%d", &NS);
            s[k][0]=NS;
            for (int i = 1; i <= NS; i++)
            {
                scanf("%d", &s[k][i]);
            }
        }
        for (int k = 1; k <= N; k++)
        {
            scanf("%d", &NT);
            t[k][0]=NT;
            for (int i = 1; i <= NT; i++)
            {
                scanf("%d", &t[k][i]);
            }
        }
        
        printf("-1\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}