#include "gtest/gtest.h"
#include "IntNode.h"
#include "IntSLList.h"

class IntSLListTest : public ::testing::Test
{
public:
    IntSLList sut;
};

TEST_F(IntSLListTest, newCreatedListIsEmpty)
{
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(IntSLListTest, listIsNotEmptyAfterHeadElementAddition)
{
    sut.addToHead(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(IntSLListTest, listIsNotEmptyAfterTailElementAddition)
{
    sut.addToTail(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(IntSLListTest, hasElementsOnListAfterHeadAddition)
{
    sut.addToHead(1);
    sut.addToHead(2);
    sut.addToHead(3);
    ASSERT_EQ("3 2 1", sut.toStr());
}

TEST_F(IntSLListTest, hasElementsOnListAfterTailAddition)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    ASSERT_EQ("1 2 3", sut.toStr());
}

TEST_F(IntSLListTest, returnNullptrWhenFindingInEmptyList)
{
    ASSERT_EQ(nullptr, sut.findNode(20));
}

TEST_F(IntSLListTest, returnCorrectElemWhenFindingForNonExistingItem)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    ASSERT_EQ(nullptr, sut.findNode(20));
}

TEST_F(IntSLListTest, returnCorrectElemWhenFindingForExistingItem)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    ASSERT_NE(nullptr, sut.findNode(2));
}

TEST_F(IntSLListTest, listIsEmptyAfterElementAdditionAndRemoval)
{
    sut.addToTail(1);
    sut.removeNode(1);
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(IntSLListTest, listIsEmptyAfterTwoElementAdditionsAndOneRemoval)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.removeNode(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(IntSLListTest, elemetIsCorrectlyRemovedFromFilledList)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    sut.addToTail(4);
    sut.addToTail(5);
    sut.removeNode(2);
    sut.removeNode(4);
    ASSERT_EQ("1 3 5", sut.toStr());
}

TEST_F(IntSLListTest, listIsEmptyAfterRemovingOnlyElementFromTail)
{
    sut.addToTail(1);
    sut.removeFromTail();
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(IntSLListTest, listIsNotEmptyAfterRemovingElementFromTailButListContainsMultipleElements)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.removeFromTail();
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(IntSLListTest, elementsAreCorrectlyRemovedFromTail)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    sut.removeFromTail();
    ASSERT_EQ("1 2", sut.toStr());
}

TEST_F(IntSLListTest, listIsEmptyAfterRemovingOnlyElementFromHead)
{
    sut.addToTail(1);
    sut.removeFromHead();
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(IntSLListTest, listIsNotEmptyAfterRemovingElementFromHeadButListContainsMultipleElements)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.removeFromHead();
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(IntSLListTest, elementsAreCorrectlyRemovedFromHead)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    sut.removeFromHead();
    ASSERT_EQ("2 3", sut.toStr());
}

TEST_F(IntSLListTest, shouldThrowExceptionAfterRemovingHeadElementFromEmptyList)
{
    ASSERT_THROW(sut.removeFromHead(), std::string);
}

TEST_F(IntSLListTest, shouldThrowExceptionAfterRemovingTailElementFromEmptyList)
{
    ASSERT_THROW(sut.removeFromTail(), std::string);
}
