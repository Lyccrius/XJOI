#include <bits/stdc++.h>
using namespace std;
struct id
{
    double x, y;
}a[1010];

struct kk
{
    double x;
    queue<int> y;
};

kk ans;
kk sum;

double dir[1010][1010];
bool cheak[1010];

int n;

void work(int begin, int to, int step)
{
    sum.y.push(to);
    sum.x = sum.x + dir[begin][to];
    if (step == n - 1)
    {
        ans.x = min(ans.x, sum.x);
        sum.x = 0;
        while (! sum.y.empty())
        {
            ans.y.push(sum.y.front());
            sum.y.pop();
        }
        return;
    }
    if (sum.x >= ans.x)
    {
        sum.x = 0;
        while (! sum.y.empty())
            sum.y.pop();
        return;
    }
    for (int i = 1; i <= n, i != to; ++ i)
    {
        if (! cheak[i])
        {
            cheak[i] = 1;
            work(to, i, step + 1);
            cheak[i] = 0;
        }
    }
}

int main()
{
    freopen ("tree.in", "r", stdin);
    freopen ("tree.out", "w", stdout);
    cin >> n;
    ans.x = 0x3f3f3f3f;
    int maxy = 0;
    int key;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i].x >> a[i].y;
        if (a[i].y >= maxy) maxy = a[i].y, key = i;
    }
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n, j != i; ++ j)
            dir[i][j] = dir[j][i] = sqrt(pow(abs(a[i].x-a[j].x), 2) + pow(abs(a[i].y - a[j].y), 2));
    work(key, key, 1);
    while (! ans.y.empty())
    {
        printf("%d ", ans.y.front());
        ans.y.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}