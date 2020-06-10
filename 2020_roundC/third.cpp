#include <iostream>
#include <cmath>

using namespace std;

int t, n;
const int maxNm = 1e5;
int arr[maxNm];
int caseCounter = 1;

void doTask() {
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int gap = n-1;
	while (gap >= 0 ) {
		for (int i=0; i < n-gap; i++) {
			int sum = 0;
			for (int j=0; j <= gap; j++){
				sum += arr[j+i];
			}
			float root = sqrt(sum);
			int casted = (int)root;
			if ((casted*casted) == sum) {
				ans += 1;
			}
		}
		gap--;
	}
	cout << ans << "\n";
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	while (t != 0) {
		cout << "Case #" << caseCounter << ": ";
		doTask();
		caseCounter++;
		t--;
	}
	
	return 0;
}
