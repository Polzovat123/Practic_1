#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

int rekursion(char *element){
    return (*element) ? rekursion(element+1) +1 : 0;
}

int first_strlen(char *index){
    int len = rekursion(index);
    return len;
}//rekursia

int second_strlen(char *arr){
    int score = 0;
    while(arr[score]>=1){
        score++;
    }
    return score;
}

int third_strlen(char *ar){
    int l=0, r=40;
    while(l+1<r){
        int tmp = (l+r)/2;
        if(ar[tmp]>=1){
            l = tmp;
        }else{
            r = tmp;
        }
    }
    if( ar[r-1] >= 1)return r;
    else return 0;
}

int fourth_strlen(char *str){
    char *tmp = str;
    while(*tmp) tmp++;
    int answer = tmp - str;
    return answer;
}

void first_function(){
    char str[10018];
    for(int i=0;i<10018;i++)str[i]= 0;
    printf(" Write string about strlen: ");
    cin.getline(str,10000);

    char *f = &str[0];
    printf("\nstrlen1(\"%s\")=%d", str, first_strlen(f));
    printf("\nstrlen2(\"%s\")=%d", str, second_strlen(f));
    printf("\nstrlen3(\"%s\")=%d", str, third_strlen(f));
    printf("\nstrlen4(\"%s\")=%d", str, fourth_strlen(f));
}

void first_function(char* f){
    printf("\nstrlen1(\"%s\")=%d", f, first_strlen(f));
    printf("\nstrlen2(\"%s\")=%d", f, second_strlen(f));
    printf("\nstrlen3(\"%s\")=%d", f, third_strlen(f));
    printf("\nstrlen4(\"%s\")=%d", f, fourth_strlen(f));
    printf("\n");
}

int binary_length(char *ar){
    int l=0, r=40;
    while(l+1<r){
        int tmp = (l+r)/2;
        if(ar[tmp]>=1){
            l = tmp;
        }else{
            r = tmp;
        }
    }
    if (ar[l+1]>=' ' - 10)return l+1;
    else if( ar[r] >= 0)return r;
    else return l;
}

int arithm_length(char *str){
    char *tmp = str;
    while(*tmp) tmp++;
    return tmp-str;
}

int first_strpos(char *a, char*b){
    for(int i=0;i<binary_length(a); i++){
        if(a[i]==b[0]){
            bool cheker = true;
            for(int h=0;h<binary_length(b);h++){
                if(a[i+h]!=b[h]){
                    cheker = false;
                    break;
                }
            }
            if(cheker){
                return i;
            }
        }
    }
    return -1;
}

int second_strpos(char *a, char*b){
    int index_element = 0;
    int answer = 0;
    int s = binary_length(b), combo = 0;
    for(int i=0;i<binary_length(a); i++){
        //cout<<i<<" "<<index_element<<" "<<a[i]<<" "<<b[index_element]<<endl;
        if( a[i] == b[index_element]){
            index_element++;
            combo++;
        }else if(combo>0){
            answer = i;
            i--;
            combo = 0;
            index_element = 0;
        }else{
            answer = i+1;
        }
        if(combo == s){
                return answer;
        }
    }
    return -1;
}

int third_strpos(char *a, char*b){
    map <char, int> element;
    int siz = 0;
    int len_b = arithm_length(b), len_a = arithm_length(a);
    //create table
    for(int i=len_b-1; i>-1; i--){
        if(element[b[i]]!=0)element[b[i]] = min(element[b[i]], siz);else element[b[i]] = siz;
        siz++;
    }
    int comb=1,ans=0;
    int index = len_b - 1;
    for(int i = len_b-2; i<=len_a; i++ ){
        if( a[i] != b[index] ){
            if(element[a[i]]!=0){
                i=i+(element[a[i]]-1);
            }else{
                i+=len_b-1;
            }
            comb = 0;
            index = len_b - 1;
        }else{
            ans = i;
            comb++;
            index--;
            i-=2;
        }
        if(comb==len_b){
            if(ans<0)return -1;
            return ans;
            return -1;
        }
    }
    return -1;
}

int fourth_strpos(char *a, char *b){
    int ans=INT_MAX, index = arithm_length(b);
    if(index==0)return -1;
    if(arithm_length(a)==0)return -1;
    for(int i = arithm_length(a)-1; i>-1; i--){
        if(a[i]==b[index-1]){
            index--;
        }else{
            index = arithm_length(b);
        }
        if(index==0){
            ans = min(i, ans);
            //i++;
            index = arithm_length(b);
        }
        if(i>=arithm_length(a))break;
    }
    if (ans!=INT_MAX )return ans;
    return -1;
}


void second_function(){
    char str[10018], str2[10019];
    for(int i=0;i<10018; i++){
        str[i] = 0;
        str2[i] = 0;
    }
    printf("\nWrite string about strpos: first: ");
    cin.getline(str,10000);
    printf("                            :second:");
    cin.getline(str2, 10018);
    char *f = &str[0];
    char *s = &str2[0];

    printf("strpos1(\"%s\",\"%s\") = %d\n", f, s, first_strpos(f,s));//Алгоритм прямого поиска
    printf("strpos2(\"%s\",\"%s\") = %d\n", f, s, second_strpos(f,s));//КПМ Алгоритм
    printf("strpos3(\"%s\",\"%s\") = %d\n", f, s, third_strpos(f,s));//Алгоритм Бойера-Мура с евристикой плохого суффикса
    printf("strpos4(\"%s\",\"%s\") = %d\n", f, s, fourth_strpos(f,s));//
}

void second_function(char* f, char *s){
    printf("strpos1(\"%s\",\"%s\") = %d\n", f, s, first_strpos(f,s));
    printf("strpos2(\"%s\",\"%s\") = %d\n", f, s, second_strpos(f,s));
    //xcout<<endl<<"New string->"<<f<<endl<<"This new second string->"<<s<<endl;
    printf("strpos3(\"%s\",\"%s\") = %d\n", f, s, third_strpos(f,s));
    printf("strpos4(\"%s\",\"%s\") = %d\n", f, s, fourth_strpos(f,s));
}

char* first_strdel(char *a, int start, int finish, char *new_file){
    int index=0;
    for(int i=0; i<arithm_length(a); i++){
        if(i<start || i>finish){
            new_file[index] = a[i];
            index++;
        }
    }
    return &new_file[0];
}

char* second_strdel(char *a, int start, int finish, char *new_file){
    char nn[10018];
    int index=0;
    for(int i=0;i<10018;i++){
        nn[i]=0;
    }
    for(int i=arithm_length(a)-1; i>-1; i--){
        //cout<<i<<endl;
        if(i<start || i>finish){
            nn[index] = a[i];
            index++;
            //cout<<"sec: "<<i<<endl;
        }
    }
    //cout<<nn<<endl;
    for(int i=0; i<arithm_length(nn); i++){
        new_file[i] = nn[arithm_length(nn) - i - 1];
    }
    return new_file;
}
//24 - не все удаляют
// 3 - с нулом и некрасивым отображением

char* third_strdel(char *a, int start, int finish, char *t){
    vector <char> new_file;

    int index=0;
    for(int i=0; i<start; i++){
        new_file.push_back(a[i]);
    }
    for(int i=finish+1; i<arithm_length(a); i++){
        new_file.push_back(a[i]);
    }
    for(int i=0;i<new_file.size(); i++){
        t[i] = new_file[i];
    }
    return t;
}

void rekursion(int now, char *old, char *n, int start, int finish, int i){
    if(now<start || now>finish && now<arithm_length(old)){
        n[i] = old[now];
        rekursion(now+1, old, n, start, finish, i+1);
    }else if(now>=start && now<=finish){
        rekursion(now+1, old, n, start, finish, i);
    }
}

