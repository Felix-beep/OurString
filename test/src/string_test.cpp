#include "technikumSTL/string.h"

#include <gtest/gtest.h>
#include <string.h>

TEST(TmpAddTest, CheckValues)
{
    ASSERT_EQ(3, 3);
    EXPECT_TRUE(true);
}

TEST(TestConstructor, SimpleString)
{
    const char* Sentence = "Hello World";

    technikum::string OurString(Sentence);

    ASSERT_EQ(std::strcmp(OurString.c_str(), Sentence), 0);
}


TEST(TestConstructor, EmptyString)
{
    technikum::string OurString;

    EXPECT_STREQ(OurString.c_str(), "");
    EXPECT_EQ(OurString.length(), 0);
    EXPECT_EQ(OurString.capacity(), 0);
} 

TEST(TestConstructor, ComparedToStdString)
{
    std::string StdString("Hello");
    technikum::string OurString("Hello");

    ASSERT_EQ(std::strcmp(OurString.c_str(), StdString.c_str()), 0);
}

TEST(TestConstructor, StringNotPointer)
{
    const char* Sentence = "Hello World";

    technikum::string OurString(Sentence);

    ASSERT_NE(OurString.c_str(), Sentence);
}

TEST(TestAppend, SimpleAppend)
{
    technikum::string OurString("Hello ");

    OurString.append("World");

    ASSERT_STREQ(OurString.c_str(), "Hello World");
}

TEST(TestAppend, ComparedToStdString)
{ 
    std::string StdString("Hello ");
    technikum::string OurString("Hello ");

    StdString.append("World");
    OurString.append("World");

    ASSERT_STREQ(OurString.c_str(), StdString.c_str());
}

TEST(TestLength, SimpleLength)
{
    technikum::string OurString("Hello World");

    ASSERT_EQ(OurString.length(), 11);
}

TEST(TestLength, ComparedToStdString)
{
    std::string StdString("Hello World");
    technikum::string OurString("Hello World");

    ASSERT_EQ(OurString.length(), StdString.length());
}

TEST(TestLength, LengthAfterAppend)
{
    std::string StdString("Hello ");
    technikum::string OurString("Hello ");

    StdString.append("World");
    OurString.append("World");

    ASSERT_EQ(OurString.length(), StdString.length());
}

TEST(TestReserve, SimpleReserve)
{
    const int SpaceToReserve = 11;

    technikum::string OurString;

    OurString.reserve(SpaceToReserve);  

    ASSERT_EQ(OurString.capacity(), SpaceToReserve);
}

TEST(TestReserve, SimpleReserveComparedToStd)
{
    const int SpaceToReserve = 11;

    technikum::string OurString;
    std::string StdString;

    OurString.reserve(SpaceToReserve);
    StdString.reserve(SpaceToReserve);

    // less or equal
    // std takes more memory space
    ASSERT_LE(OurString.capacity(), StdString.capacity());
}

TEST(TestReserve, ReserveWithAppendBelowLimit)
{
    const char* Sentence = "Hello";

    technikum::string ALovelyString(Sentence);

    ALovelyString.reserve(12);  // Zeichenanzahl Hello World ohne /0

    ALovelyString.append(" World");

    EXPECT_STREQ(ALovelyString.c_str(), "Hello World");
    EXPECT_EQ(ALovelyString.capacity(), 12);
}

TEST(TestReserve, ReserveWithAppendAboveLimit)
{
    const char* Sentence = "Hello";

    technikum::string ALovelyString(Sentence);

    ALovelyString.reserve(7);  // Zeichenanzahl Hello World ohne /0

    ALovelyString.append(" World");

    EXPECT_STREQ(ALovelyString.c_str(), "Hello World");
    EXPECT_EQ(ALovelyString.capacity(), 11);
}

TEST(TestCapacity, Capacity)
{
    const char* Sentence = "Hello";

    technikum::string ALovelyString(Sentence);

    ASSERT_EQ(ALovelyString.capacity(), 6);
  }

TEST(TestCapacity, CapacityWithAppend)
{
    const char* Sentence = "Hello";

    technikum::string ALovelyString(Sentence);

    ALovelyString.append(" World");

    ASSERT_EQ(ALovelyString.capacity(), 11);
}

TEST(TestCapacity, ComparedToStdString)
{
    std::string StdString("Hello ");
    technikum::string OurString("Hello ");

    StdString.append("World");
    OurString.append("World");

    // less or equal
    // std takes more memory space
    EXPECT_LE(OurString.capacity(), StdString.capacity());
}