class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxReach=startFuel,ind=0,res=0;
        priority_queue<int> pq;
        while(maxReach<target) {
            //store all the fuel capacity in pq until the max Reach
            while(ind<stations.size() && maxReach>=stations[ind][0]){
                pq.push(stations[ind][1]);
                ind++;
            }
            //the target isnt reached yet but no more stations left
            if(pq.empty()) 
                return -1;
            //use the station with max fuel
            maxReach += pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};