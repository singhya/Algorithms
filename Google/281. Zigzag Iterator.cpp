class ZigzagIterator {
private:
    vector< vector <int>> v;
    int size;
    int i=0;
    int j=0;
    int counter=0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty())
        v.push_back(v1);
        if(!v2.empty())
        v.push_back(v2);
    }

    int next() {
        int val = v[0][0];
        v[0].erase(v[0].begin());
        vector<int> temp = v[0];
        v.erase(v.begin());
        if(temp.size()>0)
            v.push_back(temp);
        return val;
    }

    bool hasNext() {
        return v.begin()!=v.end();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
