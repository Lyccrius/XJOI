#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int n,m,s;
const int N=200005;
int ans[N];
struct node{
    int l,r;
};
node ls[N],rs[N],mid[N];
int lnum,rnum,midnum;
bool cmp1(node x,node y){
    if(x.r>y.r)return true;
    else if(x.r<y.r)return false;
    else if(x.r==y.r)return x.l>y.l?1:0;
}
bool cmp2(node x,node y){
    if(x.l<y.l)return true;
    else if(x.l>y.l)return false;
    else if(x.l==y.l)return x.r<y.r? 1:0;
}
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        if(l>=s){
            rs[++rnum].l=l,rs[rnum].r=r;
        }
        else if(r<=s){
            ls[++lnum].l=l,ls[lnum].r=r;
        }
        else{
            ls[++lnum].r=s,ls[lnum].l=l;
            rs[++rnum].l=s,rs[rnum].r=r;
        }
    }
    sort(ls+1,ls+lnum+1,cmp1);
    sort(rs+1,rs+rnum+1,cmp2);
    int lq=s,rq=s;
    int cnt=0;
    for(int i=1;i<=lnum;i++){
        if(ls[i].r>=lq){
            lq=min(lq,ls[i].l);
            cnt++;
            ans[cnt]=ls[i].l;
        }
        if(ls[i].r<lq)break;
	}
    for(int i=1;i<=rnum;i++){
        if(rs[i].l<=rq){
            rq=max(rq,rs[i].r);
            cnt++;
            ans[cnt]=rs[i].r;
        }
        else break;
    }
    sort(ans+1,ans+cnt+1);
    for(int i=1;i<=cnt;i++){
		if(ans[i]==ans[i-1])continue;
		cout<<ans[i]<<" ";
	}
}
