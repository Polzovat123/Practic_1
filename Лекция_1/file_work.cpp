#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    int a;
    ifstream in("output.txt");
    in>>a;
    printf("Last number: %d \n", a);
    ofstream out("output.txt");
    printf("Write number: ");
    scanf("%d", &a);
    out<<a<<endl;
    return 0;
}
