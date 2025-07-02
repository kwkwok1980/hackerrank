// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int count_apple = 0;
    for (auto apple : apples) {
        int position = a + apple;
        if (s <= position && position <= t) {
            ++count_apple;
        }
    }
    
    int count_orange = 0;
    for (auto orange : oranges) {
        int position = b + orange;
        if (s <= position && position <= t) {
            ++count_orange;
        }
    }
    
    std::cout << count_apple << std::endl;
    std::cout << count_orange << std::endl;

}
