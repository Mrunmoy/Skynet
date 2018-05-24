#include "skynet.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, e;
    cin >> n >> l >> e; cin.ignore();

    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < l; i++)
    {
        int n1, n2;
        cin >> n1 >> n2; cin.ignore();
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    unordered_set<int> gatewaySet;
    for (int i = 0; i < e; i++)
    {
        int ei;
        cin >> ei; cin.ignore();
        gatewaySet.insert(ei);
    }

    while (true)
    {
        int si;
        cin >> si; cin.ignore();
        auto [c1, c2] = findLinkToSever(si, graph, gatewaySet);
        cout << c1 << " " << c2 << endl;

        auto& v1 = graph[c1];
        v1.erase(remove(v1.begin(), v1.end(), c2), v1.end());
        auto& v2 = graph[c2];
        v2.erase(remove(v2.begin(), v2.end(), c1), v2.end());
    }
}
