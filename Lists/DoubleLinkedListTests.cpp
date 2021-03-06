#include "gtest/gtest.h"
#include "DoubleLinkedNode.h"
#include "DoubleLinkedList.h"

class DoubleLinkedListTest : public ::testing::Test
{
public:
    DoubleLinkedList<int> sut;
};

TEST_F(DoubleLinkedListTest, newCreatedListIsEmpty)
{
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(DoubleLinkedListTest, listIsNotEmptyAfterHeadElementAddition)
{
    sut.addToHead(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(DoubleLinkedListTest, listIsNotEmptyAfterTailElementAddition)
{
    sut.addToTail(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(DoubleLinkedListTest, hasElementsOnListAfterHeadAddition)
{
    sut.addToHead(1);
    sut.addToHead(2);
    sut.addToHead(3);
    ASSERT_EQ("3 2 1", sut.toStr());
}

TEST_F(DoubleLinkedListTest, hasElementsOnListAfterTailAddition)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    ASSERT_EQ("1 2 3", sut.toStr());
}

TEST_F(DoubleLinkedListTest, returnNullptrWhenFindingInEmptyList)
{
    ASSERT_EQ(nullptr, sut.findNode(20));
}

TEST_F(DoubleLinkedListTest, returnCorrectElemWhenFindingForNonExistingItem)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    ASSERT_EQ(nullptr, sut.findNode(20));
}

TEST_F(DoubleLinkedListTest, returnCorrectElemWhenFindingForExistingItem)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    ASSERT_NE(nullptr, sut.findNode(2));
}

TEST_F(DoubleLinkedListTest, listIsEmptyAfterElementAdditionAndRemoval)
{
    sut.addToTail(1);
    sut.removeNode(1);
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(DoubleLinkedListTest, listIsEmptyAfterTwoElementAdditionsAndOneRemoval)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.removeNode(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(DoubleLinkedListTest, elemetIsCorrectlyRemovedFromFilledList)
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

TEST_F(DoubleLinkedListTest, listIsEmptyAfterRemovingOnlyElementFromTail)
{
    sut.addToTail(1);
    sut.removeFromTail();
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(DoubleLinkedListTest, listIsNotEmptyAfterRemovingElementFromTailButListContainsMultipleElements)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.removeFromTail();
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(DoubleLinkedListTest, elementsAreCorrectlyRemovedFromTail)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    sut.removeFromTail();
    ASSERT_EQ("1 2", sut.toStr());
}

TEST_F(DoubleLinkedListTest, listIsEmptyAfterRemovingOnlyElementFromHead)
{
    sut.addToTail(1);
    sut.removeFromHead();
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(DoubleLinkedListTest, listIsNotEmptyAfterRemovingElementFromHeadButListContainsMultipleElements)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.removeFromHead();
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(DoubleLinkedListTest, elementsAreCorrectlyRemovedFromHead)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    sut.removeFromHead();
    ASSERT_EQ("2 3", sut.toStr());
}

TEST_F(DoubleLinkedListTest, shouldThrowExceptionAfterRemovingHeadElementFromEmptyList)
{
    ASSERT_THROW(sut.removeFromHead(), std::string);
}

TEST_F(DoubleLinkedListTest, shouldThrowExceptionAfterRemovingTailElementFromEmptyList)
{
    ASSERT_THROW(sut.removeFromTail(), std::string);
}
