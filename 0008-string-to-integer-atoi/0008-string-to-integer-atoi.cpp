class Solution {
public:
    int myatoihelper(string s , int index, int result,int sign){
        
        if(index>s.size() || !isdigit(s[index])){
            return result*sign;
        }
        int digit = s[index]-'0';
        if(result>(INT_MAX-digit)/10){
            return (sign==1)?INT_MAX : INT_MIN;
        }
        result = result*10 +digit;

        return myatoihelper(s,index+1,result,sign);
    }

    
    int myAtoi(string s) {
        int index=0;
        // int result=0;
        int sign = 1;
        while(s[index]==' '){
            index++;
        }
        if(index<s.size() && s[index]=='-' || s[index]=='+'){
            sign = (s[index]=='-')? -1:1;
            index++;
        }
        if (index < s.size() && !isdigit(s[index])) {
        return 0;  // Return 0 if no valid digit is found after sign/leading zeros
    }
        return myatoihelper(s,index,0,sign);
    }
};