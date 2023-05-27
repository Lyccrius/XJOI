#include<stdio.h>
#define N 10050

int T,n,m,q,k[N],t[N];
long long a[N][N],v[N];
bool f[2][N];

int main(){

	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);

	scanf("%d",&T);

	while(T--){

		scanf("%d%d%d",&n,&m,&q);

		for(int i=1;i<=n;i+=1){
			for(int j=1;j<=m;j+=1){
				a[i][j]=-1;
			}
		}

		for(int i=1;i<=n||i<=m;i+=1){
			f[0][i]=f[1][i]=false;
		}

		for(int i=1;i<=q;i+=1)
			scanf("%d%d%lld",&k[i],&t[i],&v[i]);

		for(int i=q;i>=1;i-=1){
			if(f[k[i]][t[i]]){
				continue;
			}
			if(k[i]){
				for(int j=1;j<=n;j+=1){
					if(a[j][t[i]]==-1){
						a[j][t[i]]=v[i];
					}
				}
			}
			else{
				for(int j=1;j<=m;j+=1){
					if(a[t[i]][j]==-1){
						a[t[i]][j]=v[i];
					}
				}
			}
			f[k[i]][t[i]]=true;
		}

		for(int i=1;i<=n;i+=1){
			for(int j=1;j<=m;j+=1){
				if(a[i][j]+1) printf("%lld ",a[i][j]);
				else printf("0 ");
			}
			printf("\n");
		}

	}

	return 0;
}
