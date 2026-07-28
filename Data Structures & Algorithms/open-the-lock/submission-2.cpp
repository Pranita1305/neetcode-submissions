class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000") return 0;

        unordered_set<string> visited(deadends.begin(),deadends.end());
        if(visited.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int turns=0;

        while(!q.empty()){
            turns++;
            for(int i=q.size();i>0;i--){
                string lock=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    for(int move:{1,-1}){
                        string nextLock=lock;
                        nextLock[j]=(nextLock[j]-'0'+move+10)%10+'0';

                        if(visited.count(nextLock)) continue;
                        if(nextLock==target) return turns;
                        q.push(nextLock);
                        visited.insert(nextLock);
                    }
                }
            }
        }

        return -1;
    }
};

