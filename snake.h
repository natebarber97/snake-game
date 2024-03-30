#include "node.h"

class Snake {
    private:
        Node* head;
        Node* tail;
        int score;
        char direction;
    public:
        Snake() {

            // snake is initialized with 5 nodes in the middle of the screen string array
            // moving to the right with a score of 0 points
            head = new Node(10, 41);
            tail = new Node(10, 39);
            head->setPrev(tail);
            tail->setNext(head);
            addNode();
            addNode();
            addNode();
            direction = 'r';
            score = 0;
        };
        ~Snake() {
            Node* currNode = tail->getNext();
            while (currNode != nullptr) {
                delete currNode->getPrev();
                currNode = currNode->getNext();
            }
            delete currNode;
        };
        void addNode() {

            // add node to end of snake, then assign new node to tail
            Node* newNode = new Node(tail->getRow(), tail->getCol() - 2);
            tail->setPrev(newNode);
            tail = newNode;
            score++;
        };
        int getScore() {
            return score;
        }

        // method for moving snake across screen string array
        void moveSnake() {

            // variables to temporarily store current head node coordinates to be 
            // used by prev node when it moves
            int tempX = head->getRow();
            int tempY = head->getCol();

            // variables to change coordinates for head node based on direction
            int curRow = head->getRow();
            int curCol  = head->getCol();
            switch (direction) {
                case 'u':
                    curRow = curRow - 1;
                    break;
                case 'd':
                    curRow = curRow + 1;
                    break;
                case 'l':
                    curCol = curCol - 2;
                    break;
                case 'r':
                    curCol = curCol + 2;
                    break;
            }

            // when reaching a boundry, snake appears on opposite side of the screen string array
            if (curRow <= 0) {
                curRow = 18;
            }
            else if (curRow >= 19) {
                curRow = 1;
            }

            if (curCol <= 0) {
                curCol = 81;
            }
            else if (curCol >= 82) {
                curCol = 1;
            }
            head->setCoords(curRow, curCol);

            // loop through previous nodes to update their coordinates to match
            // the node ahead of them on the last move
            Node* currNode = head->getPrev();
            while (currNode != nullptr) {

                // variables to update coordinates of current node
                curRow = tempX;
                curCol = tempY;

                // variables to store current node coordinates before change is made
                // to be used by previous node
                tempX = currNode->getRow();
                tempY = currNode->getCol();

                currNode->setCoords(curRow, curCol);
                currNode = currNode->getPrev();
            }
        }
        void setDir(char newDir) {
            direction = newDir;
        }

        // method for adding snake nodes into screen string array
        void showSnakeOnScreen(std::string* scr) {
            scr[head->getRow()][head->getCol()] = 'O';

            Node* currNode = head->getPrev();
            while (currNode != nullptr) {
                scr[currNode->getRow()][currNode->getCol()] = 'o';
                currNode = currNode->getPrev();
            }
        }

        // method to determine if snake has run into own tail
        bool isTouching() {
            Node* currNode = head->getPrev();

            // read through all nodes after head node to see if
            // their coordinates equal to the head coordinates
            while (currNode != nullptr) {
                if (currNode->atPosition(head->getRow(), head->getCol())) {
                    std::cout << "\nYou bit yourself! ";
                    return true;
                }
                currNode = currNode->getPrev();
            }
            return false;
        }
};