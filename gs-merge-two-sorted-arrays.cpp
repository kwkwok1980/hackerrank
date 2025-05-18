// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?page=1&company=Goldman%20Sachs&sortBy=submissions
void mergeArrays(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();
    int i = m - 1;
    int j = 0;
    while ((i>=0) && (j<n)) {
        if (a[i] > b[j]) {
            std::swap(a[i], b[j]);    
            --i;
            ++j;
        } else {
            break;
        }
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
}
