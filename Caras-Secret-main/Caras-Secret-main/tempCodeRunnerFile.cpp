//create a function to insert element from rear in queue:
//create a function to insert element from in queue:
//create a function to delete element from rear in queue:
//create a function to delete element from in queue:
//create a function to display content of the dqueue:
#include<iostream>
using namespace std;
class Deque {
private:
  int arr[100];
  int front;
  int rear;
  int size;
public:
  Deque(int size) {
    front = -1;
    rear = 0;
    this->size = size;
  }

  void insertrear(int key) {
    if (isFull()) {
      cout << "Overflow\n" << endl;
      return;
    }

    if (front == -1) {
      front = 0;
      rear = 0;
    } else if (rear == size - 1) {
      rear = 0;
    } else {
      rear = rear + 1;
    }

    arr[rear] = key;
  }

  bool isFull() {
    return ((front == 0 && rear == size - 1) || front == rear + 1);
  }
  void insertfront(int key) {
    if (isFull()) {
      cout << "Overflow\n" << endl;
      return;
    }

    if (front == -1) {
      front = 0;
      rear = 0;
    } else if (front == 0) {
      front = size - 1;
    } else {
      front = front - 1;
    }

    arr[front] = key;
  }

  void deletefront() {
    if (isEmpty()) {
      cout << "Underflow\n" << endl;
      return;
    }

    if (front == rear) {
      front = -1;
      rear = -1;
    } else if (front == size - 1) {
      front = 0;
    } else {
      front = front + 1;
    }
  }

  void deleterear() {
    if (isEmpty()) {
      cout << "Underflow\n" << endl;
      return;
    }

    if (front == rear) {
      front = -1;
      rear = -1;
    } else if (rear == 0) {
      rear = size - 1;
    } else {
      rear = rear - 1;
    }
  }

  bool isEmpty() {
    return (front == -1);
  }
  void display() {
    if (isEmpty()) {
      cout << "Deque is empty\n";
      return;
    }

    cout << "Elements in Deque are: ";
    if (rear >= front) {
      for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    } else {
      for (int i = front; i < size; i++)
        cout << arr[i] << " ";

      for (int i = 0; i <= rear; i++)
        cout << arr[i] << " ";
    }
    cout << "\n";
  }
};
int main(){
  
  return 0;
}