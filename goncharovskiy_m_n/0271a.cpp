//Задача - Красивый год
#include<iostream>
int main(){
    int year = 0;
    int a =0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::cin>>year;
    bool flag = true;
    while (flag){
        year = year + 1;
        a = year%10;
        b = (year/10)%10;
        c = (year/100)%10;
        d = (year/1000)%10;
        if (a!=b && b!=c && c!=d && a!=c && a!=d && b!=d){
            flag = false;
            std::cout<<year;
        }
    }
}
