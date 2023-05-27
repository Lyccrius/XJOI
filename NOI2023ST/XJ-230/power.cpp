#include<iostream>
using namespace std;
int k;
int find(int n){
	int arr=1;
	for(int i=2;i<n;i++){
		for(int j=k;j<n;j++){
			for(int y=0;y<j;y++){
				arr*=i;
			}
			if(arr==n){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int n,ans=0;
	cin>>n>>k;
	for(int x=1;x<=n;x++){
		if(find(x)==1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
