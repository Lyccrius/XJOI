#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int T,k;
    scanf("%d%d",&T,&k);
    if(k == 1){
		for(int i = 1; i <= T; i++){
			int n,ma = 0,mi = 30004;
			scanf("%d",&n);
			for(int j = 1; j <= n; j++){
				int x;
				scanf("%d",&x);
				ma = max(x,ma);
				mi = min(x,mi);
			}
			printf("%d\n",ma - mi);
		}
	}
	if(k == 2){
		for(int i = 1; i <= T; i++){
			int n,ma1 = 0,mi1 = 30004,ma2 = 0,mi2 = 30004,a[2][50005];
			scanf("%d",&n);
			for(int j = 1; j <= n; j++){
				scanf("%d",&a[1][j]);
			}
			for(int j = 1; j <= n; j++){
				int x;
				scanf("%d",&x);
				if(x > a[1][j]){
					a[2][j] = a[1][j];
					a[1][j] = x;
				}
				ma1 = max(a[1][j],ma1);
				mi1 = min(a[1][j],mi1);
				ma2 = max(a[2][j],ma2);
				mi2 = min(a[2][j],mi2);
			}
			int ans = max(ma1 - mi1,ma2 - mi2);
			printf("%d\n",ans);
		}
	}
	return 0;
}
