#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>
#include <iostream>

class BigInt
{
private:
    std::string str; // only data member for strong Big Integer as String. [For signed int, str[0] = '-']

    static std::string trim(std::string);
    static std::string add(std::string, std::string);
    static std::string subtract(std::string, std::string);
    static std::string multiply(std::string, std::string);
    static std::string divide(std::string, std::string);

    static std::string mod(std::string, std::string);
    static std::string shortDivide(std::string, unsigned long long int);
    static std::string maximum(std::string, std::string);
    static bool is_maximum(std::string, std::string);
    static bool is_strictlyMaximum(std::string, std::string);
    static std::string minimum(std::string, std::string);
    static bool is_minimum(std::string, std::string);
    static bool is_strictlyMinimum(std::string, std::string);
    static bool is_bigint(std::string);
    static std::string abs(std::string);
    static std::string pow(std::string, std::string);
    static std::string sqrt(std::string);
    static std::string log2(std::string);
    static std::string log10(std::string);
    static std::string logwithbase(std::string, std::string);
    static std::string antilog2(std::string);
    static std::string antilog10(std::string);
    static void swap(std::string &, std::string &);
    static std::string reverse(std::string);
    static std::string gcd(std::string, std::string);
    static std::string lcm(std::string, std::string);
    static std::string fact(std::string);
    static bool isPalindrome(std::string);
    static bool isPrime(std::string);


public:
    BigInt()
    {
        str = '0';  //default value
    }
    BigInt(std::string s)
    {
        if(!is_bigint(s))
            throw std::runtime_error("Invalid Big Integer has been fed.");   // if the input string is not valid number.

        str = s;
    }
    BigInt(long long int n)
    {
        str = std::to_string(n);
    }
    BigInt(unsigned long long n)
    {
        str = std::to_string(n);
    }
    BigInt(int n)
    {
        str = std::to_string(n);
    }
    BigInt(long int n)
    {
        str = std::to_string(n);
    }
    BigInt(const BigInt &n)
    {
        str = n.str;
    }

    BigInt from_hex(std::string hex_str)
    {
        BigInt n;
        for( long long int i = 0; i < hex_str.length(); i++ )
        {
            int int_letter = (hex_str[i] >= 'A') ? (hex_str[i] >= 'a') ? (hex_str[i] - 'a' + 10) : (hex_str[i] - 'A' + 10) : (hex_str[i] - '0');
            n = n + BigInt( std::to_string(int_letter) ) *  BigInt(BigInt::pow("16", std::to_string(hex_str.length() - i - 1)));
        }
        this->str = n.to_string();
        return *this;
    }

    std::string to_hex_str()
    {
        std::vector<unsigned char> bytes = this->to_bytes();

        std::stringstream ss;
        for( long long int i = 0;  i < bytes.size(); i++ )
        {
            ss << std::hex << (int)bytes[i];
        }

        return "0x" + ss.str();
    }

    std::string to_string()
    {
        return this->str;
    }

    std::vector<unsigned char> to_bytes()
    {
        std::vector<unsigned char> output;
        BigInt n = this->str;
        if( n < BigInt(16) )
        {
            output.push_back(std::stoi(n.to_string()));
            return output;
        }

        do
        {
            output.push_back( std::stoi( (n % BigInt(16)).to_string() ) );
            n = n / BigInt(16);

        } while(n > BigInt(0));

        // Reverse to keep last byte as MSB
        std::reverse(output.begin(), output.end());
        return output;
    }

    // operator overloading for output stream {<<}
    friend std::ostream &operator<<(std::ostream &stream, const BigInt &n)
    {
        stream << n.str;
        return stream;
    }

    // operator overloading for input stream {>>}
    friend std::istream &operator>>(std::istream &stream, BigInt &n)
    {
        stream >> n.str;
        return stream;
    }

