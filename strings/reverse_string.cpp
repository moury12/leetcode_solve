#include <iostream>
using namespace std;
#include <vector>

 void reverseString(vector<char>& s) {
        char start =s[0];
        char end = s[s.size()-1];
        while(start<end){
           char temp = start;
           start=end;
           end =temp;
start++;
end--;

        }
    }