#include <bits/stdc++.h>
using namespace std;
int sid,n,k,m,p[100005],kfp[100005];
struct node{
	int ygjz[105];
	int ygbh[105];
	int ygs=0;
}bm[100005];
struct node1{
	int bm,bh;
}yg[100005];
void doit(){
	long long ans=0;
	memset(kfp,0,sizeof(kfp));
	for(int i=n;i>=1;i--){
		kfp[i]++;
		int asdf=kfp[i];
		for(int j=1;j<=asdf;j++){
			if(bm[i].ygjz[j]==0) break;
			kfp[i]--;
			ans+=bm[i].ygjz[j];
		}
		kfp[p[i]]+=kfp[i];
	}
	cout<<ans<<" ";
	return ;
}
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
    cin>>sid>>n>>k>>m;
    for(int i=2;i<=n;i++){
	    cin>>p[i];
	}
	for(int i=1;i<=k;i++){
		cin>>yg[i].bm;
		bm[yg[i].bm].ygs++;
		int srs;
		cin>>srs;
		int fz1;
		for(fz1=1;fz1<=bm[yg[i].bm].ygs;fz1++){
			if(srs>bm[yg[i].bm].ygjz[fz1]) break;
		}
		for(int j=bm[yg[i].bm].ygs;j>=fz1;j--){
			bm[yg[i].bm].ygjz[j+1]=bm[yg[i].bm].ygjz[j];
			bm[yg[i].bm].ygbh[j+1]=bm[yg[i].bm].ygbh[j];
		}
		bm[yg[i].bm].ygjz[fz1]=srs;
		bm[yg[i].bm].ygbh[fz1]=i;
	}
	/*for(int i=1;i<=n;i++){
		cout<<"bm"<<i<<":"<<endl;
		for(int j=1;j<=bm[i].ygs;j++){
			cout<<"ygbh:"<<bm[i].ygbh[j]<<"  ygjz:"<<bm[i].ygjz[j]<<endl;
		}
	}*/
	doit();
	while(m--){
		int id;
		cin>>id;
		if(id==1){
			k++;
			int i=k;
			cin>>yg[i].bm;
			bm[yg[i].bm].ygs++;
			int srs;
			cin>>srs;
			int fz1;
			for(fz1=1;fz1<=bm[yg[i].bm].ygs;fz1++){
				if(srs>bm[yg[i].bm].ygjz[fz1]) break;
			}
			for(int j=bm[yg[i].bm].ygs;j>=fz1;j--){
				bm[yg[i].bm].ygjz[j+1]=bm[yg[i].bm].ygjz[j];
				bm[yg[i].bm].ygbh[j+1]=bm[yg[i].bm].ygbh[j];
			}
			bm[yg[i].bm].ygjz[fz1]=srs;
			bm[yg[i].bm].ygbh[fz1]=i;
		}else if(id==2){
			int ygh,ygwz;
			cin>>ygh;
			int bmh=yg[ygh].bm;
			for(ygwz=1;bm[bmh].ygbh[ygwz]!=ygh;ygwz++){ }
			bm[bmh].ygs--;
			bm[bmh].ygjz[ygwz]=0;
			for(int j=ygwz;j<=bm[bmh].ygs;j++){
				bm[bmh].ygjz[j]=bm[bmh].ygjz[j+1];
				bm[bmh].ygbh[j]=bm[bmh].ygbh[j+1];
			}
		}
		doit();
	}
	fclose(stdin);
	fclose(stdout);
    return 0;	
}
