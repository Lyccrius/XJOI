#include<stdio.h>
#include<algorithm>
#define N 200005
#define M 200005

int n,m,s,x,y,lc,rc,lk,rk,p;
bool v[N];

int my_max(int mx,int my){
	return mx>my?mx:my;
}

int my_min(int mx,int my){
	return mx<my?mx:my;
}

struct node{
	int d,t;
}l[M],r[M];

bool cmp1(node cx,node cy){
	return cx.d<cy.d;
}
bool cmp2(node cx,node cy){
	return cx.d>cy.d;
}

int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&s);
	
	for(int i=1;i<=m;i+=1){
		scanf("%d%d",&x,&y);
		if(x>=s){
			rc+=1;
			r[rc].d=x,r[rc].t=y;
		}else if(y<=s){
			lc+=1;
			l[lc].d=y,l[lc].t=x;
		}else{
			rc+=1;
			r[rc].d=s,r[rc].t=y;
			lc+=1;
			l[lc].d=s,l[lc].t=x;
		}
	}
	
	std::sort(r+1,r+rc+1,cmp1);
	std::sort(l+1,l+lc+1,cmp2);
	
	/*
	for(int i=1;i<=rc;i+=1) printf("%d-%d\n",r[i].d,r[i].t);
	printf("#\n");
	for(int i=1;i<=lc;i+=1) printf("%d-%d\n",l[i].d,l[i].t);
	*/
	
	p=1,rk=s;
	while(r[p].d<=rk&&p<=rc){
		v[r[p].t]=true;
		rk=my_max(r[p].t,rk);
		p+=1;
	}
	
	p=1,lk=s;
	while(l[p].d>=lk&&p<=lc){
		v[l[p].t]=true;
		lk=my_min(l[p].t,lk);
		p+=1;
	}
	
	for(int i=1;i<=n;i+=1) if(v[i]) printf("%d ",i);
	
	return 0;
}
