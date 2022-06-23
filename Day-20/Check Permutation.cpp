bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.length()!=str2.length()) return false;
    int freq[26] = {0};
    for(int i=0;i<str1.length();i++) {
        freq[str1[i] - 'a']++;
        freq[str2[i] - 'a']--;
    }
    for(int i=0;i<26;i++) {
        if(freq[i]) return false;
    }
    return true;
}