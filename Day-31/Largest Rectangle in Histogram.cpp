#include<stack> 
int largestRectangle(vector < int > & heights) {
     // Write your code here.
     int n = heights.size();
     stack<int> s;
     vector<int> leftSmall(n), rightSmall(n);
     
     // finding left smaller element
     for(int i=0;i<n;i++) {
         while(!s.empty() && heights[i]<=heights[s.top()]) s.pop();
         if(s.empty()) leftSmall[i] = 0;
         else leftSmall[i] = s.top() + 1;
         s.push(i);
     }
     // clear the stack to reuse it
     while(!s.empty()) s.pop();
     
     // finding right smaller element
     for(int i=n-1;i>=0;i--) {
         while(!s.empty() && heights[i]<=heights[s.top()]) s.pop();
         if(s.empty()) rightSmall[i] = n-1;
         else rightSmall[i] = s.top() - 1;
         s.push(i);
     }
     int area = 0;
     for(int i=0;i<n;i++) {
         area = max(area, (rightSmall[i] - leftSmall[i] + 1) * heights[i]);
     }
     return area;
 }