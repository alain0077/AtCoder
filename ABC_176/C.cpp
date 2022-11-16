#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, sum = 0;
    cin >> n;
    vector<long long> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0) continue;

        if(a[i-1] > a[i]) {
            sum += a[i-1] - a[i];
            a[i] += a[i-1] - a[i];
        }
    }

    cout << sum << endl;
}