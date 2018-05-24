#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

std::pair<int, int> findLinkToSever(int agentPos,
        const std::unordered_map<int, std::vector<int>>& graph,
        const std::unordered_set<int>& gatewaySet);
