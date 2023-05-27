#include <bits/stdc++.h>
using namespace std;
int t,n,m,q,opt,x,c,ls[105][105];
int main(){
	//freopen("paint1.in","r",stdin);
	//freopen("paint1.out","w",stdout);
	cin>>t;	
	for(int i = 1;i <= t;i++){
		cin>>n>>m>>q;
		for(int j = 1;j <= q;j++){
			cin>>opt>>x>>c;
			if(opt == 0){
				for(int lie = 1;lie <= m;lie++){
					ls[n][lie] = c;
				}
			}else if(opt == 1){
				for(int hang = 1;hang <= n;hang++){
					ls[hang][m] = c;
				}
			}
		}
		for(int a = 1;a <= n;a++){
			for(int b = 1;b <= m;b++){
				cout<<ls[a][b]<<" ";
			}
			cout<<endl;
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
