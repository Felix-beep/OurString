#include "technikumSTL/string.h"


namespace technikum
{
    string::string()
    {
        i_length = 0;
        c_data = new char[1];
        c_data[0] = '\0';
        s_reservedSpace = 0;
    }

    string::string(const char* charArray)
    {
        i_length = 0;

        while (charArray[i_length] != '\0')
        {
            i_length++;
        }

        int i_arrayLength = i_length + 1;
        c_data = new char[i_arrayLength];
        s_reservedSpace = i_arrayLength;

        for (int i = 0; i < i_length; ++i)
        {
            c_data[i] = charArray[i];
        }
        c_data[i_length] = '\0';
    }

    // Destruktor
    string::~string()
    {
        delete c_data;
    }

    void string::append(const char* charArray)
    {  // mehrere Strings anhängen
        int Charlength = 0;

        while (charArray[Charlength] != '\0')
        {
            Charlength++;  // die Länge vom zweiten Array
        }

        if (Charlength < 1)
        return;

        int NeededSpace = i_length + Charlength;

        size_t NeededSize = NeededSpace * sizeof(char);

        if (s_reservedSpace < NeededSize)
        {
            char* NewCharArray = new char[NeededSpace + 1];  // [Array + newArray + /0]

            for (int i = 0; i < i_length; ++i)
            {
                NewCharArray[i] = c_data[i];
            }

            for (int i = 0; i < Charlength; ++i)
            {
                NewCharArray[i_length + i] = charArray[i];
            }

            i_length = i_length + Charlength;

            NewCharArray[NeededSpace] = '\0';

            delete c_data;

            s_reservedSpace = NeededSpace;

            c_data = NewCharArray;
        }
        else
        {
            // nicht neu allokieren
            for (int i = 0; i < Charlength; ++i)
            {
                c_data[i_length + i] = charArray[i];
            }

            i_length = i_length + Charlength;

            c_data[i_length] = '\0';
        }
    }

    void string::reserve(const std::size_t LengthToReserve)
    {
        if (LengthToReserve <= s_reservedSpace)
            return;

        size_t LengthWith0 = LengthToReserve + 1 * sizeof(char);
        char* NewCharArray = new char[LengthWith0];

        for (int i = 0; i < i_length; ++i)
        {
            NewCharArray[i] = c_data[i];
        }

        NewCharArray[i_length] = '\0';

        delete c_data;

        c_data = NewCharArray;
        s_reservedSpace = LengthToReserve;
    }

    size_t string::capacity()
    {
        return s_reservedSpace;
    }

    int string::length()
    {  // Zeichenlänge ohne /0
        return i_length;
    }

    int string::size()
    {  // Anzahl an bytes
        return i_length * 1;
    }

    char* string::c_str()
    {  // Länge des Char Arrays
        return c_data;
    }

    char** string::c_str_addr()
    {
        return &c_data;
    }
}
