#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk memasukkan node baru di akhir list
void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menghitung nilai desimal dari representasi biner pada linked list
int getDecimalValue(Node* head) {
    int result = 0;
    while (head != NULL) {
        result = (result << 1) | head->data; // Shift left dan tambahkan nilai node
        head = head->next;
    }
    return result;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, element;
    vector<int> elements;

    // Input jumlah elemen dalam linked list
    cout << "Masukkan jumlah elemen dalam linked list: ";
    cin >> n;

    // Input elemen linked list
    cout << "Masukkan elemen linked list (biner): ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        insert(&head, element);
        elements.push_back(element);  // Simpan elemen untuk output
    }

    // Cetak input yang dimasukkan
    cout << "Input: head = [";
    for (int i = 0; i < elements.size(); ++i) {
        cout << elements[i];
        if (i != elements.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    // Hitung nilai desimal dari linked list biner
    int decimalValue = getDecimalValue(head);

    // Output nilai desimal
    cout << "Output: " << decimalValue << endl;

    return 0;
}

// komentar