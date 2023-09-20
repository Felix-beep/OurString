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
            string();
            string(const char* charArray);
            ~string();

            void append(const char* charArray);

            void reserve(const std::size_t LengthToReserve);

            size_t capacity();

            int length();
            
            int size();

            char* c_str();

            char** c_str_addr();
    };
}
