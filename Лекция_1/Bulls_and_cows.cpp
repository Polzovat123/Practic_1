// Cow`s and Bull`s.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

string answer;
string stroka = "0000";
bool inGame = true;

string show_start_image()
{
    printf( "|-----------------------------------------------------------------| \n" );
    printf( "|                                                                 | \n" );
    printf( "|                            Menu                                 | \n" );
    printf( "|-----------------------------------------------------------------| \n" );
    printf( "|                                                                 | \n" );
    printf( "|                         Start game?                             | \n" );
    printf( "                           ");
    char str[100];
    scanf("%9s", &str);
    return str;
}

void generate_cows()
{
    bool ch = true;
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        ch = true;
        char nn = '0' + rand() % 10;
        for (int j = 0; j <= i; j++)
        {
            if (stroka[j] == nn) {
                i--;
                ch = false;
                break;
            }
        }
        if (ch == true) {
            stroka[i] = nn;
        }
    }
    int f = stoi( stroka );
    printf("%i \n", f);
}

void turn() {
    printf( "Write you word: \n");
    char str[100];
    scanf("%9s", &str);
    answer = str;
    int bulls = 0;
    for (int i = 0; i < 4; i++) {
        if (stroka[i] == answer[i] ) {
            bulls++;
        }
    }
    if (bulls == 4) {
        inGame = false;
    }
    int cows = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j && stroka[i] == answer[j] ) {
                cows++;
            }
        }
    }
    printf( "Bulls: ");
    printf("%i \n", bulls);
    printf( "Cows: ");
    printf("%i \n", cows);
}

int main()
{
    if (show_start_image() != "start") {
        generate_cows();
        int all = 0;
        while (inGame == true)
        {
            turn();
            all++;
        }
        printf("Congratulations, you've found an unknown number. You guessed it for: ");
        printf("%i \n", all);
    }
    return 0;
}
