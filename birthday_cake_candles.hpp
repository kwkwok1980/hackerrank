int birthdayCakeCandles(vector<int> candles) {
    int max = std::numeric_limits<int>::min();
    int count = 0;
    for (int candle : candles) {
        if (candle > max) {
            max = candle;
            count = 1;
        } else if (candle == max) {
            ++count;
        }
    }
    return count;
}
