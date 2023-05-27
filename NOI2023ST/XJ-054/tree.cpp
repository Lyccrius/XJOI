#include <bits/stdc++.h>
using namespace std;
int n,k,cnt = 0;
int p(int a,int b){
    int s = 1;
    for(int i = 1;i<=b;i++)s*=a;
    return s;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d%d",&n,&k);
    if(k == 1){
        printf("%d",n);
        return 0;
    }
    for(int i = 1;i<=n;i++){
        for(int j = k;p(i,j)<=n;j++){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
