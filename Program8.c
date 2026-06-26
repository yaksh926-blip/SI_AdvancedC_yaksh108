#include<stdio.h>
int main() {
    int number;
    printf("Enter any Number\n");
    scanf("%d\n", &number);
    if(number % 2 == 0) {
        printf("Entered number is even number..\n");
    } else {
        printf("Entered number is odd number..\n");
    }
    return 0;
}