#include "gtest/gtest.h"
#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"

class SingleLinkedListTest : public ::testing::Test
{
public:
    SingleLinkedList<int> sut;
};

TEST_F(SingleLinkedListTest, newCreatedListIsEmpty)
{
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(SingleLinkedListTest, listIsNotEmptyAfterHeadElementAddition)
{
    sut.addToHead(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(SingleLinkedListTest, listIsNotEmptyAfterTailElementAddition)
{
    sut.addToTail(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(SingleLinkedListTest, hasElementsOnListAfterHeadAddition)
{
    sut.addToHead(1);
    sut.addToHead(2);
    sut.addToHead(3);
    ASSERT_EQ("3 2 1", sut.toStr());
}

TEST_F(SingleLinkedListTest, hasElementsOnListAfterTailAddition)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    ASSERT_EQ("1 2 3", sut.toStr());
}

TEST_F(SingleLinkedListTest, returnNullptrWhenFindingInEmptyList)
{
    ASSERT_EQ(nullptr, sut.findNode(20));
}

TEST_F(SingleLinkedListTest, returnCorrectElemWhenFindingForNonExistingItem)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    ASSERT_EQ(nullptr, sut.findNode(20));
}

TEST_F(SingleLinkedListTest, returnCorrectElemWhenFindingForExistingItem)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    ASSERT_NE(nullptr, sut.findNode(2));
}

TEST_F(SingleLinkedListTest, listIsEmptyAfterElementAdditionAndRemoval)
{
    sut.addToTail(1);
    sut.removeNode(1);
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(SingleLinkedListTest, listIsEmptyAfterTwoElementAdditionsAndOneRemoval)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.removeNode(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(SingleLinkedListTest, elemetIsCorrectlyRemovedFromFilledList)
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

TEST_F(SingleLinkedListTest, listIsEmptyAfterRemovingOnlyElementFromTail)
{
    sut.addToTail(1);
    sut.removeFromTail();
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(SingleLinkedListTest, listIsNotEmptyAfterRemovingElementFromTailButListContainsMultipleElements)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.removeFromTail();
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(SingleLinkedListTest, elementsAreCorrectlyRemovedFromTail)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    sut.removeFromTail();
    ASSERT_EQ("1 2", sut.toStr());
}

TEST_F(SingleLinkedListTest, listIsEmptyAfterRemovingOnlyElementFromHead)
{
    sut.addToTail(1);
    sut.removeFromHead();
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(SingleLinkedListTest, listIsNotEmptyAfterRemovingElementFromHeadButListContainsMultipleElements)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.removeFromHead();
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(SingleLinkedListTest, elementsAreCorrectlyRemovedFromHead)
{
    sut.addToTail(1);
    sut.addToTail(2);
    sut.addToTail(3);
    sut.removeFromHead();
    ASSERT_EQ("2 3", sut.toStr());
}

TEST_F(SingleLinkedListTest, shouldThrowExceptionAfterRemovingHeadElementFromEmptyList)
{
    ASSERT_THROW(sut.removeFromHead(), std::string);
}

TEST_F(SingleLinkedListTest, shouldThrowExceptionAfterRemovingTailElementFromEmptyList)
{
    ASSERT_THROW(sut.removeFromTail(), std::string);
}
