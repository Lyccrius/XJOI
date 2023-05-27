#include <bits/stdc++.h>
using namespace std;
int n,m,q,opt,x,c,mapp[10005][10005];

void change(){
	if (opt==1){
		for (int i=1;i<=m;i++){
			mapp[i][x]=c;
		}
	}else {
		for (int i=1;i<=n;i++){
			mapp[x][i]=c;
		}
	}
}

void print(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cout<<mapp[i][j]<<" ";
		}
		if (i<=n-1){
			cout<<endl;
		}
	}
}

int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		cin>>n>>m>>q;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				mapp[i][j]=0;
			}
		}
		for (int i=1;i<=q;i++){
			cin>>opt>>x>>c;
			change();
		}
		print();
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
