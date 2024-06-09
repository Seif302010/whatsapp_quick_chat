#include <iostream>
#include <limits>
using namespace std;

bool isValid(const string &str){
    for(unsigned char ch:str){
        if(ch > '9' || ch < '0')
            return false;
    }
    return true;
}

void inputChecker(string &str){
    while(true){
        cin>>str;
        if(isValid(str))
            break;
        cout<<"Invalid input. only numbers are allowed"<<endl;
    }
}

int main()
{
    cout<<"Do you have whatsapp application (y/n): ";
    char ans = '0';
    while(true){
        ans = tolower(cin.get());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(ans == 'y' || ans == 'n')
            break;
        cout<<"Invalid input"<<endl;
    }
    string code,number,link = ans == 'y'? "https://wa.me/+" : "https://web.whatsapp.com/send?phone=";
    cout<<endl<<"Enter the international dialing code: ";
    inputChecker(code);
    cout<<endl<<"Enter the number: ";
    inputChecker(number);
    link = link + code + number;
    system(("start " + link).c_str());
    cout<<"The number you entered is: +"<<code<<number<<endl;
    cout<<"press any key to exit: ";
    cin.get();
    return 0;
}
