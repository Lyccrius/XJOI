#include<bits/stdc++.h>
using namespace std;
int t,k,mi;
int a[5][10010];
int n;
void s(){
	int q=0;
	for(int i=1;i<=k;i++){
		int w=a[i][1],e=a[i][1];
		for(int j=1;j<=n;j++){
			if(a[i][j]>w)w=a[i][j];
			if(a[i][j]<e)e=a[i][j];
		}
		q+=w-e;
	}
	if(mi==-1){
		mi=q;
	}else if(q<mi){
		mi=q;
	}
}
void h(int q){
	int w=a[1][q];
	for(int i=2;i<=k;i++){
		a[i-1][q]=a[i][q];
	}
	a[k][q]=w;
}
void lock(int deep){
	if(deep>k){
		s();
		return ;
	}
	for(int i=1;i<=n;i++){
		h(i);
		lock(deep+1);
	}

}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> t >> k;
	for(int i=1;i<=t;i++){
		mi=-1;
		cin >> n;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				cin >> a[i][j];
			}
		}
		lock(0);
		cout << mi << endl;
	}
	return 0;
}
