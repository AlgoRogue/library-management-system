#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50

// Kitap yapısı
struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    int available;
};

// Global değişkenler
struct Book library[MAX_BOOKS];
int bookCount = 0;

// Fonksiyon prototipleri
void addBook();
void listBooks();
void borrowBook();
void returnBook();
void displayMenu();

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Seçiminiz: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                printf("Program sonlandırılıyor...\n");
                break;
            default:
                printf("Geçersiz seçim!\n");
        }
    } while(choice != 5);
    
    return 0;
}

void displayMenu() {
    printf("\n=== Kütüphane Yönetim Sistemi ===\n");
    printf("1. Kitap Ekle\n");
    printf("2. Kitapları Listele\n");
    printf("3. Kitap Ödünç Al\n");
    printf("4. Kitap İade Et\n");
    printf("5. Çıkış\n");
}