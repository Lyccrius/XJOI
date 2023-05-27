#include <bits/stdc++.h>
using namespace std;
long long n;
int k,ans=1;

void f(int num){
	if (k==1){
		ans=num;
		return;
	}
	for (int j=2;j<=sqrt(num);j++){
		for (int i=k;i<=sqrt(n);i++){
			if (pow(j,i)==num){
				ans++;
				return;
			}else if (pow(j,i)>num){
				break;
			}
		}
	}
	return;
}

int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		f(i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