char* fourth_strdel(char *a, int start, int finish, char *new_file){
    rekursion(0, a, new_file, start, finish, 0);
    return &new_file[0];
}

void third_function(){
    char str[10018];
    char new_file [10018];
    int start, finish;
    for(int i=0;i<10018; i++){
        str[i] = 0;
    }
    printf("\nWrite string which we rename : ");
    cin.getline(str,10000);
    printf("\nWrite start  = ");scanf("%d", &start);
    if(start < 0 || start> binary_length(str))start = 0;
    printf("\nWrite finidh = ");scanf("%d", &finish);
    if(finish > binary_length(str))
        finish = binary_length(str)-1;
    else{
        if(finish < start) finish = start+1;
    }
    char *f = &str[0], *l = &new_file[0];
    //cout<<"hmhmhm"<<start<<" "<<finish<<endl;
    printf("strdel1(\" %s \", %i, %i ) = %s\n", f, start, finish, first_strdel(f, start, finish, l));
    printf("strdel2(\" %s \", %i, %i ) = %s\n", f, start, finish, second_strdel(f, start, finish, l));
    printf("strdel3(\" %s \", %i, %i ) = %s\n", f, start, finish, third_strdel(f, start, finish, l));
    printf("strdel4(\" %s \", %i, %i ) = %s\n", f, start, finish, fourth_strdel(f, start, finish, l));
}

void third_function(char *f, int start, int finish){
    char new_file [10018];char *l = &new_file[0];
    for(int i=0;i<10018; i++){
        new_file[i] = 0;
    }
    if(start < 0 || start> arithm_length(f))start = 0;
    if(finish > arithm_length(f))
        finish = arithm_length(f)+-1;
    else{
        if(finish < start) finish = start+1;
    }
    printf("strdel1(\" %s \", %i, %i ) = %s\n", f, start, finish, first_strdel(f, start, finish, l));
    printf("strdel2(\" %s \", %i, %i ) = %s\n", f, start, finish, second_strdel(f, start, finish, l));
    printf("strdel3(\" %s \", %i, %i ) = %s\n", f, start, finish, third_strdel(f, start, finish, l));
    printf("strdel4(\" %s \", %i, %i ) = %s\n", f, start, finish, fourth_strdel(f, start, finish, l));
}

bool first_strcmp(char *a, char *b){
    if(arithm_length(a) != arithm_length(b)){
        //printf("strcmp1(\" %s \", \" %s \") = false\n", a, b);
        return false;
    }
    for(int i=0; i<arithm_length(a);i++){
        if(a[i]!=b[i]){
	  return false;
	  //printf("strcmp1(\" %s \", \" %s \") = false\n", a, b);
        }
    }
    //printf("strcmp1(\" %s \", \" %s \") = true\n", a, b);
    return true;
}

bool rekursion_strcmp(char *a, char *b, int now_index){
    if(now_index < arithm_length(a) && now_index < arithm_length(b) && a[now_index] == b [now_index]){
        return rekursion_strcmp(a, b, now_index+1);
    }else if(a[now_index] != b [now_index] || arithm_length(a)!= arithm_length(b)){
        return false;
    }else{
        return true;
    }
}

bool second_strcmp(char *a, char *b){
   if(rekursion_strcmp(a, b, 0)){
     return 0;
   }else{
     return false;
   }
}

int D(int i, int j){
    if(i==j==0){
        return 0;
    }else if(j==0 && i>0){
        return i;
    }else{
        if(i==0 && j>0){
            return j;
        }else if(j>0 && i>0){
            return min(min(D(i, j-1)+1, D(i-1, j-1)+1), D(i-1, j-1)+2);
        }
    }
}

bool third_strcmp(char *a, char *b){
    int d_res = 0;
    for(int i=0;i<arithm_length(a);i++){
        for(int j=0;j<arithm_length(b);j++){
            d_res += D(i,j);
        }
    }
    if(arithm_length(a)-d_res<=1){
        for(int i=0;i<arithm_length(a); i++){
            if(a[i]!=b[i]|| a[arithm_length(a)-i-1]!=b[arithm_length(a)-i-1]){
                return false;
            }
        }
	return 0;
    }
    return false;
}

bool fourth_strcmp(char *a, char *b){
    if(arithm_length(a) != arithm_length(b)){
         return false;
    }
    int l = arithm_length(a);
    for(int i=0; i<l;i++){
      if( (*a+i) != (*b+i) ){
            return false;
        }
    }
    return 0;
}

void fourth_function(){
    char str[10018];
    char str2[10018];
    int start, finish;
    for(int i=0;i<10018; i++){
        str[i] = 0;
        str2[i] = 0;
    }
    printf("\nWrite first string: ");
    cin.getline(str,10000);
    printf("\nWrite second string: ");
    cin.getline(str2,10000);
    char *f = &str[0];
    char *s = &str2[0];
    printf("strcmp1(\" %s \", \" %s \") = %i",f,s, first_strcmp(f, s) );
    printf("strcmp2(\" %s \", \" %s \") = %i",f,s, second_strcmp(f, s));
    printf("strcmp3(\" %s \", \" %s \") = %i",f,s, third_strcmp(f, s) );
    printf("strcmp4(\" %s \", \" %s \") = %i",f,s, fourth_strcmp(f, s));
}

void fourth_function(char *f, char *s){
    printf("strcmp1(\" %s \", \" %s \") = %i",f,s, first_strcmp(f, s) );
    printf("strcmp2(\" %s \", \" %s \") = %i",f,s, second_strcmp(f, s));
    printf("strcmp3(\" %s \", \" %s \") = %i",f,s, third_strcmp(f, s) );
    printf("strcmp4(\" %s \", \" %s \") = %i",f,s, fourth_strcmp(f, s));
}

char* first_fstrcat(char *a, char *b){
    char n[10020];
    for(int i=0;i<arithm_length(a);i++){
        n[i]=a[i];
    }
    for(int i=arithm_length(a);i<arithm_length(a)+arithm_length(b);i++){
        n[i] = b [i - arithm_length(a)];
    }
    char *links = &n[0];
    //printf("fstrcat1(\" %s \", \" %s \") = %s \n", a, b, links);
    return links;
}

char* second_fstrcat(char *a, char *b){
    char n[10020];
    for(int i=0;i<arithm_length(a);i++){
        n[i]=a[i];
        if(i<arithm_length(b))
            n[i+arithm_length(a)] = b[i];
    }
    if(arithm_length(b)>arithm_length(a))
    for(int i=0;i<arithm_length(b)-arithm_length(a); i++){
        n[arithm_length(a)*2+i] = b[arithm_length(a)+i];
    }
    char *links = &n[0];
    //printf("fstrcat2(\" %s \", \" %s \") = %s \n", a, b, links);
    return links;
}

void rekursion_from_fstrcat(char *a, char *b, char *n, int now, int len_a, int len_b){
    if(now<len_a){
        n[now] = a[now];
        return rekursion_from_fstrcat(a,b,n,now+1,len_a,len_b);
    }else if(now>=len_a && now-len_a<len_b){
        n[now] = b[now-len_a];
        return rekursion_from_fstrcat(a,b,n,now+1,len_a,len_b);
    }
}

char* third_fstrcat(char *a, char *b){
    char n[10020];
    char *links = &n[0];
    rekursion_from_fstrcat(a, b, links, 0, arithm_length(a), arithm_length(b));
    //printf("fstrcat3(\" %s \", \" %s \") = %s \n", a, b, links);
    return links;
}

char* fourth_fstrcat(char *a, char *b){
    char n[10020];
    int i=0;
    while(i<arithm_length(a)){
        n[i]=a[i];i++;
    }
    while(i-arithm_length(a)<arithm_length(b)-1){
        n[i]=b[i-arithm_length(a)];i++;
    }
    return links;
}

