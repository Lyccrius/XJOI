#include<bits/stdc++.h>
using namespace std;
const int P = 4e5 + 4;
int n, m, x, ml = P, mr, cnt, con;
struct rai{
    int l, r;
} rail[P];
bool ans[P];
bool cmp1(rai a, rai b){
    return a.r < b.r;
}
bool cmp2(rai x, rai y){
    return x.l < y.l;
}
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    scanf("%d %d %d",&n,&m,&x);
    for(int i = 1;i <= m; i++){
        int tl, tr;
        scanf("%d %d",&tl,&tr);
        if(tl == tr) continue;
        if(tl < x && tr > x){
            ans[tl] = 1;
            ans[tr] = 1;
            if(tl < ml) ml = tl;
            if(tr > mr) mr = tr;
        } 
        else if(tr == x){
            ans[tl] = 1;
            if(tl < ml) ml = tl;
        }
        else if(tl == x){
            ans[tr] = 1;
            if(tr > mr) mr = tr;
        }
        else{
            cnt++;
            rail[cnt] = {tl, tr};
        }
    }
    sort(rail + 1,rail + 1 + cnt, cmp1);
    for(int i = 1;i <= cnt; i++){
        if(rail[i].l > x){
            con = i - 1;
            break;
        }
    }
    for(int i = con;i >= 1; i--){
        if(rail[i].r <= ml){
            ans[rail[i].l] = 1;
            if(rail[i].l < ml) ml = rail[i].l;
        }
        else break;
    }
    sort(rail + 1 + con, rail + 1 + cnt, cmp2);
    for(int i = con + 1; i <= cnt; i++){
        if(rail[i].l <= mr){
            ans[rail[i].r] = 1;
            if(rail[i].r > mr) mr = rail[i].r;
        }
    }
    for(int i = 1;i <= n; i++){
        if(ans[i]) printf("%d ",i);
    }
    return 0;
}