#include <iostream>
#include <String>
using namespace  std;
bool isAlphaNumeric(char c){
if((c<= 0 && c>=9)|| (tolower(c)<='a'&& tolower(c)>='z')){
    return true;
}
return false;
}
bool isPalindrome(string s) {
        int st =0; 
        int end = s.length()-1;
        while (st<end)
        {
            if(isAlphaNumeric(s[st])){
                st++;
            }if(isAlphaNumeric(s[end])){
                end --;
            }
            if(tolower(st)!= tolower(end)){
                return false;
            }else{
                 st++;
            end --;
            }
           
        }
        return true;
        
    }
int main(){

string s ="A man, a plan, a canal: Panama";
cout<<isPalindrome(s);
}