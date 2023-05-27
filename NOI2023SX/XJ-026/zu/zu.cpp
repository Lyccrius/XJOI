#include <stdio.h>
int ID; //测试点编号,样例的id为0
int T;  //数据组数
int N;  //行数
int M;  //列数
const int MAXN = 16;
char datas[MAXN][MAXN];
struct position
{
    int x; //i
    int y; //j
    void set(int nx, int ny)
    {
        x = nx;
        y = ny;
        return;
    }
} reds[MAXN * MAXN], blacks[MAXN * MAXN], locks[MAXN * MAXN];
int blacks_top, reds_top, locks_top;
int dx[4] = {-1, 0, 0, 1}; //up left right down
int dy[4] = {0, -1, 1, 0}; //up left right down
int main()
{
    freopen("zu.in", "r", stdin);
    freopen("zu.out", "w", stdout);
    scanf("%d %d", &ID, &T);
    for (int tcnt = 1; tcnt <= T; tcnt++)
    {
        bool con = false;
        scanf("%d %d\n", &N, &M);
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                datas[i][j] = getchar();
                if (datas[i][j] == 'X')
                {
                    if (i == 1)
                    {
                        con = true;
                        break;
                    }
                    blacks[++blacks_top].set(i, j);
                }
                if (datas[i][j] == 'O')
                {
                    reds[++reds_top].set(i, j);
                }
                if (datas[i][j] == '#')
                {
                    locks[++locks_top].set(i, j);
                }
            }
            getchar(); //solve \n
            if (con)
                break;
        }
        if (con)
        {
            con = false;
            printf("Black 0\n");
            continue;
        }
        if (blacks_top == 0)
        {
            printf("Red 0\n");
            continue;
        }
        if (ID >= 1 && ID <= 4)
        {
            bool flag = false;
            for (int i = 1; i <= reds_top; i++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx, ny;
                    nx = reds[i].x + dx[k];
                    ny = reds[i].y + dy[k];
                    if (nx < 1 || ny < 1 || nx > N || ny > M || datas[nx][ny] == '#')
                    {
                        continue;
                    }
                    flag = true;
                }
            }
            if (flag)
            {
                printf("Tie\n");
            }
            else
            {
                printf("Black 0\n");
            }
        }
        else if (ID >= 7 && ID <= 9)
        {
            if (reds_top != 0)
            {
                bool flag1 = false;
                for (int i = 1; i <= reds_top; i++)
                {
                    if (datas[reds[i].x + 1][reds[i].y] == '#' || datas[reds[i].x - 1][reds[i].y] == '#')
                    {
                        continue;
                    }
                    flag1 = true;
                }
                if (flag1)
                {
                    bool flag2 = false;
                    for (int i = 1; i <= blacks_top; i++)
                    {
                        if (datas[blacks[i].x + 1][blacks[i].y] == '#' || datas[blacks[i].x - 1][blacks[i].y] == '#')
                        {
                            continue;
                        }
                        flag2 = true;
                    }
                    if (flag2)
                    {

                        if (locks_top == 0)
                        {
                            int MIN = MAXN * MAXN;
                            int MAX = -1 * MAXN * MAXN;
                            bool flag3 = false;
                            for (int i = 1; i <= blacks_top; i++)
                            {
                                int j;
                                for (j = blacks[i].x; j >= 1; j--)
                                {
                                    if (datas[j][blacks[i].y] == 'O')
                                    {
                                        flag3 = false;
                                        break;
                                    }
                                    flag3 = true;
                                }
                                if (flag3)
                                {
                                    MIN = MIN > (blacks[i].x - 1) ? (blacks[i].x - 1) : MIN;
                                }
                                else
                                {
                                    MAX = MAX < (blacks[i].x - j) ? (blacks[i].x - j) : MAX;
                                }
                            }
                            if (flag3)
                            {
                                printf("Black %d\n", MIN);
                            }
                            else
                            {
                                if (MAX % 2 == 0) //BW
                                {
                                    printf("Black %d\n", (MAX - 1) + 1);
                                }
                                else //RW
                                {
                                    printf("Red %d\n", (MAX - 1));
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("Red 0\n");
                    }
                }
                else
                {
                    printf("Black 0\n");
                }
            }
            else
            {
                int MAXB = -1 * MAXN * MAXN;
                int MAXS = -1 * MAXN * MAXN;
                for (int i = 1; i <= blacks_top; i++)
                {
                    bool flag3 = false;
                    for (int j = blacks[i].x; j >= 1; j--)
                    {
                        if (datas[j][blacks[i].y] == '#')
                        {
                            MAXB = MAXB < (blacks[i].x - j) ? (blacks[i].x - j) : MAXB;
                            flag3 = false;
                            break;
                        }
                        flag3 = true;
                    }
                    if (flag3)
                    {
                        MAXS = MAXS < (blacks[i].x - 1) ? (blacks[i].x - 1) : MAXS;
                    }
                }
                if (MAXS > 0)
                {
                    printf("Black %d\n", MAXS);
                }
                else
                {
                    printf("Black %d\n", MAXB);
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}