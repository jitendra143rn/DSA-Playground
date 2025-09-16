class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        
        int size = arr.size();
        vector<int> pse(size, -1);  // initialize with -1 
        stack<int>st;
        
        for(int i = 0; i < size; i++)
        {
            while(!st.empty() && st.top() >= arr[i])
                st.pop();
            
            if(st.empty())
            {
                pse[i] = -1;
            }
            else
            {
                pse[i] = st.top();
            }
            st.push(arr[i]);
        }
        return pse;
    }
};
