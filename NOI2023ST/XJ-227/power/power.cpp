#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long inf = 1000000000000000007;
ll n,k;
ll fastjia(ll X,ll Y){
	ll ans = 0;
	for(;X!=0;X>>=1){
		if(X&1){
			if(ans + Y > inf) return -inf;
			ans = ans+Y;
		}
		Y = Y+Y;
		if(Y + Y > inf) return -inf;
	}
	return ans;
}
ll fastpower(ll A,ll X){
	ll ans = 1;
	for(;X!=0;X>>=1){
		if(X&1){
			ll chen = fastjia(ans,A);
			if(chen == -inf) return inf;
			ans = chen;
		}
		//ll chen = fastjia(A,A);
		//if(chen == -inf && X != 0) return inf;
		A = fastjia(A,A);		
	}
	return ans;
}
ll find(int a){
	int l = 1,r = 64;
	while(l<r){
		int mid = (l+r+1)>>1;
		ll z = fastpower(a,mid);
		//cout << l << ' ' << r <<' '<<mid<<' '<<z<< endl;
		if(z == n) return mid;
		else if(z<n) l = mid;
		else if(z>n) r = mid-1;
	}
	return l;
}
/*
ll find2(int l,int r){
	
	while(l<r){
		int mid = (l+r+1)>>1;
		ll z = fastpower(a,mid);
		//cout << l << ' ' << r <<' '<<mid<<' '<<z<< endl;
		if(z == n) return mid;
		else if(z<n) l = mid;
		else if(z>n) r = mid-1;
	}
	return l;
}
*/
int main(){
	//12 1000000000000
	//14 100000000000000
	//15 1000000000000000
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin >> n >> k;
    if(k == 1){
        cout << n << endl;
        return 0;
    }
    int ans = 1;
	for(int i = 2; i <= n; i++){
		bool b = 0;
		int i1=i;
		for(int z = 2; z < i; z++){
			if(i%z == 0){
				while(i1%z == 0) i1 /= z;
				if(i1 == 1) b = 1;
				break;
			}
		}
		if(b == 1) continue;
		int f = find(i);
		if(f < k) break;
		ans += f-k+1;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
