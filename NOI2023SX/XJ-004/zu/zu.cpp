#include<iostream>
#include<queue>
using namespace std;
int id,T;
int n,m;
char s[15][15];
int rx[2],ry[2],bx,by,cnt;
int redx,redy;
queue<int>q1;
queue<int>q2;
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    if(id<=4&&id>=1){
        while(T--){
            cin>>n>>m;
            cnt=0;
            rx[0]=0,rx[1]=0,ry[0]=0,ry[1]=0;
            bx=by=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++){
                    cin>>s[i][j];
                    if(s[i][j]=='O'){
                        rx[cnt]=i,ry[cnt++]=j;
                        //cout<<i<<" "<<j<<endl;
                    }
                    if(s[i][j]=='X'){
                        bx=i,by=j;
                    }
                }
            //cout<<cnt<<endl;
            //cout<<rx[0]<<" "<<ry[0]<<" "<<rx[1]<<" "<<ry[1]<<bx<<" "<<by<<" "<<endl;
            if((s[rx[0]+1][ry[0]]=='#'||rx[0]+1>n||s[rx[0]+1][ry[0]]=='O')&&(s[rx[0]-1][ry[0]]=='#'||rx[0]-1<1||s[rx[0]-1][ry[0]]=='O')&&(s[rx[0]][ry[0]+1]=='#'||ry[0]+1>m||s[rx[0]][ry[0]+1]=='O')&&(s[rx[0]][ry[0]-1]=='#'||ry[0]-1<1||s[rx[0]][ry[0]-1]=='O')&&(s[rx[1]-1][ry[1]]=='#'||rx[1]-1<1||s[rx[1]-1][ry[1]]=='O')&&(s[rx[1]+1][ry[1]]=='#'||rx[1]+1>n||s[rx[1]+1][ry[1]]=='O')&&(s[rx[1]][ry[1]+1]=='#'||ry[1]+1>m||s[rx[1]][ry[1]+1]=='O')&&(s[rx[1]][ry[1]-1]=='#'||ry[1]-1<1||s[rx[1]][ry[1]-1]=='O'))
                cout<<"Black 0"<<endl;
            else{
                cout<<"Tie"<<endl;
            }
        }
    }
    else if(id==5||id==6){
		while(T--){
			rx[0]=0,rx[1]=0,ry[0]=0,ry[1]=0;
            bx=by=0;
            redx=redy=0;
            cin>>n>>m;
            cnt=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++){
                    cin>>s[i][j];
                    if(s[i][j]=='O'){
                        rx[cnt]=i,ry[cnt++]=j;
                        if(i!=n)redx=i,redy=j;
                    }
                    if(s[i][j]=='X'){
                        bx=i,by=j;
                    }
                }
            /*cout<<rx[0]<<" "<<ry[0]<<" "<<rx[1]<<" "<<ry[1]<<bx<<" "<<by<<" "<<endl;
            cout<<redx<<" "<<redy<<" "<<bx<<" "<<by<<" "<<endl;*/
            if(s[bx-1][by]=='O'||s[bx][by-1]=='O'||s[bx][by+1]=='O')cout<<"Red 1"<<endl;
            else if(bx<=redx)cout<<"Black "<<(bx-1)*2<<endl;
            else if(abs(bx-redx)<abs(redy-by))cout<<"Black "<<(bx-1)*2<<endl;
            else if(redy-by==0&&abs(bx-redx)%2==1)cout<<"Red "<<bx-redx<<endl;
            else if(redy-by==0&&abs(bx-redx)%2==0)cout<<"Black "<<(bx-2)*2<<endl;
            /*else if(abs(abs(bx-redx)-abs(redy-by))%2==0)cout<<"Black "<<(bx-1)*2<<endl;*/
            else cout<<"Tie"<<endl;
		}
	}
	else if(id>=7&&id<=9){
		while(T--){
            cin>>n>>m;
            char ss[15];
            int rx1,rx2,bx;
            for(int i=1;i<=n;i++){
				cin>>ss[i];
				if(ss[i]=='O'&&rx1==0)rx1=i;
				else if(ss[i]=='O')rx2=i;
				if(ss[i]=='X')bx=i;
			}
			bool flag=false;
			if((ss[rx1+1]=='#'||rx1+1>n)&&(ss[rx2+1]=='#'||rx2+1>n)&&(ss[rx1-1]=='#'||rx1-1<1)&&(ss[rx2-1]=='#'||rx2-1<1))cout<<"Black 0"<<endl;
			for(int i=bx-1;i>=1;i--){
				if(ss[i]=='#'&&flag==false){flag=true;cout<<"Red "<<(bx-i)*2-1<<endl;break;}
				if((ss[i]=='O'||ss[i]=='#')&&flag==true){
					cout<<"Black "<<(bx-i-2)*2<<endl;
					break;
				}
				if(ss[i]=='O'&&bx-i%2==1){
					cout<<"Red "<<bx-i<<endl;
					flag=true;
				}
				if(ss[i]=='O'&&bx-i%2==0)flag=true;
			}
			if(flag==false)cout<<"Black "<<(bx-1)*2<<endl;
		}
	}
}
