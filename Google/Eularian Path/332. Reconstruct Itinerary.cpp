class Solution {
public:
    void DFS(map<string, multiset<string>>& graph, vector<string>& result, string airport)
    {
        while(graph[airport].size()>0)
        {
            string next_airport = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            DFS(graph, result, next_airport);
        }
        result.push_back(airport);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, multiset<string>>graph;
        for(int i=0;i<tickets.size();i++)
            graph[tickets[i].first].insert(tickets[i].second);
        vector<string> result;
        DFS(graph,result,"JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};
