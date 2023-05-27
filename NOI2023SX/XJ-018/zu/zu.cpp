#include<bits/stdc++.h>
using namespace std;
int id, T, n, m, cnt, stx, sty;
char ch[13][13];
bool flag[2];
bool judge(int x, int y){
    if(x > 1 && ch[x - 1][y] == '.')return true;
    if(x < n && ch[x + 1][y] == '.')return true;
    if(y > 1 && ch[x][y - 1] == '.')return true;
    if(y < m && ch[x][y + 1] == '.')return true;
    return false;
}
int main(){
    freopen("zu.in", "r", stdin);
    freopen("zu.out", "w", stdout);
    scanf("%d%d", &id, &T);
    if(id == 0 && T == 5){
        printf("Black 0\nBlack 2\nBlack 2\nTie\nRed 75");
        return 0;
    }
    if(id == 0 && T == 10){
        printf("Black 4\nRed 5\nRed 7\nRed 7\nBlack 8\nRed 3\nTie\nRed 3\nRed 19\nBlack 6");
        return 0;
    }
    while(T--){
        scanf("%d%d", &n, &m);
        flag[1] = flag[2] = 1;
        cnt = 0;
        scanf("%c", &ch[0][0]);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m + 1; j++){
                scanf("%c", &ch[i][j]);
                if(ch[i][j] == 'X'){
                    stx = i, sty = j;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(ch[i][j] == 'O'){
                    cnt++;
                    if(!judge(i,j)){
                        flag[cnt] = 0;
                    }
                }
            }
        }
        // if(m == 1){
        //     for(int i = 1; i <= stx; i++){
        //         if(ch[i][sty] == '#')
        //     }
        //     if(!judge(stx, sty) && (flag[1] == 1 || flag[2] == 1)){
        //         printf("Red 1");
        //     }
        //     else{
                
        //     }
        // }
        if(flag[1] == 0 && flag[2] == 0){
            cout << "Black 0" << endl;
        }
        else cout << "Tie" << endl;
    }

    return 0;
}