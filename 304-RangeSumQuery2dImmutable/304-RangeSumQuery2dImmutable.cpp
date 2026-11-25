// Last updated: 11/25/2026, 3:47:38 PM
/*
splitting convention followed

             midCol
               |
       m1      |       m2
               |
    ------------+------------
               |
       m4      |       m3
               |
             midRow

*/

class SegmentTree {
    public:
    int m;
    int n;
    int size;
    vector<int> tree;
    vector<vector<int>> sourceArray;

    // pass only unique parameters , the parameters with f(some other parameter) calculate inside.
    SegmentTree (int m, int n, vector<vector<int>> &sourceArray) {
        this->m = m;
        this->n = n;
        this->size = 4 * m * n + 1;
        this->tree = vector<int>(4 * m * n + 1, 0);
        this->sourceArray = sourceArray;
    }

    // since we already calculated the max of index will be 4*n (with dummy nodes),
    // we dont need to add any check for out of bounds of index. (not sure check while debugging)
    int build(int index, pair<int,int> low, pair<int,int> top) {
        // Invalid rectangle , prevents out of bounds
        if (low.first > top.first || low.second > top.second)
            return 0;

        // single element base
        if (low.first == top.first && low.second == top.second) { // not sure (debug if needed)

            return tree[index] = sourceArray[low.first][low.second];  
        }
        
        // double element base
        // (Handled cleanly via recursive subdivision)

        int midRow = low.first + (top.first - low.first) / 2;
        int midCol = low.second + (top.second - low.second) / 2;

        // child indices from 4 * index to 4 * index + 1, 4 * index + 2, 4 * index + 3, and 
        // 4 * index + 4 (using 4 * index as a child caused a recursive collision where node 0 was its own child).
        int m1 = build(4 * index + 1, low, {midRow, midCol});
        int m2 = build(4 * index + 2, {low.first, midCol + 1}, {midRow, top.second});
        int m3 = build(4 * index + 3, {midRow + 1, midCol + 1}, top);
        int m4 = build(4 * index + 4, {midRow + 1, low.second}, {top.first, midCol});

        return tree[index] = m1 + m2 + m3 + m4;
    }

    void build () {
        cout << "Sum of elements : " << build(0, {0,0}, {m - 1, n - 1}) << endl;
    }

    bool IsInvalidQuery(pair<int,int> qlow, pair<int,int> qtop , pair<int,int> low, pair<int,int> top) {
        // bounds exceed or [low, top] bounds invalid

        return ( qlow.first < 0 || qlow.second < 0 || qlow.first >= m || qlow.second >= n ) || 
                ( qtop.first < 0 || qtop.second < 0 || qtop.first >= m || qtop.second >= n ) || 
                ( qlow.first > qtop.first || qlow.second > qtop.second );
    }

    // -1 indicates something went wrong
    int query (int index, pair<int,int> qlow, pair<int,int> qtop, pair<int,int> low, pair<int,int> top) {
        // bounds exceed or [low, top] bounds invalid
        if(IsInvalidQuery(qlow, qtop, low, top)) {
            cout << "ERROR !" << endl;
            return 0;
        }
        
        // Check if current node's rectangle is completely outside the query range
        if (top.first < qlow.first || low.first > qtop.first ||
            top.second < qlow.second || low.second > qtop.second) {
            return 0;
        }

        // total overlapp
        if((low.first >= qlow.first && top.first <= qtop.first ) &&
            (low.second >= qlow.second && top.second <= qtop.second)) {

            return tree[index];
        }

        int midRow = low.first + (top.first - low.first) / 2;
        int midCol = low.second + (top.second - low.second) / 2;

        int sq1 = query(
            4 * index + 1,
            qlow,
            qtop,
            low,
            {midRow, midCol}
        );

        int sq2 = query(
            4 * index + 2,
            qlow,
            qtop,
            {low.first, midCol + 1},
            {midRow, top.second}
        );

        int sq3 = query(
            4 * index + 3,
            qlow,
            qtop,
            {midRow + 1, midCol + 1},
            top
        );

        int sq4 = query(
            4 * index + 4,
            qlow,
            qtop,
            {midRow + 1, low.second},
            {top.first, midCol}
        );

        return sq1 + sq2 + sq3 + sq4;

    }

    int query (pair<int,int> qlow, pair<int,int> qtop) {
        return query(0, qlow, qtop, {0,0}, {m - 1, n - 1}); 
    }
};

class NumMatrix {
public:
    SegmentTree treeInstance;
    vector<vector<int>> matrix;

   //you can avoid the initializer-list syntax, but then you must make treeInstance a pointer because SegmentTree has no default constructor.
    NumMatrix(vector<vector<int>>& matrix)
        : matrix(matrix),
          treeInstance(matrix.size(), matrix[0].size(), matrix) {

        cout << "Building" << endl;
        treeInstance.build();
        cout << "Done building" << endl;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        cout << "Start query" << endl;
        return treeInstance.query({row1,col1} , {row2,col2});
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */