#include<bits/stdc++.h>
using namespace std;
int n,m,x;
struct s{
    int l1,r1;
}a[2000010];
int v[2000100];
int v2[2000100];
bool cmp(s a,s b){
	if(a.l1==b.l1){
		return a.r1<b.r1;
	}
	return a.l1<b.l1;
}
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++)
        cin>>a[i].l1>>a[i].r1;
    int l,r;
    sort(a+1,a+1+m,cmp);
    if(x!=1){
	for(int i=1;i<=m;i++){
        if(a[i].l1<=x&&x<=a[i].r1){
            l=a[i].l1;
            r=a[i].r1;
            v2[i]=1;
            if(l<x)
                v[l]=1;
            if(r>x)
                v[r]=1;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        //if(v2[i]) continue;
        for(int j=1;j<=m;j++){
            //if(v2[j]) continue;
            if(l<=a[j].l1&&a[j].l1<=r&&a[j].r1>r){
				v[a[j].r1]=1;r=a[j].r1;v2[j]=1;
			}        
            else if(l<=a[j].r1&&a[j].r1<=r&&a[j].l1<l){
				v[a[j].l1]=1;l=a[j].l1;v2[j]=1;
			}  
            else if(l<a[j].l1&&a[j].r1<r){
                if(a[j].l1<x)
                    v[a[j].l1]=1;
                if(a[j].r1>x)
                    v[a[j].r1]=1;
                   v2[j]=1;
            }
            else if(a[j].l1<l&&a[j].r1>r){
                v[a[j].l1]=1;
                v[a[j].r1]=1;
                r=a[j].r1;
                l=a[j].l1;
                v2[j]=1;
            }
            //cout<<l<<" "<<r<<endl;
        }
        //cout<<l<<" "<<r<<endl;
    }		
	}

    if(x==1){
		l=1,r=a[1].r1;
		v[a[1].r1]=1;
		for(int i=2;i<=m;i++){
			if(l<=a[i].l1&&l<=a[i].r1&&a[i].r1>x){
				v[a[i].r1]=1;
				if(a[i].r1>r)
					r=a[i].r1;
			}
		}
	}
    for(int i=1;i<=n;i++)
        if(v[i])
            cout<<i<<" ";
    cout<<endl;
    return 0;
}
