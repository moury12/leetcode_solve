#include <iostream>
#include <vector>
using namespace std;
void findCombination(vector<int>& candidates, int target, int i,vector<vector<int>>& ans,vector<int>& ds ){
    int n = candidates.size();

    if(i==n ){
       if( target==0) ans.push_back(ds);
        return;
    }
    if(candidates[i]<=target){
ds.push_back(candidates[i]);
    //include
    findCombination(candidates,target-candidates[i],i,ans, ds );
    /* 
         * 🔙 POP_BACK কেন লাগছে? (BACKTRACKING)
         * 💡 মূল Point:
         * -------------
         * - 'ds' হলো একটা SHARED array
         * - সব recursive calls একই 'ds' modify করে
         * - একটা path explore করার পর অবশ্যই আগের state এ ফিরতে হবে
         * - না হলে পরের path corrupted state পাবে!
         * 
         * 
         * 🎯 Formula:
         * -----------
         * ds.push_back(x)  → Add element (এগিয়ে যাও)
         * recurse()        → Explore path (পথ খুঁজো)  
         * ds.pop_back()    → Remove element (পেছনে ফিরো)
         * 
         * এই তিনটা ALWAYS একসাথে থাকবে!
         * এটাই Backtracking এর সংজ্ঞা!  */
    ds.pop_back();
}
    
    //exclude 
    findCombination(candidates,target,i+1,ans, ds );

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(candidates,target,0,ans,ds);
        return ans;
    }
/*
 * ========================
 * COMPLETE TRACE - candidates=[2,3,6,7], target=7
 * ========================
 * 
 * findCombination(i=0, target=7, ds=[])
 * ├─ Include 2: ds=[2]
 * │  ├─ findCombination(i=0, target=5, ds=[2])
 * │  │  ├─ Include 2: ds=[2,2]
 * │  │  │  ├─ findCombination(i=0, target=3, ds=[2,2])
 * │  │  │  │  ├─ Include 2: ds=[2,2,2]
 * │  │  │  │  │  ├─ findCombination(i=0, target=1, ds=[2,2,2])
 * │  │  │  │  │  │  ├─ 2>1, skip Include
 * │  │  │  │  │  │  └─ Exclude: no solution
 * │  │  │  │  │  └─ pop_back() → ds=[2,2]
 * │  │  │  │  └─ Exclude 2:
 * │  │  │  │     ├─ findCombination(i=1, target=3, ds=[2,2])
 * │  │  │  │     │  ├─ Include 3: ds=[2,2,3]
 * │  │  │  │     │  │  └─ target=0 → Save [2,2,3] ✅
 * │  │  │  │     │  └─ pop_back() → ds=[2,2]
 * │  │  │  └─ pop_back() → ds=[2]
 * │  │  └─ Exclude 2: (more exploration...)
 * │  └─ pop_back() → ds=[]
 * └─ Exclude 2:
 *    ├─ findCombination(i=1, target=7, ds=[])
 *    │  └─ (3,6 explored, no solution)
 *    └─ Exclude 3,6:
 *       └─ findCombination(i=3, target=7, ds=[])
 *          ├─ Include 7: ds=[7]
 *          │  └─ target=0 → Save [7] ✅
 *          └─ pop_back() → ds=[]
 * 
 * Final ans = [[2,2,3], [7]]*/
int main(){
    vector<int> candidates ={2,3,6,7};
    int target = 7;
  vector<vector<int>> combinations =  combinationSum(candidates,target);
  for(auto comb : combinations){
    for (int i : comb)
    {
       cout<< i<<" ";

    }
    cout << endl;
  }
    return 0;
}