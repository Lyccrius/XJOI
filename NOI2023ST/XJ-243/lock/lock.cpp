#include<bits/stdc++.h>
using namespace std;
const int INF=30010;
int T,k;
int n;
int a[4][50010];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>T>>k;
    while(T--){
        cin>>n;
        int maxn=0,minn=INF;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                maxn=max(maxn,a[i][j]);
                minn=min(minn,a[i][j]);
            }
        }
        if(k==1){
            cout<<maxn-minn<<endl;
            continue;
        }
        if(k==2){
            for(int i=1;i<=n;i++){
                if(a[1][i]>a[k][i]){
                    swap(a[1][i],a[k][i]);
                }
            }
            int maxm=0;
            int minm=INF;
            for(int i=1;i<=n;i++){
                maxm=max(maxm,a[1][i]);
                minm=min(minm,a[2][i]);
            }
            cout<<max(maxn-minm,maxm-minn)<<endl;
        }
    }
    return 0;
}