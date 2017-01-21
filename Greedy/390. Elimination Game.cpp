class Solution {
public:
    int lastRemaining(int n) {
        int first_element = 1, count = n, step = 1;
        bool is_left_to_right = true;
        while(count>1){
            if(is_left_to_right || count%2!=0) first_element += step;
            count = count/2;
            step = step*2;
            if(count==1) return first_element;
            is_left_to_right = !is_left_to_right;
        }
        return first_element;
    }
};
