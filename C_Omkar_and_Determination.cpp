#include <bits/stdc++.h>
using namespace std;
int n,l,k,f[505][505],d[505],a[505];
int main(){
	cin>>n>>l>>k;
	for(int i=1;i<=n;i++)cin>>d[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(f,0x3f,sizeof(f));
	d[++n]=l;f[1][0]=0;
	int ans=1e9;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=k;j++){
			for(int p=1;p<i;p++)if(i-p-1<=j)f[i][j]=min(f[i][j],f[p][j-(i-p-1)]+a[p]*(d[i]-d[p]));
			if(i==n)ans=min(ans,f[i][j]);
		}cout<<ans;
        
}