#include <gtest/gtest.h>
#include "../skynet.h"

TEST(SkynetTests, SimpleDirectLinkToGateway) {
    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1}}, {1, {0, 2}}, {2, {1, 3}}, {3, {2, 4}}, {4, {3}}
    };
    std::unordered_set<int> gateways = {4};

    auto result = findLinkToSever(0, graph, gateways);
    // Expected path: 0 → 1 → 2 → 3 → 4, so first gateway link is (3, 4)
    EXPECT_EQ(result, std::make_pair(3, 4));
}

TEST(SkynetTests, StarTopology) {
    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1, 2, 3}}, {1, {0}}, {2, {0}}, {3, {0}}
    };
    std::unordered_set<int> gateways = {1, 2, 3};

    auto result = findLinkToSever(0, graph, gateways);
    // Any of 0-1, 0-2, 0-3 is valid
    EXPECT_TRUE((result == std::make_pair(0, 1) || result == std::make_pair(0, 2) || result == std::make_pair(0, 3)));
}

TEST(SkynetTests, NoGatewayReachable) {
    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1}}, {1, {0}}, {2, {3}}, {3, {2}}
    };
    std::unordered_set<int> gateways = {3};

    auto result = findLinkToSever(0, graph, gateways);
    EXPECT_EQ(result, std::make_pair(-1, -1));
}

TEST(SkynetTests, SeveralPathsToSingleGateway) {
    // Graph: multiple paths from agent (0) to gateway (5)
    // 0 - 1 - 2 - 3 - 4 - 5
    //  \                /
    //    ----- 6 -------
    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1, 6}}, {1, {0, 2}}, {2, {1, 3}}, {3, {2, 4}}, {4, {3, 5}},
        {5, {4, 6}}, {6, {0, 5}}
    };
    std::unordered_set<int> gateways = {5};

    auto result = findLinkToSever(0, graph, gateways);
    // Multiple shortest paths, but the first gateway edge reached is 4-5 or 6-5
    EXPECT_TRUE(result == std::make_pair(4, 5) || result == std::make_pair(6, 5));
}

TEST(SkynetTests, TripleStarLayout) {
    // Three hubs (0, 10, 20), each with three leaves, all connected to one gateway
    //  0 - 1     10 - 11     20 - 21
    //   \ 2       \ 12         \ 22
    //    \3        \13          \23
    //     \-------- G (node 99, gateway)

    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1, 2, 3}}, {1, {0}}, {2, {0}}, {3, {0, 99}},
        {10, {11, 12, 13}}, {11, {10}}, {12, {10}}, {13, {10, 99}},
        {20, {21, 22, 23}}, {21, {20}}, {22, {20}}, {23, {20, 99}},
        {99, {3, 13, 23}}  // gateway
    };
    std::unordered_set<int> gateways = {99};

    // Try from center of first star
    auto result = findLinkToSever(0, graph, gateways);
    EXPECT_EQ(result, std::make_pair(3, 99));

    // Try from center of second star
    result = findLinkToSever(10, graph, gateways);
    EXPECT_EQ(result, std::make_pair(13, 99));

    // Try from third
    result = findLinkToSever(20, graph, gateways);
    EXPECT_EQ(result, std::make_pair(23, 99));
}

TEST(SkynetTests, GatewayWithMultipleAgentRoutesButOneFastest) {
    // Agent is 0; two paths to gateway 5:
    // Fast path: 0-1-2-5
    // Slow path: 0-3-4-5

    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1, 3}}, {1, {0, 2}}, {2, {1, 5}},
        {3, {0, 4}}, {4, {3, 5}}, {5, {2, 4}}
    };
    std::unordered_set<int> gateways = {5};

    auto result = findLinkToSever(0, graph, gateways);
    // Should take the faster path and sever 2-5
    EXPECT_EQ(result, std::make_pair(2, 5));
}

TEST(SkynetTests, TwoGatewaysCloseTogether) {
    //        3
    //       / \ 
    // 0 - 1 - 2 - 4 - 5
    //        |     |
    //       G1    G2

    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1}}, {1, {0, 2}}, {2, {1, 3, 4}},
        {3, {2}}, {4, {2, 5}}, {5, {4}},
        {6, {2}}, {7, {5}}
    };
    std::unordered_set<int> gateways = {3, 5};

    auto result = findLinkToSever(0, graph, gateways);
    // Should return 2-3 since it's closer than 4-5
    EXPECT_EQ(result, std::make_pair(2, 3));
}
