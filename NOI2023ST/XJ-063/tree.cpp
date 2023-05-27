#include <bits/stdc++.h>
using namespace std;
int n,lm;
double x[1010],y[1010],len2,len=1000000000.0;
int m[1010];
double jf(double a,double b){
	return a-b;
}
double ln(double x1,double y1,double x2,double y2){
	return sqrt( jf(x1,x2)*jf(x1,x2) + jf(y1,y2)*jf(y1,y2) );
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&x[i],&y[i]);
	}
	int z=1;
	while(z<n){
		len2=0;
		lm=0;
		for(int i=0;i<n-1;i+=z){
			if(i>n){
				i%=n;
			}
			lm++;
			len2=len2+ln(x[i],y[i],x[i+1],y[i+1]);
			m[lm]=i;
		}
		if(len2<=len){
			len=len2;
		}else{
			for(int i=1;i<=lm;i++){
				m[i]=0;
			}
		}
		
	}
	for(int i=1;i<=lm;i++){
		printf("%d ",m[i]);
	}
	return 0;
}
