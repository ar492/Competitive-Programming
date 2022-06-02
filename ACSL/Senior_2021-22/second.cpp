#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'fibCypher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. CHARACTER option
 *  2. INTEGER num1
 *  3. INTEGER num2
 *  4. CHARACTER key
 *  5. STRING msg
 */

#define int long long
void encode(int num1, int num2, char key, string msg){
	
}

void decode(int num1, int num2, char key, string msg){

}

string fibCypher(char option, int num1, int num2, char key, string msg, const int mod=26, string ans=""){
	vector<int> f{ {num1 % mod, num2 % mod} };
	
	for (int i = 2; i < 201; i++){
		f.push_back((f[i - 1] + f[i - 2]) % mod);
	}
	for (int i = 1; i < (int)f.size(); i+=2){
		f[i] = -f[i];
	}

	if (option == 'E'){
		for (int i = 0; i < (int)msg.length(); i++){
			if (i) ans += " ";
			int ascii = (int)msg[i];
			int k = (int)key + f[i];
			if (k < 'a') k += 26;
			if (k > 'z') k -= 26;
			ans += to_string((k * 3 + ascii));
		}
	}
	else{
		
	}

	/*
	if (option == 'E'){
		encode(num1, num2, key, msg);
	}
	else decode(num1, num2, key, msg);*/
	return ans;
}

signed main(){

	cout << fibCypher('E', 3, 7, 'h', "ACSL Sr-5 c2");
	

}