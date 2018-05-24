#include "skynet.h"
#include <queue>

std::pair<int, int> findLinkToSever(
    int start,
    const std::unordered_map<int, std::vector<int>>& graph,
    const std::unordered_set<int>& gateways)
{
    std::unordered_set<int> visited;
    std::queue<int> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : graph.at(node))
        {
            if (visited.count(neighbor)) continue;
            if (gateways.count(neighbor)) return {node, neighbor};
            visited.insert(neighbor);
            q.push(neighbor);
        }
    }
    return {-1, -1};
}
