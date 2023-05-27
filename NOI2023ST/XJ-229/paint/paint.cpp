#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    int t=0;
    cin>>t;
    for(int k=1;k<=t;k++){
        int n=0,m=0,q=0;
        cin>>n>>m>>q;
        int a[1010][1010]={0,0};
        for(int i=0;i<q;i++){
            int op,x,c;
            cin>>op>>x>>c;
            if(op==1){
                for(int j=0;j<m;j++){
                    a[j][x-1]=c;
                }
            }
            else{
                for(int j=0;j<n;j++){
                    a[x-1][j]=c;
                }
            }
        }
        for(int u=0;u<n;u++){
            for(int e=0;e<m;e++){
                cout<<a[u][e]<<' ';
            }
            cout<<endl;
        }
    }
    fclose(stdin);
	fclose(stdout);
    return 0;
}
                }
            }
            else{
                for(int j=0;j<n;j++){
                    a[x-1][j]=c;
                }
            }
        }
        for(int u=0;u<n;u++){
            for(int e=0;e<m;e++){
                cout<<a[u][e]<<' ';
            }
            cout<<endl;
        }
    }
    fclose(stdin);
	fclose(stdout);
    return 0;
}
        }
        for(int u=0;u<n;u++){
            for(int e=0;e<m;e++){
                cout<<a[u][e]<<' ';
            }
            cout<<endl;
        }
    }
    fclose(stdin);
	fclose(stdout);
    return 0;
}
