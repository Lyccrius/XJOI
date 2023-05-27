#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int T,n,m,q,ost,x,c;
struct node{
	int num,id;
};
node h[100005],l[100005];
priority_queue <int> pq;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(h,0,sizeof(h));
		memset(l,0,sizeof(l));
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=q;i++){
			scanf("%d%d%d",&ost,&x,&c);
			if(ost==0){
				h[x].num=c;
				h[x].id=i;
			}		
			else{
				l[x].num=c;
				l[x].id=i;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(h[i].id>l[j].id){
					printf("%d ",h[i].num);				
				}
				else{
					printf("%d ",l[j].num);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
