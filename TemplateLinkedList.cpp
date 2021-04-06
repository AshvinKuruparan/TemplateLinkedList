#include<bits/stdc++.h>
using namespace std;

template <typename T>
//Creating the node
struct Node{
    T _data;
    Node *_next;
};

template <typename T>//Has to be declared again for the linkedlist
class LinkedList{
    Node<T> *_head, *_tail;
    
    public:
        LinkedList(){//Construct
            _head = NULL;
            _tail = NULL;
        }

        void add(T x){//Adds a new node to the linkedlist
            Node<T> *temp = new Node<T>;
            temp->_data = x;
            temp->_next = NULL;

            if(_head == NULL){//Checks if the linkedlist is empty
                _head = temp;
                _tail = temp;
            }
            else{
                //Adds the new node to the end of the linkedlist
                _tail->_next = temp;
                _tail = _tail->_next;
            }

        }

        void remove(T x){//removes the last node
            if(_head->_data == x){//if the values are the same move to the next node
                _head = _head->_next;
            }
            else{
                Node<T> *temp = _head;
                Node<T> *back = _head;

                while (temp != NULL){//Loop until the value is found or there are no more nodes
                    if(temp->_data == x){
                        break;
                    }
                    back = temp;
                    temp = temp->_next;
                }

                back->_next = temp->_next;//unlink the temp node
                if(temp == _tail){
                    _tail = back;
                }
            }
        }

        //Display list
        void show (){
            Node<T> *temp = _head;
            while(temp != NULL){
                cout << temp->_data;
               
                if(temp->_next != NULL){
                    cout << " -> ";
                } 
                temp = temp->_next;
            }
            cout << endl;
        }
        Node<T>* head(){
            return _head;
        }
  
        Node<T>* tail(){
            return _tail;
        }
};

int main() {
    LinkedList<int> li;
    for (int i = 10; i > 0; --i) {
        li.add(i);
    }
    li.show();

    li.remove(10);
    li.remove(5);
    li.remove(1);
    li.show();

    return 0;
}