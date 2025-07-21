#ifndef NODE_H
#define NODE_H
#include<memory>

template<class T>
class Node{

private:
    std::shared_ptr<T> data;
    std::shared_ptr<Node<T>> next;
public:
    Node()
        :data(nullptr), next(nullptr)
    {}
    Node(const std::shared_ptr<T>& data)
        :data(data), next(nullptr)
    {}

    ~Node()=default;

    void setData(std::shared_ptr<T> data){
        this->data=data;
    }
    void setNext(std::shared_ptr<Node<T>> next){
        this->next=next;
    }

    const std::shared_ptr<T>& getData()const {
        return this->data;
    }
    const std::shared_ptr<Node<T>>& getNext()const {
        return this->next;
    }

};

#endif // NODE_H
