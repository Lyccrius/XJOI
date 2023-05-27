#include<cstdio>
using namespace std;
typedef long long ll;
const int mod = 998244353;

int n, m, k;
ll ans = 1;
int dfs(int x){
    if(x % 2 == 0){
        return ans = (ans * (dfs(x / 2) + 1) )% mod;
    }
}
void meth1(){
    ans = (ans * (dfs(m) + 1) )% mod;
    printf("%lld",ans);
    return ;
}
int main(){
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    scanf("%d %d",&n,&m);
    if(m == n - 1) meth1();


    printf("%lld",ans);
    return 0;
}