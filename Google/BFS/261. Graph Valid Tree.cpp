class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        map<int,set<int>>graph;
        set<int> vertex;
        for(int i=0;i<n;i++)
            vertex.insert(i);
        for(int i=0;i<edges.size();i++)
        {
            if(graph.find(edges[i].first)!=graph.end())
                graph[edges[i].first].insert(edges[i].second);
            else
            {
                set<int>s;
                s.insert(edges[i].second);
                graph[edges[i].first]= s;
            }
            if(graph.find(edges[i].second)!=graph.end())
                graph[edges[i].second].insert(edges[i].first);
            else
            {
                set<int>s;
                s.insert(edges[i].first);
                graph[edges[i].second]= s;
            }
        }
        set<int>visited;
        int root = *vertex.begin();
        queue<int>q;
        q.push(root);
        while(!q.empty())
        {
            int f = q.front();
            if(visited.find(f)!=visited.end())
                return false;
            q.pop();
            vertex.erase(f);
            visited.insert(f);
            for(auto child:graph[f])
            {
                q.push(child);
                graph[f].erase(child);
                graph[child].erase(f);
            }
        }
        if(vertex.empty())
            return true;
        return false;
    }
};
