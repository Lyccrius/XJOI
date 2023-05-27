#include<iostream>
using namespace std;
int arr[100][100],C,c[100];
int main(){
	int T,k;
	cin>>T>>k;
	for(int u=0;u<T;u++){
		int n;
		cin>>n;
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				c[i]=max(arr[i][j],c[i])-min(arr[i][j]);
			}
		}
		for(int i=0;i<n;i++){
			C=max(c[i],C);
		}
		cout<<C;
	}
	return 0;
}
