#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int a[5][50005],c[50005],d[50005];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d%d",&t,&k);
    if (k == 1){
        while (t--){
            int ma = INT_MIN,mi = INT_MAX;
            cin >> n;
            int q;
            while (n--){
                scanf("%d",&q);
                if (q > ma) ma = q;
                if (q < mi) mi = q;
            }
            cout << ma - mi << endl;
        }
    }
    return 0;
}
