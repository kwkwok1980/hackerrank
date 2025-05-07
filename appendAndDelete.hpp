std::string appendAndDelete(std::string s, std::string t, int k) {
    int match = 0;
    int len_s = s.length();
    int len_t = t.length();
    if (len_s + len_t < k) {
        return "Yes";
    }
    int len = std::min(len_s, len_t);
    for (int i=0; i<len; ++i) {
        if (s[i] == t[i]) {
            ++match;
        } else {
            break;
        }
    }
    if (match == 0) {
        if ((len_s + len_t) <= k) {
            return "Yes";
        } else {
            return "No";
        }
    } else {
        k = k - (len_s - match) - (len_t - match);
        if (k >=0) {
            if (k % 2 == 0) {
                return "Yes";
            } else {
                return "No";
            }
        } else {
            return "No";
        }
    }
}
