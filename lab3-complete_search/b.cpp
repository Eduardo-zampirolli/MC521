#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
#define MAX 10e5

int checkRec(vector<int>& nums, int Idx, int curr){
    if (Idx == 5) return curr == 23;
    return checkRec(nums, Idx+1, curr + nums[Idx]) ||
            checkRec(nums, Idx+1, curr - nums[Idx]) ||
            checkRec(nums, Idx+1, curr * nums[Idx]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> nums(5);
    while(true){
        for (int i = 0; i < 5; i++) cin >> nums[i];
        if (!nums[0] && !nums[1] && !nums[2] && !nums[3] && !nums[4])
            break;
        bool poss = false;
        sort(nums.begin(), nums.end());
        while(true){
            if(checkRec(nums, 1, nums[0])){
                poss = true;
                break;
            }
            if (next_permutation(nums.begin(), nums.end()))
                continue;
            else
                break;
        }
        if (poss)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;

    }
    
    return 0;
}
