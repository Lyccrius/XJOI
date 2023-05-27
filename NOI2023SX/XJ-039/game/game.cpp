#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n,m;
int S[1000005][3],T[1000005][3];
int a[1000005],b[32775][10005];
int kb = 1;
bool make_a(long long A){
    for(int i = 1; i <= n; i++){
        if(((A>>(i-1)) & 1) == 0) a[i] = S[i][1];
        else{
            if(S[i][0] == 1) return 0;
            a[i] = S[i][2];
        }   
    }
    return 1;
}
bool make_b(long long B){
    map<int,int> MAP;
    for(int i = 1; i <= n; i++){
        if(((B>>(i-1)) & 1) == 0) b[kb][i] = T[i][1];
        else{
            if(T[i][0] == 1) return 0;
            b[kb][i] = T[i][2];
        }
        if(MAP[ b[kb][i] ] == 1) return 0;
        MAP[ b[kb][i] ] = 1;
    }
    return 1;
}
void solve(){
    kb = 1;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%d",&S[i][0]);
        if(S[i][0] == 1)
            scanf("%d",&S[i][1]),S[i][2] = S[i][1];
        else
            scanf("%d%d",&S[i][1],&S[i][2]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d",&T[i][0]);
        if(T[i][0] == 1)
            scanf("%d",&T[i][1]),T[i][2] = T[i][1];
        else
            scanf("%d%d",&T[i][1],&T[i][2]);
    }
    long long A = (1<<n) - 1, B = (1<<n) - 1;
    int A_best = 0;

    for(;B >= 0; B--){
        if(make_b(B)){
            kb++;
        }
    }
    kb--;



        // cout << kb << endl;
        // for(int j = 1; j <= kb; j++){
        //     for(int i = 1; i <= n; i++){
        //         cout << b[j][i];
        //     }
        //     cout << endl;
        // }
        // for(;A >= 0; A--)
        //     if(make_a(A))
        //         for(int i = 1; i <= n; i++){
        //             cout << a[i];
        //         }
        // A = (1<<n) - 1;



    if(kb == 0){
        printf("-1\n");
        return;
    }
    for(;A >= 0; A--){
        if(make_a(A)){
            int min_A = inf;
            for(int j = 1; j <= kb; j++){
                int sum = 0;
                for(int i = 1; i <= n; i++){
                    if(a[i] == b[j][i]) sum++;
                }
                min_A = min(min_A,sum);
            }
            A_best = max(A_best,min_A);
        }
    }
    printf("%d\n",A_best);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
