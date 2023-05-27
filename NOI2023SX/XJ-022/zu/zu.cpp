#include<bits/stdc++.h>
using namespace std;
string s;
int n, m, id, T;
struct ch{
    int x, y;
};
ch black, red1, red2;
bool use[15][15], flag;
void change(){
    int t;
    if(red1.y < red2.y){
        t = red1.y;
        red1.y = red2.y;
        red2.y = t;
        t = red1.x;
        red1.x = red2.x;
        red2.x = t;
    }
    return ;
}
int abs(int x, int y){
    if(x > y) return x - y;
    return y - x;
}
bool judge(){
    if(use[red1.x - 1][red1.y] && use[red1.x + 1][red1.y] && use[red1.x][red1.y - 1] && use[red1.x][red1.y + 1] &&
       use[red2.x - 1][red2.y] && use[red2.x + 1][red2.y] && use[red2.x][red2.y - 1] && use[red2.x][red2.y + 1]) return 1;
       return 0;
}
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    scanf("%d %d",&id,&T);
    while(T--){
        memset(use,0,sizeof use);
        scanf("%d %d",&n,&m);
        for(int i = 0;i <= n + 1; i++){
            use[0][i] = use[n + 1][i] = use[i][0] = use[i][n + 1] = 1;
        }
        for(int i = 1;i <= n; i++){
            cin >> s;
            for(int j = 0, c = s.size();j < c; j++){
                if(s[j] == '#') use[i][j + 1] = 1;
                else if (s[j] == 'O'){
                    if(flag) red1 = {i, j + 1};
                    else{
                        red2 = {i, j + 1};
                        flag = 1;
                    }
                } 
                else if(s[j] == 'X') black = {i, j + 1};
            }
        }    
        if(id >= 1 && id <= 4){
            if(judge()) printf("Black 0");
            else printf("Tie");
            printf("\n");
        }
        else if(id == 5 || id == 6){
            change();
            if(abs(black.x, red1.x) + abs(black.y, red1.y) == 1) printf("Red 1");
            else if(black.y > red1.y) printf("Black %d",(black.y - 1) * 2);
            // else if(m == 1){
            //     if
            // } 
            printf("\n");
        }
    }
    return 0;
}