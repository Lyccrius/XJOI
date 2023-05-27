#include<stdio.h>
#define N 15

int T,id,n,m,f;
char s[N][N];

int main(){
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	
	scanf("%d%d",&id,&T);
	
	while(T--){
		
		scanf("%d%d",&n,&m);
		f=0;
		for(int i=0;i<=n;i+=1) a[i][0]=a[i][m+1]='#';
		for(int i=0;i<=m;i+=1) a[0][i]=a[n+1][i]='#';
		
		for(int i=1;i<=n;i+=1){
			scanf("%s",s[i]+1);
		}
		
		for(int i=1;i<=n;i+=1){
			for(int j=1;j<=m;j+=1){
				
				if(s[i][j]=='X'){
					s[i-1][j]='#'
					s[i+1][j]='#'
					s[i][j-1]='#'
					s[i][j+1]='#'
				}
			}
		}
		for(int i=1;i<=n;i+=1){
			for(int j=1;j<=m;j+=1){
				
				if(s[i][j]=='O'&&(s[i-1][j]=='#'||s[i-1][j]=='O')&&(s[i+1][j]=='#'||s[i+1][j]=='O')&&(s[i][j-1]=='#'||s[i][j-1]=='O')&&(s[i][j+1]=='#'||s[i][j+1]=='O')){
					f+=1;
				}
			}
		}
		
		if(f==2) printf("Black 0\n");
		else printf("Tie\n");
	}
	return 0;
}
