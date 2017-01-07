class ValidWordAbbr {
private:
    unordered_map<string,vector<string>> occurence;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i=0;i<dictionary.size();i++)
        {
            int length = dictionary[i].size();
            string key = dictionary[i];
            if(length>2);
            {
                length = length-2;
                key = dictionary[i][0]+to_string(length)+dictionary[i][length+1];
            }
            if(occurence.count(key)==0)
            {
                occurence[key] = vector<string>(0);
                occurence[key].push_back(dictionary[i]);
            }
            else if(occurence[key].size()==1 && occurence[key][0]!=dictionary[i])
            occurence[key].push_back(dictionary[i]);
        }
    }

    bool isUnique(string word) {
        int length = word.size();
            string key = word;
            if(length>2);
            {
                length = length-2;
                key = word[0]+to_string(length)+word[length+1];
            }
        if(occurence.count(key)==0 || (occurence[key].size()==1 && occurence[key][0]==word))
            return true;
        else
            return false;
    }
};
