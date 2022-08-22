class Solution {
private:
    map<int, vector<int>>adjlist; //course, edge
    set<int> vlist;
    bool dfs(int course){
        //cout << "course "<< course << ":";
        if(vlist.find(course) != vlist.end()){
            //cout << "loop detected" << endl;
            return false;
        }
        if(adjlist[course].size() == 0){
            //cout << "no adj" << endl;
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
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i = 0;i < numCourses; i++){
            adjlist[i] = {};
        }
        for(auto i :prerequisites){
            vlist.clear();
            adjlist[i.back()].push_back(i.front());
            //cout << "couse" << i.front();
            //cout << "added to adj of course" << i.back();
            //cout << endl;
        }
        
        for(auto i = 0; i < numCourses; i++){
            //cout << "checking cours" << i <<endl;
            if(dfs(i) == false){
                return false;
            }
        }
        return true;
    }
};
