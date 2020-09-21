#include <iostream>
#include <cmath>

using namespace std;

double M1[100],M2[100],M0[100],I[100];
int n=0;

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("            Расчет взлета вашей ракеты по формуле Циалковского для многоступенчатой ракеты. \n");
    printf("<-----------------------------------------------------------------------------------------------> \n");
    printf("Информация о ракете:\n");
    string answer = "";
    while(answer!="no"){
        printf("Добавить еще один модуль для ракеты?(если нет то напишите \"дальше\") \n");
        char a[30];
        scanf("%s", &a);
        answer= a;
        int t;
        if(answer == "add"){
            printf("---Укажите эти данные по очереди для каждого модуля \n");
            printf("----масса заправленной i-й ступени ракеты: ");
            scanf("%g", &M1[n]);
            printf("----масса i-й ступени без топлива: ");
            scanf("%g", &M2[n]);
            printf("----удельный импульс двигателя i-й ступени: ");
            scanf("%g", &I[n]);
            printf("----масса полезной нагрузки: ");
            scanf("%g", &M0[n]);
            n++;

        }
    }
    printf("Данные успешно собраны и сохранены.\n");
    printf("Идет подготовка к началу подсчета конечной скорости ракеты.....\n");

    unsigned long long m1;
    for(int i=0;i<n;i++){
        m1+=M1[i];
    }

    printf("Начало счета......\n");
    double v=0;

    for(int i=0;i<n;i++){
        cout<<I[i]<<" "<<M0[i]<<" "<<endl;
        v+= I[i]*log10((M0[i]+m1) / (M0[i]+m1+M2[i]-M1[i]));
        cout<<v<<endl;
    }
     printf("%d", v);

    return 0;
}
