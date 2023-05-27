#include<bits/stdc++.h>
using namespace std;
int n, m, T, s[1010][4], t[1010][4];
long long cnt;
bool path[200011];
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        if(n > m){
            printf("-1");
            continue;
        }
        for(int i = 1; i <= n; i++){
            int x;
            scanf("%d", &s[i][0]);
            for(int j = 1; j <= s[i][0]; j++){
                scanf("%d", &s[i][j]);
            }
        }
        for(int i = 1; i <= n; i++){
            int x;
            scanf("%d", &t[i][0]);
            for(int j = 1; j <= t[i][0]; j++){
                scanf("%d", &t[i][j]);
                path[t[i][j]] = 1;
            }
            
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= s[k][0]; i++){
                if(s[k][i] != t[k][1] && s[k][i] != t[k][2]){
                    s[k][i] = s[k][i + 1];
                    s[k][0]--;
                    i--;
                }
            }

        }
        for(int i = 1; i <= m; i++){
            if(path[i] == 1) cnt++;
        }
        if(cnt < n) cout << "-1";
        else cout << "0";
        
    }
    
    


    return 0;
}