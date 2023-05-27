#include <bits/stdc++.h>
//#define int long long
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
bool v[100005];
double ans=0X3f;
int a[1005];//record the process paths
int anpath[1005];//record the final paths
void dfs(node tmp,int num,double sum){//id   the amount of the dfs
	if(num==n){
		//cout<<"----"<<endl;
		if(ans>sum){
			ans=sum;
		}
		return ;
	}
	if(num>n) return ;
	for(int i=1;i<=n;i++){
		if(v[i]==0){//if haven't gone there, go
			v[i]=1;//mark
			dfs(edge[i],num+1,sum+=get_dis(tmp,edge[i]));
			v[i]=0;//back
		}
	}
}
int main(){
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

	v[st.id]=1;
	a[1]=st.id;
	dfs(st,1,0);
	printf("%.9f",ans);
	return 0;
}
