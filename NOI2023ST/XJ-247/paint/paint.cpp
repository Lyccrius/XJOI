#include<bits/stdc++.h>
using namespace std;
struct wall{
	long long color;
	int timen;
	void cinn(int x){
		cin>>color;
		timen=x;
		return;
	}
}a[1000005],b[1000005];   //a表示行，b表示列
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int T;
	cin>>T;
for(int sh=1;sh<=T;sh++){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(x){
			b[y].cinn(i);
		}
		else{
			a[y].cinn(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i].timen>b[j].timen){
				cout<<a[i].color<<" ";
			}
			else{
				cout<<b[j].color<<" ";
			}
		}
		puts("");
	}
	for(int i=1;i<=n;i++){
		a[i].color=0;
		a[i].timen=0;
	}
	for(int j=1;j<=m;j++){
		b[j].color=0;
		b[j].timen=0;
	}
}	
fclose(stdin);
fclose(stdout);
}
