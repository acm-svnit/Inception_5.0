#include<bits/stdc++.h>
using namespace std;
int main() {
    long long int n , i;
    cin >> n;
    string s;
    if(n == 2) {
    	cout << "A " << 1 << "\n";
	cout.flush();
	cin >> s;
	if(s == "Yes") return 0;
	cout << "A " << 1 << "\n";
	cout.flush();
	cin >> s;
	if(s == "Yes") return 0;    
    
    }
    for(i = 2 ; i <= n-1 ; i++) {
        cout << 'A' << " " << i << "\n";
        cout.flush();
        cin >> s;
        if(s == "Yes") return 0;
    }
    i = 1;
    if(n%2) i = 2;
    for(i = i ; i <= n ; i++) {
        cout << 'A' << " " << i << "\n";
        cout.flush();
        cin >> s;
        if(s == "Yes") return 0;
    }
}