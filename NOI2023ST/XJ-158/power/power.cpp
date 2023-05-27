#include<bits/stdc++.h>
using namespace std;
int vis[500000000];
int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    int n, k, ans = 1, i = 2;
    scanf("%d %d", &n, &k);
    while(i <= n){
        int num = 1 ;
        for(int j = 1; num <= n; j ++){
            num *= i;
            if(num <= n && j >= k && vis[num] == 0) ans ++, vis[num] = 1;
        }
        i++;
    }
    printf("%d", ans);
    return 0;
}