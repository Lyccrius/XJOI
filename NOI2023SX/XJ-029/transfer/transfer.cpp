#include <bits/stdc++.h>
using namespace std;
int sid,n,k,m,p,x,v,e,ans;

struct state{
	int up;
	int count=1;
	int exc[2338];
	int maxn=0;
	void cmax(){
		maxn=0;
		for (int i=1;i<count;i++){
			maxn=max(maxn,exc[i]);
		}
	}
}st[2338];

void cal(){
	for (int i=1;i<=n;i++){
		ans+=st[i].maxn;
	}
	cout<<ans<<" ";
	ans=0;
}

int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	cin>>sid>>n>>k>>m;
	for (int i=2;i<=n;i++){
		cin>>p;
		st[i].up=p;
	}
	for (int i=1;i<=k;i++){
		cin>>x>>v;
		st[x].exc[st[x].count++]=v;
		if (st[x].maxn<v){
			st[x].maxn=v;
		}
	}
	cal();
	int temp;
	for (int i=1;i<=m;i++){
		cin>>temp;
		if (temp==1){
			cin>>x>>v;
			if (st[x].maxn<v){
				st[x].maxn=v;
			}
			cal();
		}else {
			int id;
			cin>>id;			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
