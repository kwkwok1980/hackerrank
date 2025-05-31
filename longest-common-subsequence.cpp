// https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

std::vector<int> longestCommonSubsequence(std::vector<int> a, std::vector<int> b) {
    int results[100+1][100+1]{};

    int N = a.size();
    int M = b.size();
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            results[i][j] = 0;
        }
    }

    for (int i=N-1; i>=0; --i) {
        if (i == N-1) {
            for (int j=M-1; j>=0; --j) {
                if (j == M-1) {
                    if (a[i] == b[j]) {
                        results[i][j] = 1;
                    }
                } else {
                    int result = results[i][j+1];
                    if (a[i] == b[j]) {
                        result = std::max(result, 1);
                    }
                    results[i][j] = result;
                }
            }
        } else {
            for (int j=M-1; j>=0; --j) {
                if (j == M-1) {
                    if (a[i] == b[j]) {
                        results[i][j] = 1;
                    }
                } else {
                    int result = std::max(results[i][j+1], results[i+1][j]);
                    if (a[i] == b[j]) {
                        result = std::max(result, 1 + results[i+1][j+1]);
                    }
                    results[i][j] = result;
                }
            }
        }
    }
    std::vector<int> output{};
    int result = results[0][0];
    int x = 0;
    int y = 0;
    while (result >0) {
        while (results[x+1][y] == result) ++x;
        while (results[x][y+1] == result) ++y;
        output.push_back(b[y]);
        --result;
        ++x;
        ++y;
    }
    return output;

}
