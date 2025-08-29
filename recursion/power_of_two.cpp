#include <iostream>
using namespace std;


// bool isPowerByTwo(int n){

//  long x = 1;
//         while (n > x) {
//             x = x * 2;
//         }
//         return n == x;
// }
bool isPowerByTwo(int n){


        return n>0 and  (n& (n-1))==0;
}
int main(){
cout<< isPowerByTwo(34)<<endl;
}