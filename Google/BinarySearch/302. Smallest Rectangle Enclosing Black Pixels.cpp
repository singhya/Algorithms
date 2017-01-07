class Solution {
public:
    bool isPresent(vector<vector<char>> &image, int index, bool colSearch){
        int m = image.size();
        int n = image[0].size();
        if(colSearch){
            for(int i=0;i<m;i++)
                if(image[i][index]=='1')
                    return true;
            return false;
        }
        else{
            for(int i=0;i<n;i++)
                if(image[index][i]=='1')
                    return true;
            return false;
        }
    }
    int search(vector<vector<char>> &image, int index, int alwaysPresent, bool colSearch){
        if(index==alwaysPresent)
            return index;
        else if(abs(index-alwaysPresent)==1)
            if(isPresent(image,index,colSearch))
                return index;
            else
                return alwaysPresent;
        int mid = (index+alwaysPresent)/2;
        if(isPresent(image,mid,colSearch))
            return search(image, index,mid,colSearch);
        else
            return search(image, mid,alwaysPresent,colSearch);
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        int y1 = search(image,0,y,true);
        int y2 = search(image,n-1,y,true);
        int x1 = search(image,0,x,false);
        int x2 = search(image,m-1,x,false);
        return (x2-x1+1)*(y2-y1+1);
    }
};
