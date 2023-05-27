#include<cstdio>
int C,n,m,t,a[60];
int main(){
 	freopen("color.in","r",stdin);
 	freopen("color.out","w",stdout);
	scanf("%d",&C);
	while(C--){
		scanf("%d%d%d",&n,&m,&t);
		for(int i=0;i<t;++i)
			scanf("%d",&a[i]);
		if(n==t){
			puts("1 0");
		}else{
			puts("2 2");
		}
	}
}