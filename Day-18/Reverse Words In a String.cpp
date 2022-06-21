string reverseString(string str)
{
    // Write your code here.
    string res;
    for(int i=str.size()-1;i>=0;i--) {
        
        if(str[i]==' ') continue;
        int j = i;
        while(j>=0 && str[j]!=' ') {
            j--;
        }
        res += str.substr(j+1, i-j) + " ";
        i = j;
    }
    return res;
}