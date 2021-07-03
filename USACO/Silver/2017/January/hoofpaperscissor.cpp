#include <bits/stdc++.h>
using namespace std;

int p[(int)1e5];
int s[(int)1e5];
int n;
char a[(int)1e5];
int main() {
  ifstream cin("hps.in");
  ofstream cout("hps.out");
  cin>>n;
  for(int i=0; i<n; i++) cin>>a[i];
  p[0]=1;

  int pcnt=(a[0]=='P');
  int hcnt=(a[0]=='H');
  int scnt=(a[0]=='S');

  for(int i=1; i<n; i++){
    if(a[i]=='P') pcnt++;
    else if(a[i]=='S') scnt++;
    else hcnt++;
    p[i]=max({pcnt, hcnt, scnt});
  }
  s[n-1]=1;
  pcnt=(a[n-1]=='P');
  hcnt=(a[n-1]=='H');
  scnt=(a[n-1]=='S');

  for(int i=n-2; i>=0; i--){
    if(a[i]=='P') pcnt++;
    else if(a[i]=='S') scnt++;
    else hcnt++;
    s[i]=max({pcnt, hcnt, scnt});
  }

  int ans=0;
  for(int i=0; i<n-1; i++){
    ans=max(ans, p[i]+s[i+1]);
  }
  cout<<ans<<endl;
  return 0;
}
