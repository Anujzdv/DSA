class MyCircularDeque {
public:
    vector<int> dq;
    int fidx, ridx, size, cap;

    MyCircularDeque(int k) {
        cap = k + 1;
        dq.resize(cap);
        fidx = 0;
        ridx = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        fidx = (fidx - 1 + cap) % cap;
        dq[fidx] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        dq[ridx] = value;
        ridx = (ridx + 1) % cap;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        fidx = (fidx + 1) % cap;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        ridx = (ridx - 1 + cap) % cap;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return dq[fidx];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return dq[(ridx - 1 + cap) % cap];
    }
    
    bool isEmpty() {
        return fidx == ridx;
    }
    
    bool isFull() {
         return (ridx + 1) % cap == fidx; 
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */