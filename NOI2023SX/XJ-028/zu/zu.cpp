#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[15];
int check=0,place=0,place1=0,place2=0,place1y=0,place2y=0,xx=0,xy=0;
int move(int y1,int x1,int y2,int x2){
	a[x2][y2]='#';
	bool checkx;
	if(y1==0&&y1==m-1){
		if(a[x1-1][y1]=='#'&&a[x1+1][y1]=='#')checkx=true;
		else checkx=false;
	}
	else if(y1==0){
		if(a[x1-1][y1]=='#'&&a[x1+1][y1]=='#'&&a[x1][y1+1]=='#')checkx=true;
		else checkx=false;
	}
	else if(y1==m-1){
		if(a[x1-1][y1]=='#'&&a[x1+1][y1]=='#'&&a[x1][y1-1]=='#')checkx=true;
		else checkx=false;
	}
	else{
		if(a[x1-1][y1]=='#'&&a[x1+1][y1]=='#'&&a[x1][y1-1]=='#'&&a[x1][y1+1]=='#')checkx=true;
		else checkx=false;
	}
	a[x2][y2]='O';
	return checkx;
}
int main(){
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	int lie,T;
	a[0]="############";
	cin>>lie>>T;
	for(int jjjj=1;jjjj<=T;jjjj++){    
		cin>>n>>m;
		a[n+1]="###########";
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(lie>6&&lie<10){                               //pian fen 7~9(15tik)
			int check=0,place=0,place1=0,place2=0;
			for(int i=n;i>=1;i--){
				if(a[i]=="X")place=i;
				if(a[i]=="#"&&place!=0)check=-1;
				if(a[i]=="O"&&place1==0)place1=i;
				else if(a[i]=="O")place2=i;
			}
			if(check==-1){
				cout<<"tie"<<endl;
				continue;
			}	
			
			int x=min(abs(place-place1),abs(place-place2));
			if(place<place1&&place<place2){
				cout<<"Black "<<(place-1)*2<<endl;
				continue;
			}
			if(x%2==1)cout<<"Red "<<x<<endl;
			else {
				if(move(0,place1,0,place2))cout<<"Black "<<x*2<<endl;
				else cout<<"Red "<<x<<endl;
			}
		}
		else if(lie>0&&lie<5){                                //pian fen 1~4(20tik)            
			check=0,place=0,place1=-1,place2=0,place1y=0,place2y=0;
			for(int i=n;i>=1;i--){
				for(int j=0;j<m;j++){
				if(a[i][j]=='X')place=i;
				if(a[i][j]=='O'&&place1==-1)place1y=i,place1=j;
				else if(a[i][j]=='O')place2y=i,place2=j;
			}}
			if(move(place1,place1y,place2,place2y)){
				if(move(place2,place2y,place1,place1y))cout<<"Black 0"<<endl;
			}
			else cout<<"tie"<<endl;
		}
		else if(lie>4&&lie<7){                                //pian fen 5,6(10tik)
			check=0,place=0,place1=-1,place2=0,place1y=0,place2y=0,xx=0,xy=0;
			for(int i=n;i>=1;i--){
				for(int j=0;j<m;j++){
				if(a[i][j]=='X')xy=i,xx=j;
				if(a[i][j]=='O'&&place1==-1) place1y=i,place1=j;
				else if(a[i][j]=='O')place2y=i,place2=j;
			}}
			int shit=abs(place2y-xy)-1+abs(place2-xx)-1;
			if(xx>place2)shit+=n-xx;
			else shit+=xx;
			if(abs(place2-xx)>xy-place2y)cout<<"Black "<<(xy-1)*2;
			else cout<<"Red "<<(shit*2+3)<<endl;
		}
		else{
			cout<<"tie"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
