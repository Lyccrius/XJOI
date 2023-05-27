#include <cstdio>
#include <iostream>
#include <queue>
int a[1000010];
using namespace std;
int n,k,T;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>T>>k;
	for(int u=1;u<=T;u++){
		for(int i=1;i<=600000;i++) a[i]=0;
		if(k==1) {
			
			cin>>n;
			int na(-1),ni(100000);
			for(int i=1;i<=n;i++){
				
				cin>>a[i];
				if(a[i]<ni) ni=a[i];
				if(a[i]>na) na=a[i];
				
			}
		
		cout<<na-ni<<endl;
		}
	}
	return 0;
}
