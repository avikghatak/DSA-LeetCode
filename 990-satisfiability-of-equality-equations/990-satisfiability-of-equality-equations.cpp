class Solution {
public:
    //find the ultimate parent of the given element 
    int getParent(int a, vector<int> parent){
        if(parent[a]==a)
            return a;
        return getParent(parent[a],parent);
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        //originally they are parent of themselves
        for(int i=0;i<26;i++)
            parent[i]=i;
        
        //find the overall parent 
        //eg: a<-b & b<-c => a<-c
        for(string eq: equations){
            char sign = eq[1];
            if(sign == '='){
                int p1 = getParent(eq[0]-'a',parent);
                int p2 = getParent(eq[3]-'a',parent);
                if(p1!=p2)
                    parent[p2]=p1;
            }
        }
        //check if ! equation has two ele with same parent
        for(string eq:equations){
            if(eq[1]=='!'){
                int p1 = getParent(eq[0]-'a', parent);
                int p2 = getParent(eq[3]-'a', parent);
                if(p1==p2)
                    return false;
            }
        }
        return true;
    }
};