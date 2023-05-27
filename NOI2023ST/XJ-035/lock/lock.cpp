#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int t;
	cin>>t;
	for(int e=1;e<=t;e++){
		int k,n,a[105][105],c[105][105],C;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				}
			}
			for(int j=1;j<=n;j++){
				for(int i=1;i<=k;i++){
					n[i+1][j]=a[i][j];
					}
					for(int s=1;s<=k+1;s++){
						a[s][j]=n[s][j];
						if(s==1){
							a[s][j]=n[k+1][j];
							}
						}
					for(int r=1;r<=k;r++){
						for(int f=1;f<=n;r++){
							if(a[r][f]>=a[r][f+1]){
								c[r]=a[r][f];
								}
							}
						}
				}
				for(int i=1;i<=k;i++){
					if(c[i]>=max){
						max=c[i];
						}
					}
					C=max;
					cout<<C;
					return 0;
		}
}
