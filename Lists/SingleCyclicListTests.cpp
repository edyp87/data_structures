#include "gtest/gtest.h"
#include "SingleCyclicList.h"

class SingleCyclicListTest : public ::testing::Test
{
public:
    SingleCyclicList<int> sut;
};

TEST_F(SingleCyclicListTest, newCreatedListIsEmpty)
{
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(SingleCyclicListTest, listIsNotEmptyAfterElementAddition)
{
    sut.add(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(SingleCyclicListTest, hasElementsOnListAfterAddition)
{
    sut.add(1);
    sut.add(2);
    sut.add(3);
    ASSERT_EQ("1 2 3", sut.toStr());
}

TEST_F(SingleCyclicListTest, returnNullptrWhenFindingInEmptyList)
{
    ASSERT_EQ(nullptr, sut.findNode(20));
}

TEST_F(SingleCyclicListTest, returnCorrectElemWhenFindingForNonExistingItem)
{
    sut.add(1);
    sut.add(2);
    sut.add(3);
    ASSERT_EQ(nullptr, sut.findNode(20));
}

TEST_F(SingleCyclicListTest, returnCorrectElemWhenFindingForExistingItem)
{
    sut.add(1);
    sut.add(2);
    sut.add(3);
    ASSERT_NE(nullptr, sut.findNode(2));
}

TEST_F(SingleCyclicListTest, listIsEmptyAfterElementAdditionAndRemoval)
{
    sut.add(1);
    sut.removeNode(1);
    ASSERT_TRUE(sut.isEmpty());
}

TEST_F(SingleCyclicListTest, listIsEmptyAfterTwoElementAdditionsAndOneRemoval)
{
    sut.add(1);
    sut.add(2);
    sut.removeNode(1);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(SingleCyclicListTest, 1listIsEmptyAfterTwoElementAdditionsAndOneRemoval)
{
    sut.add(1);
    sut.add(2);
    ASSERT_FALSE(sut.isEmpty());
}

TEST_F(SingleCyclicListTest, elemetIsCorrectlyRemovedFromFilledList)
{
    sut.add(1);
    sut.add(2);
    sut.add(3);
    sut.add(4);
    sut.add(5);
    ASSERT_EQ("1 2 3 4 5", sut.toStr());
    sut.removeNode(2);
    sut.removeNode(4);
    ASSERT_EQ("1 3 5", sut.toStr());
    sut.removeNode(5);
    ASSERT_EQ("1 3", sut.toStr());
}
