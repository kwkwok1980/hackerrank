string timeConversion(string s) {
    std::string result = s.substr(0, 8);
    if (s[8] == 'P') {
        int n = stoi(s.substr(0,2)) + 12;
        if (n < 10) {
            result[0] = '0';
            result[1] = std::to_string(n)[0];
        } else if (n < 24) {
            result[0] = std::to_string(n)[0];
            result[1] = std::to_string(n)[1];
        } else {
            result[0] = '1';
            result[1] = '2';
        }
    } else if (s[8] == 'A') {
        if (result[0] == '1' and result[1] == '2') {
            result[0] = '0';
            result[1] = '0';
        }
    }
    return result;
}
