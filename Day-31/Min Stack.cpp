// Implement class for minStack.
class minStack
{
    vector<pair<int,int>> st;
	public:
		
		// Constructor
		minStack() 
		{ 
			
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
            if(st.empty()) st.push_back({num,num});
            else {
                int minEle = min(num, st.back().second);
                st.push_back({num, minEle});
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty()) return -1;
            else {
                int x = st.back().first;
                st.pop_back();
                return x;
            }
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.empty()) return -1;
            else {
                int x = st.back().first;
                return x;
            }
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(st.empty()) return -1;
            else return st.back().second;
		}
};