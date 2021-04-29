#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int WEIGHT = 50;
const int HEIGHT = 20;

int answer_int;
///variable-for-algorithm
int N;
int matrix[100][100];

void draw_monitor_with_text(string answer){
  system("cls");
  for(int h=0; h<HEIGHT; ++h){
    printf("|");
    if(h == 0 || h+1 == HEIGHT){
      for(int i=1; i<WEIGHT-1; ++i)
	printf("-");
    }else if(h == HEIGHT/4){
      ///Now it is a simple
      ///but home i am rewrite this module
      ///maybe not because it will be strange
      int l = answer.length();
      int start_position = (WEIGHT - l)/2;
      for(int i=1; i<WEIGHT-1; ++i){
	if(i<start_position){
	  printf(" ");
	}else if(i>start_position && i<start_position + l){
	  printf("%s", answer.c_str());
	  i = start_position + l;
	}else{
	  printf(" ");
	}
      } 
    }else{
      for(int i=1; i<WEIGHT-1; ++i)
	printf(" ");
    }
    printf("|\n");
  }
}

void ask_monitor(string question){
  system("cls");
  draw_monitor_with_text(question);
  scanf("%i", &answer_int);
}

void ask_monitor_for_matrix(int []*a){
  system("cls");
  printf("Write matrix\n");
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      scanf("%i", *(*(f+i)+j) );
    }
  }
}

void read_input(){
  ask_monitor("Enter the dimension of the matrix.");
  N = answer_int;
  int (*f)[100] = matrix;
  ask_monitor_for_matrix(f);
  system("pause");
}

void calculate_matrix_short_way(){}

void write_matrix(){}

void calculate_ways(){}

void write_ways(){}

void stable_work(){
  read_input();
  calculate_matrix_short_way();
  write_matrix();
  calculate_ways();
  write_ways();
}

int main(){
  ofstream config("config.txt");
  draw_monitor_with_text("It is DIMA Program");
  while(1){
    stable_work();
    config<<"another compilation was successful"<<endl;
  }
  return 0;
}
