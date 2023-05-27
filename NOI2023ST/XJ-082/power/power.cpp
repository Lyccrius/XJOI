#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long n,k,j,m=0;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		for(int l=1;l<=n;l++){
			j=k;
			while(pow(l,j)<=i){
				if(pow(l,j)==i){
					m++;
					continue;		
				}
				j++;	
			}				
		}	
	}				
	cout<<m;
	return 0;
}
	
	

