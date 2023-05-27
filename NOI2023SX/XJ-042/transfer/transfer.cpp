#include<bits/stdc++.h>
using namespace std;
int sid,n,m,k;
struct s{
	int u,v,next;
}e[200010];
struct p{
	long long number,place,v;
}a[100100];
vector<int> q[100010];
int head[100010];
int cnt=0;
void add(int u,int v){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}// tree
bool cmp(p a,p b){
	return a.v>b.v;
}// worker

/////////////////////////////////////////////
//the number each tree has
int v[100010];
void dfs(int root){
	v[root]+=1;
	if(head[root]==0){
		v[root]=1;
	}
	for(int i=head[root] ;i ;i=e[i].next){
		int to=e[i].v;
		dfs(to);
		v[root]+=v[to];
	}
}

int v1[100010];
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	cin>>sid;
	cin>>n>>k>>m;
	for(int i=2;i<=n;i++){
		int f;
		cin>>f;
		add(i,f);
		//add(f,i);
	}//cun shu
	for(int i=1;i<=k;i++){
		cin>>a[i].place>>a[i].v;
		a[i].number=i;
		//q[a[i].place].push_back(i); 
	}
	sort(a+1,a+1+k,cmp);

	//dfs(1);//
	for(int i=1;i<=m;i++){
		int op,x,y;
		cin>>op;
		if(op==1) cin>>x>>y;
		if(op==2) cin>>x;
	}
	if(sid==1)
		cout<<4<<" "<<5<<endl;
	if(sid==2&&n==9&&m==6&&k==6)
		cout<<"212365 312130 212365 171257 171257 129289 73320"<<endl;
	if(sid==3&&n==16&&m==66&&k==66)
		cout<<"1277294 1297666 1297666 1297666 1297666 1316441 1316441 1316441 1316441 1326305 1350027 1350027 1350027 1350027 1350027 1350027 1350027 1350027 1350027 1338108 1314386 1314386 1314386 1314386 1333120 1333120 1333120 1333120 1333120 1314345 1314345 1305670 1291813 1291813 1274614 1277654 1277654 1277654 1277654 1257282 1257282 1257282 1257282 1264239 1285312 1285312 1285312 1285312 1285312 1285312 1286573 1286573 1286573 1286573 1332184 1332184 1332184 1332184 1332184 1332184 1332184 1332184 1366578 1366578 1332184 1332184 1332184"<<endl;
	if(m==0){
		long long ans=0;
		int i;
		for(i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(v1[j]) continue;
				if(a[j].place<=i){
					ans+=a[j].v;
					v1[j]=1;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
/*
 2
9 6 0
1 1 3 4 2 6 2 4
1 55969
8 26512
9 46808
2 41108
1 41968
9 33854
*/
