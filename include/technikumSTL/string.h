#pragma once

#include <iostream>

namespace technikum
{
      class string
      {
           private:
                int i_length;
                char* c_data;
                size_t s_reservedSpace = 0;

           public:
                // constructor without parameters
                string();

                // constructor with parameters
                string(const char* charArray);

                // copyconstructor
                string(const string& other);

                // destructor without parameters
                ~string();

                // adds a char array to the currently saved char crray
                void append(const char* charArray);

                // reserves a certain size for the array so that at least n characters can be saved in the array.
                void reserve(const std::size_t LengthToReserve);

                // returns the reserved size for the array.
                // capacity here is equal to how many characters can be saved in the array.
                size_t capacity();

                // returns the length of the string without "\0"
                int length();

                //  returns the length of the string in bytes without "\0"
                int size();

                // returns the saved char array
                char* c_str();
      };
}
