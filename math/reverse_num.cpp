#include <iostream>
using namespace std;
int reverse(int n)
{
    int reverseNum = 0;

    while (n != 0)
    {
        int digit = n % 10;
        // ধরুন, reverseNum এখন 214748364 (এটা INT_MAX এর কাছাকাছি)। যখনই আপনি এটাকে ১০ দিয়ে গুণ করছেন, সেটা হয়ে যাচ্ছে 2147483640, যা INT_MAX (২১৪৭৪৮৩৬৪৭) কে ছাড়িয়ে যাওয়ার খুব কাছাকাছি। এরপর যখন আপনি digit যোগ করবেন, তখনই কোডটি ক্র্যাশ করবে বা ভুল মান দেবে।আমাদের চেক করতে হবে reverseNum কে ১০ দিয়ে গুণ করার ঠিক আগে।
        // time complexity log(n)
        if (reverseNum > INT_MAX / 10 || reverseNum < INT_MIN / 10)
        { 
            return 0;
        } 
        reverseNum = reverseNum * 10 + digit;
        n = n / 10;
        
    }
    return reverseNum;
}
int main()
{
    int n = 3568;
    cout << "Reversed Number: " << reverse(n) << endl;
    return 0;
}