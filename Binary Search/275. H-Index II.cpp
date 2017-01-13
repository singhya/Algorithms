class Solution {
public:
    int hIndex(vector<int>& citations) {
        int first = 0;
        int n = citations.size();
        int last = n-1;
        while(first<=last){
            int mid = (first+last)/2;
            if(citations[mid]==n-mid) return citations[mid];
            else if(citations[mid]>n-mid) last = mid-1;
            else first = mid+1;
        }
        return n-(last+1);
    }
};
