#include <bits/stdc++.h>
using namespace std;
int n,m,s[1000005][3],t[1000005][3],cnt,x;
bool vis[1000005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	while (T--){
		cin>>n>>m;
		for (int i=1;i<=n;i++){
			cin>>s[i][0];
			for (int j=1;j<=s[i][0];j++){
				cin>>s[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++){
			cin>>t[i][0];
			for (int j=1;j<=t[i][0];j++){
				cin>>t[i][j];
				if (!vis[t[i][j]]){
					vis[t[i][j]]=true;
					cnt++;
				}
			}
		}
		if (cnt<n){
			cout<<-1<<endl;
			continue;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
