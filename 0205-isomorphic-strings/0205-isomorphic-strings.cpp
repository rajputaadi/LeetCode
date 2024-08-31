class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char> m1,m2;
        for(int i = 0; i<s.size();i++ )
        {
        char char_s =s[i];
        char char_t = t[i];
        if(m1.find(char_s) != m1.end()){
            if(m1[char_s] != char_t){
                return false;
            }
           
        }
        else if(m2.find(char_t) != m2.end()){
            if(m2[char_t]!= char_s){
                return false;
            }
        }
        else{
                m1[char_s]= char_t;
                m2[char_t] = char_s;

        }
        }
    return true;
    }
    };
