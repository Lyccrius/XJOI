#include <bits/stdc++.h>
using namespace std;
long long i,j,n,k,s,z,p;
void aaa(long long i1,long long j1){
	z=0;
	if(j1==1){
		z=1;
		return ;
	}
	while(true){
		if(i1%j1!=0||i1<0||j1<0){
			return ;
		}else {
			i1=int(i1/j1);
			if(i1==1){
				p++;
				//cout<<i1<<" "<<j1<<endl;
				z=1;
				return ;
			}
		}
	}
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	s=(long long)sqrt(0.0+n);
	for(i=1;i<=n;i++){
		for(j=k;j<=s;j++){
			z=0;
			aaa(i,j);
			if(z==1){
				if(i==j){
					p--;
					//cout<<"@";
				}
				//cout<<i<<" "<<j<<" ";
				break;
			}
		}
	}
	cout<<p;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
