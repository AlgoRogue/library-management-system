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

// Fonksiyon implementasyonları
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Kütüphane dolu!\n");
        return;
    }
    
    printf("Kitap başlığını girin: ");
    getchar(); // Buffer temizleme
    fgets(library[bookCount].title, MAX_TITLE_LENGTH, stdin);
    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0; // Yeni satır karakterini kaldır
    
    library[bookCount].id = bookCount + 1;
    library[bookCount].available = 1;
    
    bookCount++;
    printf("Kitap eklendi. ID: %d\n", bookCount);
}

void listBooks() {
    if (bookCount == 0) {
        printf("Kütüphanede kitap yok.\n");
        return;
    }
    
    printf("\nKitap Listesi:\n");
    printf("ID\tBaşlık\t\tDurum\n");
    printf("--------------------------------\n");
    
    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%-20s\t%s\n", 
               library[i].id, 
               library[i].title, 
               library[i].available ? "Mevcut" : "Ödünç Verildi");
    }
}

void borrowBook() {
    int id;
    printf("Ödünç almak istediğiniz kitabın ID'sini girin: ");
    scanf("%d", &id);
    
    if (id < 1 || id > bookCount) {
        printf("Geçersiz kitap ID'si!\n");
        return;
    }
    
    if (!library[id-1].available) {
        printf("Bu kitap zaten ödünç verilmiş!\n");
        return;
    }
    
    library[id-1].available = 0;
    printf("Kitap başarıyla ödünç alındı.\n");
}

void returnBook() {
    int id;
    printf("İade etmek istediğiniz kitabın ID'sini girin: ");
    scanf("%d", &id);
    
    if (id < 1 || id > bookCount) {
        printf("Geçersiz kitap ID'si!\n");
        return;
    }
    
    if (library[id-1].available) {
        printf("Bu kitap zaten kütüphanede!\n");
        return;
    }
    
    library[id-1].available = 1;
    printf("Kitap başarıyla iade edildi.\n");
}

void displayMenu() {
    printf("\n=== Kütüphane Yönetim Sistemi ===\n");
    printf("1. Kitap Ekle\n");
    printf("2. Kitapları Listele\n");
    printf("3. Kitap Ödünç Al\n");
    printf("4. Kitap İade Et\n");
    printf("5. Çıkış\n");
}

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