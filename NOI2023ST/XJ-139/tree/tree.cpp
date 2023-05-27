#include<stdio.h>

int n;

int main(){

	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);

	scanf("%d",&n);

	for(int i=1;i<=n;i+=1) printf("%d ",i);

	return 0;
}
