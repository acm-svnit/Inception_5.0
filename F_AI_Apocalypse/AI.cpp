#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define pb push_back
#define S second
#define F first

void query(int position) {
  cout << "A " << position << "\n";
  cout.flush();

  string response;
  cin >> response;
  // response is 1 we have found the AI 
  if(response == "Yes") {
    exit(0);
  }
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  
  // assuming that AI is in even position
  for(int i = 2; i <= n - 2; ++i) {
    query(i);
  }
  query(n - 1);
  // if query(n - 1) is not true then your assumption is wrong so at this time AI must be in any odd parity position
  
  for(int i = n - 1; i >= 2; --i)
    query(i);
  return 0;
}


