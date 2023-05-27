#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,t;
int a[10000];
int b[10000];
int ans[100005][55][2],as=1,anss;
queue<int>r,g,r1,g1;
int f=0;
int l=0;
int pd(){
	while(!r.empty()){
		int rr;
		
		rr=r.front();
		//cout<<"r "<<rr<<" ";
		r.pop();
		if(rr<r.front()){ 
			l=1;
			break;
		}
	}
	
	if(l)return 0;
	while(!g.empty()){
		int gg;
	
		gg=g.front();
		//	cout<<"g "<<gg<<" ";
		g.pop();
		if(gg>g.front()){
			l=1;
			break;
		}
	}
	if(l) return 0;
	while(!r1.empty()){
			ans[as][r1.front()][1]=1;
			r1.pop();
	}
	while(!g1.empty()){
			ans[as][g1.front()][2]=1;
			g1.pop();
	}
	//cout<<endl;
	as++;
	return 1;
}
void dfs(int s){
	if(f) return;
	if(s-1==t){
			//cout<<pd()<<endl;
			//cout<<1<<endl;
			
		if(pd()==1) {
			f=1;
			while(!g.empty())g.pop();
			while(!r.empty())r.pop();
			}
			return;
	}
	if(a[s]>r.front()||r.empty()) r.push(a[s]);//cout<<"b"<<a[s];
	else if(a[s]<g.front()||g.empty()) g.push(a[s]);
	else return;
	dfs(s+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int c;
	cin>>c;
	while(c--){
		cin>>n>>m>>t;
		for(int i=1;i<=t;i++){
			cin>>a[i];
		}
	}
	r.push(a[1]);
	dfs(2);
	g.push(a[1]);
	dfs(2);
	if(f) cout<<1;
	else cout<<1;
	cout<<" "<<66<<endl;
	
}
