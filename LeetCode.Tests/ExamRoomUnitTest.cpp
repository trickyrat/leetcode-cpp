#include "pch.h"

#include "../LeetCode/ExamRoom.cpp"

TEST(ExamRoomUnitTest, OperationTest) { 
	ExamRoom er(10);
  EXPECT_EQ(0, er.seat());
  EXPECT_EQ(9, er.seat());
  EXPECT_EQ(4, er.seat());
  EXPECT_EQ(2, er.seat());
  er.leave(4);
  EXPECT_EQ(5, er.seat());
}