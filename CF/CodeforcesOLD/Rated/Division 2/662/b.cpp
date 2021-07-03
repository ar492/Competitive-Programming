#include<iostream>
#define endl "\n"
using namespace std;

int arr[100001];
int N,cnt4,cnt2,M;
char c; int a;

int main() {
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>a;
        arr[a]++;
        if (arr[a]%2==0) cnt2++;
        if (arr[a]==4) cnt4++;
    }
    cin>>M;
    while(M--) {
        cin>>c>>a;
        if (c == '+') {
            arr[a]++;
            if (arr[a]%2==0) cnt2++;
            if (arr[a] == 4) cnt4++;
        }
        else{
            arr[a]--;
            if (arr[a]%2) cnt2--;
            if (arr[a] == 3)cnt4--;
        }
        if (cnt4>0 && cnt2>3) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
