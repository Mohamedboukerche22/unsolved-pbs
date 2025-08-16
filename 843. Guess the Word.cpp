//https://leetcode.com/problems/guess-the-word/
class Solution {
public:
    int matchcount(string &a , string &b){
        int count = 0;
        for(int i = 0 ; i < 6 ; i++){
            if(a[i] == b[i]){
                count++;
            }
        }
        return count;

    }
    void findSecretWord(vector<string>& words, Master& master) 
    {
       for(int g = 0 ; g < 10 ;g++){
       string guessWord ;

       int score = 1000000000;
       
        for(string &ss : words){
            vector<int>count(7 , 0);
            for(string &s : words){
                if(s == ss){continue;}
                count[matchcount(s ,ss)]++;
            }
        int w = *max_element(count.begin(),count.end());
        if(w < score){score = w; guessWord = ss ;} }
        int ll = master.guess(guessWord);
        if(ll == 6){return;}
        vector<string>arr;
        for(string &wrd : words){
            if(matchcount(wrd,guessWord) == ll)
            {
                arr.push_back(wrd);
            }

        }
        words = arr;


        
    }
   }};
