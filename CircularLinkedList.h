#pragma once
#include <iostream>

template <class T>
struct CircularLinkedList {
        template <class S>
        struct Node {
            S data;
            Node<S> *next;

            Node() :next(NULL) {}
            Node(S data) :next(NULL), data(data) {}
        };
        
        Node<T> *head;
        Node<T> *tail;

        CircularLinkedList() :head(NULL), tail(NULL) {}

        ~CircularLinkedList() {
            Node<T> *del;
            while (this->head != this->tail){
                del = this->head;
                this->head = this->head->next;
                delete [] del;
            }
            delete [] this->tail;
        }

        void insert_front(T data){
            Node<T> *temp = this->head;
            this->head = new Node<T>(data);
            this->head->next = temp;
            this->tail->next = this->head;
        }

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

        void print(){
            Node<T> *it = this->head;
            while (it != this->tail) {
                std::cout << it->data;
                it = it->next;
            }
            std::cout << this->tail->data;
        }
};