long flippingBits(long n) {
    std::uint32_t value = n;
    value = ~value;
    return value;
}
