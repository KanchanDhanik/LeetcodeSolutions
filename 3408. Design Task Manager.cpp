3408. Design Task Manager 


🔷 Problem Statement:
In this problem, we are asked to design a Task Manager that supports adding tasks with a task ID, user ID, and priority. We need to implement the following functions:

🔧 Data Structures Used:
unordered_map<int, pair<int, int>> mpp
This map stores each task using its task ID as the key. The value is a pair of user ID and priority:
taskId → {userId, priority}


set<pair<int, int>> st
This set stores tasks sorted by priority, represented as {priority, taskId}.
Since set stores elements in sorted order, the task with the highest priority will always be at the end.
(Alternatively, a max-heap could be used, but a set is preferred here for easier task deletion.)

⚙️ Constructor: TaskManager
Initializes the task manager with a list of tasks, where each task is given as {userId, taskId, priority}.
For each task:

Insert the task into the map for quick access by task ID.

Insert the task into the set to maintain priority ordering.

➕ Add Function
Adds a new task to the task manager:

Insert the task ID and its {userId, priority} into the map.

Insert {priority, taskId} into the set to maintain the sorted order.

✏️ Edit Function
Updates the priority of an existing task:

Access the task from the map using its task ID.

Use the existing priority to form {oldPriority, taskId} and remove it from the set.

Update the priority in the map.

Insert the new {newPriority, taskId} into the set.

❌ Remove Function
Removes a task from the task manager:

Access the task from the map to get its priority.

Form {priority, taskId} and remove it from the set.

Erase the task from the map as well.

▶️ Execute Top Function
Executes and removes the task with the highest priority:

The task with the highest priority will be the last element in the set.

Retrieve and remove it from both the set and the map.

Return the user ID associated with that task.



class TaskManager {
public:
   // taskid->{userid,priority};
    unordered_map<int,pair<int,int>>mpp;
    
   // {priority,taskid}
    set<pair<int,int>>st;
    TaskManager(vector<vector<int>>& tasks) {
        //task - userid,taskid,priority
        for(auto it:tasks){
            mpp[it[1]]={it[0],it[2]};
            st.insert({it[2],it[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[taskId]={userId,priority};
        st.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        pair<int,int>p=mpp[taskId];
        p={p.second,taskId};
        auto it=st.find(p);
        st.erase(it);
        st.insert({newPriority,taskId});
        mpp[taskId]={mpp[taskId].first,newPriority};
    }
    
    void rmv(int taskId) {
        pair<int,int>p=mpp[taskId];
        p={p.second,taskId};
        auto it=st.find(p);
        st.erase(p);
        mpp.erase(taskId);
    }
    
    int execTop() {
        if(mpp.size()==0)return -1;
        auto it=st.end();
        it--;
        pair<int,int>p=*it;
        int ans=mpp[p.second].first;
        mpp.erase(p.second);
        st.erase(it);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */