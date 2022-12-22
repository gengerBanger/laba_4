#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
HANDLE hConsole;
using namespace std;
bool TextInput(string &str1){
    char buff;
    ifstream openF(R"(C:\Users\aleks\CLionProjects\laba_4\Text_laba4.txt)");
    if(!openF.is_open()){
        cout << "Failed to open file";
        return false;
    }
    while ( ! openF.eof () ){
        openF.get(buff);
        str1 += buff;
    }
    cout << "Entered string" <<'\n';
    cout << str1 << '\n';
    openF.close ();
    return true;
}
void task2_1( string &str1) {
    for (int i = 0; i < str1.length(); i++) {
        if ((str1[i] == ' ') && (str1[i + 1] == ' ')) {
            while (!((str1[i] == ' ') && (str1[i + 1] != ' '))) {
                str1.erase(str1.begin() + i);
            }
        }
        if ((str1[i] == '!') && (str1[i + 1] == '!')) {
            while (!((str1[i] == '!') && (str1[i + 1] != '!'))) {
                str1.erase(str1.begin() + i);
            }
        }
        if ((str1[i] == '?') && (str1[i + 1] == '?')) {
            while (!((str1[i] == '?') && (str1[i + 1] != '?'))) {
                str1.erase(str1.begin() + i);
            }
        }
        if ((str1[i] == ':') && (str1[i + 1] == ':')) {
            while (!((str1[i] == ':') && (str1[i + 1] != ':'))) {
                str1.erase(str1.begin() + i);
            }
        }
        if ((str1[i] == ';') && (str1[i + 1] == ';')) {
            while (!((str1[i] == ';') && (str1[i + 1] != ';'))) {
                str1.erase(str1.begin() + i);
            }
        }
        if ((str1[i] == '"') && (str1[i + 1] == '"')) {
            while (!((str1[i] == '"') && (str1[i + 1] != '"'))) {
                str1.erase(str1.begin() + i);
            }
        }
        if ((str1[i] == ',') && (str1[i + 1] == ',')) {
            while (!((str1[i] == ',') && (str1[i + 1] != ','))) {
                str1.erase(str1.begin() + i);
            }
        }
        if (str1[i] == '.') {
            string buff;
            buff = str1[i];
            int j = i;
            j++;
            while (str1[j] == '.') {
                buff += str1[j];
                j++;
            }
            if (buff.length() < 3) {
                while (!((str1[i] == '.') && (str1[i + 1] != '.'))) {
                    str1.erase(str1.begin() + i);
                }
            }
            else {
                while (str1[i + 3] == '.') {
                    str1.erase(str1.begin() + i);
                }
                i += 3;
            }
        }
    }
}
bool isLetter(char x)
{
    return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}
bool number(char x)
{
    return (x >= '0' && x <= '9');
}
void task2_2(string &str){
    for (int i = 0; i < str.length(); i++){
        if (isLetter(str[i])){
                i++;
                while(isLetter(str[i])){
                    str[i] = tolower(str[i]);
                    i++;
                }
        }
    }
}
void task3(string &str){
    for (int i = 0; i < str.length(); i++){
        if (isLetter(str[i])){
            string buff;
           int j = i;
           while(isLetter(str[j])){
               buff += str[j];
               j++;
           }
           for(int p = buff.length() - 1;p >= 0; p--){
               str[i] = buff[p];
               i++;
           }
        }
    }
}
void task4(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (isLetter(str[i])) {
            string buffA, buff1;
            int j = i;
            while (isLetter(str[j]) || number(str[j])) {
                if (isLetter(str[j])) {
                    buffA += str[j];
                } else {
                    buff1 += str[j];
                }
                j++;
            }
            for (int p = 0; p < buffA.length(); p++) {
                str[i] = buffA[p];
                i++;
            }
            for (int p = 0; p < buff1.length(); p++) {
                str[i] = buff1[p];
                i++;
            }
        }
    }
}
void linSearch(string strM, string str1){
    int len = str1.length();
    string buff;
    bool flag = 0;
    for (int i = 0; i < strM.length(); i++){
         int j = i, count = 0;
         while(count != len){
             buff += strM[j];
             j++;
             count++;
         }
         if (buff == str1){
             cout << i << ' ';
             flag = 1;
         }
         buff = "";
    }
    if (!flag) cout << "Line not found";
    cout << '\n';
}
void myrr(string strM, string str1){
    int len = str1.length(), mass[len], index = 0; // Заполняем таблицу отступов
    string strBuff = str1.substr(0, len - 1);
    bool flag = 0;
    for (int i = len - 2; i >= 0; i--){
        if (strBuff.rfind(str1[i]) != i){
            mass[i] = mass[strBuff.rfind(str1[i])];
        }
        else{
            mass[i] = len - (i + 1);
        }
    }
    if(str1.find(str1[len - 1]) != len - 1){
        mass[len - 1] = mass[str1.find(str1[len - 1])];
    }
    else{
        mass[len - 1] = len;
    }
    while(!flag){ // Находим подстроку
        strBuff = strM.substr(index, len);
        if (strBuff == str1){
            cout << index << '\n';
            flag = true;
        }
        else{
            if(str1.find(strBuff[len - 1]) != std :: string :: npos ){
                index += mass[str1.find(strBuff[len - 1])];
            }
            else{
                index += len;
                }
            }
        }
    }
int main() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char key;
    string strM, str1,strCopy;
    while(true){
        repeat1 :
        cout << "Enter input method"<<'\n'<<'\t'<< "1) Keyboard"<<'\n'<<'\t'<<"2) File"<<'\n'<<'\n'<<'\t'<<"3) exit"<<'\n';
        cin.clear();
        cin >> key;
        if (key == '3') break;
        switch (key){
            case '1':
                cin.clear();
                while(cin.get() != '\n');
                getline(cin, strM);
                break;
            case '2':
                TextInput(strM);
                break;
            default:
                cout << "Error";
                goto repeat1;
        }
        task2_1(strM);
        cout  << "Task 2.1" <<'\n'<< strM << '\n'<< '\n';
        task2_2(strM);
        cout  << "Task 2.2" <<'\n'<< strM << '\n'<< '\n';
        strCopy = strM;
        task3(strM);
        cout << "Task 3" <<'\n'<< strM <<'\n'<< '\n';
        task4(strM);
        cout << "Task 4" <<'\n'<< strM <<'\n'<< '\n' << "Task 5.1" <<'\n'<<'\t'<< "Enter the line" << '\n';
        cin >> str1;
        repeat2:
        cout << "Enter search method"<< '\n'<<'\t'<< "1) Linear search"<<'\n'<<'\t'<<"2) Fast search (Boyer Moore)"<<'\n';
        cin >> key;
        switch(key){
            case '1':
                linSearch(strCopy, str1);
                break;
            case '2':
                myrr(strCopy, str1);
                break;
            default:
                goto repeat2;
        }
    }
    return 0;
}
