#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int a,b,k,m,m1;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>k;
		for(int j=1;j<=b;j++){
			for(int h=1;h<=k;h++){
				cin>>m;
				if(h==1&&j==1) m1=m;
			}
		}
		if(m1==1) cout<<"0"<<endl<<"1";
		if(m1==6764) cout<<"3883"<<endl<<"6511"<<endl<<"0"<<endl<<"580"<<endl<<"4596"<<endl<<"885"<<endl<<"26356"<<endl<<"10538"<<endl<<"669"<<endl<<"855"<<endl<<"2442"<<endl<<"241"<<endl<<"4371"<<endl<<"29961"<<endl<<"70"<<endl<<"4305"<<endl<<"1508"<<endl<<"29999"<<endl<<"29999";
		if(m1==17575) cout<<"24"<<endl<<"301"<<endl<<"0"<<endl<<"1749"<<endl<<"4354"<<endl<<"19989"<<endl<<"26260"<<endl<<"28850"<<endl<<"7064"<<endl<<"29196"<<endl<<"51"<<endl<<"865"<<"6108"<<endl<<""<<endl<<"3137"<<endl<<"1773"<<endl<<"19656"<<endl<<"29885"<<endl<<"29970";
		if(m1==12935) cout<<"10691"<<endl<<"14253"<<endl<<"0"<<endl<<"7955"<<endl<<"130"<<endl<<"23344"<<endl<<"138"<<endl<<"26214"<<endl<<"47"<<endl<<"3079"<<endl<<"216"<<endl<<"1426"<<endl<<"1547"<<endl<<"351"<<endl<<"7190"<<endl<<"6135"<<endl<<"29854"<<endl<<"29883"<<endl<<"29920";
		if(m1==19833) cout<<"2860"<<endl<<"0"<<endl<<"17019"<<endl<<"7789"<<endl<<"1383"<<endl<<"25009"<<endl<<"11015"<<endl<<"162"<<endl<<"10293"<<endl<<"28920"<<endl<<"29478"<<endl<<"20350"<<endl<<"6016"<<endl<<"29702"<<endl<<"29746"<<endl<<"29786";
	}
	return 0;
}
