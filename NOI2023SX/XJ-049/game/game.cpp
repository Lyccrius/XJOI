#include<bits/stdc++.h>
using namespace std;
int t;
int a[2000010],b[2000010],cnt[1000010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> t;
	for(int x=1;x<=t;x++){
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			for(int j=1;j<=x;j++){
				int k;
				scanf("%d",&k);
				if(j==1) a[i]=k;
			}
		}
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			for(int j=1;j<=x;j++){
				int k;
				scanf("%d",&k);
				if(j==1) b[i]=k;
				cnt[b[i]]++;
			}
		}
		int flag=0;
		for(int i=1;i<=m;i++){
			if(cnt[i]){
				flag++;
				cout << i << " ";
			}
		}
		if(flag<n){
			cout << -1 << endl;
			continue;
		}
		cout << 0 << endl;
	}
	return 0;
}
