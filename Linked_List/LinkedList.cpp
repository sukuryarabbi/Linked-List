#include<iostream>

using namespace std;

class Node{
    private:
        int value;
        Node* next;

    public:
        Node(int value){
            this->value = value;
            next = nullptr ;
        }
        int getValue(){return value;}

        Node* getNext(){return next;}

        void setValue(int value){this->value = value;}

        void setNext(Node* next){this->next = next;}
};

class LinkedList{

    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value){
            Node* newNode = new Node(value);

            this->head = newNode;
            this->tail = newNode;
            this->length = 1;

        }

        Node* get(int index){
            Node* temp = head;

            if(index < 0 || index > length){return nullptr;}

            for(int i = 0 ; i<index ; i++){
                temp = temp->getNext();
            }
            return temp;

        }

        void Set(int index,int value){
            Node* temp = get(index);
            if(temp != nullptr){
                temp->setValue(value);
            }
            else{
                cout<<"Error";
            }
        }

        void Insert(int index,int value){
            Node* newNode = new Node(value);
            Node* temp = head;

            if(index<0 ||index >= length){cout<<"Error";}
            for(int i = 1; i<index ; i++){
                temp = temp->getNext();
            }
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
            length++;

        }
        void Append(int value){
            Node* newNode = new Node(value);

            tail->setNext(newNode);
            tail = newNode;
            length++;
        }

        void PrintList(){
            Node* temp = head;

            while(temp != nullptr){

                cout<<temp->getValue()<<" ";
                temp = temp->getNext();
            }
        }

        void DeleteLast(){
            Node* temp = head;
            Node* pre = head;
            while(temp->getNext() != nullptr){
                pre = temp;
                temp = temp->getNext();
            }
            pre->setNext(nullptr);
            tail = pre;
            delete temp;


        }

        void Prepend(int value){
            Node* newNode = new Node(value);

            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->setNext(head);
                head = newNode;
            }
        }

        void DeleteFirst(){
            Node* temp = head;

            if(head == nullptr){
                cout<<"Error, linked list is empty";
            }
            else if(head->getNext() == nullptr){
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->getNext();

            }
            delete temp;
        }

        void DeleteNode(int index){
            Node* temp = head;
            Node* pre = head;

            if(index<0 || index>length){cout<<"Error";}
            if(index == 0){return DeleteFirst();}
            for(int i = 1; i<index ; i++){
                temp = temp->getNext();

            }
            for(int j = 0 ; j<index ; j++){
                pre = pre->getNext();
            }

            temp->setNext(pre->getNext());
            pre->setNext(nullptr);

            length--;
            delete pre;

        }

        void Reverse(){
            Node* temp = head;
            Node* after = temp->getNext();
            Node* before = nullptr;

            for(int i = 0 ; i<length ; i++) {

            }

        }

};

int main() {
    //1,67,10,100
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->Append(10);
    myLinkedList->Append(12);
    myLinkedList->Set(2,100);
    myLinkedList->Insert(1,67);
    myLinkedList->DeleteNode(0);
    //cout<<myLinkedList->get(1)->getValue();
    myLinkedList->PrintList();

}
