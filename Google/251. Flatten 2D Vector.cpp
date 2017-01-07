class Vector2D {
public:
    vector<int> v;
    int counter = 0;
    Vector2D(vector<vector<int>>& vec2d) {
        v = vector<int>(0);
        for(int i=0;i<vec2d.size();i++)
            v.insert(v.end(),vec2d[i].begin(),vec2d[i].end());
    }

    int next() {
        return v[counter++];
    }

    bool hasNext() {
        return counter<v.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
