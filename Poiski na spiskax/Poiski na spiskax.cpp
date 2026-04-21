#include <iostream>
#include <cmath>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

    Node* getNode(int index) {
        if (index < 0 || index >= size) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        return temp;
    }

public:
    LinkedList() : head(nullptr), size(0) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    // Блочный поиск
    bool BlokoviSearch(int target, int& pos) {
        if (!head) return false;

        int step = sqrt(size);
        Node* current = head;
        int idx = 0;

        while (current && current->data < target) {
            for (int i = 0; i < step && current; i++) {
                current = current->next;
                idx++;
            }
        }

        Node* start = head;
        int startIdx = 0;
        for (int i = 0; i < idx - step; i++) {
            start = start->next;
            startIdx++;
        }

        while (start && start->data <= target) {
            if (start->data == target) {
                pos = startIdx;
                return true;
            }
            start = start->next;
            startIdx++;
        }
        return false;
    }

    // Фибоначчиииииииииииииииииииии
    bool fibonacciSearch(int target, int& pos) {
        if (!head) return false;

        int fibM2 = 0, fibM1 = 1, fibM = fibM2 + fibM1;
        while (fibM < size) {
            fibM2 = fibM1;
            fibM1 = fibM;
            fibM = fibM2 + fibM1;
        }

        int offset = -1;

        while (fibM > 1) {
            int idx = std::min(offset + fibM2, size - 1);
            Node* node = getNode(idx);

            if (node->data < target) {
                fibM = fibM1;
                fibM1 = fibM2;
                fibM2 = fibM - fibM1;
                offset = idx;
            }
            else if (node->data > target) {
                fibM = fibM2;
                fibM1 = fibM1 - fibM2;
                fibM2 = fibM - fibM1;
            }
            else {
                pos = idx;
                return true;
            }
        }

        if (fibM1 && getNode(offset + 1) && getNode(offset + 1)->data == target) {
            pos = offset + 1;
            return true;
        }
        return false;
    }
};

int main() {
    LinkedList list;
    setlocale(LC_ALL, "Rus");
    
    int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    for (int i = 0; i < 10; i++) list.append(arr[i]);

    
    int primerpoiska[] = { 7, 13, 699999 };
    int pos;

    for (int i = 0; i < 3; i++) {
        std::cout << "Ищем " << primerpoiska[i] << ":\n";

        if (list.BlokoviSearch(primerpoiska[i], pos))
            std::cout << "  Блочный: найден на позиции " << pos << "\n";
        else
            std::cout << "  Блочный: не найден\n";

        if (list.fibonacciSearch(primerpoiska[i], pos))
            std::cout << "  Фибоначчи: найден на позиции " << pos << "\n";
        else
            std::cout << "  Фибоначчи: не найден\n";

        std::cout << "\n";
    }

    return 0;
}