struct node{
    string word;
    int len;
};
bool isAdj(string a,string b){
    int count = 0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]) count++;
    }
    if(count==1) return true;
    return false;
}
bool found(string a,vector<string>& wordList){
    for(int i=0;i<wordList.size();i++){
        if(wordList[i]==a) return true;
    }
    return false;
}
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(found(endWord,wordList)==false) return 0;
        queue<node> q1;
        queue<node> q2;
        unordered_map<string,int> vis1;
        unordered_map<string,int> vis2;
        node start = {beginWord,1};
        node end = {endWord,1};
        vis1[beginWord] = 1;
        q1.push(start);
        vis2[endWord] = 1;
        q2.push(end);
        while(!q1.empty() && !q2.empty()){
            node curr1 = q1.front();
            q1.pop();
            node curr2 = q2.front();
            q2.pop();
            for(auto it=wordList.begin();it!=wordList.end();it++){
                if(isAdj(curr1.word,*it) && vis1.count(*it)==false){
                    node temp = {*it,curr1.len+1};
                    q1.push(temp);
                    vis1[*it] = curr1.len + 1;
                    cout<<temp.word<<" - ";
                    if(temp.word == endWord){
                        return temp.len;
                    }
                    if(vis2.count(temp.word)){
                        return temp.len + vis2[temp.word] - 1;
                    }
                }
            }
            for(auto it=wordList.begin();it!=wordList.end();it++){
                if(isAdj(curr2.word,*it) && vis2.count(*it)==false){
                    node temp = {*it,curr2.len+1};
                    q2.push(temp);
                    vis2[*it] = curr2.len + 1;
                    cout<<temp.word<<" - ";
                    if(temp.word == beginWord){
                        return temp.len;
                    }
                    if(vis1.count(temp.word)){
                        return temp.len + vis1[temp.word] - 1;
                    }
                }
            }
        }
        return 0;
    }
};