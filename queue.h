#pragma once
#include <iostream>

template <typename T>
class queue {
private:
	struct node {
		T value;
		node* next;
		node(T value, node* next = nullptr) {
			this->value = value;
			this->next = next;
		}
	};
	node* head;
	node* end;
	size_t queue_size;
public:
	queue();
	void push(T to_add);
	T pop();
	size_t size() { return queue_size; };
	~queue();
};

template <typename T> queue<T>::queue() {
	head = nullptr;
	end = nullptr;
	queue_size = 0;
}

template <typename T> void queue<T>::push(T to_add) {
	if (head == nullptr) {
		head = new node(to_add);
		end = head;
		++queue_size;
	}

	else {
		end->next = new node(to_add);
		end = end->next;
		++queue_size;
	}
}

template <typename T> T queue<T>::pop() {
	if (queue_size == 0) {
		std::cout << "queue is empty " << std::endl;
	}
	
	else if (head == end) {
		T to_return = head->value;
		delete head;
		head = nullptr;
		end = nullptr;
		--queue_size;
		return to_return;
	}

	else {
		T to_return = head->value;
		node* victim = head;
		head = head->next;
		delete victim;
		--queue_size;
		return to_return;
	}
}

template <typename T> queue<T>::~queue() {
	if (queue_size != 0) {
		if (head == end) delete head;
		else {
			node* iterator = head;
			node* victim;
			while (iterator != nullptr) {
				victim = iterator;
				iterator = iterator->next;
				delete victim;
			}
		}
	}
}