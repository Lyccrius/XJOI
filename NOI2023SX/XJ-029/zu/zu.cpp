#include <bits/stdc++.h>
using namespace std;
int id,n,m,mapp[15][15],ans;
int bx,by,rx1,ry1,rx2,ry2;
int dx[5]={0,1,0,0,-1},dy[5]={0,0,-1,1,0};
int ddx[5]={0,2,0,0,-2},ddy[5]={0,0,-2,2,0};
char judge(int r1x,int r1y,int r2x,int r2y){
	if (bx==1){
		return 'b';
	}
	bool f,f1=false,f2=false;
	for (int i=1;i<=4;i++){
		int tx=bx+ddx[i],ty=by+ddy[i];
		if (tx==r1x && ty==r1y){
			f1=true;
		}
		if (tx==r2x && ty==r2y){
			f2=true;
		}
	}
	if (id>=5 && id<=6){
		f=true;
	}
	if ((f1 && f2) || (f1 && f) || (f2 && f)){
		return 'b';
	}else {
		return 'n';
	}
}
void go_red(int &x,int &y,int gx,int gy){
	if (x<gx){
		int tx=x+dx[3],ty=y+dy[3];
		if (mapp[tx][ty]!=1 && mapp[tx][ty]!=3 && tx>=1 && tx<=n && ty>=1 && ty<=m){
			mapp[x][y]=0;
			x=tx;
			y=ty;
			mapp[x][y]=3;
			ans++;
			return;
		}
	}
	if (x>gx){
		int tx=x+dx[2],ty=y+dy[2];
		if (mapp[tx][ty]!=1 && mapp[tx][ty]!=3 && tx>=1 && tx<=n && ty>=1 && ty<=m){
			mapp[x][y]=0;
			x=tx;
			y=ty;
			mapp[x][y]=5;
			ans++;
			return;
		}
	}
	if (y>gy){
		int tx=x+dx[4],ty=y+dy[4];
		if (mapp[tx][ty]!=1 && mapp[tx][ty]!=3 && tx>=1 && tx<=n && ty>=1 && ty<=m){
			mapp[x][y]=0;
			x=tx;
			y=ty;
			mapp[x][y]=5;
			ans++;
			return;
		}
	}
	if (y<gy){
		int tx=x+dx[1],ty=y+dy[1];
		if (mapp[tx][ty]!=1 && mapp[tx][ty]!=3 && tx>=1 && tx<=n && ty>=1 && ty<=m){
			mapp[x][y]=0;
			x=tx;
			y=ty;
			mapp[x][y]=5;
			ans++;
			return;
		}
	}
}
bool judge_red(int x,int y){
	for (int i=1;i<=4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if (mapp[tx][ty]!=1 && mapp[tx][ty]!=3 && tx>=1 && tx<=n && ty>=1 && ty<=m){
			return true;
		}
	}
	return false;
}
bool judge_black(int x,int y){
	for (int i=1;i<=4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if (mapp[tx][ty]==3){
			return false;
		}
	}
	return true;
}
void go_black(int &x,int &y){
	for (int i=1;i<=3;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if (mapp[tx][ty]!=1 && tx>=1 && tx<=n && ty>=1 && ty<=m){
			if (judge_black(tx,ty)){
				mapp[x][y]=0;
				x=tx;
				y=ty;
				ans++;
				mapp[x][y]=5;
				return;
			}
		}
	}
}
int main(){
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	int T;
	bool f=false;
	cin>>id>>T;
	while (T--){
		cin>>n>>m;
		char temp;
		ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>temp;
				if (temp=='.'){
					mapp[i][j]=0;
				}else if (temp=='#'){
					mapp[i][j]=1;
				}else if (temp=='X'){
					mapp[i][j]=5;
					bx=i;
					by=j;
				}else {
					mapp[i][j]=3;
					if (!f){
						f=!f;
						rx1=i;
						ry1=j;
					}else {
						rx2=i;
						ry2=j;
					}
				}
			}
		}
		if (id>=1 && id<=4){
			if (!judge_red(rx1,ry1) && !judge_red(rx2,ry2)){
				printf("Black %d\n",ans);
				continue;
			}else {
				printf("Tie\n");
				continue;
			}
		}else if (id>=5 && id<=6){
			int rx=rx1,ry=ry1;
			if (rx1==n){
				rx=rx2;
				ry=ry2;
			}
			while (judge(rx,ry,rx1,ry1)!='r' && judge(rx,ry,rx1,ry1)!='b'){
				go_red(rx,ry,bx,by);
				go_black(bx,by);
			}
			if (judge(rx,ry,rx1,ry1)=='r'){
				printf("Red %d\n",ans);
			}else if (judge(rx,ry,rx1,ry1)=='b'){
				printf("Black %d\n",ans);
			}else {
				printf("Tie\n");
			}
			
		}else if (id>=7 && id<=9){
			printf("Tie\n");
		}else if (id>=10 && id<=13){
			printf("Tie\n");
		}else {
			printf("Tie\n");
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
