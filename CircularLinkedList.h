#pragma once
#include <iostream>

/**
 * @brief Creating a Linked List
 * 
 * @tparam T 
 */
template <class T>
struct CircularLinkedList {
        template <class S>
        /**
         * @brief Node struct that has the data and the next key.
         * 
         */
        struct Node {
            S data;
            Node<S> *next;

            Node() :next(NULL) {}
            Node(S data) :next(NULL), data(data) {}
        };
        
        Node<T> *head;
        Node<T> *tail;

        /**
         * @brief Construct a new Circular Linked List object
         * makes the head and tail null
         * 
         */
        CircularLinkedList() :head(NULL), tail(NULL) {}

        /**
         * @brief Destroyes the Linked List and deletes the array.
         * 
         */
        ~CircularLinkedList() {
            Node<T> *del;
            while (this->head != this->tail){
                del = this->head;
                this->head = this->head->next;
                delete [] del;
            }
            delete [] this->tail;
        }

        /**
         * @brief Function to insert at the front of the Linked List.
         * 
         * @param data 
         */
        void insert_front(T data){
            Node<T> *temp = this->head;
            this->head = new Node<T>(data);
            this->head->next = temp;
            this->tail->next = this->head;
        }

        /**
         * @brief Function to insert at the back of the Linked List
         * 
         * @param data 
         */
        void insert_back(T data){
            if(this->head == NULL){
                this->head = new Node<T>(data);
                this->tail = this->head;
                this->head->next = this->head;
                return;
            }

            this->tail->next = new Node<T>(data);
            this->tail = this->tail->next;
            this->tail->next = this->head;
        }

        /**
         * @brief Function to print the linked list.
         * 
         */
        void print(){
            Node<T> *it = this->head;
            while (it != this->tail) {
                std::cout << it->data;
                it = it->next;
            }
            std::cout << this->tail->data;
        }
};