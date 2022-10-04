//Задача - Проблемные обеды
#include<iostream>
int main(){
    int n,k;
    int t, f;
    long maks_enjoy;
    int local_enjoy;
    std::cin>>n>>k;
    maks_enjoy = -1000000000;
    for (n; n > 0; n--){
        std::cin>>f>>t;
        if (t <= k){
            local_enjoy = f;
        }
        else{
            local_enjoy = f - (t - k);
        }
        if (local_enjoy > maks_enjoy){
            maks_enjoy = local_enjoy;
        }
    }
    std::cout<<maks_enjoy;
}
