class Solution {
public:
    class node{
        public:
        string nodeString;
        int level;
        node(string n, int l){
            nodeString = n;
            level = l;
        }
    };
    int minMutation(string start, string end, vector<string>& bank){
        if(start==end){
            return 0;
        }
        set<string> bankSet;
        int length = start.size();
        vector<char> options = {'A', 'T', 'C', 'G'};
        bankSet.insert(start);
        for(auto b:bank){
            if(b.size()==length)
                bankSet.insert(b);
        }
        node new_node(start,0);
        queue<node> q;
        q.push(new_node);
        set<string> visited;
        while(!q.empty()){
            node parent = q.front();
            q.pop();
            visited.insert(parent.nodeString);
            if(parent.nodeString==end)
                return parent.level;
            for(int i=0;i<length;i++){
                string child = parent.nodeString;
                for(int j=0;j<options.size();j++){
                    child[i] = options[j];
                    if(visited.find(child)==visited.end()
                       && bankSet.find(child)!=bankSet.end())
                    {
                        node new_child(child, parent.level+1);
                        q.push(new_child);
                    }
                }
            }
        }
        return -1;
    }
};
