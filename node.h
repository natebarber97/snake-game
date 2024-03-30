#include <iostream>

class Node {
    private:
        Node* next;
        Node* prev;
        int rowCoord;
        int colCoord;
    public:
        Node(int rc, int cc) {
            next = nullptr;
            prev = nullptr;
            rowCoord = rc;
            colCoord = cc;
        };
        Node(Node& toCopy) {
            next = toCopy.next;
            prev = toCopy.prev;
            rowCoord = toCopy.rowCoord;
            colCoord = toCopy.colCoord;
        };
        Node& operator=(const Node& toCopy) {
            this->next = toCopy.next;
            this->prev = toCopy.prev;
            this->rowCoord = toCopy.rowCoord;
            this->colCoord = toCopy.colCoord;
            return *this;
        };
        ~Node() {
        }
        int getRow() {
            return rowCoord;
        }
        int getCol() {
            return colCoord;
        };
        void setCoords(int rc, int cc) {
            rowCoord = rc;
            colCoord = cc;
        }
        Node* getNext() {
            return next;
        };
        Node* getPrev() {
            return prev;
        };
        void setNext(Node* nextNode) {
            next = nextNode;
            nextNode->prev = this;
        }
        void setPrev(Node* prevNode) {
            prev = prevNode;
            prevNode->next = this;
        }
        bool atPosition(int x, int y) {
            if ((rowCoord == x) && (colCoord == y)) {
                return true;
            }
            return false;
        }
};