class Solution {
public:
    //Returns vector of sets with k bits set to 1.
    //Each set contains the bit positions which are set to 1
    //e.g. - for k=3, one of the set could be : {2,4,7} means 0101 001000
    vector<set<int>> DFS(set<int>&bits, int k)
    {
        vector<set<int>> results;
        if(k==0)
        {
            results.push_back(bits);
            return results;
        }
        for(int i=bits.empty()?1:*bits.rbegin()+1;i<=10;i++)
        {
            bits.insert(i);
            vector<set<int>> new_results = DFS(bits,k-1);
            results.insert(results.end(),new_results.begin(),new_results.end());
            bits.erase(i);
        }
        return results;
    }

    // Converts set to time
    // E.g. {2,4,7} = 0101 001000 will get converted to 5:08
    string getTime(set<int> &s)
    {
        int hr=0, min=0;
        while(!s.empty())
        {
            int val = *s.begin();
            if(val<=4)
                hr+=pow(2,4-val);
            else
                min+=pow(2,10-val);
            if(hr>11 || min>59)
                return "";
            s.erase(val);
        }
        string str = to_string(hr)+":";
        str+=((min<10)?"0":"") +to_string(min);
        return str;
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> combinations;
        set<int>bits;
        vector<set<int>> results = DFS(bits,num);
        vector<string>output;
        for(auto s:results)
        {
            string str = getTime(s);
            if(str!="")
            output.push_back(str);
        }
        return output;
    }
};
