#include <bits/stdc++.h>
using namespace std; 
int T,n,k,a[5][50010],san=INT_MAX;
void bd(int b){
	a[0][b]=a[n][b];
	a[n][b]=0;
	int z;
	z=a[1][b];
	a[1][b]=a[0][b];
	for(int j=0;j<n;j++){
		z=a[j+1][b];
		a[j+1][b]=z;
	}
}
int c(int b){
	int maxb=0,minb=INT_MAX;
	for(int j=1;j<=n;j++){
		if(a[j][b]>=maxb){
			maxb=a[j][b];
		}
		if(a[j][b]<=minb){
			minb=a[j][b];
		}
	}
	return maxb-minb;
}
int C(){
	
	int maxc=0;
	for(int i=1;i<=n;i++){
		if(c(i)>=maxc){
			maxc=c(i);
		}
	}
	return maxc;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d%d",&T,&k);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int x=0;
		for(int i=0;i<=2*n;i++){
			x++;
			if(x>n){
				x%=n;
			}
			bd(x);
			if(C()<=san){
				san=C();
			}
			if(C()==0){
				continue;
			}
		}
	}
	printf("%d",san);
	return 0;
}
