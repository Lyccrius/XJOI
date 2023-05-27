#include<bits/stdc++.h>
using namespace std;
const int N=12;
int mx[]={0,1,0,-1},my[]={1,0,-1,0};
int id,T;
char s[N][N];
int n,m;
struct node{
    int x,y;
}; node r1,r2,b;

namespace subtask1{
    bool check(int x,int y)
    {   
        for(int i=0;i<4;i++)
        {
            int nx=x+mx[i],ny=y+my[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s[nx][ny]=='.') return false;
        }
        return true;
    }
    void solve()
    {
        if(check(r1.x,r1.y)&&check(r2.x,r2.y)) puts("Black 0");
        else puts("Tie");
    }
}

namespace subtask3{
    bool eat(int x,int y)
    {
        for(int i=0;i<4;i++)
        {
            int nx=x+mx[i],ny=y+my[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s[nx][ny]=='X') return true;
        }
        return false;
    }
    bool move(int x,int y)
    {
        for(int i=0;i<4;i++)
        {
            int nx=x+mx[i],ny=y+my[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s[nx][ny]=='.') return true;
        }
        return false;
    }
    int reach(int ya,int yb)
    {
        if(ya>yb) swap(ya,yb);
        for(int i=ya;i<=yb;i++)
            if(s[i][1]=='#') return i;
        return 0;
    }
    void solve()
    {   
        if(eat(r1.x,r1.y)||eat(r2.x,r2.y)) {puts("Red 1"); return;}
        if(r1.x>r2.x) swap(r1,r2);
        bool f1=move(r1.x,r1.y),f2=move(r2.x,r2.y),b1=move(b.x,b.y);
        if(!f1&&!f2) {puts("Black 0"); return;}
        if((f1||f2)&&!b1) {puts("Red 1");return;}
        int pos=reach(1,b.x);
        if(!pos)
        {
            if(b.x>=r1.x&&b.x>=r2.x) printf("Black %d\n",2*(b.x-1));
            else if(b.x>=r2.x)
            {
                int len=b.x-r2.x-1;
                if(len%2==0) printf("Red %d\n",len+1);
                else 
                {
                    if(!f1&&len==1) puts("Black 2\n");
                    else printf("Red %d\n",len/2*2+3);
                }
            }
            else
            {
                int len=b.x-r1.x-1;
                if(len%2==0) printf("Red %d\n",len+1);
                else 
                {
                    if(!f2) printf("Black %d\n",len+1);
                    else printf("Red %d\n",len/2*2+3);
                }
            }
        }
        else 
        {
            if((b.x<r1.x||reach(b.x,r1.x))&&(b.x<r2.x||reach(b.x,r2.x))) printf("Red %d\n",2*(b.x-pos));
            else if(b.x<r1.x&&b.x<r2.x) 
            {
                int len=b.x-r2.x-1;
                if(len%2==0) printf("Red %d\n",len+1);
                else 
                {
                    if(!f1&&len==1) puts("Black 2\n");
                    else printf("Red %d\n",len/2*2+3);
                }
            }
            else
            {
                int len=b.x-r1.x-1;
                if(len%2==0) printf("Red %d\n",len+1);
                else 
                {
                    if(!f2) printf("Black %d\n",len+1);
                    else printf("Red %d\n",len/2*2+3);
                }
            }
        }
    }
}

//WaWaWa QAQ
namespace subtask2{
    bool eat(int x,int y)
    {
        for(int i=0;i<4;i++)
        {
            int nx=x+mx[i],ny=y+my[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s[nx][ny]=='X') return true;
        }
        return false;
    }
    int calcr(node f,node g)
    {
        int len=g.x-f.x-1;
        int left=n-1-g.y;
        int sumr=left+len;
        if(sumr%2!=(n-g.y)%2) return 2*sumr+1;
        else return 2*sumr+3;
    }
    int calcl(node f,node g)
    {
        int len=f.x-g.x-1;
        int left=g.y-2;
        int sumr=left+len;
        if(sumr%2!=(g.y)%2) return 2*sumr+1;
        return 2*sumr+3;
    }
    void solve()
    {
        node r=(r1.x==n)?r2:r1;
        if(eat(r.x,r.y)) {puts("Red 1"); return;}
        if(b.x<=r.x||b.x-1<=abs(r.y-b.y)) {printf("Black %d\n",2*(b.x-1)); return;}
        if(m==1) {subtask3::solve(); return;}
        int len=b.x-r.x-1,need=abs(b.x-r.x)+1;
        int lc=r.x-1,rc=n-r.x;
        if(lc<=rc)
        {
            if(b.y>r.y) printf("Red %d\n",calcr(b,r));
            else
            {
                if(need<len) 
                {
                    b.y=r.y; r.x-=need;
                    printf("Red %d\n",2*need+calcr(b,r));
                }
                else printf("Red %d\n",calcl(b,r));
            }
        }
        else
        {
            if(b.y<r.y) printf("Red %d\n",calcl(b,r));
            else
            {
                if(need<len)
                {
                    b.y=r.y; r.x-=need;
                    printf("Red %d\n",2*need+calcl(b,r));
                }
                else printf("Red %d\n",calcr(b,r));
            }
        }
    }
}

int main()
{
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    scanf("%d%d",&id,&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
            for(int j=1;j<=m;j++)
            {
                if(s[i][j]=='O') 
                {
                    if(!r1.x) r1=node{i,j};
                    else r2=node{i,j};
                } 
                if(s[i][j]=='X') b=node{i,j};
            }
        }
        if(!subtask3::move(r1.x,r1.y)&&!subtask3::move(r2.x,r2.y)) 
        {
            puts("Black 0");
            continue;
        }
        else if(subtask3::move(b.x,b.y))
        {
            puts("Red 1");
            continue;
        }
        if(id<=4) subtask1::solve();
        else if(id<=6) subtask2::solve();
        else if(id<=9) subtask3::solve();
        else puts("Tie");
        r1=node{0,0};
    }
}
