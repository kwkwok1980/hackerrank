std::string biggerIsGreater(std::string w) {
    int N = w.size();
    int result1 = -1;
    for (int i=1; i<N; ++i) {
        if (w[i] > w[i-1]) {
            result1 = i;
        }
    }
    if (result1 == -1) {
        return "no answer";
    }
    int result2 = result1;
    for (int i=result1+1; i<N; ++i) {
        if (w[i] > w[result1-1]) {
            if (w[i] < w[result2]) {
                result2 = i;
            }
        }
    }

    std::swap(w[result1-1], w[result2]);
    std::sort(w.data() + result1, w.data() + N);
    return w;
}
