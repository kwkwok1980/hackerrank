vector<int> compareTriplets(vector<int> a, vector<int> b) {
    std::vector<int> results(2, 0);
    for (int i=0; i<3; ++i) {
        int aValue = a[i];
        int bValue = b[i];
        if (aValue > bValue) {
            ++results[0];
        } else if (aValue < bValue) {
            ++results[1];
        }
    }
    return results;
}
