//Задача - Красивая матрица
//Идея решения: Считываем в цикле по одной строке, проверяя каждый элемент 
//на 1. Если какой-то элемент равен 1, мы сохраняем значения его строки и столбца и выходим
//из цикла. Затем просто считаем сколько ходов нужно сделать (abs(3-line)) + (abs(3-column))
#include<iostream>
int main(){
    int line = 1;//номер текущей строки
    int column = 0, a, b, c, d, e;
    for (line; line <= 5; line++){
        std::cin>>a>>b>>c>>d>>e;
        if (a==1){
            column = 1;
            break;
        }
        if (b==1){
            column = 2;
            break;
        }
        if (c==1){
            column = 3;
            break;
        }
        if (d==1){
            column = 4;
            break;
        }
        if (e==1){
            column = 5;
            break;
        }
    }
    std::cout<<(abs(3 - line) + abs(3 - column));
}
