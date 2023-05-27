#include<stdio.h>
#include<queue>
using namespace std;
#define N 100005

int sid,n,k,m,fa[N],x,y,a[N];
long long ans;
struct Near_Set{
	int tot,hed[N],ver[N],nxt[N];
	void add(int ax,int ay){
		tot+=1,ver[tot]=ay;nxt[tot]=hed[ax];hed[ax]=tot;
	}
	//for(int ni=NS.hed[];ni;ni=NS.nxt[ni]) =NS.ver[ni];
}NS;

struct node{
	priority_queue <pair<int,int> > mi,ma;
}t[N];

int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	
	scanf("%d%d%d%d",&sid,&n,&k,&m);
	
	for(int i=2;i<=n;i+=1) scanf("%d",&fa[i]);
	
	for(int i=1;i<=k;i+=1){
		scanf("%d%d",&x,&a[i]);
		t[x].ma.push(make_pair(a[i],i));
		NS.add(x,i);
	}
	
	for(int i=n;i>=1;i-=1){
		if(t[i].ma.empty()) t[fa[i]].mi.push(make_pair(0,0));
		else{
			t[i].mi.push(make_pair(-t[i].ma.top().first,0));
			ans+=t[i].ma.top().first;
			t[i].ma.pop();
		}
		
		while(!(t[i].ma.empty()||t[i].mi.empty())){
			
			if((-t[i].mi.top().first)>=t[i].ma.top().first) break;
			ans+=t[i].ma.top().first+t[i].mi.top().first;
			t[fa[i]].mi.push(make_pair(-t[i].ma.top().first,0));
			t[i].ma.pop();t[i].mi.pop();
		}
		
		while(!t[i].mi.empty()){
			t[fa[i]].mi.push(make_pair(t[i].mi.top().first,0));
			t[i].mi.pop();
		}
		
	}
	
	printf("%lld ",ans);
	
	for(int i=1;i<=m;i+=1){
		
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d",&x,&y);
			k+=1;
			NS.add(x,k);
			a[k]=y;
			ans=0;
			for(int op=1;op<=n;op+=1){
				while(!t[op].ma.empty()) t[op].ma.pop();
				while(!t[op].mi.empty()) t[op].mi.pop();
				for(int ni=NS.hed[op];ni;ni=NS.nxt[ni])
					t[op].ma.push(make_pair(a[NS.ver[ni]],op));
			}
			for(int j=n;j>=1;j-=1){
				
				if(t[j].ma.empty()) t[fa[j]].mi.push(make_pair(0,0));
				else{
					t[j].mi.push(make_pair(-t[j].ma.top().first,0));
					ans+=t[j].ma.top().first;
					t[j].ma.pop();
				}
				
				while(!(t[j].ma.empty()||t[j].mi.empty())){
					if((-t[j].mi.top().first)>=t[j].ma.top().first) break;
					ans+=t[j].ma.top().first+t[j].mi.top().first;
					t[fa[j]].mi.push(make_pair(-t[j].ma.top().first,0));
					t[j].ma.pop();t[j].mi.pop();
				}
				
				while(!t[j].mi.empty()){
					t[fa[j]].mi.push(make_pair(t[j].mi.top().first,0));
					t[j].mi.pop();
				}
			}
		}else if(x==2){
			scanf("%d",&y);
		}else printf("EEROR!\n");
		printf("%lld ",ans);
	}
	
	return 0;
}
