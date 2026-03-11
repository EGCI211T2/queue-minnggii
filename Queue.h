
#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};


void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
    if(new_node != NULL){ 
        /* Add head and tail for me please */
        /*
        1. connect & Change tail
        2. (may be) change head  when the queue is empty
        3. increase size */
        if(size > 0)
        {
            tailPtr -> set_next(new_node);
        }
        else
        {
            headPtr = new_node;
        }
        tailPtr = new_node;
        size++;
    }
    //cout<<new_node -> get_value() <<endl;
}

int Queue::dequeue(){
  if(size>0)
  {
    /* Add head and tail for me please */
    NodePtr t = headPtr;
    int value = t -> get_value();
    headPtr = headPtr -> get_next();
    if(size==1) tailPtr=NULL;
    size--;
    delete t;
    return value;
  }
  else
  {
    cout<<"Empty Queue" <<endl;
    return -1;
  }
}


Queue::Queue(){
    //initialize Queue
    
    
}
Queue::~Queue(){
    cout<<"Clearing queue" <<endl;
    //delete all remaning Queue (i.e. DQ all) 
    while(size > 0)
    {
        dequeue();
    }
}


#endif
