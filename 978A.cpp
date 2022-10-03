#include <iostream>
#include <array>
int main(){
    int n;
    std::cin>>n;
    std::array<int, 50> a{0};
    int i = 0, j = 0;
    for (i; i < n; i ++){
        std::cin>>a[i];
    }
    i = n - 1;
    int count = n;
    for (i; i > 0; i--){
        for (j = i - 1; j >= 0; j--){
            if (a[j] == a[i]){
                 if (a[i]!=0 && a[j]!=0){
                   count = count - 1; 
                }
                a[j] = 0;
              
            }
        }
    }
    i = 0;
    std::cout<<count<<std::endl;
    for (i; i < n; i++){
        if (a[i] != 0){
           std::cout<<a[i]<<" "; 
        }
    }
}
