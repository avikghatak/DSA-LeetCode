class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int,int> pos;
    for(int i=0;i<nums.size();++i){
        //If number already exists in map
        if(pos.count(nums[i])){
            //calculate distance of last occurance, if <k
            if((i-pos[nums[i]])<=k) return true;
            // otherwise make it the last occurance 
            pos[nums[i]] = i;
        }
        //if doesnt exist add new entry
        else pos[nums[i]] = i;
    }
    return false;
}
};