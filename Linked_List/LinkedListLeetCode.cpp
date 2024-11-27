#include<iostream>

using namespace std;

class Node{
    private:
        int data;
        Node* next;

    public:
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }

        void setData(int data){
            this->data = data;
        }

        void setNext(Node* next){
            this->next = next;
        }

        int getData(){
            return data;
        }

        Node* getNext(){
            return next;
        }

};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int data){
            Node* newNode = new Node(data);

            head = newNode;
            tail = newNode;
            length = 1;
        }

        void PrintList(){
            Node* temp = head;

            while(temp != nullptr){
            cout<<temp->getData()<<" ";
            temp = temp->getNext();
            }
        }

        void Append(int data){
            Node* newNode = new Node(data);
            tail->setNext(newNode);
            tail = newNode;
            length++;
        }
//
//        Node* findMiddleNode(){
//            Node* temp = head;
//            for(int i = 0 ; i<(length/2) ; i++){
//                temp = temp->getNext();
//                }
//            return temp;
//        }

        void FindDelete(){
            Node* temp;

            while(temp!=nullptr){
                temp = temp->getNext();
            }
            delete temp;
        }

        //Question 1
        Node* findMiddleNode(){
            Node* slow = head;
            Node* fast = head;

            while(fast != nullptr && fast->getNext()!= nullptr){
                slow = slow->getNext();
                fast = fast->getNext()->getNext();
            }

            return slow;
        }

        //Question 2
        bool hasLoop(){

            if(head == nullptr){return false;}

            Node* slow = head;
            Node* fast = head;

            while(fast != nullptr && fast->getNext()!= nullptr){
                fast = fast->getNext()->getNext();
                slow = slow->getNext();

                if(fast == slow){
                    return true;
                }
            }
            return false;
        }
        //Question 3
        Node* FindKFromtheEnd(int k){
            Node* temp = head;
            Node* pre = head;

            for(int i = 0 ; i<k ; i++){
                if(temp == nullptr){return nullptr;}
                temp = temp->getNext();
            }

            while(temp != nullptr){
                temp = temp->getNext();
                pre = pre->getNext();
            }

            return pre;
        }

        //Question 4
        void partitionList(int x){
            Node* temp = head;
            LinkedList* x_small = new LinkedList(0);
            LinkedList* x_big = new LinkedList(0);

            while(temp != nullptr){
                if(temp->getData()< x){
                    x_small->Append(temp->getData());
                }
                else{
                    x_big->Append(temp->getData());
                }
                temp = temp->getNext();

            }
//            delete x_small->head;
//            delete x_big->head;

            x_small->tail->setNext(x_big->head);
            x_small->PrintList();
        }

        void RemoveDuplication(){
            Node* temp = head;
            Node* pre = head;

            temp = temp->getNext();

            while(temp != nullptr){
                if(temp->getData() == pre->getData()){

                }
                pre = pre->getNext();
            }

        }

};

int main() {
    //12 111 14 7 2
    LinkedList* myLinkedList = new LinkedList(12);
    myLinkedList->Append(111);
    myLinkedList->Append(12);
    myLinkedList->Append(7);
    myLinkedList->Append(2);
    myLinkedList->removeDuplication();
}
