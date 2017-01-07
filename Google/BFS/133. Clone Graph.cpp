/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode* root = NULL;
        if(node==NULL)
            return root;
        map<int, UndirectedGraphNode*> nodes;
        set<int>visited;
        queue<UndirectedGraphNode*>q;
        q.push(node);
        while(!q.empty()) {
            UndirectedGraphNode* parent = q.front();
            if(visited.find(parent->label)==visited.end()) {
                visited.insert(parent->label);
                UndirectedGraphNode* new_parent_node;
                if(nodes.find(parent->label)==nodes.end())
                    new_parent_node = new UndirectedGraphNode(parent->label);
                else
                    new_parent_node = nodes[parent->label];
                nodes[parent->label] = new_parent_node;
                for(auto child:parent->neighbors)
                {
                    if(nodes.find(child->label)==nodes.end())
                        nodes[child->label] = new UndirectedGraphNode(child->label);
                    nodes[parent->label]->neighbors.push_back(nodes[child->label]);
                    q.push(child);
                }
            }
            q.pop();
        }
        return nodes[node->label];
    }
};
