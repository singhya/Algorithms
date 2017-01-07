/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> flattened_list;
    int counter;
    void DFS(vector<NestedInteger> nestedList)
    {
        for(int i=0;i<nestedList.size();i++)
        {
            if(nestedList[i].isInteger())
            {
                flattened_list.push_back(nestedList[i].getInteger());
            }
            else
                DFS(nestedList[i].getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        DFS(nestedList);
        counter=0;
    }

    int next() {
        return flattened_list[counter++];
    }

    bool hasNext() {
        return counter<flattened_list.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
