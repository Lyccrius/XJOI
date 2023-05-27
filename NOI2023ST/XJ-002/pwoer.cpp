# include <dits/stdc++.h>
using namespace std;
int main(){
	int a,b,sum;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		int c;
		for(int j=1;i<=a;j++){
			c=swap(j,b);
			if(a==c){
				sum++;
				break;
				}
			}
	}
	cout<<sum;
}
