class MyCircularQueue {
private:
    vector<int> queue;
    int front=-1,rear=-1,length=0,cap=0;
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        cap=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty())
            front=rear=0;
        else{
            rear++;
            rear=rear%cap;
        }
        queue[rear]=value;
        length++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front+1)%cap;
        length--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : queue[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : queue[rear];
    }
    
    bool isEmpty() {
        return length==0;
    }
    
    bool isFull() {
        return length==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */