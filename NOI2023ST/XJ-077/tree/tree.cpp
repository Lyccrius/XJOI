#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int mp[1000000];
int ns[20],ls[20];
double ans=0x7f7f7f7f7f;
struct node{
double u,v;	
}e[10005];
int n;
void dfs(int m,double as,int x,int y){
	if(m==n){
		if(as<ans) {
			ans=as;
			for(int i=2;i<=n;i++){
				ns[i]=ls[i];
			}	
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		double jl;
		if(mp[i]==0){
			jl=sqrt((x-e[i].u)*(x-e[i].u)+(y-e[i].v)*(y-e[i].v));
			//cout<<as+jl<<" "<<ans<<endl;
			if(as+jl>ans) continue;
			//cout<<i<<endl;
				//cout<<"        "<<i<<endl;
			ls[m+1]=i;
			mp[i]=1;
			dfs(m+1,as+jl,e[i].u,e[i].v);
			mp[i]=0;
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    cin>>n;
    int bh;
    double yy=-1;
    for(int i=1;i<=n;i++){
		cin>>e[i].u>>e[i].v;
		if(e[i].v>yy){
				yy=e[i].v;
				bh=i;
		}
	}
	mp[bh]=1;
	ns[1]=bh;
	dfs(1,0,e[bh].u,e[bh].v);
	for(int i=1;i<=n;i++) cout<<ns[i]<<" ";
    return 0;
    fclose(stdin);
    fclose(stdout);
}
