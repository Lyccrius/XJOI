#include <bits/stdc++.h>
using namespace std;
struct line
{
    int val,pos,id;
    friend bool operator<(line a,line b)
    {
        if(a.val!=b.val)return a.val<b.val;
        else            return a.pos<b.pos;
    }
}L[400010];
queue<line> q;
int n,m,x,cnt;
int k,last;
int vis[200010];
bool flag;
int main()
{
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    scanf("%d%d%d",&n,&m,&x);
    vis[x]=1;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        L[++cnt].val=l;
        L[cnt].pos=1;
        L[cnt].id=i;
        L[++cnt].val=r;
        L[cnt].pos=2;
        L[cnt].id=i;
    }
    L[++cnt].val=x;
    L[cnt].pos=1;
    L[cnt].id=m+1;
    L[++cnt].val=x;
    L[cnt].pos=2;
    L[cnt].id=m+1;
    sort(L+1,L+1+cnt);
    for(int i=1;i<=cnt;i++)
    {
        if(L[i].id==m+1)
        {
            flag=1;
            continue;
        }
        q.push(L[i]);
        if(L[i].pos==1)k++;
        if(L[i].pos==2)k--;
        if(k==0&&!flag)while(!q.empty())q.pop();
        if(k==0&&flag)
        {
            while(!q.empty())
            {
                if(!vis[q.front().val])
                {
                    if(q.front().pos==1&&q.front().val<x)
                    {
                        printf("%d ",q.front().val);
                        vis[q.front().val]=1;
                    }
                    if(q.front().pos==2&&q.front().val>x)
                    {
                        printf("%d ",q.front().val);
                        vis[q.front().val]=1;
                    }
                }
                q.pop();
            }
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}