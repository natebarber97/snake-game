#include <iostream>

class Node {
    private:
        Node* next;
        Node* prev;
        int* coord;
    public:
        Node(int rowCoord, int colCoord) {
            next = nullptr;
            prev = nullptr;
            coord = new int[2];
            coord[0] = rowCoord;
            coord[1] = colCoord;
        };
        Node(Node& toCopy) {
            next = toCopy.next;
            prev = toCopy.prev;
            coord = toCopy.coord;
        };
        Node& operator=(const Node& toCopy) {
            this->next = toCopy.next;
            this->prev = toCopy.prev;
            this->coord = toCopy.coord;
            return *this;
        };
        ~Node() {
            delete coord;
        }
        int* getCoords() {
            return coord;
        };
        void setCoords(int rowCoord, int colCoord) {
            coord[0] = rowCoord;
            coord[1] = colCoord;
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
            if ((coord[0] == x) && (coord[1] == y)) {
                return true;
            }
            return false;
        }
};