#include <stdio.h>
#include <string.h>

 /*
    1. [설계]에서 정의한 변수, 배열, (필요하면) 구조체를 여기에 선언하세요.

    ▶ 도서 관리 프로그램 설계 기반

    구조체 Book:
        - title   : 책 제목
        - author  : 저자명
        - price   : 가격

    books 배열:
        - 최대 100권 저장
        - struct Book books[100]

    count 변수:
        - 현재 등록된 책 수 저장
 */

struct Book {
    char title[100];
    char author[100];
    int price;
};

struct Book books[100];
int count = 0;



/*
    2. [알고리즘]에서 설계한 핵심 기능 함수들을 여기에 선언하세요.
*/

void addBook();       // 책 등록
void listBooks();     // 전체 목록 출력
void searchBook();    // 제목 검색



int main() {
    


    /*
        3. [알고리즘]에서 설계한 main 함수의 흐름을
           여기에 C언어로 자유롭게 구현하세요.
    */

    int menu;

    while (1) {
        printf("\n===== 도서 관리 프로그램 =====\n");
        printf("1. 책 등록\n");
        printf("2. 전체 목록 보기\n");
        printf("3. 제목으로 검색\n");
        printf("4. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &menu);

        if (menu == 1) {
            addBook();
        }
        else if (menu == 2) {
            listBooks();
        }
        else if (menu == 3) {
            searchBook();
        }
        else if (menu == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}


void addBook() {
    if (count >= 100) {
        printf("더 이상 책을 등록할 수 없습니다.\n");
        return;
    }

    printf("책 제목: ");
    scanf(" %[^\n]", books[count].title);

    printf("저자: ");
    scanf(" %[^\n]", books[count].author);

    printf("가격: ");
    scanf("%d", &books[count].price);

    count++;
    printf("책 등록 완료!\n");
}


void listBooks() {
    if (count == 0) {
        printf("등록된 책이 없습니다.\n");
        return;
    }

    printf("\n===== 전체 도서 목록 =====\n");
    for (int i = 0; i < count; i++) {
        printf("%d) 제목: %s | 저자: %s | 가격: %d원\n",
               i + 1,
               books[i].title,
               books[i].author,
               books[i].price);
    }
}


void searchBook() {
    if (count == 0) {
        printf("등록된 책이 없습니다.\n");
        return;
    }

    char key[100];
    int found = 0;

    printf("검색할 제목 키워드: ");
    scanf(" %[^\n]", key);

    printf("\n===== 검색 결과 =====\n");

    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, key) != NULL) {
            printf("제목: %s | 저자: %s | 가격: %d원\n",
                   books[i].title,
                   books[i].author,
                   books[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("일치하는 책이 없습니다.\n");
    }
}