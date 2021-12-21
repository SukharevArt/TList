#pragma once

#include<iostream>

template<class T>
struct TSNode {
	T Val;
	TSNode* pNext;
};

template<class T>
class TStackList {
private:
	TSNode<T>* pFirst;	
public:
	TStackList() {
		pFirst = nullptr;
	}
	TStackList(const TStackList<T>& a) {
		pFirst = nullptr;
		TSNode<T>* newNode;
		TSNode<T>* anode = a.pFirst;
		if (anode != nullptr) {
			newNode = new TSNode<T>;
			newNode->Val = anode->Val;
			newNode->pNext = nullptr;
			pFirst = newNode;
			TSNode<T>* t=pFirst;
			anode = anode->pNext;
			while (anode != nullptr) {
				newNode = new TSNode<T>;
				newNode->Val = anode->Val;
				newNode->pNext = nullptr;
				t->pNext = newNode;
				anode = anode->pNext;
				t = t->pNext;
			}
		}
	}
	TStackList& operator=(const TStackList& a) {
		TSNode<T>* e;
		while (pFirst != nullptr) {
			e = pFirst;
			pFirst = pFirst->pNext;
			delete e;
		}
		TSNode<T>* newNode;
		TSNode<T>* anode = a.pFirst;
		if (anode != nullptr) {
			newNode = new TSNode<T>;
			newNode->Val = anode->Val;
			newNode->pNext = nullptr;
			pFirst = newNode;
			TSNode<T>* t = pFirst;
			anode = anode->pNext;
			while (anode != nullptr) {
				newNode = new TSNode<T>;
				newNode->Val = anode->Val;
				newNode->pNext = nullptr;
				t->pNext = newNode;
				anode = anode->pNext;
				t = t->pNext;
			}
		}
		return *this;
	}
	~TStackList() {
		TSNode<T>* e;
		while (pFirst != nullptr) {
			e = pFirst;
			pFirst = pFirst->pNext;
			delete e;
		}
	}
	bool empty() {
		return pFirst == nullptr;
	}
	bool full() {
		TSNode<T>* node = (TSNode<T>*)malloc(sizeof(TSNode<T>));
		//TSNode<T>* node = new TSNode<T>;
		bool r = (node == nullptr);
		if (!r)
			delete node;
		return r;
	}
	void push(T _val) {
		TSNode<T>* node = (TSNode<T>*)malloc(sizeof(TSNode<T>));
		//TSNode<T>* node = new TSNode<T>;
		if (node == nullptr)
			throw "not_enough_memory";
		node->Val = _val;
		node->pNext = pFirst;
		pFirst = node;
	}
	T pop() {
		if (empty()) {
			throw "Empty_Stack";
		}
		T _val;
		_val = pFirst->Val;
		TSNode<T>* t = pFirst;
		pFirst = pFirst->pNext;
		delete t;
		return _val;
	}
	T top() {
		if (empty()) {
			throw "Empty_Stack";
		}
		return pFirst->Val;
	}

	bool operator==(const TStackList<T>& a) const {
		TSNode<T>* t1,*t2;
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
	bool operator!=(const TStackList<T>& a) const {
		TSNode<T>* t1, *t2;
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