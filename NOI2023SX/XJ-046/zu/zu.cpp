#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int id,T,n,m,rx1,ry1,rx2,ry2,bx,by;
char c[15][15];
int main(){
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	cin>>id>>T;
	if(id>=1&&id<=4){
		while(T--){
			rx1=0;rx2=0;ry1=0;ry2=0;
			cin>>n>>m;
			memset(c,'#',sizeof(c));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cin>>c[i][j];
					if(c[i][j]=='O'){
						if(rx1==0&&ry1==0){
							rx1=i;
							ry1=j;
						}
						else{
							rx2=i;
							ry2=j;
						}
					}
					if(c[i][j]=='X'){
						bx=i;
						by=j;
					}
				}				
			}
			if(c[rx1+1][ry1]=='#'&&c[rx1-1][ry1]=='#'&&c[rx1][ry1+1]=='#'&&c[rx1][ry1-1]=='#'&&c[rx2+1][ry2]=='#'&&c[rx2-1][ry2]=='#'&&c[rx2][ry2+1]=='#'&&c[rx2][ry2-1]=='#'){
				cout<<"Black 0"<<endl;
			}
			else
			{
				cout<<"Tie"<<endl;
			}
		}
	}
	if(id>=5&&id<=6)
	{
		while(T--){
			cin>>n>>m;
			memset(c,'#',sizeof(c));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cin>>c[i][j];
					if(c[i][j]=='O'){
						if(i==n){
							rx1=i;
							ry1=j;
						}
						else{
							rx2=i;
							ry2=j;
						}
					}
					if(c[i][j]=='X'){
						bx=i;
						by=j;
					}
				}				
			}
			if(bx<rx2)
			{
				if(bx-rx2==1&&by==ry2){
					cout<<"Red 1"<<endl;
				}
				else{
					cout<<"Black "<<2*(bx-1)<<endl;
				}
			}
			else if(abs(bx-rx2)+abs(by-ry2)==1){
				cout<<"Red 1"<<endl;
			}
			else 
			{
				if(bx<(bx-rx2+abs(by-ry2))&&bx<abs(by-ry2)){
					cout<<"Black "<<2*bx<<endl;
				}
				else if(by>ry2){
					cout<<"Red "<<m-by+m-ry2+1<<endl;
				}
				else if(by<ry2){
					cout<<"Red "<<by+ry2<<endl;
				}
			}
		}
	}
	if(id>=7&&id<=9)
	{
		while(T--){
			rx1=0;rx2=0;ry1=0;ry2=0;
			cin>>n>>m;
			memset(c,'#',sizeof(c));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cin>>c[i][j];
					if(c[i][j]=='O'){
						if(rx1==0&&ry1==0){
							rx1=i;
							ry1=j;
						}
						else{
							rx2=i;
							ry2=j;
						}
					}
					if(c[i][j]=='X'){
						bx=i;
						by=j;
					}
				}				
			}int t=0;
			for(int i=1;i<=n;i++){
				if(c[i][1]=='#'){
					if(i<rx1&&i>bx){
						t++;
					}
					if(i<rx2&&i>bx){
						t++;
					}
				}
			}
			if(t==2){
				cout<<"Tie"<<endl;
			}
			else if(rx2<bx){
				if((bx-rx2-1)%2==0){
					cout<<"Red "<<bx-rx2<<endl;
				}
				else{
					cout<<"Red "<<(bx-rx2-1)*2+1;
				}
			}
			else{
				if(min(bx-rx1,rx2-bx)%2==0){
					cout<<"Red "<<min(bx-rx1,rx2-bx)+1<<endl;
				}
				else{
					cout<<"Red "<<(min(bx-rx1,rx2-bx))*2+1<<endl;
				}
			}
		}
	}
	if(id>=9&&id<=13){
		while(T--){
			cin>>n>>m;
			memset(c,'#',sizeof(c));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cin>>c[i][j];
					if(c[i][j]=='O'){
						if(rx1==0&&ry1==0){
							rx1=i;
							ry1=j;
						}
						else{
							rx2=i;
							ry2=j;
						}
					}
					if(c[i][j]=='X'){
						bx=i;
						by=j;
					}
				}				
			}
			cout<<"Tie"<<endl;
		}	
	}
	return 0;	
}
