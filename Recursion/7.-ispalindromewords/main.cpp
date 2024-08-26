//Know if a word is palindrome 
//Programmer: Paul Manriquez 
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& word, int start, int end) {
    // Base case: If start index exceeds end index, it means all characters have been checked
    if (start == end) {
        return true; // Return true for empty or single-character words
    }
    
    // Recursive case: Check if characters at start and end positions are equal
    if (word[start] == word[end]) {
        // Move to the next characters (start+1 and end-1) and continue checking recursively
        return isPalindrome(word, start + 1, end - 1);
    } else {
        return false; // If characters are not equal, the word is not a palindrome
    }
}

int main() {
    string word1 = "reconocer";
    
    cout<<isPalindrome(word1,0,word1.length()-1);
    
    return 0;
}

