#include <iostream>
#include <vector>
using namespace std;

//Sieve Eratosthenes to find the length of prime numbers in list of range 

   int countPrimes(int n) {
        int count =0;
        vector<bool> isPrime (n+1, true);
        for(int i =2; i<n;i++){
            if(isPrime[i]==true){
                count++;
                for(int j = i*2; j<n ; j = i +j){
                    isPrime[j]= false;
                }
            }
        }
        return count;
    }

int main(){
    int n =10;
cout<< countPrimes(n);
}