class WordDictionary {
public:
    struct node
    {
        bool flag;
        node *next[26];
        node(){
            flag = false;
            for(int i=0; i<26; i++){
                next[i] = NULL;
            }
        }
    };
    node *root; string s;
    bool dfs(node *curr, int i)
    {
       // cout<<i<<" "<<curr->flag<<endl;
        if(i>=s.size()) return curr->flag;

        bool flg = false;
        if(s[i]=='.'){
            for(int j=0; j<26; j++){
                if(curr->next[j]!=NULL){
                    if(dfs(curr->next[j],i+1))
                        flg = true;
                }
            }
        }
        else{
            int id = s[i]-'a';
            if(curr->next[id]==NULL) flg = false;
            else if(dfs(curr->next[id], i+1)) flg = true;
        }

        return flg;
    }
    WordDictionary() {
        root = new node();
    }

    void addWord(string word) {
        node *curr = root;
        for(int i=0; i<word.size(); i++)
        {
            int id = word[i] - 'a';
            if(curr->next[id]==NULL)
                curr->next[id] = new node();
            curr = curr->next[id];
        }
        curr->flag = true;
    }

    bool search(string word) {
        s = word;
        return dfs(root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
