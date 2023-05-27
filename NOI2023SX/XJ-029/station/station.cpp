#include <bits/stdc++.h>
using namespace std;
int n,m,x,a[200005],b[200005],vis[200005],start[200005];
void find(int now,int dir){
	for (int i=1;i<=m;i++){
		if (dir==1 || dir==0){
			if (a[i]==now && !vis[b[i]]){
				vis[b[i]]=true;
				if (!vis[now+1] && start[now+1]){
					find(now+1,1);
				}
				find(b[i],1);
			}
		}
		if (dir==2 || dir==0){
			if (b[i]==now && !vis[a[i]]){
				vis[a[i]]=true;
				if (!vis[now-1] && start[now-1]){
					find(now-1,2);
				}
				find(a[i],2);
			}
		}
	}
}
void find1(int now){
	for (int i=1;i<=m;i++){
		if (a[i]==now && !vis[b[i]]){
			vis[b[i]]=true;
			if (!vis[now+1] && start[now+1]){
				find(now+1,1);
			}
			find(b[i],1);
		}
	}	 
}
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	cin>>n>>m>>x;
	for (int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
		start[a[i]]=true;
		start[b[i]]=true;
	}
	if (x==1){
		find1(x);
	}else {
		find(x,0);
	}
	for (int i=1;i<=n;i++){
		if (vis[i]){
			cout<<i<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
