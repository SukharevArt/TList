#include "pch.h"
#include "..\TQueueList.h"


TEST(TQueueList, can_create_queue) {
	ASSERT_NO_THROW(TQueueList<int> q);
}

TEST(TQueueList, can_push_into_queue) {
	TQueueList<int> q;
	ASSERT_NO_THROW(q.push(39));
}

TEST(TQueueList, can_pop_from_queue) {
	TQueueList<int > q;
	q.push(30);
	q.push(32);
	int y;
	ASSERT_NO_THROW(y = q.pop());
	EXPECT_EQ(y, 30);
}

TEST(TQueueList, cant_pop_from_empty_queue) {
	TQueueList<int> q;
	ASSERT_ANY_THROW(q.pop());
}

TEST(TQueueList, can_get_front_queue) {
	TQueueList<int > q;
	q.push(30);
	q.push(32);
	ASSERT_NO_THROW(q.front());
	EXPECT_EQ(q.front(), 30);
}

TEST(TQueueList, can_check_empty_queue) {
	TQueueList<int > q;
	EXPECT_TRUE(q.empty());
	for (int i = 0; i < 10; i++) {
		q.push(i + 2);
		EXPECT_FALSE(q.empty());
	}
}

TEST(TQueueList, can_copy_queue) {
	TQueueList<int> q;
	q.push(4);
	q.push(5);
	q.push(0);
	q.push(2);
	TQueueList<int> q1;
	ASSERT_NO_THROW(TQueueList<int> q2(q));
	TQueueList<int> q2(q);
	ASSERT_NO_THROW(q1 = q);
	while (!q.empty()) {
		EXPECT_EQ(q1.front(), q.front());
		EXPECT_EQ(q2.front(), q.front());
		q.pop(); q1.pop(); q2.pop();
	}
}

TEST(TQueueList, copy_queue_have_own_memory) {
	TQueueList<int> q;
	q.push(50);
	q.push(6);
	TQueueList<int > q1, q2(q);
	q1 = q;
	q.pop();
	EXPECT_NE(q1.front(), q.front());
	EXPECT_NE(q2.front(), q.front());
	EXPECT_EQ(q1.front(), 50);
	EXPECT_EQ(q2.front(), 50);
}

