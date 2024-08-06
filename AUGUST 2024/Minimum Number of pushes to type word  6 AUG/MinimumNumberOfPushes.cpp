prblm :__EDG__
You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

<p>image oF keypad is added outside the source file </P>


Intuition :--

We will count the frequency of each character then sort by frequency in decreasing order and start allocating first 8 character at starting position of all 8 keys and then next 8 to second position of 8 keys similarly for remaining characters.

code --

class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        vector<int> freq(26,0); // frequenct calculated
        for(auto it: word){
            freq[it-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>()); // sort frequency in decreasing order
        for(int i=0;i<26;i++){
            if(i<8){
                ans+= freq[i]; // map at first positon of all keys
            }
            else if(i<16){
                ans+= freq[i]*2; // map with second position of all keys
            }else if(i<24){
                ans+= freq[i]*3; // map with third position all keys
            }
            else ans+= freq[i]*4; // map with fourth position of all keys
        
        }
        return ans;
    }
};
