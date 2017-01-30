class Solution {
public:
    vector<int> constructRectangle(int area) {
        int s = sqrt(area);
        for(int i = s; i>=1; i--)
            if(area%i ==0){
                vector<int> result;
                result.push_back(area/i);
                result.push_back(i);
                return result;
            }
    }
};
