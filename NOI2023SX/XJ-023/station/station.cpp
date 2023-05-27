#include<stdio.h>
struct edge{
    int r, tail;
}e[200010];
int head[200010], cnt, vis[200010], vis2[200010], mx;
void pin(int l, int r)
{
    cnt ++;
    e[cnt].r = r;
    e[cnt].tail = head[l];
    head[l] = cnt;
    return ;
}
void dfs1(int s){
    if(vis2[s] == 1) return ;
    vis2[s] = 1;
    for(int i = head[s]; i != 0; i = e[i].tail){
        int r2 = e[i].r;
        if(s > r2) continue;
        if(vis[r2] == 0){
               vis[r2] = 1;
               if(mx < r2) mx = r2;
        }
        for(int j = s + 1; j <= r2; j ++)
            dfs1(j);
    }
}
void dfs2(int s){
    if(vis2[s] == 2) return ;
    vis2[s] = 2;
    for(int i = head[s]; i != 0; i = e[i].tail){
        int r2 = e[i].r;
        if(s < r2) continue;
        if(vis[r2] == 0){
               vis[r2] = 1;
        }
        for(int j = s - 1; j >= r2; j --)
            dfs2(j);
    }
}
int main()
{
    freopen("station.in", "r", stdin);
    freopen("station.out", "w", stdout);
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    for(int i = 1; i <= m; i ++){
        int l, r;
        scanf("%d %d", &l, &r);
        pin(l, r);
        pin(r, l);
    }
    dfs1(x);
    dfs2(x);
    for(int i = 1; i <= mx; i ++)
        if(vis[i] == 1)
            printf("%d ", i);
    return 0;
}