void fifth_function(){
    char str[10018];
    char str2[10018];
    int start, finish;
    for(int i=0;i<10018; i++){
        str[i] = 0;
        str2[i] = 0;
    }
    printf("\nWrite first string: ");
    cin.getline(str,10000);
    printf("\nWrite second string: ");
    cin.getline(str2,10000);
    char *f = &str[0];
    char *s = &str2[0];
    printf("fstrcat1(\" %s \", \" %s \") = %s \n", f, s, first_fstrcat(f, s));
    printf("fstrcat2(\" %s \", \" %s \") = %s \n", f, s, second_fstrcat(f, s));
    printf("fstrcat3(\" %s \", \" %s \") = %s \n", f, s, third_fstrcat(f, s));
    printf("fstrcat4(\" %s \", \" %s \") = %s \n", f, s, fourth_fstrcat(f, s));
}

void fifth_function(char *f, char *s){
    printf("fstrcat1(\" %s \", \" %s \") = %s \n", f, s, first_fstrcat(f, s));
    printf("fstrcat2(\" %s \", \" %s \") = %s \n", f, s, second_fstrcat(f, s));
    printf("fstrcat3(\" %s \", \" %s \") = %s \n", f, s, third_fstrcat(f, s));
    printf("fstrcat4(\" %s \", \" %s \") = %s \n", f, s, fourth_fstrcat(f, s));
}


char* first_strcpy(char *d, char *s){
    for(int i=0; i<arithm_length(s); i++){
        d[i] = s[i];
    }
    return d;
}

char* second_strcpy(char *d, char *s){
    d = s;
    return d;
}

char* third_strcpy(char *d, char *s){
    int i=0;
    while(i<arithm_length(s)){
        d[i]=s[i];
        i++;
    }
    return d;
}

void rekursion_strcpy(int i, char *d, char *s){
    if(i<arithm_length(s)){
        d[i]=s[i];
        rekursion_strcpy(i+1, d, s);
    }
}

char* fourth_strcpy(char *d, char *s){
    rekursion_strcpy(0, d, s);
    return d;
}

void sixth_function(){
    char str[10018];
    char str2[10018];
    int start, finish;
    for(int i=0;i<10018; i++){
        str[i] = 0;
        str2[i] = 0;
    }
    printf("\nWrite first string: ");
    cin.getline(str,10000);
    char *f = &str[0];
    char *s = &str2[0];
    printf("strcpy1(\" %s \") = %s \n", s, first_strcpy(s, f));
    printf("strcpy2(\" %s \") = %s \n", s, second_strcpy(s, f));
    printf("strcpy3(\" %s \") = %s \n", s, third_strcpy(s, f));
    printf("strcpy4(\" %s \") = %s \n", s, fourth_strcpy(s, f));
}

void sixth_function(char *s, char *f){
    printf("strcpy1(\" %s \") = %s \n", s, first_strcpy(s, f));
    printf("strcpy2(\" %s \") = %s \n", s, second_strcpy(s, f));
    printf("strcpy3(\" %s \") = %s \n", s, third_strcpy(s, f));
    printf("strcpy4(\" %s \") = %s \n", s, fourth_strcpy(s, f));
}

char m[10018];
char b[10018];
void clear_m(){
    for(int i=0;i<10018;i++){
        m[i]=0;
    }
}

char* get_link(string f){
    clear_m();
    for(int i=0;i<f.length();i++){
        m[i]=f[i];
    }
    return &m[0];
}

void clear_b(){
    for(int i=0;i<10018;i++){
        b[i]=0;
    }
}

char* get_links(string f){
    clear_b();
    for(int i=0;i<f.length();i++){
        b[i]=f[i];
    }
    return &b[0];
}

char* mind(int i){
    switch(i){
    case 0:{
        return get_link("");
    }
    case 1:{
        return get_link("no");
    }
    case 2:{
        return get_link("this is first string");
    }
    case 3:{
        return get_link("aa");
    }
    }
}

