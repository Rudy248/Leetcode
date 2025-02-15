class Solution {
public:
    vector<int> generateRow(int n){
        long long ans=1;
        vector<int> row;
        row.push_back(ans);
        for(int i=1; i<n; i++){
            ans=ans*(n-i);
            ans=ans/i;
            row.push_back(ans);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalAns;
        for(int i=1; i<=numRows; i++){
            finalAns.push_back(generateRow(i));
        }
        return finalAns;
    }
};