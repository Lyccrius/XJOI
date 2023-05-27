#include<bits/stdc++.h>
using namespace std;
struct doge{
    double x, y;
}dot[1010];
int n, st;
bool use[1010];
double mmaxy = -2147483646.00000;
queue<doge> Q;
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf", &dot[i].x, &dot[i].y);
        if(dot[i].y > mmaxy){
            mmaxy = dot[i].y;
            st = i;
        }
    }
    Q.push(dot[st]);
    printf("%d", st);
    use[st] = 1;
    while(!Q.empty()){
        doge u = Q.front();
        Q.pop();
        double d = 0.00000, mmind = 2147483647.00000;
        for(int i = 1; i <= n; i++){
            if(!use[i]){
                d = sqrt((u.x - dot[i].x) * (u.x - dot[i].x) + (u.y - dot[i].y) * (u.y - dot[i].y));
                if(d < mmind){
                    mmind = d;
                    st = i;
                }
            }
            
        }
        if(!use[st]){
            use[st] = 1;
            Q.push(dot[st]);
            printf(" %d", st);
        }
    }
    return 0;
}