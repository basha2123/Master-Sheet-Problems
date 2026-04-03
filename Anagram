#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s1 = "listen";
    string s2 = "silent";

    int freq[26] = {0};

    for(char c : s1)
        freq[c - 'a']++;

    for(char c : s2)
        freq[c - 'a']--;

    for(int i = 0; i<26; i++){
        if(freq[i] != 0){
            cout << "Not anagram";
            return 0;
        }
    } 
    cout << "Anagram";
    return 0;
}
