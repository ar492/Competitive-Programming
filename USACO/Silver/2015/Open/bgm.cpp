#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
long long vals[256][7];

void setup()
{
    freopen("bgm.in", "r", stdin);
    freopen("bgm.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        char c;
        int u;
        cin >> c >> u;
        vals[(int)c][((int)(u+7e6))%7]++;
    }

}

int main()
{
    setup();
    // b e s i g o m
    for(int b=0; b<7; b++)
    for(int e=0; e<7; e++)
    for(int s=0; s<7; s++)
    for(int i=0; i<7; i++)
    for(int g=0; g<7; g++)
    for(int o=0; o<7; o++)
    for(int m=0; m<7; m++){
        if((b+e+s+s+i+e)*(g+o+e+s)*(m+o+o)%7==0){
           ans+=vals['B'][b]*vals['E'][e]*vals['S'][s]*vals['I'][i]*vals['G'][g]*vals['O'][o]*vals['M'][m];
        }

    }
    cout<<ans<<endl;
    return 0;
}