    /* Operator {+} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    BigInt operator+(BigInt const &n)
    {
        BigInt ans;
        ans.str = add(str, n.str);
        return ans;
    }
    friend BigInt operator+(BigInt const &n1, int n2)
    {
        BigInt ans;
        ans.str = add(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator+(int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = add(n2.str, std::to_string(n1));
        return ans;
    }
    friend BigInt operator+(BigInt const &n1, long int n2)
    {
        BigInt ans;
        ans.str = add(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator+(long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = add(n2.str, std::to_string(n1));
        return ans;
    }
    friend BigInt operator+(BigInt const &n1, long long int n2)
    {
        BigInt ans;
        ans.str = add(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator+(long long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = add(n2.str, std::to_string(n1));
        return ans;
    }
    BigInt &operator+=(BigInt const n)
    {
        (*this).str = add((*this).str, n.str);
        return (*this);
    }


    /* Operator {-} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    BigInt operator-(BigInt const &n)
    {
        BigInt ans;
        ans.str = subtract(str, n.str);
        return ans;
    }
    friend BigInt operator-(BigInt const &n1, int n2)
    {
        BigInt ans;
        ans.str = subtract(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator-(int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = subtract(std::to_string(n1), n2.str);
        return ans;
    }
    friend BigInt operator-(BigInt const &n1, long int n2)
    {
        BigInt ans;
        ans.str = subtract(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator-(long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = subtract(std::to_string(n1), n2.str);
        return ans;
    }
    friend BigInt operator-(BigInt const &n1, long long int n2)
    {
        BigInt ans;
        ans.str = subtract(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator-(long long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = subtract(std::to_string(n1), n2.str);
        return ans;
    }
    BigInt &operator-=(BigInt const n)
    {
        (*this).str = subtract((*this).str, n.str);
        return (*this);
    }

    /* Operator {*} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    BigInt operator*(BigInt const &n)
    {
        BigInt ans;
        ans.str = multiply(str, n.str);
        return ans;
    }
    friend BigInt operator*(BigInt const &n1, int n2)
    {
        BigInt ans;
        ans.str = multiply(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator*(int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = multiply(std::to_string(n1), n2.str);
        return ans;
    }
    friend BigInt operator*(BigInt const &n1, long int n2)
    {
        BigInt ans;
        ans.str = multiply(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator*(long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = multiply(std::to_string(n1), n2.str);
        return ans;
    }
    friend BigInt operator*(BigInt const &n1, long long int n2)
    {
        BigInt ans;
        ans.str = multiply(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator*(long long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = multiply(std::to_string(n1), n2.str);
        return ans;
    }
    BigInt &operator*=(BigInt const n)
    {
        (*this).str = multiply((*this).str, n.str);
        return (*this);
    }

    /* Operator {/} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    BigInt operator/(BigInt const &n)
    {
        BigInt ans;
        ans.str = divide(str, n.str);
        return ans;
    }
    friend BigInt operator/(BigInt const &n1, int n2)
    {
        BigInt ans;
        ans.str = divide(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator/(int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = divide(std::to_string(n1), n2.str);
        return ans;
    }
    friend BigInt operator/(BigInt const &n1, long int n2)
    {
        BigInt ans;
        ans.str = divide(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator/(long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = divide(std::to_string(n1), n2.str);
        return ans;
    }
    friend BigInt operator/(BigInt const &n1, long long int n2)
    {
        BigInt ans;
        ans.str = divide(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator/(long long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = divide(std::to_string(n1), n2.str);
        return ans;
    }
    BigInt &operator/=(BigInt const n)
    {
        (*this).str = divide((*this).str, n.str);
        return (*this);
    }

    /* Operator {%} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    BigInt operator%(BigInt const &n)
    {
        BigInt ans;
        ans.str = mod(str, n.str);
        return ans;
    }
    friend BigInt operator%(BigInt const &n1, int n2)
    {
        BigInt ans;
        ans.str = mod(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator%(int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = mod(std::to_string(n1), n2.str);
        return ans;
    }
    friend BigInt operator%(BigInt const &n1, long int n2)
    {
        BigInt ans;
        ans.str = mod(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator%(long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = mod(std::to_string(n1), n2.str);
        return ans;
    }
    friend BigInt operator%(BigInt const &n1, long long int n2)
    {
        BigInt ans;
        ans.str = mod(n1.str, std::to_string(n2));
        return ans;
    }
    friend BigInt operator%(long long int n1, BigInt const &n2)
    {
        BigInt ans;
        ans.str = mod(std::to_string(n1), n2.str);
        return ans;
    }
    BigInt &operator%=(BigInt const n)
    {
        (*this).str = mod((*this).str, n.str);
        return (*this);
    }

    /* Increment/Decrement operators */
    BigInt &operator++()
    {
        (*this).str = add((*this).str, "1");
        return (*this);
    }
    BigInt operator++(int)
    {
        (*this).str = add((*this).str, "1");
        return (*this);
    }
    BigInt &operator--()
    {
        (*this).str = subtract((*this).str, "1");
        return (*this);
    }
    BigInt operator--(int)
    {
        (*this).str = subtract((*this).str, "1");
        return (*this);
    }

