#include <bits/stdc++.h>
using namespace std;
int n,k,cnt = 0;
bool v[1005];
int pa(int a,int b){
    int s = 1;
    for(int i = 1;i<=b;i++)s*=a;
    return s;
}
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scanf("%d%d",&n,&k);
    if(k == 1){
        printf("%d",n);
        return 0;
    }
    for(int i = 1;i*i<=n;i++){
        for(int j = k+3;j>=k;j--){
            int t = pa(i,j);
            if(t<=n && !v[t]){
                cnt+=j-k+1;
                v[t] = 1;
            }
        }
    }
    cout << cnt;
    return 0;
}
