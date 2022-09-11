#define mod 1000000007;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long ans=0,sum=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        //adding speed and eff to a single vector
        vector<vector<int>> v;
        for(int i=0;i<speed.size();i++)
            v.push_back({efficiency[i],speed[i]});
        //sort it according to efficiency
        sort(v.begin(),v.end());
        //traverse from end to find at most k greatest speed using min pq
        for(int i=speed.size()-1;i>=0;i--){
            //add speed to sum
            sum += v[i][1];
            pq.push(v[i][1]);
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            //since we are traversing from end the current efficiency in v will be the lowest
            long  perf = sum*v[i][0];
            ans = max(ans,perf);
        }
        return ans%mod;
    }
};