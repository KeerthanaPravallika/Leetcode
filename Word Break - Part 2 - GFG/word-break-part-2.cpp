// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<string> ans;//Store all valid sentences
    struct trienode{
        char c;
        int we;
        trienode *child[26];
        trienode(char c){
            we = 0;
            this->c = c;
            for(int i=0;i<26;++i)
                child[i]=NULL;
        }
    };
    trienode *root;//root of TRIE
    void insertInTrie(const string &word){
        trienode *curr = root;
        int idx;
        for(int i=0;i<word.size();++i){
            idx = word[i]-'a';
            if(!curr->child[idx])
                curr->child[idx] = new trienode(char(97+idx));
            curr = curr->child[idx];
        }
        curr->we += 1;
    }
    bool searchInTrie(string s){
        trienode *curr = root;
        int idx;
        for(int i=0;i<s.size();++i){
            idx = s[i]-'a';
            if(!curr->child[idx])
                return false;
            curr = curr->child[idx];
        }
        return curr->we>0;
    }
    
    void solve(const string &s,string st,int pos){
        if(pos==s.size()){
            ans.push_back(st);
            return;
        }
        st += " ";
        for(int i=pos;i<s.size();++i){
            if(searchInTrie(s.substr(pos,i+1-pos)))
                solve(s,st+s.substr(pos,i+1-pos),i+1);
        }
    }
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        root = new trienode('/');
        for(auto word: dict)
            insertInTrie(word);
        
        for(int i=0;i<s.size();++i){
            if(searchInTrie(s.substr(0,i+1)))
                solve(s,s.substr(0,i+1),i+1);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends