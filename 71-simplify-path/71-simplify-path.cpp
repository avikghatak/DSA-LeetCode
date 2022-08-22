class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        for(int i=0;i<path.length();i++) {
            if(path[i]=='/')
                continue;
            //find the substring str until the next /
            string str="";
            while(i<path.length() && path[i]!='/') {
                str += path[i++];
            }
            //single . means current dir
            if(str==".")
                continue;
            //double . means go a dir back if possible
            else if(str=="..")  {
                if(!s.empty())
                    s.pop();
            }
            //push the dir name in stack
            else 
                s.push(str);
        }
        string ans ="";
        //add ans to last to get the dir name in sequence as its stored in reverse order in stack
        while(!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        return ans.size()?ans:"/";
    }
};