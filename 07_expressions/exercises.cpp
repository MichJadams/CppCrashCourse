//7-1. Create an UnsignedBigInteger class that can handle numbers bigger than a long.
//You can use a byte array as the internal representation (for example, uint8_t[] or char[]).
//Implement operator overloads for operator+ and operator-. Perform runtime checks for overflow.
//For the intrepid, also implement operator*, operator/, and operator%.
//Make sure that your operator overloads work for both int types and UnsignedBigInteger types.
//Implement an operator int type conversion. Perform a runtime check if narrowing would occur.

#include <cstdio>
#include <limits>
#include <cstdint>

struct BigNumber
{
    BigNumber(const uint8_t *input_digits, size_t input_digits_length)
    {
        // for each digit in bigNumber, place it in the upper or lower half
        // of the bigNumber storage array

        // the length of big number only needs to be half as long as
        // the input_digits array because we are storing two digits
        // in each element in bigNumber

        // create an array to hold the incoming digits
        // each item in the bigNumber array will hold two digits
        // encoded in hex.
        bigNumberSize = static_cast<int>((input_digits_length + 1) / 2);
        bigNumber = new uint8_t[bigNumberSize];

        int bigNumberIndex = 0;

        // Loop start at the end and move backwards (from the ones place
        // to the tens place etx).
        for (int c = input_digits_length - 1; c >= 0; c--)
        {
            // odds are lower
            if (c % 2 == 0)
            {
                bigNumber[bigNumberIndex] = (input_digits[c] << 4) | bigNumber[bigNumberIndex];
                bigNumberIndex += 1;
            }
            // events are upper
            else
            {
                bigNumber[bigNumberIndex] = input_digits[c];
            }
        };
    }

    uint8_t *bigNumber;
    int bigNumberSize;
};

int main()
{
    // How big is a long? 4 bytes, so 4 * 8 bits which is .... 32.
    // So I need a type that can hold a number longer than 32 bits.
    // 2 ^ 32 is 8589934592, so I've made an array larger than that :)

    // I think I want to use uint8_t as a type to store an array of bytes?
    //

    uint8_t arr[] = {2, 4, 3, 3, 2, 5, 0, 0, 0, 0, 0};
    BigNumber test{arr, sizeof(arr)};
}
