class MedianFinder {
    multiset<int> min_heap;
    multiset<int> max_heap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(min_heap.size()<max_heap.size())
        {
            //Add to min heap
            if(max_heap.size()==0)
            {
                min_heap.insert(num);
            }
            else
            {
                int min_in_max_heap = *max_heap.begin();
                if(num<min_in_max_heap)
                {
                    min_heap.insert(num);
                }
                else
                {
                    max_heap.insert(num);
                    min_heap.insert(min_in_max_heap);
                    max_heap.erase(max_heap.begin());
                }
            }
        }
        else
        {
            if(max_heap.size()==0)
            {
                max_heap.insert(num);
            }
            else
            {
                int max_in_min_heap = *min_heap.rbegin();
                if(num>max_in_min_heap)
                {
                    max_heap.insert(num);
                }
                else
                {
                    min_heap.insert(num);
                    max_heap.insert(max_in_min_heap);
                    min_heap.erase(prev(min_heap.end()));
                }
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(min_heap.size()<max_heap.size())
        {
            return *max_heap.begin();
        }
        else
        {
            return ((double)(*max_heap.begin()+*min_heap.rbegin()))/2.0;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
