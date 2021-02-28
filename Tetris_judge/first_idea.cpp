#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map <string, int> score;
vector <string> name;
vector <string> winners;
char symbol = '-';
int number_winers = 2;

int get_score(string a){
    a = a.substr(a.find_first_of(symbol)+1);
    return std::stoi(a);
}

string get_name(string a){
    a = a.substr(0, a.find_first_of(symbol));
    return a;
}

void read_data(){
    ifstream in("log.txt");
    string inp = "";
    in>>inp;
    while(inp!="0"){
        if(score[get_name(inp)]==0){
            name.push_back(get_name(inp));
        }
        score[get_name(inp)]+=get_score(inp);
        in>>inp;
    }
    in.close();
}

void change_table_winners(int index, string new_winers){
    string last = new_winers;
    for(int i=index; i<winners.size(); ++i){
        swap(winners[i], last);
    }
}

int chage_winners_list(string names){
    if(winners.size()<number_winers){
        winners.push_back(names);
        return score[names];
    }
    for(int i=winners.size()-1; i>-1; --i){
        if(score[winners[i]]>score[names]){
            change_table_winners(i, names);
            return score[winners[winners.size()-1]];
        }
        if(score[winners[i]]==score[names]){
            change_table_winners(i+1, names);
            return score[winners[winners.size()-1]];
        }
    }
}

void print_result(){
    int minimum_for_win = -1;
    for(string names : name){
        if(score[names]>=minimum_for_win || winners.size()<number_winers){
            minimum_for_win = chage_winners_list(names);
        }
    }
    for(string winer: name){
        cout<<winer<<" : "<<score[winer]<<endl;
    }
    cout<<endl;
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
