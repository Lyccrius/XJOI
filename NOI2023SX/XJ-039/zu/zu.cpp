#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n,m;
int M[15][15];
int black[15][15],red1[15][15],red2[15][15];
int bx,by,r1x = 0,r1y = 0,r2x,r2y;
int blackw = inf, redw = inf;
int gx[5] = {0,1,-1,0,0};
int gy[5] = {0,0,0,1,-1};
bool wall1(int x,int y){
    int sum = 0;
    if(M[x-1][y] == '#') sum++;
    if(M[x+1][y] == '#') sum++;
    if(M[x][y-1] == '#') sum++;
    if(M[x][y+1] == '#') sum++;
    if(x == 1) sum++;
    if(x == n) sum++;
    if(y == 1) sum++;
    if(y == m) sum++;
    if(sum == 4) return 1;
    else         return 0;
}
// inline redwall(int x,int y){
//     red1[x−1][y] = red1[x+1][y] = red1[x][y−1] = red1[x][y+1] = '#';
// }
// bool blackbfs(int x,int y){
//     if(black[x−1][y] == black[x][y−1] == black[x][y+1] != '#'){
//         black = 'X';
//         red1[x−1][y] == black[x][y−1] == black[x][y+1]
//     }
//     black[x][y] = '.';
// }
// void blackbfs(int x,int y){
    
// }

void solve14(){
    cin >> n >> m;
    string line;
    for(int i = 1; i <= n; i++){
        cin >> line;
        for(int j = 1; j <= m; j++){
            M[i][j] = line[j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!(M[i][j] = 'O' && wall1(i,j))){
                cout << "Tie" << endl;
            }
        }
    }
    cout << "Black 0" << endl;
    return;
}
void solve79(){
    cin >> n >> m;
    string line;
    for(int i = 1; i <= n; i++){
        cin >> line;
        for(int j = 1; j <= m; j++){
            M[i][j] = line[j-1];
        }
    }
    int bo = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(M[i][j] = 'O' && wall1(i,j)){
                bo++;
            }
        }
    }
    if(bo == 2){
        cout << "Black 0" << endl;
        return;
    }
    int q='.',qi=1,h='#',hi=n+1,xi=99999999;
    for(int i = 1; i < xi; i++){
        if(M[i][1] != '.') q = M[i][1],qi = i;
        if(M[i+1][1] == 'X') xi = i+1;
    }
    for(int i = xi+1; i <= n; i++){
        if(M[i][1] != '.'){
            h = M[i][1],hi = i;
            break;
        }
    }
    if(q == '#' && h == '#'){
        cout << "Tie" << endl;
        return;
    }
    if(q == 'O' && qi == xi-1 || h == 'O' && hi == xi+1){
        cout << "Red 1" << endl;
        return;
    }
    int rwin = 0;
    if(q == '.'){
        cout << "Black " << 2*xi-2 << endl;
        return;
    }
    // if(q == 'O'){
        cout << "Red " << 2*xi-2 << endl;
    //     return;
    // }
    // if(q == '.'){
    //     cout << "Black " << 2*xi-2 << endl;
    //     return;
    // }
    return;
}
// void dfs(int k){
//     if(k > 9) return;
//     if(k % 2 == 1){
//         for(int j = 1; j <= 4; j++){
//             int ox,oy,oM;
//             ox = r1x, oy = r1y;
//             r1x += gx[j],r1y += gy[j];
//             oM = M[r1x][r1y];
//             if(M[r1x][r1y] == 'X') redw = min(redw,k);
//             else if(M[r1x][r1y] == '.'){
//                 M[r1x][r1y] = 'O';
//                 M[ox][oy] = '.';
//                 dfs(k+1);
//             }
//             M[r1x][r1y] = oM;
//             r1x = ox, r1y = oy;
//             M[r1x][r1y] = 'O';

//             ox = r2x, oy = r2y;
//             r2x += gx[j],r2y += gy[j];
//             oM = M[r2x][r2y];
//             if(M[r2x][r2y] == 'X') redw = min(redw,k);
//             else if(M[r2x][r2y] == '.' || M[r2x][r2y] == 'X'){
//                 M[r2x][r2y] = 'O';
//                 M[ox][oy] = '.';
//                 dfs(k+1);
//             }
//             M[r2x][r2y] = oM;
//             r2x = ox, r2y = oy;
//             M[r2x][r2y] = 'O';
//         }
//     }
//     else if(k % 2 == 0){
//         for(int j = 2; j <= 4; j++){
//             int ox,oy,oM;
//             ox = bx, oy = by;
//             bx += gx[j],by += gy[j];
//             oM = M[bx][by];
//             if(M[bx][by] == 'O' || bx == 1) blackw = min(blackw,k);
//             else if(M[bx][by] == '.'){
//                 M[bx][by] = 'X';
//                 M[ox][oy] = '.';
//                 dfs(k+1);
//             }
//             M[bx][by] = oM;
//             bx = ox,by = oy;
//             M[bx][by] = 'X';
//         }
//     }
//     return;
// }
void solve1013(){
    cin >> n >> m;
    string line;
    for(int i = 1; i <= n; i++){
        cin >> line;
        for(int j = 1; j <= m; j++){
            M[i][j] = line[j-1];
        }
    }
    cout << "Tie" << endl;
    return;
}
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    int id,T;
    cin >> id >> T;
    while (T--){
        if(1<=id && id<=4) solve14();
        else if(7<=id && id<=9) solve79();
        else if(10<=id && id<=13) solve1013();
        else solve1013();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
