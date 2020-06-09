#include <iostream>

using namespace std;

int t,k,n;
const int maxNm = 2e5;
int arr[maxNm];
int caseCounter = 1;

void doTask() {
	cin >> n >> k;
	for (int i=0; i < n; i++) {
		cin >> arr[i];
	}
	int current = k;
	bool start = false;
	int ans = 0;
	for (int i=0; i < n; i++) {
		if (start && (current == 1)) {
			ans++;
			start = false;
			current = k;
		}
		if (arr[i] == current) {
			start = true;
			current--;
		} else {
			start = false;
			current = k;
		}
		if (arr[i] == k) {
			start = true;
			current = k - 1;
		}
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
