// Last updated: 11/25/2026, 3:49:03 PM
class Solution {
public:
    vector<vector<int>> generate(int N) {
    vector<vector<int>> answer;
    for (int i = 1; i <= N; i++)
    {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    int row=i;
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    answer.push_back(ansRow);
    }
    return answer;
    }
};