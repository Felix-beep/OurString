#include "technikumSTL/string.h"

#include <gtest/gtest.h>
#include <string.h>

TEST(TestConstructor, SimpleString)
{
	  const char* Sentence = "Hello World";

	  technikum::string OurString(Sentence);

	  ASSERT_STREQ(OurString.c_str(), Sentence);
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

TEST(TestConstructor, CopyConstructor)
{
	  technikum::string StringOne("Hello");

	  technikum::string StringTwo(StringOne);

	  StringOne.append(" World");

	  EXPECT_STRNE(StringOne.c_str(), StringTwo.c_str());
	  EXPECT_STREQ(StringTwo.c_str(), "Hello");
}

// copy constructor
TEST(TestCopyOperator, SimpleCopy)
{
	technikum::string StringOne("Hello");

	technikum::string StringTwo = StringOne;
	
	EXPECT_STREQ(StringTwo.c_str(), StringTwo.c_str());
    EXPECT_STREQ(StringTwo.c_str(), "Hello");
}

TEST(TestCopyOperator, NullptrCopy)
{
        technikum::string StringOne;

        technikum::string StringTwo = StringOne;

        EXPECT_STREQ(StringTwo.c_str(), StringTwo.c_str());
}

// move constructor
TEST(TestMove, SimpleMoveConstructor)
{
        technikum::string StringOne("Hello");

        technikum::string StringTwo = std::move(StringOne);

		EXPECT_STREQ(StringTwo.c_str(), "Hello");
        EXPECT_STREQ(StringOne.c_str(), "");
}

TEST(TestMove, SimpleMove)
{
        technikum::string StringOne("Hello");

        technikum::string StringTwo(" World");

		StringTwo = std::move(StringOne);

        EXPECT_STREQ(StringTwo.c_str(), "Hello");
        EXPECT_STREQ(StringOne.c_str(), "");
}

TEST(TestMove, SimpleMoveNullptr)
{
        technikum::string StringOne;

        technikum::string StringTwo(" World");

        StringTwo = std::move(StringOne);

        EXPECT_STREQ(StringTwo.c_str(), "");
        EXPECT_STREQ(StringOne.c_str(), "");
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

TEST(TestCapacity, SimpleCapacity)
{
	  const char* Sentence = "Hello";

	  technikum::string ALovelyString(Sentence);

	  ASSERT_EQ(ALovelyString.capacity(), 5);
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

TEST(TestNullptr, Constructor)
{
        technikum::string StringOne;

        EXPECT_STREQ(StringOne.c_str(), "");
        EXPECT_EQ(StringOne.length(), 0);
        EXPECT_EQ(StringOne.size(), 0);
        EXPECT_EQ(StringOne.capacity(), 0);
}

TEST(TestNullptr, Append)
{
    technikum::string StringOne;
    technikum::string StringTwo;

    StringOne.append(StringTwo.c_str());

    std::string StdStringOne;
    std::string StdStringTwo;

    StdStringOne.append(StdStringTwo.c_str());

    EXPECT_STREQ(StringOne.c_str(), StdStringOne.c_str());
    EXPECT_EQ(StringOne.length(), StdStringOne.length());
    EXPECT_EQ(StringOne.size(), StdStringOne.size());
    EXPECT_LE(StringOne.capacity(), StdStringOne.capacity());
}

TEST(TestNullptr, AppendFirst)
{
    technikum::string StringOne("Hello ");
    technikum::string StringTwo;

    StringOne.append(StringTwo.c_str());

    std::string StdStringOne("Hello ");
    std::string StdStringTwo;

    StdStringOne.append(StdStringTwo.c_str());

    EXPECT_STREQ(StringOne.c_str(), StdStringOne.c_str());
    EXPECT_EQ(StringOne.length(), StdStringOne.length());
    EXPECT_EQ(StringOne.size(), StdStringOne.size());
    EXPECT_LE(StringOne.capacity(), StdStringOne.capacity());
}

TEST(TestNullptr, AppendSecond)
{
    technikum::string StringOne;
    technikum::string StringTwo("World");

    StringOne.append(StringTwo.c_str());

	std::string StdStringOne;
    std::string StdStringTwo("World");

    StdStringOne.append(StdStringTwo.c_str());

    EXPECT_STREQ(StringOne.c_str(), StdStringOne.c_str());
    EXPECT_EQ(StringOne.length(), StdStringOne.length());
    EXPECT_EQ(StringOne.size(), StdStringOne.size());
    EXPECT_LE(StringOne.capacity(), StdStringOne.capacity());
}

TEST(TestPlusEqualOperator, SimplePlusEquals)
{
    technikum::string StringOne = "Hello ";
    technikum::string StringTwo = "World";

	StringOne += StringTwo;

	EXPECT_STREQ(StringOne.c_str(), "Hello World");
    EXPECT_EQ(StringOne.length(), 11);
}

TEST(TestPlusEqualOperator, PlusEqualsDoesNotChangeSource)
{
	technikum::string StringOne = "Hello ";
	technikum::string StringTwo = "World";

	StringTwo += StringOne;

	EXPECT_STREQ(StringOne.c_str(), "Hello ");
}

TEST(TestPlusOperator, SimplePlus)
{
	technikum::string StringOne = "Hello ";
	technikum::string StringTwo = "World";
	technikum::string StringThree;

	StringThree = StringOne + StringTwo;

	EXPECT_STREQ(StringThree.c_str(), "Hello World");
	EXPECT_EQ(StringThree.length(), 11);
}

TEST(TestPlusOperator, PlusString)
{
	technikum::string StringOne = "Hello ";
	technikum::string StringTwo;

	StringTwo = StringOne + "World";

	EXPECT_STREQ(StringTwo.c_str(), "Hello World");
	EXPECT_EQ(StringTwo.length(), 11);
}

TEST(TestPlusOperator, PlusDoesNotChangeSource)
{
	technikum::string StringOne = "Hello ";
	technikum::string StringTwo;
	StringTwo = StringOne + "World";

	EXPECT_STREQ(StringOne.c_str(), "Hello ");
}

TEST(TestPlusEqualOperator, PlusEqualString)
{
	technikum::string StringOne = "Hello ";
	StringOne += "World";

	EXPECT_STREQ(StringOne.c_str(), "Hello World");
	EXPECT_EQ(StringOne.length(), 11);
}

TEST(TestPlusIntOperator, PlusInt)
{
        technikum::string StringOne = "Hello ";
        technikum::string StringTwo;

        StringTwo = StringOne + 11245;

        EXPECT_STREQ(StringTwo.c_str(), "Hello 11245");
        EXPECT_EQ(StringTwo.length(), 11);
}

TEST(TestPlusIntOperator, PlusIntZero)
{
        technikum::string StringOne = "Hello ";
        technikum::string StringTwo;

        StringTwo = StringOne + 0;

        EXPECT_STREQ(StringTwo.c_str(), "Hello 0");
        EXPECT_EQ(StringTwo.length(), 7);
}

TEST(TestPlusIntOperator, PlusNegativeInt)
{
        technikum::string StringOne = "Hello ";
        technikum::string StringTwo;

        StringTwo = StringOne + (-15);

        EXPECT_STREQ(StringTwo.c_str(), "Hello -15");
        EXPECT_EQ(StringTwo.length(), 9);
}

TEST(TestPlusEqualIntOperator, PlusEqualInt)
{
        technikum::string StringOne = "Hello ";

        StringOne += 15;

        EXPECT_STREQ(StringOne.c_str(), "Hello 15");
        EXPECT_EQ(StringOne.length(), 8);
}

TEST(TestPlusEqualIntOperator, PlusEqualNegativeInt)
{
        technikum::string StringOne = "Hello ";

        StringOne += -3;

        EXPECT_STREQ(StringOne.c_str(), "Hello -3");
        EXPECT_EQ(StringOne.length(), 8);
}

TEST(TestPuts, SimplePuts)
{
	technikum::string StringOne = "Hello World";

	int Success = puts(StringOne);

	EXPECT_NE(Success, EOF);
	EXPECT_GE(Success, 0);
}