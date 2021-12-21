#pragma once

template<class T>
struct TQNode {
	T Val;
	TQNode* pNext;
};

template<class T>
class TQueueList {
private:
	TQNode<T> *pFirst, *pLast;
public:
	TQueueList() {
		pFirst = pLast = nullptr;
	}
	TQueueList(const TQueueList& a) {
		pFirst = nullptr;
		pLast = nullptr;
		TQNode<T>* newNode;
		TQNode<T>* anode = a.pFirst;
		if (anode != nullptr) {
			newNode = new TQNode<T>;
			newNode->Val = anode->Val;
			newNode->pNext = nullptr;
			pFirst = newNode;
			TQNode<T>* t = pFirst;
			anode = anode->pNext;
			while (anode != nullptr) {
				newNode = new TQNode<T>;
				newNode->Val = anode->Val;
				newNode->pNext = nullptr;
				t->pNext = newNode;
				anode = anode->pNext;
				t = t->pNext;
			}
			pLast = t;
		}
	}
	TQueueList& operator=(const TQueueList& a) {
		pFirst = nullptr;
		pLast = nullptr;
		TQNode<T>* newNode;
		TQNode<T>* anode = a.pFirst;
		if (anode != nullptr) {
			newNode = new TQNode<T>;
			newNode->Val = anode->Val;
			newNode->pNext = nullptr;
			pFirst = newNode;
			TQNode<T>* t = pFirst;
			anode = anode->pNext;
			while (anode != nullptr) {
				newNode = new TQNode<T>;
				newNode->Val = anode->Val;
				newNode->pNext = nullptr;
				t->pNext = newNode;
				anode = anode->pNext;
				t = t->pNext;
			}
			pLast = t;
		}
		return *this;
	}
	~TQueueList() {
		TQNode<T>* e;
		while (pFirst != nullptr) {
			e = pFirst;
			pFirst = pFirst->pNext;
			delete e;
		}
	}
	bool full() {
		TQNode<T>* node = (TQNode<T>*)malloc(sizeof(TQNode<T>));
		//TQNode<T>* node = new TQNode<T>;
		bool r = (node == nullptr);
		if (r)
			delete node;
		return r;
	}
	bool empty() {
		return pFirst == nullptr;
	}
	void push(T _val) {

		TQNode<T>* node = (TQNode<T>*)malloc(sizeof(TQNode<T>));
		//TQNode<T>* node = new TQNode<T>;
		if (node == nullptr)
			throw "not_enough_memory";
		node->Val = _val;
		node->pNext = nullptr;
		if (pLast != nullptr) {
			pLast->pNext = node;
		}
		else {
			pFirst = node;
		}
		pLast = node;
	}
	T pop() {
		if (empty())
			throw "Empty_Queue";
		TQNode<T>* t;
		T _val = pFirst->Val;
		t = pFirst;
		pFirst = pFirst->pNext;
		delete t;
		if (pFirst == nullptr)
			pLast = nullptr;
		return _val;
	}
	T front() {
		if (empty())
			throw "Empty_Queue";
		return pFirst->Val;
	}
	T back() {
		if (empty())
			throw "Empty_Queue";
		return pLast->Val;
	}


	bool operator==(const TQueueList<T>& a) const {
		TQNode<T>* t1, *t2;
		t1 = a.pFirst;
		t2 = pFirst;
		while (t1 != nullptr && t2 != nullptr) {
			if (t1->Val != t2->Val)
				return 0;
			t1 = t1->pNext;
			t2 = t2->pNext;
		}
		if (t1 != nullptr || t2 != nullptr)
			return 0;
		return 1;
	}
	bool operator!=(const TQueueList<T>& a) const {
		TQNode<T>* t1, *t2;
		t1 = a.pFirst;
		t2 = pFirst;
		while (t1 != nullptr && t2 != nullptr) {
			if (t1->Val != t2->Val)
				return 1;
			t1 = t1->pNext;
			t2 = t2->pNext;
		}
		if (t1 != nullptr || t2 != nullptr)
			return 1;
		return 0;
	}
};
