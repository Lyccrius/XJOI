#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int T;
int opt[10001];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int n, q, m;
    int x[10001], y[10001], c[10001], v[10001][10001];
    cin >> T;
    cin >> n >> m >> q;
    for(int i = 0; i < T; i++) {
    for(int k = 0; k < n; k++){
        for(int j = 0; j < m; j++){
            cin >> opt[i] >> v[m][n] >> c[i];
        }
        for (int z = 0; z < q; z++){
            if(opt[i] = 0){
                n = c[i];
            }else m = c[i];
        }
        }
    }
    for(int i = 0; i < T; i++){
        for(int j = 0; j < m; j++){
            for(int k = 1; k < n; k++){
                printf("%d/n", v[m][n]);
            }
        }
    }
    return 0;
}