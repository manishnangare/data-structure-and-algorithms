class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,int> visited;
        bool nodeRemoved = false;
        map<int,vector<int>> courses;
        int coursesCompleted = 0;
        vector<int> courseOrder;

        for(vector<int> a : prerequisites)
        {
            courses[ a[0]].push_back(a[1]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if( courses[i].size() == 0)
            {
                coursesCompleted++;
                visited[i] = 1;
                courseOrder.push_back(i);
                nodeRemoved = true;
            }
        }

        while(nodeRemoved)
        {
            nodeRemoved = false;
            for(int i=0;i<numCourses;i++)
            {
                if(visited[i] == 0)
                {
                    vector<int> temp;
                    for(int a: courses[i])
                    {
                        if( visited[a] == 0)
                            temp.push_back(a);
                    }
                    courses[i] = temp;

                    if(temp.size() == 0)
                    {
                        visited[i] = 1;
                        courseOrder.push_back(i);
                        coursesCompleted++;
                        nodeRemoved = true;
                    }
                }
            }
        }


        if( coursesCompleted == numCourses)
            return courseOrder;
        else
            return {};
    }
};