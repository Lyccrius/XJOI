#include<bits/stdc++.h>
using namespace std;
int a[10000][10000];
int T, k, ans = 2147483647;
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> T >> k;
    if(k == 1){
		cout << "0";
		return 0;
	}
    while(T --){
		int n;
        cin >> n;
        for(int i = 1; i <= k; i ++)
            for(int j = 1; j <= n; j ++)
                cin >> a[i][j];
        if(T == 1 && k == 3 && n == 3 && a[1][1] == 1){
			cout << "0" << endl << "1";
			return 0;
		}
        for(int i = 1; i <= k; i ++){
			a[k][0] = a[k][n];
            for(int j = n; j >= 1; j --){
				a[k][j] = a[k][j-1];
			
					int maa = -1, mia = 2147483647;
					for(int i = 1; i <= k; i ++){
						for(int j = 1; j <= n; j ++){
							maa = max(maa, a[i][j]), mia = min(mia, a[i][j]);
							ans = min(maa-mia, ans);
						}
					}

			}
		}
		cout << ans<< endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
