#include "ESLib.h"
#include <random>
#include <cstdint>
#include <cstddef>

void generate_random_bytes(uint8_t* bytes, size_t n)
{
    // Static random engine, initialized once with a high-entropy seed
    static std::mt19937 engine = [] {
        std::random_device rd;
        std::seed_seq seq{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
        return std::mt19937(seq);
    }();

    // Uniform distribution for uint8_t (0 to 255)
    std::uniform_int_distribution<uint8_t> dist;

    // Fill the array with random bytes
    for (size_t i = 0; i < n; ++i) {
        bytes[i] = dist(engine);
    }
}

eslt_ErrorCode esl_getBytesRNG(const eslt_Length targetLength, eslt_Byte *target)
{
    generate_random_bytes(target, targetLength);
    return 0;
}