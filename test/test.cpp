#include  <../thirdparty/ctest.h>
#include <../src/libgeometry/func.h>

// Given

CTEST(parsing_suite, IsFingCircle)
{
    const std::string str = "circle(2 2, 3.1)";
    unsigned int i = 0;
    // When
    const int result = IsFingCircle(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, error1)
{
    const std::string er1 = "circe(2 2, 3.1)";
    unsigned int i = 0;
    // When
    const int result = IsFingCircle(er1, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingLeftBracket)
{
    const std::string str = "circle(2 2, 3.1)";
    unsigned int i = 6;
    // When
    const int result = IsFingLeftBracket(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, error2)
{
    const std::string er2 = "circle)2 2, 3.1)";
    unsigned int i = 6;
    // When
    const int result = IsFingLeftBracket(er2, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingFirstDigit1)
{
    std ::string point1 = "";
    const std::string str = "circle(2 2, 3.1)";
    unsigned int i = 7;
    // When
    const int result = IsFingFirstDigit1(str, i, point1);
    point1 = "";

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, error3)
{
    const std::string er3 = "circle(f 2, 3.1)";
    std ::string point1 = "";
    unsigned int i = 7;
    // When
    const int result = IsFingFirstDigit1(er3, i, point1);
    point1 = "";

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingSecDigit2)
{
    std ::string point1 = "";
    const std::string str = "circle(2 2, 3.1)";
    unsigned int i = 9;
    // When
    const int result = IsFingSecDigit2(str, i, point1);
    point1 = "";

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

const std::string er4 = "circle(2 f, 3.1)";

CTEST(parsing_suite, error4)
{
    std ::string point1 = "";
    const std::string er4 = "circle(2 f, 3.1)";
    unsigned int i = 9;
    // When
    const int result = IsFingFirstDigit1(er4, i, point1);
    point1 = "";

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingLeftComma)
{
    const std::string str = "circle(2 2, 3.1)";
    unsigned int i = 10;
    // When
    const int result = IsFingLeftComma(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, error5)
{
    const std::string er5 = "circle(2 2. 3.1)";
    unsigned int i = 10;
    // When
    const int result = IsFingLeftComma(er5, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingLeftDigit3)
{
    std ::string point1 = "";
    const std::string str = "circle(2 2, 3.1)";
    unsigned int i = 12;
    // When
    const int result = IsFingLeftDigit3(str, i, point1);
    point1 = "";

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, error6)
{
    std ::string point1 = "";
    const std::string er6 = "circle(2 2, 3g1)";
    unsigned int i = 12;
    // When
    const int result = IsFingLeftDigit3(er6, i, point1);
    point1 = "";

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, IsFingRightBracket)
{
    const std::string str = "circle(2 2, 3.1)";
    unsigned int i = 15;
    // When
    const int result = IsFingRightBracket(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

const std::string er7 = "circle(2 2, 3.1(";

CTEST(parsing_suite, error7)
{
    const std::string er7 = "circle(2 2, 3.1(";
    unsigned int i = 15;
    // When
    const int result = IsFingRightBracket(er7, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, UnexToken)
{
    const std::string str = "circle(2 2, 3.1)";
    unsigned int i = 16;
    // When
    const int result = UnexToken(str, i);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(parsing_suite, error8)
{
    const std::string er8 = "circle(2 2, 3.1) o";
    unsigned int i = 16;
    // When
    const int result = UnexToken(er8, i);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}



