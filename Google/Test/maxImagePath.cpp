#include<iostream>
#include<stack>
#include<vector>
#include<sstream>
#include<set>
using namespace std;
class Solution{
    public:
    void split(string s, char delim, vector<string>& res){
        stringstream ss(s);
        string elem;
        while(getline(ss, elem, delim)){
            res.push_back(elem);
        }
    }
    findMaxPath(string s){
        stack<string> path;
        vector<string>lines;
        split(s, '\n', lines);
        set<string> images = {"jpeg","gif","png"};
        int max=0;
        int current_length = 0;
        for(int i=0; i<lines.size(); i++){
            int level=0;
            while(level<lines[i].size() && lines[i][level]==' '){
                level++;
            }
            while(!path.empty() && level<path.size()){
                int top_element_length = path.top().size()+1;
                current_length-=top_element_length;
                path.pop();
            }
            string ext = "";
            if(lines[i].find(".")!=-1){
                ext = lines[i].substr(lines[i].find(".")+1);
                if(images.find(ext)!=images.end()){
                    max = std::max(1,max);
                    max = std::max(current_length,max);
                }
            }
            path.push(lines[i].substr(level));
            current_length+=lines[i].size()-level+1;
        }
        return max;
    }
};
int main(){
        vector<string>cases={
            "AA\n BCD\n  EFG.jpeg",
            "abc.txt",
            "abc.png",
            "nfwejfg.gif",
            "ndsklfnwod.jpeg",
            "AA\n BCD\n  EFG.jpeg\nAA\n BCDE\n  EFG.png",
            "AA\n BCD\n  EFG.cpp",
            "AA\n BCD\n  EFG.java\n  sdkfbnkl.png",
            "AA\n BCD\n  sadfhbisj\n    sdjfosdo\n     sdfj.gif\n  QST.png\n  EFG.jpeg",

            };
        Solution s;
        for(int i=0;i<cases.size();i++){
            cout<<"-----------------"<<endl;
            cout<<cases[i]<<endl;
            cout<<"Result : "<<s.findMaxPath(cases[i])<<endl;
        }
    return 0;
}
