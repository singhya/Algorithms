class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        long min_x=INT_MAX;
        long min_y=INT_MAX;
        long max_x=INT_MIN;
        long max_y=INT_MIN;
        long area = 0;
        set<string>corners;
        for(int i=0;i<n;i++)
        {
            if(rectangles[i][0]<=min_x && rectangles[i][1]<=min_y)
            {
                min_x = rectangles[i][0];
                min_y = rectangles[i][1];
            }
            if(rectangles[i][2]>=max_x && rectangles[i][3]>=max_y)
            {
                max_x = rectangles[i][2];
                max_y = rectangles[i][3];
            }
            area += (rectangles[i][2]-rectangles[i][0])*(rectangles[i][3]-rectangles[i][1]);
            string upper_left = to_string(rectangles[i][0])+"|"+to_string(rectangles[i][3]);
            string upper_right = to_string(rectangles[i][2])+"|"+to_string(rectangles[i][3]);
            string lower_left = to_string(rectangles[i][0])+"|"+to_string(rectangles[i][1]);
            string lower_right = to_string(rectangles[i][2])+"|"+to_string(rectangles[i][1]);
            if(corners.find(upper_left)!=corners.end())
                corners.erase(upper_left);
            else
                corners.insert(upper_left);
            if(corners.find(upper_right)!=corners.end())
                corners.erase(upper_right);
            else
                corners.insert(upper_right);
            if(corners.find(lower_left)!=corners.end())
                corners.erase(lower_left);
            else
                corners.insert(lower_left);
            if(corners.find(lower_right)!=corners.end())
                corners.erase(lower_right);
            else
                corners.insert(lower_right);
        }
        string upper_left = to_string(min_x)+"|"+to_string(max_y);
        string upper_right = to_string(max_x)+"|"+to_string(max_y);
        string lower_left = to_string(min_x)+"|"+to_string(min_y);
        string lower_right = to_string(max_x)+"|"+to_string(min_y);
        if(corners.find(upper_left)==corners.end() || corners.find(upper_right)==corners.end() || corners.find(lower_left)==corners.end() || corners.find(lower_right)==corners.end())
            return false;
        if(area==(max_y-min_y)*(max_x-min_x) && corners.size()==4)
            return true;
        return false;
    }
};
