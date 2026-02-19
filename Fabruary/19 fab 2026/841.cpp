class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> st;
        vector<bool> visited(rooms.size(),false);
        visited[0]=true;
        st.push(0);
        int count=0;
        while(!st.empty())
        {
            int x = st.top();
            st.pop();
            count++;
            for(int i=0;i<rooms[x].size();i++)
            {
                int y= rooms[x][i];
                if(!visited[y])
                {
                    st.push(y);
                    visited[y]=true;
                }
            }
        }
        return count==rooms.size();
    }
};