#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    int price;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("더 이상 책을 저장할 수 없습니다.\n");
        return;
    }

    printf("책 제목 입력: ");
    getchar(); // 버퍼 비우기
    fgets(library[bookCount].title, sizeof(library[bookCount].title), stdin);
    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0;

    printf("저자 입력: ");
    fgets(library[bookCount].author, sizeof(library[bookCount].author), stdin);
    library[bookCount].author[strcspn(library[bookCount].author, "\n")] = 0;

    printf("가격 입력: ");
    scanf("%d", &library[bookCount].price);

    bookCount++;
    printf("책이 성공적으로 추가되었습니다!\n");
}

void searchBook() {
    char keyword[50];
    int found = 0;

    printf("검색할 책 제목 입력: ");
    getchar();
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, keyword) != NULL) {
            printf("\n[검색 결과]\n");
            printf("제목: %s\n", library[i].title);
            printf("저자: %s\n", library[i].author);
            printf("가격: %d원\n\n", library[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("해당 제목의 책을 찾을 수 없습니다.\n");
    }
}

void showAllBooks() {
    if (bookCount == 0) {
        printf("등록된 책이 없습니다.\n");
        return;
    }

    printf("\n===== 전체 도서 목록 =====\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d번째 책\n", i + 1);
        printf("제목: %s\n", library[i].title);
        printf("저자: %s\n", library[i].author);
        printf("가격: %d원\n\n", library[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n==== 도서 관리 프로그램 ====\n");
        printf("1. 책 추가\n");
        printf("2. 책 검색\n");
        printf("3. 전체 책 보기\n");
        printf("0. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                showAllBooks();
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
