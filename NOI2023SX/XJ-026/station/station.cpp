//按照车站编号升序排序输出。
#include <stdio.h>
#include <string.h>
#include <algorithm>
int n;                   //有n个火车站
int m;                   //一共有m条火车轨道
const int MAXN = 256000; //2×10^5
int x;                   //小A初始的起点
int ans[MAXN];           //可达地点
int ans_top;             //答案计数
bool ahead;              //方向0左1右
bool vis[MAXN];          //访问标记
struct node
{
    int left, right;
} trains[MAXN];
bool cmp1(node a, node b)
{
    return a.right > b.right;
}
bool cmp2(node a, node b)
{
    return a.left < b.left;
}
void solve(int position)
{
    if (vis[position])
        return;
    vis[position] = true;
    if (position <= 1 && ahead == 0)
    {
        return;
    }
    if (position >= n && ahead == 1)
    {
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        if (ahead == false)
        {
            if (trains[i].right >= position)
            {
                if (trains[i].left >= position)
                    continue;
                ans[++ans_top] = trains[i].left;
                solve(trains[i].left);
            }
            else
            {
                break;
            }
        }
        else
        {
            if (trains[i].left <= position)
            {
                if (trains[i].right <= position)
                    continue;
                ans[++ans_top] = trains[i].right;
                solve(trains[i].right);
            }
            else
            {
                break;
            }
        }
    }
    return;
}
int main()
{
    freopen("station.in", "r", stdin);
    freopen("station.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &trains[i].left, &trains[i].right); //1≤li<ri≤n
    }
    if(x!=1)
    {
        memset(vis, 0, sizeof(vis));
        ahead = false;
        std::sort(trains + 1, trains + 1 + m, cmp1);
        solve(x);
    }
    if(x!=n)
    {
        memset(vis, 0, sizeof(vis));
        ahead = true;
        std::sort(trains + 1, trains + 1 + m, cmp2);
        solve(x);
    }
    std::sort(ans + 1, ans + 1 + ans_top);
    for (int i = 1; i <= ans_top; i++)
    {
        if (ans[i] != ans[i - 1])
            printf("%d ", ans[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}