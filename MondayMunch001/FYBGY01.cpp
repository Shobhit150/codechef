class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;
        if(rank[pu] < rank[pv]) swap(pu, pv);

        parent[pv] = pu;
        rank[pu] += rank[pv];
    }
};
class Solution {
public:
    int maxStonesRemoved(vector<vector<int>>& stones) {
        // write your code here 

        int n = stones.size();
        DSU dsu(200000);

        unordered_set<int> nodes;

        for(auto &stone: stones) {
            int r = stone[0];
            int c = stone[1] + 10000;
            dsu.unionSet(r,c);
            nodes.insert(r);
            nodes.insert(c);
        }
        int component = 0;
        for(auto &node: nodes) {
            if(dsu.find(node) == node) {
                component++;
            }
        }
        return n-component;
        
    }
};
