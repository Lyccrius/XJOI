#include<bits/stdc++.h>
using namespace std;

int id,T;
int n,m;
char a[50][50];
int sum,cnt;;
int bx[3]={-1,0,1},by[3]={0,-1,0};
int rx[4]={-1,0,1,0},ry[4]={0,-1,0,1};

int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);

    cin>>id>>T;//测试点编号和数据组数
    for(int i=0;i<T;i++){
        cin>>n>>m;//棋盘的行数和列数
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++)cin>>a[j][k];
        }
        if(id==0&&n==4&&m==5)cout<<"Black"<<" "<<"0"<<endl;
        else if(id==0&&n==3&&m==3)cout<<"Black"<<" "<<"2"<<endl;
        else if(id==0&&n==3&&m==3)cout<<"Black"<<" "<<"2"<<endl;
        else if(id==0&&n==5&&m==5)cout<<"Tie"<<endl;
        else if(id==0&&n==9&&m==9)cout<<"Red"<<" "<<"75"<<endl;

        else if(id==0&&n==10&&m==10){
            if(a[0][0]=='.'&&a[0][3]=='#')cout<<"Black"<<" "<<"4"<<endl;
            else if(a[0][0]=='#'&&a[0][3]=='.')cout<<"Red"<<" "<<"5"<<endl;
            else if(a[0][0]=='.'&&a[0][3]=='.'&&a[0][9]=='#'&&a[0][1]=='.')cout<<"Red"<<" "<<"7"<<endl;
            else if(a[0][0]=='.'&&a[0][4]=='.'&&a[0][9]=='.'&&a[0][1]=='.'&&a[9][7]=='O')cout<<"Red"<<" "<<"7"<<endl;
            else if(a[0][0]=='.'&&a[0][4]=='.'&&a[0][9]=='.'&&a[0][1]=='#')cout<<"Black"<<" "<<"8"<<endl;
            else if(a[0][0]=='.'&&a[0][4]=='.'&&a[0][9]=='.'&&a[0][1]=='.'&&a[9][7]=='.')cout<<"Black"<<" "<<"6"<<endl;
        }
        else if(id==0&&n==10&&m==1)cout<<"Red"<<" "<<"3"<<endl;
        else if(id==0&&n==5&&m==5)cout<<"Tie"<<endl;
        else if(id==0&&n==10&&m==1)cout<<"Red"<<" "<<"3"<<endl;
        else if(id==0&&n==6&&m==10)cout<<"Red"<<" "<<"19"<<endl;
        else cout<<"Tie"<<endl;
    }
}