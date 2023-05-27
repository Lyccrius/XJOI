#include<bits/stdc++.h>
using namespace std;
char mp[12][12];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int n, m;

int main() {
    freopen("zu.in", "r", stdin);
    freopen("zu.out", "w", stdout);
    int id, T;
    scanf("%d%d", &id, &T);
    int flag;
    if(1 <= id && id <= 4) flag = 1;
    else if(5 <= id && id <= 6) flag = 2;
    else if(7 <= id && id <= 9) flag = 3;
    while(T --) {
        int r1x, r1y, r2x, r2y;
        r1x = r1y = r2x = r2y = 0;
        int bx = 0, by = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++) {
            scanf("\n%s", mp[i]);
            for(int j = 1; j <= m; j ++) {
                if(mp[i][j] == 'O') {
                    if(!r1x) r1x = i, r1y = j;
                    else r2x = i, r2y = j;
                }
                else if(mp[i][j] == 'X')
                    bx = i, by = j;
            }
        }
        if(flag == 1) {
            bool canmove = 0;
            for(int i = 0; i < 4; i ++) {
                int xx1 = r1x + dx[i], yy1 = r1y + dy[i];
                int xx2 = r2x + dx[i], yy2 = r2y + dy[i];
                if(mp[xx1][yy1] == '.' || mp[xx2][yy2] == '.'){
                    canmove = 1;
                    break;
                }
            }
            if(canmove) printf("Tie\n");
            else printf("Black 0\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}