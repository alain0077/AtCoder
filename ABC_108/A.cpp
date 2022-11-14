#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long s, p;

	cin >> s >> p;

	for (long long i = 1; i < s; i++) {
		
		if (i * (s - i) == p) {
			cout << "Yes" << endl;
			return 0;
		}
		else if (i * (s - i) > p) break;
	}

    cout << "No" << endl;
}