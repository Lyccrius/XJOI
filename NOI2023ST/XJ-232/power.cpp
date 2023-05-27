#include <bits/stdc++.h>
using namespace std;
int n,k,z=0;
int mi(int x,int y){;
	for(int i=1;;i++)
	{
		if(x%y==0)
		{x=x/y;
		z++;}
	    else{break;}
	}
	return z;
	
}
int main(){
int a=0,b;
 cin>>n>>k;
 
 for(int i=1;i<=n;i++)
{b=0;
 for(int j=1;j<=k;j++)
   {
	 if(b==0)
	 {
	  if(mi(i,j)>=k)
	   {  a=a+1;
		  b=1;
		  }
		  }
		  
		  
	  }
	  }

  cout<<a<<endl;


    return 0;
}
