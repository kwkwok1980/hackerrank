void staircase(int n) {
    std::string value(n, ' ');
    for (int i=n-1; i>=0; --i) {
        value[i] = '#';
        std::cout << value << std::endl;
    }
}
