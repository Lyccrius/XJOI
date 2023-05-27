#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int bh,t;
int n,m;
int ans=0;
char mp[100][100];
int bx,by;
int rx1,ry1,rx2,ry2,rx,ry;
int dfs(int h){
		if(rx1+2==bx&&rx2-2==bx) {
			ans+=2;
			return 0;
		}
		cout<<rx1<<" "<<bx<<" "<<rx2<<endl;
		if(h==1){
			if(bx-rx1>rx2-bx){rx1+=1,ans+=1,dfs(2);}
			else {rx2-=1;
				ans+=1;
				dfs(2);
			}
		}else{
			if(bx-rx1>rx2-bx) {bx-=1,ans+=1,dfs(1);}
			else bx+=1,ans+=1,dfs(1);
		}
		
		return 0;
	}
int main(){
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	cin>>bh>>t;
	while(t--){
		memset(mp,0,sizeof(mp));
		cin>>n>>m;
		int rr=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				if(mp[i][j]=='X') bx=i,by=j;
				if(mp[i][j]=='O'){
					if(rr==1){
						rx1=i,ry1=j;
						rr++;
					}else{
						rx2=i,ry2=j;
					}
				}
			}
		}
		//cout<<bh<<" "<<t<<endl;
		if(bh<=4){	
			int tx,ty;
			int st=0;
			for(int i=1;i<=4;i++){
				tx=rx1+dx[i];
				ty=ry1+dy[i];
				if(tx<=0||ty<=0||tx>n||ty>m||mp[tx][ty]=='#') continue;
				//cout<<" "<<tx<<" "<<ty<<endl;
				st++;
			}
			for(int i=1;i<=4;i++){
				tx=rx2+dx[i];
				ty=ry2+dy[i];
				if(tx<=0||ty<=0||tx>n||ty>m||mp[tx][ty]=='#') continue;
				st++;
			}
			//cout<<" "<<t<<endl;
			//cout<<"   "<<st<<endl;
			if(st!=0){
				cout<<"Tie"<<endl;
			}else{
				cout<<"Black "<<0<<endl;
			}
		}else if(bh<=6){
			//int rx,ry;
			if(rx1==n){ rx=rx2,ry=ry2;}
			else rx=rx1,ry=ry1;
		//	cout<<bx<<" "<<by<<" "<<rx<<" "<<ry<<endl;
			if(rx==bx){
				if(ry-1==by||ry+1==by) cout<<"Red "<<1<<endl;
			}else if(ry==by){
					if(rx-1==bx||rx+1==bx) cout<<"Red "<<1<<endl;
			}else{
				if(bx<rx){
					cout<<"Black "<<2*bx-2<<endl;
				}else{
					int c1,c2;
					if(ry>by) c1=ry-by;
					else c1=by-ry;
					c2=bx-rx;
					if(c2<c1-1){
						cout<<"Black "<<2*bx-2<<endl;
					}else if(c2==c1){
						cout<<"Black "<<c1*2<<endl;
					}else {
						if(c2>c1){
							if((c2-c1)%2==0){cout<<"Tie "<<endl;}
							else{ cout<<"Red "<<c2+c1<<endl;}
						}
						else cout<<"Red "<<c2+c1<<endl;
					}
				}
			}
		}else if(bh<=9){
			if(bx<rx1-1&&bx<rx2-1){
				int zh;
				if(mp[rx1-1][m]=='#'&&mp[rx2+1][m]=='#'&&mp[rx1+1][m]=='#'&&mp[rx2-1][m]=='#'){
					cout<<"Black "<<0<<endl;
				}else{
					int f=0;
					for(int i=1;i<=bx;i++){
						if(mp[i][m]=='#'){
							f=1;
							zh=i;
						}
					}
					if(f){
						rx=min(rx1,rx2);
						
						for(int i=bx;i<=rx1;i++){
							if(mp[i][m]=='#') f=2;
						}
						if(f==2) {
							cout<<"Tie "<<endl;
							continue;
						}
						if(zh==bx-1){
								if((rx-bx)%2==0){cout<<"Black "<<rx-bx<<endl;}
								else cout<<"Red "<<rx-bx<<endl;
								//cout<<rx<<" "<<bx<<endl;
						}
					}
					else cout<<"Black "<<2*bx-2<<endl;
				} 
			}else if(rx1-1==bx||rx1+1==bx||rx2-1==bx||rx2+1==bx){
				cout<<"Red "<<1<<endl;
			}else{
				int mm;
				if(rx1>rx2){mm=rx1,rx1=rx2,rx2=mm;}
				cout<<rx1<<" "<<rx2<<" "<<bx<<endl;
				dfs(1);
				cout<<"Red "<<ans<<endl;
				
			}
			

		}else if(bh<=13){
			cout<<"None"<<endl;
		}else{
			cout<<"None"<<endl;
		}
	}
}
