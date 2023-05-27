#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
node sm;
double maxn=INT_MIN;
bool vis[100005];
int copway[1005];
int ans=0x3;
int v[10005];
struct node{
	int ig;
	int x,y;
}edge[1005];
double get(node a,node b){
	double x1=a.x,y1=a.y;
	double x2=b.x,y2=b.y;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(node tmp,ll num,double sum,int way[]){
	if(num==n){
		if(ans>sum){
			ans=sum;
			for(int i=1;i<=n;i++){
				copway[i]=way[i];
			}
		}
	}
	if(num>n) return ;
	for(int i=1;i<=n;i++){
		if(v[i])
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int a;
	cin>>n;
	get(n);
	for(ll i=1;i<=n;i++){
		cin>>edge[i].x>>edge[i].y;
		if(edge[i].y>maxn){
			maxn=edge[i].y;
			sm.x=edge[i].x,sm.y=edge[i].y;
			sm.id=i;
		}
	    memset(a,0,sizeof a);
	}
}



