#include <iostream>
#include <fstream>
using namespace std;

int n;
int wine[10005];
int memo[10005][3];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> wine[i];
		memo[i][0] = max(max(memo[i-1][0], memo[i-1][1]), memo[i-1][2]);
		memo[i][1] = memo[i-1][0]+wine[i];
		memo[i][2] = memo[i-1][1]+wine[i];
	}
	
	cout << max(max(memo[n][0], memo[n][1]), memo[n][2]);
}