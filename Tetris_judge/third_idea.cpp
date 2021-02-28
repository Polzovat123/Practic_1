#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

map <string, int> score;
vector <string> name;
vector <string> winners;
char symbol = '-';
int number_winers = 3;

int my_stoi(string a){
    int res = 0;
    for(int i=a.length()-1; i>-1; i--){
        res += int(a[i]-'0') * pow(10 , i);
    }
    return res;
}

int get_score(string a){
    a = a.substr(a.find_first_of(symbol)+1);
    return my_stoi(a);
}

string get_name(string a){
    a = a.substr(0, a.find_first_of(symbol));
    return a;
}

void change_table_winners(int index, string new_winers){
    string last = new_winers;
    for(int i=index; i<winners.size(); ++i){
        swap(winners[i], last);
    }
}

void change_winners_list(string names){
    if(winners.size()<number_winers){
        winners.push_back(names);
        return;
    }
    for(int i=winners.size()-1; i>-1; --i){
        if(score[winners[i]]>score[names]){
            change_table_winners(i+1, names);
            return;
        }
        if(score[winners[i]]==score[names]){
            change_table_winners(i+1, names);
            return;
        }
    }
    change_table_winners(0, names);
}

bool check_have_element(string news){
    for(string winer: winners){
        if(news == winer)return false;
    }
    return true;
}

int update_win_por(){
    int mini = INT_MAX;
    for(string a: winners){
        if(score[a]<mini){
            mini = score[a];
        }
    }
    return mini;
}

void read_data(){
    ifstream in("log.txt");
    string inp = "";
    int score_for_win = -1;
    in>>inp;
    while(inp!="0"){
        if(score[get_name(inp)]==0){
            name.push_back(get_name(inp));
        }
        score[get_name(inp)]+=get_score(inp);
        cout<<get_name(inp)<<" : "<<score[get_name(inp)]<<endl;
        if((score_for_win <= score[get_name(inp)] || winners.size()!=number_winers) && check_have_element(get_name(inp))==true){
                cout<<(score_for_win <= score[get_name(inp)])<<" : "<<(winners.size()!=number_winers)<<endl;
            change_winners_list(get_name(inp));
        }
        for(string winer: winners){
            cout<<winer<<" : "<<score[winer]<<endl;
        }
        cout<<"------------------------"<<endl;
        in>>inp;
        score_for_win = update_win_por();
        cout<<score_for_win<<endl;
    }
    in.close();
}

void print_result(){
    for(string winer: winners){
        cout<<winer<<" : "<<score[winer]<<endl;
    }
}

int main()
{
    read_data();
    print_result();
    cout<<winners[0]<<endl;
    return 0;
}
