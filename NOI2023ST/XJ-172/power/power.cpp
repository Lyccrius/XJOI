#include<cstdio>
#include<cmath>
#include<iostream>
// #include<map>
#include<set>
using namespace std;
int main(){
  freopen("power.in","r",stdin);
  freopen("power.out","w",stdout);
  long long n,k,ans=1;cin>>n>>k;
  if(k==1){
    cout<<n<<endl;
    return 0;
  }
  // map<long long,bool>mp;
  set<long long>st;
  for(long long i=k;i<=n;++i){
  // for(long long i=2;i<=n;++i){
    // if(mp[i])continue;
    // long long tmp=(long double)log(n)/(long double)log(i);
    // if(tmp<k)continue;
    // for(long long j=k;j<=tmp;++j)mp[pow((long double)i,(long double)j)]=1;
    // ans+=tmp-k+1;
    long long j=pow((long double)n,(long double)1./i);
    if(j==1&&!st.empty())break;
    while(j-->0)st.insert(pow(j+1,i));//,cout<<pow(j+1,i)<<' ';
    //cout<<endl;
    // cout<<(long long)(pow(n,1./i))<<' ',ans+=(long long)(pow(n,1./i)); 
  }
  // cout<<endl;
  // for(long long i=2;i<=n;++i){
  //   for(long long j=2;j<=i;++j){
  //     long long _j=j,cnt=1;
  //     while(_j<i)_j*=j,++cnt;
  //     if(cnt>=k&&_j==i){
  //       ++ans;
  //       break;
  //     }
  //   }
  // }
  cout<<st.size()<<endl;
  // cout<<ans<<endl;
}