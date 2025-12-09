class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        queue<int> q1;

        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                q1.push(i);
            }
            m[s[i]]++;
            while(q1.size()>0 && m[s[q1.front()]]>1){
                q1.pop();
            }
        }
        return q1.empty() ? -1 : q1.front();
    }
};
