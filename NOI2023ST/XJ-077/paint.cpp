#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int mp[1000][1000];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    int t;
    cin>>t;
    int n,m,q,opt,x,c;
    for(int i=1;i<=t;i++){
		cin>>n>>m>>q;
		 memset(mp,0,sizeof(mp));
		for(int j=1;j<=q;j++){
			cin>>opt>>x>>c;
			if(opt==0){
					for(int k=1;k<=m;k++){
							mp[x][k]=c;
					}
			}else{
				for(int k=1;k<=n;k++){
							mp[k][x]=c;
					}
			}	
		}
		for(int x=1;x<=n;x++){
			for(int y=1;y<=m;y++){
					cout<<mp[x][y]<<" ";
				}
				cout<<endl;
			}
	}
    return 0;
    fclose(stdin);
    fclose(stdout);
}
