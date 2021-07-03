
#include<bits/stdc++.h>
using namespace std;

int n, cows[100], reach[100], to[100];

// reach[i] is how many cows pass the ball to cow i
// to[i] is where does cow i pass the ball

int main(){
	ifstream cin("hoofball.in"); ofstream cout("hoofball.out");
	cin >> n;
	for (int i = 0; i < n; i++) cin >> cows[i];
	if (n <= 2){
		cout << 1 << endl;
		return 0;
	}
	sort(cows, cows + n); // O(nlogn) 
	reach[1]++; reach[n - 2]++;
	to[0] = 1; to[n - 1] = n - 2;
	for (int i = 1; i < n-1; i++){
		if (cows[i] - cows[i - 1] <= cows[i + 1] - cows[i]){
			reach[i - 1]++;
			to[i] = i - 1;
		}
		else{
			reach[i + 1]++;
			to[i] = i + 1;
		}
	}
	int num_islands = 0;
	if (reach[0] == 1 && reach[1] == 1 && to[2]!=1) num_islands++;
	if (reach[n - 1] == 1 && reach[n - 2] == 1 && to[n - 3] != n - 2) num_islands++;
	
	for (int i = 2; i < n - 3; i++){
		if (reach[i] == 1 && reach[i + 1] == 1 && to[i + 2] != i + 1 && to[i - 1] != i){
			num_islands++;
		}
	}
	cout << count(reach, reach + n, 0) + num_islands << endl;
}
