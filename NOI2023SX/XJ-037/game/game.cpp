#include <bits/stdc++.h>
using namespace std;
int T,n,m;
int cxcs[150005],sfsy[150005];
struct node{
	int t1,t2;
}t[150005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		int fznum;
		memset(cxcs,0,sizeof(cxcs));
		memset(sfsy,0,sizeof(sfsy));
		for(int i=1;i<=n;i++){
			cin>>fznum;
			if(fznum==1){
			    cin>>fznum;
			}else{
				cin>>fznum;
				cin>>fznum;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>fznum;
			if(fznum==1){
			    cin>>t[i].t1;
			    t[i].t2=t[i].t1;	
			}else{
				cin>>t[i].t1>>t[i].t2;
			}
			cxcs[t[i].t1]++;
			cxcs[t[i].t2]++;
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			int s1=t[i].t1,s2=t[i].t2;
			if(sfsy[s1]&&sfsy[s2]){
				cout<<-1<<endl;
				flag=1;
				break;
			}else if(sfsy[s1]){
				sfsy[s2]=1;
			}else if(sfsy[s2]){
				sfsy[s1]=1;
			}else{
				if(cxcs[s1]<cxcs[s2]) sfsy[s1]=1;
				else sfsy[s2]=1;
			}
		}
		if(flag==0) cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
