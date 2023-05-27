#include <cstdio>
#include <iostream>
int n,ans(0);int k;
using namespace std;

int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	for(int u=1;u<=n;u++){
		if(u==1) {
				ans++;
				continue;
			}
		for(int i=1;i<u;i++){
			
			int a=u;int b=i;int an(0);
			while(a>1){
				int m; 
				m=a/b;
				if(m*b!=a) {
					an=-1;
					a=-1;
				}
				else {
					a=a/b;
					an++;
				}
				
			}
			if(an>=k) {ans++;u++;i=1;}		
		}
	}
		
	
	
	cout<<ans;
	return 0;
}