    /* Operator {>} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    bool operator>(BigInt const &n)
    {
        return is_strictlyMaximum(str, n.str);
    }
    friend bool operator>(BigInt const &n1, int n2)
    {
        return is_strictlyMaximum(n1.str, std::to_string(n2));
    }
    friend bool operator>(int n1, BigInt const &n2)
    {
        return is_strictlyMaximum(std::to_string(n1), n2.str);
    }
    friend bool operator>(BigInt const &n1, long int n2)
    {
        return is_strictlyMaximum(n1.str, std::to_string(n2));
    }
    friend bool operator>(long int n1, BigInt const &n2)
    {
        return is_strictlyMaximum(std::to_string(n1), n2.str);
    }
    friend bool operator>(BigInt const &n1, long long int n2)
    {
        return is_strictlyMaximum(n1.str, std::to_string(n2));
    }
    friend bool operator>(long long int n1, BigInt const &n2)
    {
        return is_strictlyMaximum(std::to_string(n1), n2.str);
    }

    /* Operator {<} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    bool operator<(BigInt const &n)
    {
        return is_strictlyMinimum(str, n.str);
    }
    friend bool operator<(BigInt const &n1, int n2)
    {
        return is_strictlyMinimum(n1.str, std::to_string(n2));
    }
    friend bool operator<(int n1, BigInt const &n2)
    {
        return is_strictlyMinimum(std::to_string(n1), n2.str);
    }
    friend bool operator<(BigInt const &n1, long int n2)
    {
        return is_strictlyMinimum(n1.str, std::to_string(n2));
    }
    friend bool operator<(long int n1, BigInt const &n2)
    {
        return is_strictlyMinimum(std::to_string(n1), n2.str);
    }
    friend bool operator<(BigInt const &n1, long long int n2)
    {
        return is_strictlyMinimum(n1.str, std::to_string(n2));
    }
    friend bool operator<(long long int n1, BigInt const &n2)
    {
        return is_strictlyMinimum(std::to_string(n1), n2.str);
    }

    /* Operator {>=} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    bool operator>=(BigInt const &n)
    {
        return is_maximum(str, n.str);
    }
    friend bool operator>=(BigInt const &n1, int n2)
    {
        return is_maximum(n1.str, std::to_string(n2));
    }
    friend bool operator>=(int n1, BigInt const &n2)
    {
        return is_maximum(std::to_string(n1), n2.str);
    }
    friend bool operator>=(BigInt const &n1, long int n2)
    {
        return is_maximum(n1.str, std::to_string(n2));
    }
    friend bool operator>=(long int n1, BigInt const &n2)
    {
        return is_maximum(std::to_string(n1), n2.str);
    }
    friend bool operator>=(BigInt const &n1, long long int n2)
    {
        return is_maximum(n1.str, std::to_string(n2));
    }
    friend bool operator>=(long long int n1, BigInt const &n2)
    {
        return is_maximum(std::to_string(n1), n2.str);
    }

    /* Operator {<=} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    bool operator<=(BigInt const &n)
    {
        return is_minimum(str, n.str);
    }
    friend bool operator<=(BigInt const &n1, int n2)
    {
        return is_minimum(n1.str, std::to_string(n2));
    }
    friend bool operator<=(int n1, BigInt const &n2)
    {
        return is_minimum(std::to_string(n1), n2.str);
    }
    friend bool operator<=(BigInt const &n1, long int n2)
    {
        return is_minimum(n1.str, std::to_string(n2));
    }
    friend bool operator<=(long int n1, BigInt const &n2)
    {
        return is_minimum(std::to_string(n1), n2.str);
    }
    friend bool operator<=(BigInt const &n1, long long int n2)
    {
        return is_minimum(n1.str, std::to_string(n2));
    }
    friend bool operator<=(long long int n1, BigInt const &n2)
    {
        return is_minimum(std::to_string(n1), n2.str);
    }


    /* Operator {==} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    bool operator==(BigInt const &n)
    {
        return (*this).str == n.str;
    }
    friend bool operator==(BigInt const &n1, int n2)
    {
        return n1.str == std::to_string(n2);
    }
    friend bool operator==(int n1, BigInt const &n2)
    {
        return std::to_string(n1) == n2.str;
    }
    friend bool operator==(BigInt const &n1, long int n2)
    {
        return n1.str == std::to_string(n2);
    }
    friend bool operator==(long int n1, BigInt const &n2)
    {
        return std::to_string(n1) == n2.str;
    }
    friend bool operator==(BigInt const &n1, long long int n2)
    {
        return n1.str == std::to_string(n2);
    }
    friend bool operator==(long long int n1, BigInt const &n2)
    {
        return std::to_string(n1) == n2.str;
    }


    /* Operator {!=} Overloadings, for different kind of
    parameter for the programmer's convinience  */
    bool operator!=(BigInt const &n)
    {
        return (*this).str != n.str;
    }
    friend bool operator!=(BigInt const &n1, int n2)
    {
        return n1.str != std::to_string(n2);
    }
    friend bool operator!=(int n1, BigInt const &n2)
    {
        return std::to_string(n1) != n2.str;
    }
    friend bool operator!=(BigInt const &n1, long int n2)
    {
        return n1.str != std::to_string(n2);
    }
    friend bool operator!=(long int n1, BigInt const &n2)
    {
        return std::to_string(n1) != n2.str;
    }
    friend bool operator!=(BigInt const &n1, long long int n2)
    {
        return n1.str != std::to_string(n2);
    }
    friend bool operator!=(long long int n1, BigInt const &n2)
    {
        return std::to_string(n1) != n2.str;
    }
};

#endif