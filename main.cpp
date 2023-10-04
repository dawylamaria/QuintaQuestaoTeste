#include <iostream>

struct No {
    int data;
    No *next;
};

void inserirNoInicio(No *&head, int data) {
    No *novoNo = new No;
    novoNo -> data = data;
    novoNo -> next = head;
    head = novoNo;
}

bool Palindromo(No *head) {
    No *headReversa = NULL;
    No *atual = head;

    while (atual != NULL) {
        inserirNoInicio(headReversa, atual->data);
        atual = atual->next;
    }

    while (atual != NULL) {
        if (atual->data != headReversa->data) {
            return false; 
        }
        atual = atual->next;
        headReversa = headReversa->next;
    }

    return true;
}

using namespace std;
void mostrarLista(No *head) {
    No *atual = head;
    while (atual != NULL) {
        cout << atual->data << " , ";
        atual = atual->next;
    }
    cout << "NULL" << endl;
}
using namespace std;
int main() {
    No *lista = NULL;

    inserirNoInicio(lista, 1);
    inserirNoInicio(lista, 2);
    inserirNoInicio(lista, 3);
    inserirNoInicio(lista, 2);
    inserirNoInicio(lista, 1);

    cout << "Lista original:" << endl;
    mostrarLista(lista);

    if (Palindromo(lista)) {
        cout << "A lista eh um palindromo." << endl;
    } else {
        cout << "A lista nao eh um palindromo." << endl;
    }
    
	system("pause");
    return 0;
}

