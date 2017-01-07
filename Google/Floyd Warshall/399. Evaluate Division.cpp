class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string,map<string,double>>graph;
        for(int i=0;i<equations.size();i++)
        {
            graph[equations[i].first][equations[i].first]=1;
            graph[equations[i].second][equations[i].second]=1;
            graph[equations[i].first][equations[i].second]=values[i];
            graph[equations[i].second][equations[i].first]=1/values[i];
        }
        for(auto i:graph)
            for(auto j:graph[i.first])
               for(auto k:graph[i.first])
               {
                   graph[j.first][k.first] = graph[j.first][i.first]*graph[i.first][k.first];
                   graph[k.first][j.first] = graph[k.first][i.first]*graph[i.first][j.first];
               }
        vector<double> results;
        for(int i=0;i<queries.size();i++)
        {
            if(graph.find(queries[i].first)!=graph.end() && graph[queries[i].first].find(queries[i].second)!=graph[queries[i].first].end())
                results.push_back(graph[queries[i].first][queries[i].second]);
            else
                results.push_back(-1);
        }
        return results;
    }
};
