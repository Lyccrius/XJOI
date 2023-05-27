#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int T,m,n,opt,q,x,c,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
	int ans1[100001][100001],ans2[100001][100001],ans3[100001][100001],ans4[100001][100001],ans5[100001][100001],ans6[100001][100001],ans7[100001][100001],ans8[100001][100001],ans9[100001][100001],ans10[100001][100001];
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>m>>n>>q;
		int a[100001][100001];
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
					a[j][k]=0;
			}
		}
		for(int j=0;j<q;j++){
			cin>>opt>>x>>c;//0 1 2;0 3 1;1 1 3;
			if(opt==0){
				for(int k=1;k<=n;k++){
					a[x][k]=c;
				}
			}
			if(opt==1){
				for(int k=1;k<=m;k++){
					a[k][x]=c;
				}
			}
		}
		if(i==1){
			m1=m,n1=n;
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n1;k++){
					ans1[j][k]=a[j][k];
				}
			}
		}
		if(i==2){
			m2=m,n2=n;
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					ans2[j][k]=a[j][k];
				}
			}
		}
		if(i==3){
			m3=m,n3=n;
			for(int j=1;j<=m3;j++){
				for(int k=1;k<=n3;k++){
					ans3[j][k]=a[j][k];
				}
			}
		}
		if(i==4){
			m4=m,n4=n;
			for(int j=1;j<=m4;j++){
				for(int k=1;k<=n4;k++){
					ans4[j][k]=a[j][k];
				}
			}
		}
		if(i==5){
			m5=m,n5=n;
			for(int j=1;j<=m5;j++){
				for(int k=1;k<=n5;k++){
					ans5[j][k]=a[j][k];
				}
			}
		}
		if(i==6){
			m6=m,n6=n;
			for(int j=1;j<=m6;j++){
				for(int k=1;k<=n6;k++){
					ans6[j][k]=a[j][k];
				}
			}
		}
		if(i==7){
			m7=m,n7=n;
			for(int j=1;j<=m7;j++){
				for(int k=1;k<=n7;k++){
					ans7[j][k]=a[j][k];
				}
			}
		}
		if(i==8){
			m8=m,n8=n;
			for(int j=1;j<=m8;j++){
				for(int k=1;k<=n8;k++){
					ans8[j][k]=a[j][k];
				}
			}
		}
		if(i==9){
			m9=m,n9=n;
			for(int j=1;j<=m9;j++){
				for(int k=1;k<=n9;k++){
					ans9[j][k]=a[j][k];
				}
			}
		}
		if(i==10){
			m10=m,n10=n;
			for(int j=1;j<=m10;j++){
				for(int k=1;k<=n10;k++){
					ans10[j][k]=a[j][k];
				}
			}
		}
	}
	if(T==1){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n1;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
		}
		if(T==2){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n1;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans2[j][k]<<' ';
				}
				cout<<endl;
			}
		}
		if(T==3){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans2[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m3;j++){
				for(int k=1;k<=n3;k++){
					cout<<ans3[j][k]<<' ';
				}
				cout<<endl;
			}
		}
		if(T==4){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans2[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m3;j++){
				for(int k=1;k<=n3;k++){
					cout<<ans3[j][k]<<' ';
				}
			}
			for(int j=1;j<=m4;j++){
				for(int k=1;k<=n4;k++){
					cout<<ans4[j][k]<<' ';
				}
				cout<<endl;
			}
		}
		if(T==5){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans2[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m3;j++){
				for(int k=1;k<=n3;k++){
					cout<<ans3[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m4;j++){
				for(int k=1;k<=n4;k++){
					cout<<ans4[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m5;j++){
				for(int k=1;k<=n5;k++){
					cout<<ans5[j][k]<<' ';
				}
				cout<<endl;
			}
		}
		if(T==6){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans2[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m3;j++){
				for(int k=1;k<=n3;k++){
					cout<<ans3[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m4;j++){
				for(int k=1;k<=n4;k++){
					cout<<ans4[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m5;j++){
				for(int k=1;k<=n5;k++){
					cout<<ans5[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m6;j++){
				for(int k=1;k<=n6;k++){
					cout<<ans6[j][k]<<' ';
				}
				cout<<endl;
			}
		}
		if(T==7){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans2[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m3;j++){
				for(int k=1;k<=n3;k++){
					cout<<ans3[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m4;j++){
				for(int k=1;k<=n4;k++){
					cout<<ans4[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m5;j++){
				for(int k=1;k<=n5;k++){
					cout<<ans5[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m6;j++){
				for(int k=1;k<=n6;k++){
					cout<<ans6[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m7;j++){
				for(int k=1;k<=n7;k++){
					cout<<ans7[j][k]<<' ';
				}
				cout<<endl;
			}
		}
		if(T==8){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans2[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m3;j++){
				for(int k=1;k<=n3;k++){
					cout<<ans3[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m4;j++){
				for(int k=1;k<=n4;k++){
					cout<<ans4[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m5;j++){
				for(int k=1;k<=n5;k++){
					cout<<ans5[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m6;j++){
				for(int k=1;k<=n6;k++){
					cout<<ans6[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m7;j++){
				for(int k=1;k<=n7;k++){
					cout<<ans7[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m8;j++){
				for(int k=1;k<=n8;k++){
					cout<<ans8[j][k]<<' ';
				}
				cout<<endl;
			}
		}
		if(T==9){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans2[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m3;j++){
				for(int k=1;k<=n3;k++){
					cout<<ans3[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m4;j++){
				for(int k=1;k<=n4;k++){
					cout<<ans4[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m5;j++){
				for(int k=1;k<=n5;k++){
					cout<<ans5[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m6;j++){
				for(int k=1;k<=n6;k++){
					cout<<ans6[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m7;j++){
				for(int k=1;k<=n7;k++){
					cout<<ans7[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m8;j++){
				for(int k=1;k<=n8;k++){
					cout<<ans8[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m9;j++){
				for(int k=1;k<=n9;k++){
					cout<<ans9[j][k]<<' ';
				}
				cout<<endl;
			}
		}
		if(T==10){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans1[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=n2;k++){
					cout<<ans2[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m3;j++){
				for(int k=1;k<=n3;k++){
					cout<<ans3[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m4;j++){
				for(int k=1;k<=n4;k++){
					cout<<ans4[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m5;j++){
				for(int k=1;k<=n5;k++){
					cout<<ans5[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m6;j++){
				for(int k=1;k<=n6;k++){
					cout<<ans6[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m7;j++){
				for(int k=1;k<=n7;k++){
					cout<<ans7[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m8;j++){
				for(int k=1;k<=n8;k++){
					cout<<ans8[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m9;j++){
				for(int k=1;k<=n9;k++){
					cout<<ans9[j][k]<<' ';
				}
				cout<<endl;
			}
			for(int j=1;j<=m10;j++){
				for(int k=1;k<=n10;k++){
					cout<<ans10[j][k]<<' ';
				}
				cout<<endl;
			}
		}
	return 0;
}
