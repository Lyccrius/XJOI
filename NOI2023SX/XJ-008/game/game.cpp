#include<bits/stdc++.h>
using namespace std;
int read();
const int N=1e6+10;

int T,n,m; int len,a1;
bool vis[N];
vector<int>s[N],t[N];
int st1[N],st2[N];

namespace subtasks{
    int ans=0;
    bool vis[N];
    int bet=0,ab=0,minnbob; bool flag=0;
    void tbob(int now)
    {
        if(now==n)
        {
            int x=0;
            for(int i=1;i<=n;i++) x+=(st1[i]==st2[i]);
            bet=min(bet,x);
            return;
        }
        for(int u:t[now+1])
        {
            if(!vis[u])
            {
                st2[now+1]=u; vis[u]=1;
                tbob(now+1);
                vis[u]=0;
            }
        }
    }
    void dfs(int now)
    {
        if(now==n)
        {
            bet=n+1;
            tbob(0);
            if(bet==n+1) return;
            flag=1; 
            if(bet>ab) 
            {
                ab=bet;
                minnbob=bet;
            }
            else if(bet==ab)
            {
                minnbob=min(minnbob,bet);
            }
            return;
        }   
        for(int u:s[now+1])
        {
            st1[now+1]=u;
            dfs(now+1);
        }
    }
    void solve()
    {
        ab=0; minnbob=n+1; flag=0;
        dfs(0);
        if(!flag) {puts("-1");}
        else printf("%d\n",minnbob);
    }
}

namespace subtask1{
    bool check()
    {
        for(int i=1;i<=n;i++)
        {
            for(int x:s[i])
                for(int y:t[i]) if(x==y) return false;
        }
        return true;
    }
    void solve()
    {

    }
}
// task B
namespace subtask2{
    bool check()
    {
        for(int i=1;i<n;i++)
        {
            if((int)t[i].size()!=2) return false;
            if(!(t[i][0]==i&&t[i][1]==i+1))
                if(i!=n) return false;
        }
        if((int)t[n].size()!=2) return false;
        if(t[n][0]==1&&t[n][1]==n) return true;
        return false;
    }  
    int s0,s1,s2,s3;  
    void calc(int i,int w1,int w2)
    {
        int tot=0; int ps=0;
        for(int u:s[i])  
        {
            if(u==w1) tot++,ps=1;
            if(u==w2) tot++,ps=2;
        }
        if(!tot) s0++;
        else if(tot==2) s3++;
        else if(ps==1) s1++;
        else s2++;
    }
    void solve()
    {
        s1=s2=s3=s0=0;
        for(int i=1;i<=n;i++) st1[i]=i;
        st2[n]=1; for(int i=1;i<n;i++) st2[i]=i+1;
        for(int i=1;i<=n;i++) calc(i,st1[i],st2[i]);
        if(s1>s2) swap(s1,s2);
        int need=s2-s1;
        int val=min(s3,need);
        s1+=val; s3-=val;
        printf("%d\n",min(s1,s2)+s3/2);
    }
 }

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        n=read(); m=read();
        for(int i=1;i<=m;i++) vis[i]=0;
        for(int i=1;i<=n;i++) s[i].clear(),t[i].clear();
        for(int i=1;i<=n;i++)
        {
            len=read();
            while(len--) a1=read(),s[i].push_back(a1);
            sort(s[i].begin(),s[i].end());
        }
        for(int i=1;i<=n;i++)
        {
            len=read();
            while(len--) a1=read(),t[i].push_back(a1);
            sort(t[i].begin(),t[i].end());
        }
        if(n<=10&&m<=10) subtasks::solve();
        else if(subtask2::check()) subtask2::solve();
        else puts("-1");
    }
}

int read()
{
    int ans=0; char f=getchar();
    while(f<'0'||f>'9') f=getchar();
    while(f>='0'&&f<='9') ans=ans*10+f-'0',f=getchar();
    return ans;
}