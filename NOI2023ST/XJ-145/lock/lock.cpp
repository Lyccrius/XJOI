#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int P = 1e5 + 10;

// int num[P][5];
int n, k, T, lit[P], big[P];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> T >> k;
    while(T--){
        scanf("%d",&n);
        int mi = 1e9, ma = -1;
        if(k == 1){
            for(int i = 1;i <= n; i++){
                int t;
                scanf("%d",&t);
                mi = min(mi, t);
                ma = max(ma, t);
            }
            printf("%d",ma - mi);
        }
        else{
            memset(lit,0x3f,sizeof lit);
            memset(big,-1,sizeof big);
            for(int i = 1;i <= n; i++){
                for(int j = 1;j <= k; j++){
                    int t;
                    scanf("%d",&t);
                    lit[i] = min(lit[i], t);
                    big[i] = max(big[i], t);
                }
            }
            for(int i = 1;i <= n; i++){
                ma = max(lit[i], ma);
                mi = min(big[i], mi);
            }
            printf("%d",mi - ma);
        }
    }

    return 0;
}