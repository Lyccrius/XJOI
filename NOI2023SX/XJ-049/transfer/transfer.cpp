#include<bits/stdc++.h>
using namespace std;
int n,k,m,sid;
long long su;
int a[100010];
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	cin >> sid;
	cin >> n >> k >> m;
	for(int i=2;i<=n;i++){
		int q;
		cin >> q;
	}
	for(int i=1;i<=k;i++){
		int q,w;
		cin >> q >> w;
		a[q]=w;
		su += w;
	}
	cout << su << " ";
	for(int i=1;i<=m;i++){
		int x;
		cin >> x;
		if(x==1){
			int w,v;
			cin >> w >> v;
			if(a[w]<v){
				su += v-a[w];
				a[w]=v;
			}
		}else{
			int w;
			cin >> w;
		}
		cout << su << " ";
	}
	return 0;
}
