#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node.h"

template<class T>
class LinkedList{

private:
    std::shared_ptr<Node<T>> listHead;
    std::shared_ptr<Node<T>> listTail;
    size_t listSize;

public:
    LinkedList()
        :listHead(nullptr), listTail(nullptr), listSize(0)
    {}
    ~LinkedList(){
        while (listHead != nullptr) {
            listHead = listHead->getNext();
        }
        listTail=nullptr;
        listSize=0;
    }

    void listPushBack(const std::shared_ptr<T>& data){

        std::shared_ptr<Node<T>> newNode =std::make_shared<Node<T>>(data);
        if(listSize==0){
            listHead=listTail=newNode;
            newNode->setNext(nullptr);
        }
        else{
            listTail->setNext(newNode);
            newNode->setNext(nullptr);
            listTail=newNode;
        }

        listSize++;
    }


    void setListHead(std::shared_ptr<Node<T>> listHead){
        this->listHead=listHead;
    }
    void setListTail(std::shared_ptr<Node<T>> listTail){
        this->listTail=listTail;
    }
    void setListSize(int value){
        this->listSize=value;
    }


    const std::shared_ptr<Node<T>>& getListHead()const{
        return listHead;
    }
    const std::shared_ptr<Node<T>>& getListTail()const{
        return listTail;
    }
    size_t getListSize()const{
        return listSize;
    }

    const std::shared_ptr<T>& operator[](size_t index)const {

        std::shared_ptr<Node<T>> current =listHead;

        for(size_t i=0; i<index; i++){
            current=current->getNext();
        }

        return current->getData();
    }

    void clearList(){
        while (listHead != nullptr) {
            listHead = listHead->getNext();
        }
        listTail=nullptr;
        listSize=0;
    }
};


#endif // LINKEDLIST_H
