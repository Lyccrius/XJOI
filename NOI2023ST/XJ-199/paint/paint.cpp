#include <iostream>
using namespace std;
int n, m, q;
int opt[10010], x[10010], c[10010];
int a[100100][100100];
int main(){
    freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> q;
        a[n][m] = 0;
        for(int i = 1; i <= q; i++){
            cin >> opt[i] >> x[i];
            cin >> c;
        
            int w = x[i];

         if(opt[i] == 1){
             for(int ii = 1;ii <= n; ii++){
                    a[w][ii] = c;
                }
           }
           if(opt[i] == 0){
              for(int ii = 1; ii <= m; i++){
                  a[ii][w] = c;
              }
         }
         for(int i i= 1; ii <= n; i++){
               for(int j = 1; j <= m; j++){
                    cout << a[i][j] << endl;
                }
            }
        }  
    } 
    return 0;
}
