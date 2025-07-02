// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
int birthday(vector<int> s, int d, int m) {
    int result = 0;
    for (int i=0; i<=s.size()-m; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j) {
            sum = sum + s[i+j];
        }
        if (sum == d) {
            ++result;
        }
    }
    return result;
}
