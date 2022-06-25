void insertSort(int x, stack<int> &s) {
    if(s.size()==0 || s.top()<x) {
        s.push(x);
        return;
    }
    int t = s.top();
    s.pop();
    insertSort(x,s);
    s.push(t);
}
void sort(stack<int>& s) {
    if(s.size()==0) return;
    int x = s.top();
    s.pop();
    sort(s);
    insertSort(x,s);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    sort(stack);
}