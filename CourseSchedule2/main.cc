class Solution {
    private:
    map<int, vector<int>>adjlist; //course, edge
    set<int> vlist;
    set<int> visited;
    vector<int> output;
    bool dfs(int course){
        //cout << "course "<< course << ":";
        if(vlist.find(course) != vlist.end()){
            //cout << "loop detected" << endl;
            return false;
        }
        if(visited.find(course) != visited.end()){
            return true;
        }
        if(adjlist[course].size() == 0){
            //cout << "no adj" << endl;
            visited.insert(course);
            output.push_back(course);
            return true;
        }
        //cout << "add vlist" << course << endl;
        vlist.insert(course);
        
        //for(auto i : adjlist[course]){
        //    cout << i << " "; 
        //}
        //cout << endl;
        
        while(adjlist[course].size()){
            auto ptr = adjlist[course].begin();
            //cout << "offset" << ptr - adjlist[course].begin() << endl;
            //cout << "ready to dfs " << *ptr << endl; 
            
            if(dfs(*ptr) == false){
                return false;
            }
            //cout << "erase" << course << endl;
            vlist.erase(course);
            //cout << "erase adjlist" << course << endl;
            adjlist[course].erase(ptr);
        }
        //cout << "cleared" << endl;
        visited.insert(course);
        output.push_back(course);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i:prerequisites){
            adjlist[i.front()].push_back(i.back());
            //cout << "add adjlist" << i.front() << "|"<< i.back() << endl; 
        } 
        
        for(auto i = 0; i < numCourses; i++){
            if(dfs(i) == false)
                return {};
        }
        return output;
    }
};
