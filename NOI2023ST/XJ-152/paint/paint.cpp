#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int SIZE=100005;
struct rec{
	int id,w;
};
rec vx[SIZE],vy[SIZE];
int T;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vx,0,sizeof(vx));
		memset(vy,0,sizeof(vy));
		int q;
		int n,m;
		cin>>n>>m>>q;
		for(int i=1;i<=q;i++){
			int otp,x,c;
			cin>>otp>>x>>c;
			if(otp==1)vx[x].id=i,vx[x].w=c;
			if(otp==0)vy[x].id=i,vy[x].w=c;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vx[j].id>vy[i].id)cout<<vx[j].w<<" ";
				else if(vx[j].id<vy[i].id)cout<<vy[i].w<<" ";
				else if(vx[j].id==vy[i].id&&vx[j].id==0)cout<<"0"<<" ";
			}
			cout<<endl;
		}
	}
}
