#include<bits/stdc++.h>
using namespace std;
const int P = 1e5 + 3;
struct em{
    int v, pos;
} empl[P];
int n, m, k, sid, tip, rot[P], father[P];
bool use[P];
vector<int> head;
bool cmp (int a, int b){
    return a > b;
}
int main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    scanf("%d %d %d %d",&sid,&n,&k,&m);
    // if(sid == 6 || sid == 9 || sid == 13){
        for(int i = 1;i < n; i++) scanf("%d",&sid);
        for(int i = 1;i <= k; i++){
            int tv, tpos;
            scanf("%d %d",&tv,&tpos);
            head.push_back(tv);
        }
        for(int i = 1;i <= n; i++){
            printf("%d",head[i]);
        }
        
    // }

    return 0;
}