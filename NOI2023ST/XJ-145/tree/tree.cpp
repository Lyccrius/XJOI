#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

const int P = 1e3 + 2;
struct poi{
    double x0, y0;
} po[P];
double len[P][P], hma = -1e9;
int n, k, beg, path[P], an[P]; 
bool use[P];

double dis(poi a, poi b){
    double fr;
    fr = sqrt(pow(a.x0 - b.x0, 2) + pow(a.y0 - b.y0, 2));
    return fr;
}
void dfs(int x, int num, double ans){
    if(num > n){
        if(hma > ans){
            for(int i = 2;i <= n; i++){
                an[i] = path[i];
            }
            hma = ans;
        }
        return ;
    }
    for(int i = 1;i <= n; i++){
        if(!use[i]){
            use[i] = 1;
            path[num] = i;
            dfs(i, num + 1, ans + len[x][i]);
            use[i] = 0;
            path[num] = 0;
        }
    }
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    if(n == 1){
        printf("1");
        return 0;
    }
    for(int i = 1;i <= n; i++){
        scanf("%lf %lf",&po[i].x0,&po[i].y0);
        if(po[i].y0 > hma){
            beg = i;
            hma = po[i].y0;
        }
    }
    for(int i = 1;i < n; i++){
        for(int j = i + 1;j <= n; j++){
            double t = dis(po[i], po[j]);
            len[i][j] = len[j][i] = t;
        }
    }
    use[beg] = 1;
    hma = 0x3f3f3f3f;
    an[1] = beg;
    dfs(beg, 2, 0);

    for(int i = 1;i <= n; i++){
        printf("%d ",an[i]);
    }    
    return 0;
}