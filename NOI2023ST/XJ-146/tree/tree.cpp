#include <bits/stdc++.h>
#define double  long double
using namespace std;
struct node{
	int id;
	double x,y;
}edge[1005];
double get_dis(node a,node b){
	double x1=a.x,y1=a.y;
	double x2=b.x,y2=b.y;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int n;
node st;
double maxs=INT_MIN	;
bool v[1005];
double ans=INT_MAX;
int a[1005];//record the process paths
int anpath[1005];//record the final paths
void dfs(node tmp,int num,double sum,int path[]){//id   the amount of the dfs
	if(num==n){
		//cout<<"ans="<<ans<<endl<<"sum="<<sum<<endl;
		if(ans>sum){
			ans=sum;
			for(int i=1;i<=n;i++){
				anpath[i]=path[i];
			}
		}
		return ;
	}
	if(num>n) return ;
	for(int i=1;i<=n;i++){
		if(v[i]==0){//if haven't gone there, go
			v[i]=1;//mark
			path[num+1]=edge[i].id;
			dfs(edge[i],num+1,sum+=get_dis(tmp,edge[i]),path);
			v[i]=0;//back
			path[num+1]=0;
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>edge[i].x>>edge[i].y;
		edge[i].id=i;
		if(edge[i].y>maxs){
			maxs=edge[i].y;
			st.x=edge[i].x,st.y=edge[i].y;
			st.id=i;
		}
	}
	memset(v,0,sizeof v);
	memset(a,0,sizeof a);
	v[st.id]=1;
	a[1]=st.id;
	dfs(st,1,0,a);
	for(int i=1;i<=n;i++)cout<<anpath[i]<<" ";
	return 0;
}





