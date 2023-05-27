#include<bits/stdc++.h>

using namespace std;

int a;
int ans=1;
int k;
long long n;
bool x[1000000000];

int main(){
	
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
    cin>>n>>k;
    for (int i=0;i<65;i++){
		if (pow(2,i) >= n){
			a = i;
			break;
		}
	}
    if (k == 1){
        cout<<n;
    }
    else{
		for (int j=k;j<a;j++){
			for (int i=2;i<=n;i++){
				if (x[i]){
					continue;
				}
				else{
					if(pow(i,k) <= n){
						i = pow(i,k);
						x[i] = true;
						i--;
						ans++;
					}
				}
			}
		}
		cout<<ans;
    }

    return 0;
}
