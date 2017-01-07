class TrieNode{
public:
    TrieNode* next[26];
    string word;
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
        word = "";
    }
    void createTrie(vector<string> dict)
    {
        for(auto a:dict)
        {
            TrieNode* temp = this;
            for(auto c:a)
            {
                if(!temp->next[c-'a'])
                {
                    temp->next[c-'a'] = new TrieNode();
                }
                temp = temp->next[c-'a'];
            }
            temp->word = a;
        }
    }
    void dfs(vector<vector<char>>  board, TrieNode* t, int i, int j, vector<string> *result,int r, int c)
    {
        if(board[i][j]=='#' || t==NULL)
        {
            return;
        }
        if(t->next[board[i][j]-'a']==NULL)
            return;
        else
        {
            if(t->next[board[i][j]-'a']->word!="")
            {
                result->push_back(t->next[board[i][j]-'a']->word);
                t->next[board[i][j]-'a']->word="";
            }
            t=t->next[board[i][j]-'a'];
            char ch = board[i][j];
            board[i][j]='#';
            if(i+1<r)dfs(board,t,i+1,j,result,r,c);
            if(j+1<c)dfs(board,t,i,j+1,result,r,c);
            if(i-1>=0)dfs(board,t,i-1,j,result,r,c);
            if(j-1>=0)dfs(board,t,i,j-1,result,r,c);
            board[i][j] = ch;
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector<string> res;
        root->createTrie(words);
        int r = board.size();
        if(r==0)
            return res;
        int c = board[0].size();
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                root->dfs(board,root,i,j,&res,r,c);
            }
        return res;
    }
};
