#include<bits/stdc++.h>
using namespace std;
int T, k, n, a[12][50010];
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d%d", &T, &k);
    if(k == 1){
        while(T--){
            scanf("%d", &n);
            int x, mmaxc = -1, mminc = 21474836;
            for(int j = 1; j <= n; j++){
                scanf("%d", &x);
                mmaxc = max(mmaxc, x);
                mminc = min(mminc, x);
            }
            printf("%d\n",mmaxc - mminc);
        }
    }
    else if(k == 2){
        while(T--){
            scanf("%d", &n);
            int mmaxc = -1, mminc = 21474836, mmaxcn;
            for(int j = 1; j <= n; j++){
                scanf("%d", &a[1][j]);
            }
            for(int j = 1; j <= n; j++){
                scanf("%d", &a[2][j]);
                if(a[2][j] < a[1][j]){
                    int pp = a[2][j];
                    a[2][j] = a[1][j];
                    a[1][j] = pp;
                }
                mmaxc = max(mmaxc, a[2][j]);
                mminc = min(mminc, a[2][j]);
            }
            mmaxcn = mmaxc - mminc;
            mmaxc = -1, mminc = 21474836;
            for(int j = 1; j <= n; j++){
                mmaxc = max(mmaxc, a[1][j]);
                mminc = min(mminc, a[1][j]);
            }
            mmaxcn = max(mmaxcn, mmaxc - mminc);
            printf("%d\n",mmaxcn);
        }
    }
    else{
        while(T--){
            scanf("%d", &n);
            int tt = 0, mmaxc = -1, mminc = 21474836, mmaxcn = 0;
            for(int i = 1; i <= k; i++){
                for(int j = 1; j <= n; j++){
                    scanf("%d", &a[i][j]);
                }
            }
            for(int j = 1; j <= n; j++){
                tt = 0, mminc = 21474836;
                for(int i = 1; i <= k; i++){
                    if(a[i][j] < mminc){
                        mminc = a[i][j];
                        tt = i;
                    }
                }
                for(int i = 1; i < tt; i++){
                    a[i + k][j] = a[i][j];
                }
                for(int i = 1; i <= k; i++){
                    a[i][j] = a[i + tt - 1][j];
                }
            }
            for(int i = 1; i <= k; i++){
                mmaxc = -1, mminc = 21474836;
                for(int j = 1; j <= n; j++){
                    mmaxc = max(mmaxc, a[i][j]);
                    mminc = min(mminc, a[i][j]);
                }
                mmaxcn = max(mmaxcn, mmaxc - mminc);
            }
            printf("%d\n",mmaxcn);
        }
    }
    return 0;
}