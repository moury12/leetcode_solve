#include <iostream>
#include <vector>

using namespace  std;
   int compress(vector<char>& chars) {
        ///get length of char array
        int n = chars.size();
        ///where in the index of vector i will replace the cout value or the value 
        int writeIdx =0 ;
        for( int i =0 ; i <n;i++){
            ///for comparing with current index char initially it sets to first index
            char ch = chars[i];
            ///using this if any character occure multiple time we will add and get count 
            int count = 0;
            int idx =0;
            if(ch==chars[i]){
                count++;
            }
        }
    }
int main(){

vector<char> s ={'a','a','b','b','c','c','c'};
cout<<compress(s);
}