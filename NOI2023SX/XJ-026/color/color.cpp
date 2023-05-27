#include <stdio.h>
const int MAXN = 64;
const int MOD = 998244353;
int C, N, M, T;
int ans1, cnt;
long long score, ans2, tmpscore;
int argnum[MAXN];
bool argcol[MAXN]; //0red;1green
/*void PT()
{
    for (int i = 1; i <= N; i++)
    {
        if (argcol[i])
        {
            printf("\033[32m");
        }
        else
        {
            printf("\033[31m");
        }
        printf("%3d \033[0m", argnum[i]);
    }
    printf("\n");
    return;
}*/
bool is_good()
{
    bool flag = false;
    int last_green = -1, last_red = -1;
    for (int i = 1; i <= N; i++)
    {
        if (argcol[i] == 0)
        {
            if (last_red == -1)
            {
                last_red = argnum[i];
                continue;
            }
            if (argnum[i] < last_red)
            {
                flag = false;
                break;
            }
            flag = true;
            last_red = argnum[i];
            score += M - last_red + 1;
        }
        else
        {
            if (last_green == -1)
            {
                last_green = argnum[i];
                continue;
            }
            if (argnum[i] > last_green)
            {
                flag = false;
                break;
            }
            flag = true;
            last_green = argnum[i];
            score += last_green;
        }
    }
    return flag;
}
void fillupcol(int num)
{
    if (num > N)
    {
        score = 0;
        if (is_good())
        {
            cnt++;
            tmpscore = tmpscore < score ? score : tmpscore;
        }
        return;
    }
    for (int i = num; i <= N; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            argcol[i] = j;
            fillupcol(num + 1);
            if (!is_good())
                argcol[i] = 0;
        }
    }
}
bool is_perfect()
{
    cnt = 0;
    tmpscore = 0;
    fillupcol(1);
    return cnt >= 2;
}

void fillupnum(int num)
{
    if (num > N)
    {
        if (is_perfect())
        {
            ans1++;
            ans1 %= MOD;
            ans2 += tmpscore;
            ans2 %= MOD;
            //PT();
        }
        return;
    }
    for (int i = num; i <= N; i++)
    {
        for (int k = 1; k <= M; k++)
        {
            argnum[i] = k;
            fillupnum(num + 1);
            //argnum[i] = 0;
        }
    }
    return;
}
long long A(int n, int m) //下n上m
{
    long long sum = 1;
    for (int i = 1; i <= m; i++)
    {
        sum *= n;
        n--;
    }
    return sum;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &C);
    for (int tmpc = 1; tmpc <= C; tmpc++)
    {
        scanf("%d %d %d", &N, &M, &T);
        for (int i = 1; i <= T; i++)
        {
            scanf("%d", &argnum[i]);
        }
        if (T == 1 && argnum[1] != M)
        {
            argnum[2] = M;
            T++;
        }
        if (N > 8)
        {
            printf("%lld %lld\n", A(M, N - T) % MOD, (A(M, N - T) % MOD) / (A(N - T, N - T) % MOD));
            continue;
        }
        fillupnum(T + 1);
        printf("%d %lld\n", ans1 % MOD, ans2 % MOD);
        ans1 = ans2 = 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}