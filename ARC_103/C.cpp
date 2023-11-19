#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> om;
    map<int, int> em;
    
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a; 
        if(i&1) em[a]++;
        else om[a]++;
    }

    set<pair<int, int>> os;
    set<pair<int, int>> es;

    os.insert({0, 0});
    es.insert({0, 0});

    for(auto p : om)
    {
        os.insert({p.second, p.first});
    }

    for(auto p : em)
    {
        es.insert({p.second, p.first});
    }

    auto it = os.rbegin();
    int o1 = (it++)->second;
    int o2 = (it)->second;

    it = es.rbegin();
    int e1 = (it++)->second;
    int e2 = (it)->second;

    int cnt;
    if(e1 != o1) cnt = em[e1] + om[o1];
    else if(em[e2] > om[o2]) cnt = em[e2] + om[o1];
    else cnt = em[e1] + om[o2];

    cout << n - cnt << endl;
}