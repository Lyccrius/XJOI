#include<stdio.h>
#define N 1000005
#define db1 false

int T,n,m,k,x,y,d[N],r[N],pc;
bool f;

struct node{
	int x,y,z;
}A[N],B[N];

struct Near_Set{
	int tot=0,hed[N],ver[2*N],nxt[2*N];
	void add(int ax,int ay){
		tot+=1;ver[tot]=ay;nxt[tot]=hed[ax];hed[ax]=tot;
	}
	//for(int ni=NS.hed[];ni;ni=NS.nxt[ni]) =NS.ver[ni];
}NS;

int my_min(int x,int y){
	return x<y?x:y;
}

bool sol(int sx,bool sv){
	
	if(db1) printf("#%d:\n",sx);
	
	if(d[sx]==-1&&sv) return true;
	d[sx]=-1;
	for(int si=NS.hed[sx];si;si=NS.nxt[si]){
		int sy=NS.ver[si];
		if(B[sy].z) continue;
		
		if(db1) printf("*%d:\n",sy);
		
		if(B[sy].x==sx){
			B[sy].z=B[sy].y;
			r[0]+=1;
			r[r[0]]=sy;
			if(sol(B[sy].y,true)){
				B[sy].z=0;
				return true;
			}
		}
		else{
			B[sy].z=B[sy].x;
			r[0]+=1;
			r[r[0]]=sy;
			if(sol(B[sy].x,true)){
				B[sy].z=0;
				return true;
			}
		}
	}
	return false;
}

void doo(int dc){
	int dx=NS.hed[dc];
	int dy=NS.ver[dx];
	if((A[dy].x-dc)&&(A[dy].y-dc)) return;
	B[dy].z=dc;
	d[dc]=-1;
	if(B[dy].x==dc){
		if(d[B[dy].y]==2) d[B[dy].y]-=1,doo(B[dy].y);
	}
	else{
		if(d[B[dy].x]==2) d[B[dy].x]-=1,doo(B[dy].x);
	}
	return;
}

int get(){
	int gc=1,gx=0x7fffffff,gy=0x7fffffff;
	while(B[gc].z&&gc<=n) gc+=1;
	if(db1) printf("&%d:\n",gc);
	if(gc>n){
		int ans=0;
		for(int gi=1;gi<=n;gi+=1){
			//if(d[i]+1) printf("%d!\n",i);
			if(A[gi].z){
				if(A[gi].z==B[gi].z) ans+=1;
			}
			else if(A[gi].x==B[gi].z||A[gi].y==B[gi].z) ans+=1;
		}
		return ans;
	}
	B[gc].z=B[gc].x;
	d[B[gc].z]=-1;
	if(!sol(B[gc].z,false)) gx=get();
	while(r[0]){B[r[r[0]]].z=0;r[0]-=1;}
	d[B[gc].z]=1;
	B[gc].z=B[gc].y;
	d[B[gc].z]=-1;
	if(!sol(B[gc].z,false)) gy=get();
	d[B[gc].z]=1;
	return my_min(gx,gy);
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		f=false,
		NS.tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i+=1) A[i].x=A[i].y=A[i].z=B[i].x=B[i].y=B[i].z=0;
		for(int i=0;i<=m;i+=1) d[i]=0,NS.hed[i]=0;
		for(int i=1;i<=n;i+=1){
			scanf("%d",&k);
			if(k==1){
				scanf("%d",&A[i].z);
			}else if(k==2){
				scanf("%d%d",&A[i].x,&A[i].y);
			}else printf("ERROR!\n");
		}
		for(int i=1;i<=n;i+=1){
			scanf("%d",&k);
			if(k==1){
				scanf("%d",&B[i].z);
				NS.add(0,B[i].z);
				if(d[B[i].z]+1){
					d[B[i].z]=-1;
				}else f=true;
			}else if(k==2){
				scanf("%d%d",&B[i].x,&B[i].y);
				NS.add(B[i].x,i);
				NS.add(B[i].y,i);
				if(d[B[i].x]+1) d[B[i].x]+=1;
				if(d[B[i].y]+1) d[B[i].y]+=1;
			}else printf("ERROR!\n");
		}
		
		if(f){
			printf("-1\n");
			continue;
		}
		
		for(int ni=NS.hed[0];ni;ni=NS.nxt[ni]){
			if(sol(NS.ver[ni],false)){
				f=true;
				break;
			}
		}
		
		if(f){
			printf("-1\n");
			continue;
		}
		
		for(int i=1;i<=n;i+=1){
			if(d[i]==1) doo(i);
		}
		
		r[0]=0;
		int pp=get();
		if(pp-0x7fffffff) printf("%d\n",pp);
		else printf("-1\n");
		
		/*
		if(db1){
			for(int i=0;i<=n;i+=1){
				printf("\n#%d:\n",i);
				for(int ni=NS.hed[i];ni;ni=NS.nxt[ni]){
					printf("%d ",NS.ver[ni]);
				}
				printf("\n%d\n",B[i].z);
			}
		}
		*/
		
		/*
		for(int i=1;i<=n;i+=1){
			if(ct[B[i].x]==-1&&ct[B[i].y]==-1) f=true;
			else if(ct[B[i].x]==-1) ct[B[i].y]==-1,B[i].z=B[i].y;
			else if(ct[B[i].y]==-1) ct[B[i].x]==-1,B[i].z=B[i].x;
		
		if(f){
			printf("-1\n");
			continue;
		}
		*/
	}
	return 0;
}
