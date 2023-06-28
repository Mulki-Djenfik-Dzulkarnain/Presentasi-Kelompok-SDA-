#include <iostream>
#define MAX_SIZE 10

using namespace std;

class DoubleStack {
    private:
        int arr[MAX_SIZE];
        int top1, top2;

    public:
        DoubleStack() {
            top1 = -1;
            top2 = MAX_SIZE;
        }

        void push1(int x) {
            if (top1 < top2 - 1) {
                arr[++top1] = x;
            } else {
                cout << "Stack Overflow!" << endl;
            }
        }

        void push2(int x) {
            if (top1 < top2 - 1) {
                arr[--top2] = x;
            } else {
                cout << "Stack Overflow!" << endl;
            }
        }

        int pop1() {
            if (top1 == -1) {
                cout << "Stack Underflow!" << endl;
                return -1;
            } else {
                int x = arr[top1--];
                return x;
            }
        }

        int pop2() {
            if (top2 == MAX_SIZE) {
                cout << "Stack Underflow!" << endl;
                return -1;
            } else {
                int x = arr[top2++];
                return x;
            }
        }
};

int main() {
    DoubleStack ds;

    int choice, value;

    do {
        cout << "1. Push element to stack 1" << endl;
        cout << "2. Push element to stack 2" << endl;
        cout << "3. Pop element from stack 1" << endl;
        cout << "4. Pop element from stack 2" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the value to be pushed: ";
                cin >> value;
                ds.push1(value);
                break;
            case 2:
                cout << "Enter the value to be pushed: ";
                cin >> value;
                ds.push2(value);
                break;
            case 3:
                cout << "Popped value from stack 1: " << ds.pop1() << endl;
                break;
            case 4:
                cout << "Popped value from stack 2: " << ds.pop2() << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
