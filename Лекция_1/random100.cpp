#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    printf("Second, number generate..... \n");
    srand(time(0)); // рандомизация генератора случайных чисел
    int number = rand() % 102-1;
    int ans,turns = 0;
    do{
        scanf("%d", &ans);
        if(ans >number){
            printf("too much\n");
        }else if(ans<number) {
            printf("too few\n");
        }
        turns++;
    }while(ans!=number);
    printf("You win!!! You need : %d , turns", turns);
    return 0;
}
