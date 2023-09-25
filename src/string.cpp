#include "technikumSTL/string.h"


namespace technikum
{

  string::string()
  {
    // create an array with just a "\0" to signal an empty string
    i_length = 0;

    c_data = nullptr;
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
    delete[] c_data;
  }

  technikum::string string::append(const char* charArray)
  {
    // get length of the charArray
    int CharLength = GetLength(charArray);

    // if there is nothing to copy
    if (CharLength < 1)
      return *this;

    // get spaced required for the chars of both arrays
    int NeededSpace = i_length + CharLength;

    size_t NeededSize = (NeededSpace + 1 ) * sizeof(char);

    // check if we already have enough space reserved
    if (s_reservedSpace < NeededSize)
    {
      // if we dont have enough space
      char* NewCharArray = MergeTwoCharArrays(c_data, charArray);

      i_length = NeededSpace;
      s_reservedSpace = NeededSpace;

      // delete the old c_data
      delete[] c_data;

      // overwrite it with the new one
      c_data = NewCharArray;
    }
    else
    {
      // if we do have enough space
      // copy the new charArray to the end of c_data
      for (int i = 0; i < NeededSpace && charArray[i] != '\0'; ++i)
      {
        c_data[i_length + i] = charArray[i];
      }

      c_data[NeededSpace] = '\0';

      i_length = NeededSpace;
    }

    return *this;
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
    delete[] c_data;

    // overwrite it with the new one
    c_data = NewCharArray;
    s_reservedSpace = LengthToReserve;
  }

  size_t string::capacity() const
  {
    return s_reservedSpace;
  }

  int string::length() const
  {
    return i_length;
  }

  int string::size() const
  {
    return i_length * sizeof(char);
  }

  const char* string::c_str() const
  {
    if (c_data == nullptr) return "";
    return c_data;
  }

  // **** HELPER FUNCTIONS ****

  // make these more save 

  // gets the length of a char array without the "\0"
  int string::GetLength(const char* charArray)
  {
    if (charArray == nullptr) return 0;

    int result = 0;
    while (charArray[result] != '\0')
    {
      result++;
    }
    return result;
  }

  char* string::CopyCharArray(const char* charArray, const char lengthOfArray)
  {
    if (charArray == nullptr)
      return nullptr;

    char* NewCharArray = new char[lengthOfArray + 1];

    int i = 0;
    for (; i < lengthOfArray && charArray[i] != '\0'; ++i)
    {
      NewCharArray[i] = charArray[i];
    }
    NewCharArray[i] = '\0';

    return NewCharArray;
  }

  char* string::AddToExistingCharArray(
      char* firstCharArray,
      const char* secondCharArray,
      const char lengthOTotalCharArray,
      const int offset)
  {
    for (int i = 0; i < lengthOTotalCharArray && secondCharArray[i] != '\0'; ++i)
    {
      firstCharArray[offset + i] = secondCharArray[i];
    }

    firstCharArray[lengthOTotalCharArray] = '\0';

    return firstCharArray;
  }

  char* string::MergeTwoCharArrays(const char* firstCharArray, const char* secondCharArray)
  {
    int lengthFirstArray = GetLength(firstCharArray);
    int lengthSecondArray = GetLength(secondCharArray);

    int combinedLength = lengthFirstArray + lengthSecondArray;
    int neededSpace = combinedLength + 1;

    if (combinedLength == 0)
      return nullptr;

    if (firstCharArray == nullptr)
    {
      return CopyCharArray(secondCharArray, combinedLength);
    }

    if (secondCharArray == nullptr)
    {
      return CopyCharArray(firstCharArray, combinedLength);
    }

    char* NewCharArray = CopyCharArray(firstCharArray, combinedLength);

    NewCharArray = AddToExistingCharArray(NewCharArray, secondCharArray, combinedLength, lengthFirstArray);

    return NewCharArray;
  }
}  
