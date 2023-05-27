#include<iostream>
#include<stdio.h>
using namespace std;
int T,k;
int a[50005][3];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>T>>k;
	while(T--){
		int n;
		cin>>n;
		int maxx=0,minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			maxx=max(maxx,a);
			minn=min(minn,a);
		}
		cout<<maxx-minn<<endl;
	}
}
