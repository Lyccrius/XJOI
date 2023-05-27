#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int n;
int flag[1010];
double x[1005],y[1005];
priority_queue <int> pq;
int minl(int z){
	double l,min=0x7fffffff;
	int r=0;
	for(int i=1;i<n;i++){
		if(flag[i]==0){
			l=sqrt((x[i]-x[z])*(x[i]-x[z])+(y[i]-y[z])*(y[i]-y[z]));
			if(min>l){
				min=l;
				r=i;
				flag[i]=1;
			}	
		}
	}
	return r;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&x[i],&y[i]);
	}
	double max=-0x7fffffff;
	int e;
	for(int i=1;i<=n;i++){
		if(max<y[i]){
			max=y[i];
			e=i;
		}
		else if(max==y[i]){
			if(x[i]<x[e]){
				e=i;
			}
		}
	}
	printf("%d ",e);
	int j=n;//i shi ge shu       j shi xu hao
	e--;
	flag[n]=1;
	while(e--){
		j=minl(j);
		printf("%d ",j);
	}
	return 0;
}
