class Solution {
public:
    int opt;
    vector<int> dict;
    int max;
    int n;
    int minlen;
    int res;
    string binaryInt(int i){
        string str = "";
        while(i>0){
            str = to_string(i%2+0) + str;
            i = i/2;
        }
        while(str.size()<n){
            str="0"+str;
        }
        return str;
    }
    int findLength(int number){
        int count = n;
        for(int i=3;i<max;i<<=1){
            if((number&i)==0)
                count--;
        }
        return count;
    }
    void DFS(int nextBit, int mask){
        int len = findLength(mask);
        if(len>minlen){
            return;
        }
        bool conflict = false;
        for(auto d:dict){
            if((mask&d)==0){
                conflict = true;
                break;
            }
        }
        if(!conflict){
            if(minlen>len){
                minlen = len;
                res = mask;
            }
        }
        else
            for(int bit=nextBit; bit<max; bit<<=1)
                DFS(bit<<1, mask+bit);
    }

    string minAbbreviation(string target, vector<string>& dictionary) {
        opt = 0;
        n = target.size();
        max = 1<<n;
        minlen = INT_MAX;
        res = 0;
        for(int i=0;i<n;i++){
            res = res<<1;
            res = res|1;
        }
        for(auto v:dictionary){
            int num = 0;
            if(v.size()!=n)
                continue;
            for(int i=0; i<n; i++){
                num = num<<1;
                if(v[i]!=target[i]){
                    num = num | 1;

                }
            }
            dict.push_back(num);
            opt = opt | num;
        }

        DFS(1,0);
        string st = binaryInt(res);
        string result;
        int i=0;
        int prev = -1;
        while(i<n){
            if(st[i]=='1'){
                if(prev==i-1)
                    result+=target[i];
                else
                    result+=to_string(i-prev-1)+target[i];
                prev = i;
            }
            i++;
        }
        if(prev!=n-1){
            result+=to_string(i-prev-1);
        }
        return result;
    }
};
