#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(unordered_map<int, pair<bool,int>>& nodes,
                      unordered_map<int, set<int>>& group,
                      unordered_map<int, set<int>::iterator>& head,
                      vector<vector<int>>& queries) {
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto &q : queries) {
            int a = q[0];
            int b = q[1];

            if (a == 2) {
                auto &node = nodes[b];
                if (node.first) {
                    node.first = false;
                    int gno = node.second;

                    auto &s = group[gno];
                    auto &it = head[gno];
                    while (it != s.end() && nodes[*it].first == false) ++it;
                }
            } else if (a == 1) {
                if (nodes[b].first) {
                    ans.push_back(b);
                    continue;
                }

                int gno = nodes[b].second;
                auto &s = group[gno];
                auto &it = head[gno];

                while (it != s.end() && nodes[*it].first == false) ++it;

                if (it == s.end()) ans.push_back(-1);
                else ans.push_back(*it);
            }
        }
        return ans;
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mpp;
        mpp.reserve(connections.size() * 2 + 10);
        for (const auto &e : connections) {
            int u = e[0], v = e[1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        unordered_map<int, pair<bool,int>> nodes;
        unordered_map<int, set<int>> group;
        nodes.reserve(c + 5);
        group.reserve(c / 2 + 5);

        vector<int> vis(c + 1, false);
        int index = 1;

        for (int i = 1; i <= c; ++i) {
            if (vis[i]) continue;
            queue<int> pq;
            pq.push(i);
            vis[i] = true;
            while (!pq.empty()) {
                int a = pq.front(); pq.pop();
                nodes[a] = {true, index};
                group[index].insert(a);

                for (int nb : mpp[a]) {
                    if (!vis[nb]) {
                        vis[nb] = true;
                        pq.push(nb);
                    }
                }
            }
            ++index;
        }

        unordered_map<int, set<int>::iterator> head;
        head.reserve(group.size() * 2 + 5);
        for (auto &p : group) {
            head[p.first] = p.second.begin();
            auto &it = head[p.first];
            auto &s = p.second;
            while (it != s.end() && nodes[*it].first == false) ++it;
        }

        return solve(nodes, group, head, queries);
    }
};
