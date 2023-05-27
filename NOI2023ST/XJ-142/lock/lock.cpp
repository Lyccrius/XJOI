#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int k,n,T,a[5][50005];
	cin>>T>>k;
	for(int w=0;w<T;w++){
		cin>>n;
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		int ma=-10,mi=50009;
		if(k==1){
			for(int i=0;i<n;i++){
				if(a[0][i]>ma){
					ma=a[0][i];
				}
				if(a[0][i]<mi){
					mi=a[0][i];
				}
			}
			cout<<ma-mi;
		}
	}
	return 0;
}
