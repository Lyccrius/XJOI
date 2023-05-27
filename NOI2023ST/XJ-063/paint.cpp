#include<bits/stdc++.h>
using namespace std;
int T,n,m,q,opt,x,c;
int a[100010][100010];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		while(q--){
			scanf("%d%d%d",&opt,&c,&x);
			if(opt==0){
				for(int i=0;i<m;i++){
					a[x][i]=c;
				}
			}else{
				for(int i=0;i<n;i++){
					a[i][x]=c;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ",a[i][j]);
				a[i][j]=0;
			}
			printf("\n");
		}
	}
	return 0;
}