void first_test(){
    char t = 0; char *i = &t;
    char str[]="this is first string ";char *a = &str[0];
    printf("FIRST FUNCTION DATA STRLEN\n \"%s\" \n\"%s\"", a, i);
    first_function(a);
    first_function(i);
    return;
}

void test_3_point_toabc(char *a, char *sub){
    for(int i=0;i<3;i++){
        if(i==0){
            a[0]='a';
            a[1]='a';
            second_function(a, sub);
        }
        if(i==1){
            a[arithm_length(a)  - arithm_length(sub)-1] = 'a';
            a[arithm_length(a)  - arithm_length(sub)-2] = 'a';
            second_function(a, sub);
        }
        if(i==2){
            a[arithm_length(a)  - arithm_length(sub)] = 'a';
            a[arithm_length(a)  - arithm_length(sub)+1] = 'a';
            second_function(a, sub);
        }
        printf("\n");
        a = get_links("this is first string");;
    }
}

void second_test(){
    printf("SECOND FUNCTION DATA STRPOS\n");
    char *a;
    for(int i=0;i<2;i++){
        if(i==0){char str[]="";a = &str[0];}
        if(i==1){char str[]="this is first string";a = &str[0];}
        for(int j=0;j<4;j++){
            char *sub = mind(j);
            printf("\"%s\" :  \"%s\"\n", a, sub);
            printf("\n");
            if(j!=3||i!=1)second_function(a, sub);else{
                test_3_point_toabc(a, sub);
            }
            printf("\n");
        }
    }
    return;
}

int mind_k(int i, char *a){
    srand(time(0));
    switch(i){
    case 0:{
        if(arithm_length(a)!=0)return rand() % arithm_length(a);
        return 1;
    }
    case 1:{
        return (-1)*rand()%10;
    }
    case 2:{
        return arithm_length(a) + rand()%4;
    }
    case 3:{
        return arithm_length(a);
    }
    case 4:{
        return 0;
    }
    }
}

int mind_p(int i, char *a , int k){
    srand(time(0));
    switch(i){
    case 0:{
        return 0;
    }
    case 1:{
        return arithm_length(a);
    }
    case 2:{
        return arithm_length(a) + rand()%10 - k;
    }
    case 3:{
        return (-1)*rand()%10;
    }
    case 4:{
        return arithm_length(a) - k;
    }
    case 5:{
        if(arithm_length(a)!=0)
        return rand()%(arithm_length(a) - k);
        return 1;
    }
    }
}

void third_test(){
    printf("THIRT FUNCTION DATA\n");
    char f[]="";char *a = &f[0];
    char e[]="it is long string for delete operation";char *l = &e[0];
    printf("\"%s\" :  \"%s\"\n", a, l);
    char *u;
    for(int i=0;i<2;i++){
        if(i==1)u = l;else u = a;
        for(int j=0; j<5; j++){
            int k = mind_k(j, u);
            for(int y=0;y<6;y++){
                int p = mind_p(y, u, k);
                third_function(u, k, p);
                printf("\n");
            }
        }
    }
}

void fourth_test(){
    printf("FOURTH FUNCTION DATA\n");

}

void fivth_test(){
    printf("FIVETH FUNCTION DATA\n");
}

void sixth_test(){
    printf("SIXTH FUNCTION DATA\n");
}

void read_data(int name){
  switch(name){
  case 1:{
        //first_test();
    break;}
  case 2:{
        //second_test();
    break;}
  case 3:{
    //third_test();
    break;}
  case 4:{
    fourth_test();
    break;}
  case 5:{
    fivth_test();
    break;}
  case 6:{
    sixth_test();
    break;}
  default:
    cout<<"ERROR"<<endl;
  }
}

int main()
{
    //setlocale(LC_ALL, "Russian");
    ///first_function();///one function with
    ///second_function();
    ///third_function();
    //fourth_function();
    //ifth_function();
    //sixth_function();
    int i=1;
    while(i<7){
        read_data(i);
        i++;
    }
    return 0;
}
