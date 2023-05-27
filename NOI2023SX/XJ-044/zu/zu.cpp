#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
char dt[50][50];
int id,t,n,m,l;
int mn(int aaa,int bbb){
    if(aaa<bbb)return aaa;
    else return bbb;
}
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    scanf("%d %d",&id,&t);
    for(int s=1;s<=t;s++){
        l=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n+1;i++){for(int j=0;j<=m+1;j++){dt[i][j]='1';}}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>dt[i][j];
            }
            getchar();
        }
      /*for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<dt[i][j];}cout<<endl;}*/
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(dt[i][j]=='O'&&dt[i+1][j]!='.'&&dt[i-1][j]!='.'
                    &&dt[i][j+1]!='.'&&dt[i][j-1]!='.'){
                    l++;
                }
            }
        }
        if(l==2)cout<<"Black 0"<<endl;
        else if(id<=4)cout<<"Tie"<<endl;
        if(id>4&&id<=6){
            int ll=0,ii=7,kk=0,i1,j1;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(dt[i][j]=='X'&&ll==0){
                        kk=1;ii=i;ll=2;
                    }
                    else if(dt[i][j]=='O'&&ll==0){
                        ll=1;i1=i;j1=j;
                    }
                    else if(dt[i][j]=='X'&&ll==1){
                        if((abs(i1-i)+1)<abs(j1-j)||((abs(i1-i)+1)==abs(j1-j)&&i1==1))kk=1,ii=i;
                        else {
                            kk=2;
                            if(i-i1==1){
                                if(j1-j==-1)ii=2*(m-j1)+1;
                                else if(j1-j==1)ii=2*(j1-1)+1;
                                else if(j1-j==-2)ii=2*(m-j1)-1;
                                else if(j1-j==2)ii=2*(j1-1)-1;
                            }
                            if(i-i1==2){
                                if(j1-j==-1)ii=2*(m-j1)+1;
                                else if(j1-j==1)ii=2*(j1-1)+1;
                                else if(j1-j==-2)ii=2*(m-j1)+3;
                                else if(j1-j==2)ii=2*(j1-1)+3;
                            }
                        }
                    }
                }
            }
            if(kk==1)cout<<"Black "<<(2*ii-2)<<endl;
            if(kk==2)cout<<"Red "<<ii<<endl;
        }
        if(id>=7&&id<=9){
            int ll=0,ii,kk=0,ill,i1=0,al=1;
            for(int i=1;i<=n;i++){
                if(dt[i][1]=='#'&&ll==0){
                    kk=2;ii=i;ll=1;i1=i;
                }
                if(dt[i][1]=='X'&&ll==0){
                    kk=1;ii=i;ll=2;
                }
                else if(dt[i][1]=='O'&&ll!=2){
                    kk=2;ii=i;ll=1;al=0;
                }
                else if(dt[i][1]=='X'&&ll==1){
                    if(l==0&&al==0&&abs(ii-i)%2==1){kk=2;ill=abs(ii-i);}
                    else if(l==0&&al==0&&abs(ii-i)%2==0){kk=2;ill=abs(ii-i)+2;}
                    else if(l==1&&al==1&&(ii-i)%2==0){kk=3;ill=(mn(ii,i1)-i-1)*2;}
                    else if(l==1&&al==0&&(i-ii)%2==0){kk=3;ill=(i-ii-1)*2;}
                }
            }
            cout<<s;
            if(kk==1&&l!=2)cout<<"Black "<<(2*ii-2)<<endl;
            if(kk==2&&l!=2)cout<<"Red "<<ill<<endl;
            if(kk==3&&l!=2)cout<<"Black "<<ill<<endl;
        }
        if(id>10){
            cout<<"Tie"<<endl;
        }
    }
    return 0;
}
