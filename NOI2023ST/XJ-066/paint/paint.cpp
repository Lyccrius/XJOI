#include<bits/stdc++.h>
using namespace std;
int t;
int a[10010][10010],n,m,q;
void k(){
	memset(a,0,sizeof(a));
	cin >> n >> m >> q;
	for(int i=1;i<=q;i++){
		int o,x,c;
		scanf("%d%d%d",&o,&x,&c);
		if(o){
			for(int j=1;j<=n;j++){
				a[j][x]=c;
			}
		}else{
			for(int j=1;j<=m;j++){
				a[x][j]=c;
			}
		}
		//cout << i << endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return ;
}
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		k();
	}
	return 0;
}
