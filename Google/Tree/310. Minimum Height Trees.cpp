class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        map<int,set<int>>graph;
        set<int> nodes;
        for(int i=0;i<n;i++)
            nodes.insert(i);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i].first].insert(edges[i].second);
            graph[edges[i].second].insert(edges[i].first);
            if(graph[edges[i].first].size()>1)
               nodes.erase(edges[i].first);
            if(graph[edges[i].second].size()>1)
                nodes.erase(edges[i].second);
        }
        while(n>2)
        {
            n = n-nodes.size();
            set<int> children;
            for(auto node:nodes)
                for(auto child:graph[node])
                {
                    graph[child].erase(node);
                    if(graph[child].size()==1)
                        children.insert(child);
                }
            nodes = children;
        }
        vector<int> result;
        for(auto node:nodes)
            result.push_back(node);
        return result;
    }

};
