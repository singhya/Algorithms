#include<iostream>
#include<vector>
using namespace std;
class stone
{
    public:
    int index;
    stone* next;
    stone* prev;
    stone()
    {
        next = NULL;
        prev = NULL;
        index = -1;
    }
};
class Solution{
public:
    int monkey(vector<int>nums, int D)
    {
        int max_time = INT_MIN;
        int n = nums.size();
        if(D>n)
            return 0;
        // Find max time.
        for(int i=0;i<n;i++)
            max_time = std::max(max_time,nums[i]);

        //Initializing time array
        vector<int>time(max_time+1,-1);
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=-1)
                time[nums[i]] = i;

        //Initializing stones array
        vector<stone*>stones(n+2, new stone());
        int prev = 0;
        stones[0] = new stone();
        stones[0]->index = 0;
        for(int i=0;i<n;i++)
        {
            int current = i+1;
            if(nums[i]!=-1)
            {
                stone* s = new stone();
                stones[current] = s;
                stones[current]->index=current;
                stones[current]->prev = stones[prev];
                stones[prev]->next = stones[current];
                prev = current;
            }
        }

        stones[n+1]->index = n+1;
        stones[n+1]->prev = stones[prev];
        stones[prev]->next=stones[n+1];

        //Check for valid path initially
        int i=0;
        while(i!=n+1)
        {
            if(stones[i]->next->index-stones[i]->index>D)
                return -1;
            else
                i = stones[i]->next->index;
        }

        //Check for valid path on each time step
        int currentTime = max_time;
        int valid_time = currentTime;
        bool path_exist = true;
        while(path_exist && currentTime>=0)
        {
            int currentStone = time[currentTime];
            if(currentStone!=-1)
            {
                if(stones[currentStone+1]->next->index-stones[currentStone+1]->prev->index>D)
                    path_exist = false;
                else
                {
                    stones[currentStone+1]->next->prev = stones[currentStone+1]->prev;
                    stones[currentStone+1]->prev->next = stones[currentStone+1]->next;
                }
                valid_time = currentTime;
            }
            currentTime--;
        }
        return valid_time;
    }
};
int main()
{
    Solution s;
    vector<int>nums{1,-1,6,2,3,5};
    int D = 6;
    for(int i=0;i<=7;i++)
    cout<<"Solution for "<<i<<" : "<<s.monkey(nums,i)<<endl;
    return 0;
}
