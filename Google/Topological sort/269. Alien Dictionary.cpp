class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> roots;
        map<char,unordered_set<char>>graph;
        for(auto s:words)
            for(int i=0;i<s.length();i++)
            {
                roots.insert(s[i]);
            }

        for(int i=0;i<words.size()-1;i++)
        {
            string first = words[i];
            string second = words[i+1];
            for(int j=0;j<min(first.length(),second.length());j++)
            {
                if(first[j]!=second[j])
                {
                    if(graph.find(second[j])==graph.end())
                    {
                        unordered_set<char> s;
                        s.insert(first[j]);
                        graph[second[j]]=s;
                    }
                    else
                        graph[second[j]].insert(first[j]);
                    if(roots.find(second[j])!=roots.end())
                        roots.erase(second[j]);
                    break;
                }
            }
        }
        string result = "";
        while(roots.size()>0)
        {
            char c = *(roots.begin());
            roots.erase(c);
            result+=c;
            for(auto node:graph)
            {
                if(node.second.find(c)!=node.second.end())
                {
                    graph[node.first].erase(c);
                }
                if(graph[node.first].empty())
                {
                    roots.insert(node.first);
                    graph.erase(node.first);
                }
            }
        }
        if(graph.size()!=0)
            return "";
        return result;
    }
};
