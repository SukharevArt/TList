#include "pch.h"
#include "..\TStackList.h"



TEST(TStackList, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStackList<int> v);
}

TEST(TStackList, can_push_in_stack) {
	TStackList<int> v;
	ASSERT_NO_THROW(v.push(5));
}

TEST(TStackList, can_get_top_of_stack) {
	TStackList<int> v;
	v.push(5);
	v.push(7);
	ASSERT_NO_THROW(v.top());
}
TEST(TStackList, top_of_stack_equal) {
	TStackList<int> v;
	v.push(5);
	v.push(7);
	EXPECT_EQ(v.top(), 7);
}

TEST(TStackList, can_create_copied_stack)
{
	TStackList<int> s;
	ASSERT_NO_THROW(TStackList<int> s1(s));
}

TEST(TStackList, copied_stack_is_equal_to_source_one)
{
	TStackList<int> s;
	s.push(3);
	s.push(2);
	TStackList<int> s1(s);
	EXPECT_EQ(s1, s);
}

TEST(TStackList, copied_and_changed_stack_is_equal_to_source_one)
{
	TStackList<int> s;
	s.push(3);
	s.push(2);
	TStackList<int> s1(s);
	s1.push(4);
	EXPECT_NE(s1, s);
}

TEST(TStackList, can_push_to_not_full_stack)
{
	TStackList<int> s;
	for (int i = 0; i < 10; i++)
		ASSERT_NO_THROW(s.push(i));
}

TEST(TStackList, can_check_empty_stack)
{
	TStackList<int> s;
	EXPECT_TRUE(s.empty());
	for (int i = 0; i < 9; i++)
		s.push(i);
	EXPECT_FALSE(s.empty());
	s.push(5);
	EXPECT_FALSE(s.empty());
}

TEST(TStackList, can_pop_from_not_empty_stack)
{
	TStackList<int> s;
	for (int i = 0; i < 10; i++)
		s.push(i);
	for (int i = 0; i < 10; i++)
		ASSERT_NO_THROW(s.pop());
}

TEST(TStackList, cant_pop_from_empty_stack)
{
	TStackList<int> s;
	for (int i = 0; i < 10; i++)
		s.push(i);
	for (int i = 0; i < 10; i++)
		s.pop();
	ASSERT_ANY_THROW(s.pop());
}


