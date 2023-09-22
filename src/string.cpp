#include "technikumSTL/string.h"


namespace technikum
{
  /* make these private functions */
  static int GetLength(const char* charArray);
  static char* CopyCharArray(const char* charArray, const char lengthOfArray);
  static void CopyCharArrayWithOffSet(
      char* outputCharArray,
      const char* inputCharArray,
      const char lengthOfInputCharArray,
      const int offset);

  string::string()
  {
    // create an array with just a "\0" to signal an empty string
    i_length = 0;

    /* make it point to a null ptr and not just "\0"*/
    c_data = new char[1];
    c_data[0] = '\0';
    s_reservedSpace = 0;
  }

  string::string(const char* charArray)
  {

    // get length of the charArray
    i_length = GetLength(charArray);

    s_reservedSpace = i_length;

    // copy charArray to c_data
    c_data = CopyCharArray(charArray, i_length);
  }

  string::string(const string& other)
  {
    i_length = other.i_length;
    s_reservedSpace = other.s_reservedSpace;

    c_data = CopyCharArray(other.c_data, i_length);
  }

  string::~string()
  {
    /* always use delete[] so you don't only delete the value the pointer */
    delete c_data;
  }

  void string::append(const char* charArray)
  {
    // get length of the charArray
    int Charlength = GetLength(charArray);

    // if there is nothing to copy
    if (Charlength < 1)
      return;

    // get spaced required for the chars of both arrays
    int NeededSpace = i_length + Charlength;

    size_t NeededSize = NeededSpace * sizeof(char);

    // check if we already have enough space reserved
    if (s_reservedSpace < NeededSize)
    {
      // if we dont have enough space
      char* NewCharArray = new char[NeededSpace + 1];

      // copy c_data to the a new place
      CopyCharArrayWithOffSet(NewCharArray, c_data, i_length, 0);

      // copy charArray to the a new place
      CopyCharArrayWithOffSet(NewCharArray, charArray, Charlength, i_length);

      NewCharArray[NeededSpace] = '\0';

      i_length = i_length + Charlength;
      s_reservedSpace = NeededSpace;

      // delete the old c_data
      delete c_data;

      // overwrite it with the new one
      c_data = NewCharArray;
    }
    else
    {
      // if we do have enough space
      // copy the new charArray to the end of c_data

      CopyCharArrayWithOffSet(c_data, charArray, Charlength, i_length);

      c_data[NeededSpace] = '\0';

      i_length = NeededSpace;
    }
  }

  void string::reserve(const std::size_t LengthToReserve)
  {
    // check if we already have more space reserved
    // allowing people to shorten the reserved space would lead to loss of chars and the ending "\0"
    if (LengthToReserve <= s_reservedSpace)
      return;

    // get enough space to fit n chars and the ending "\0"
    size_t LengthWith0 = LengthToReserve + 1 * sizeof(char);
    char* NewCharArray;

    // copy c_data to the a new place
    NewCharArray = CopyCharArray(c_data, LengthToReserve);

    // delete the old c_data
    delete c_data;

    // overwrite it with the new one
    c_data = NewCharArray;
    s_reservedSpace = LengthToReserve;
  }

  size_t string::capacity()
  {
    return s_reservedSpace;
  }

  int string::length()
  {
    return i_length;
  }

  int string::size()
  {
    return i_length * sizeof(char);
  }

  char* string::c_str()
  {
    return c_data;
  }

  // **** HELPER FUNCTIONS ****

  // make these more save 

  // gets the length of a char array without the "\0"
  static int GetLength(const char* charArray)
  {
    int result = 0;
    while (charArray[result] != '\0')
    {
      result++;
    }
    return result;
  }

  static char* CopyCharArray(const char* charArray, const char lengthOfArray)
  {
    char* NewCharArray = new char[lengthOfArray + 1];

    for (int i = 0; i < lengthOfArray; ++i)
    {
      NewCharArray[i] = charArray[i];
    }
    NewCharArray[lengthOfArray] = '\0';

    return NewCharArray;
  }

  static void CopyCharArrayWithOffSet(
      char* outputCharArray,
      const char* inputCharArray,
      const char lengthOfInputCharArray,
      const int offset)
  {
    for (int i = 0; i < lengthOfInputCharArray; ++i)
    {
      outputCharArray[offset + i] = inputCharArray[i];
    }
  }
}  
