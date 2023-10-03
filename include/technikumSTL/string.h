#pragma once

#include <iostream>

namespace technikum
{
      class string
      {
           private:
                int i_length; /* make it a longer int */
                char* c_data; 
                size_t s_reservedSpace = 0;

                // returns the length of a charArray
                static int GetLength(const char* charArray);
                // reserves a X long Array and then copies charArray into it - lengthOfArray can be bigger than charArray
                static char* CopyCharArray(const char* charArray, const char lengthOfArray);
                // adds a secondCharArray to the firstCharArray without reallocating
                static char* AddToExistingCharArray(
                    char* firstCharArray, 
                    const char* secondCharArray, 
                    const int lengthOTotalCharArray,
                    const int offset);
                // reallocates two charsArrays into one
                static char* MergeTwoCharArrays(const char* firstCharArray, const char* secondCharArray);

           public:
                // constructor without parameters
                string();

                // constructor with parameters
                string(const char* charArray);

                // copy constructor
                string(const string& other);

                // copy assignment operator
                string& operator=(const string& other);

                // move constructor
                string(string&& other);

                // move assignment operator
                string& operator=(string&& other);

                // destructor without parameters
                ~string();

                // overload + operator
                string operator+(const string& other) const;

                // overload + operator : adding int to string
                string operator+(const int& other) const;

                // overload += operator
                string& operator+=(const string& other);

                // overload += operator : adding int to string
                string& operator+=(const int& other) ;

                // cast to char*
                operator const char*() const;

                // adds a char array to the currently saved char crray
                string append(const char* charArray);

                // reserves a certain size for the array so that at least n characters can be saved in the array.
                void reserve(const std::size_t LengthToReserve);

                // returns the reserved size for the array.
                // capacity here is equal to how many characters can be saved in the array.
                size_t capacity() const;

                // returns the length of the string without "\0"
                int length() const; /* make it const by adding const behind length */

                //  returns the length of the string in bytes without "\0"
                int size() const;

                // returns the saved char array
                const char* c_str() const;
      };
}
