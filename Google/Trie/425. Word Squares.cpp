class Solution {
public:
    class Trie{
        public:
        vector<string> str;
        vector<Trie*> nodes;
        Trie(){
            nodes = vector<Trie*>(26);
            for(int i=0; i<26; i++){
                nodes[i] = NULL;
            }
        }
    };
    Trie* createTrie(vector<string>& words, Trie* head){
        for(auto word:words){
            Trie* it = head;
            for(auto c: word){
                if(it->nodes[c-'a']==NULL){
                    Trie* new_node = new Trie();
                    it->nodes[c-'a'] = new_node;
                }
                it = it->nodes[c-'a'];
                it->str.push_back(word);
            }
        }
        return head;
    }
    void DFS(vector<string> temp, vector<vector<string>> &result, Trie* head){
        int index = temp.size();
        if(index==temp[0].size()){
            result.push_back(temp);
            return;
        }
        string prefix = "";
        for(int i=0;i<index;i++){
            prefix+=temp[i][index];
        }
        Trie* it = head;
        for(int i=0;i<prefix.size();i++){
            if(it->nodes[prefix[i]-'a']!=NULL){
                it = it->nodes[prefix[i]-'a'];
            }
            else{
                return;
            }
        }
        for(auto s:it->str){
            temp.push_back(s);
            DFS(temp,result,head);
            temp.erase(temp.end()-1);
        }

    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        Trie* head = new Trie();
        createTrie(words, head);
        vector<vector<string>> result;
        vector<string> temp;
        for(auto word: words){
            temp.push_back(word);
            DFS(temp, result, head);
            temp.erase(temp.end()-1);
        }
        return result;
    }
};
