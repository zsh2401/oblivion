#include "../headers/fx.h"
namespace oopds{

template<typename T>
class SingleNode{
    public:
        SingleNode(T data,SingleNode* next);
        SingleNode* next;
        T data;
};

template<typename T>
class DoubleNode : SingleNode<T>{
    public:
        DoubleNode(T data,DoubleNode* prev,DoubleNode* next) : SingleNode(data,next)
        SingleNode* prev;
};

template<typename T>
class LinkedList{
    public:
        LinkedList();
        size_t count();
        T get(size_t index);
        void set(size_t index,T value);
        void removeAt(size_t index);
        void forEach(fx::Traveller traveller);

    private:
        size_t _count;
        DoubleNode* firstNode;
};
}