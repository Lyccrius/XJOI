#include <iostream>
#include <cmath>
using namespace std;
struct tre{
	double x,y,num=0;
}a[1005];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,ma=-10000005,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].y>ma){
			ma=a[i].y;
			b=i;
		}
	}
	int mi=10000005,d,mi2[1005],j=1;
	a[b].num=1;
	mi2[0]=b;
	for(int w=0;w<n-1;w++){
		
		for(int i=0;i<n;i++){
			d=pow(a[b].x-a[i].x,2)+pow(a[b].y-a[i].y,2);
			if(mi>d&&a[i].num==0){
				mi=d;
				mi2[j]=i;
			}
		}
		a[mi2[j]].num=1;
		b=mi2[j];
		j++;
	}
	for(int i=0;i<n;i++){
		cout<<mi2[i]+1<<" ";
	}
	return 0;
}
