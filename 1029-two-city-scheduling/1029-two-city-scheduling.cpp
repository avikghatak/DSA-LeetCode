class Solution {
public:
    static bool myCmp(vector<int>& a,vector<int>& b){
        //a[1] is cost to fly to city B
        //sort according to profit/loss made by flying the person to A rather than B
        return a[1]-a[0] > b[1]-b[0];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),myCmp);
        int n = costs.size()/2,sum=0;
        //after sorting, first half(n) of people will go to city A 
        for(int i=0;i<n;i++)
            sum+=costs[i][0];
        //and the next half(n) will go to city B;
        for(int i=n;i<2*n;i++)
            sum+=costs[i][1];
        return sum;
    }
};