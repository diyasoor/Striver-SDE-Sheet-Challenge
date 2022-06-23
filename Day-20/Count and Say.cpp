string writeAsYouSpeak(int n) 
{
	// Write your code here.	
    if(n==1) return "1";
    if(n==2) return "11"; 
    string s="11", temp;
    for(int i=3;i<=n;i++) {
        temp="";
        int cnt=1 ,j;
        for(j=1;j<s.size();j++) {
            if(s[j]!=s[j-1]) {
                temp += to_string(cnt) + s[j-1];
                cnt=1;
            }
            else cnt++;
        }
        temp += to_string(cnt) + s[j-1];
        s=temp;
    }
    return s;
}