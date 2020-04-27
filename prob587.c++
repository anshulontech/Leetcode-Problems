// https://leetcode.com/problems/erect-the-fence/

class Solution {
public:
    // Prints convex hull of a set of n points.
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=3)
            return points;
        
        int ymin=points[0][1],min=0;
        for(int i=1;i<n;i++) {
            int y=points[i][1];
            
            if((y<ymin) || ( (y==ymin) && points[i][0]<points[min][0] )) {
                ymin=points[i][1];
                min=i;
            }
        }
        
        vector<int> temp=points[0];
        points[0]=points[min];
        points[min]=temp;
        
        // Sort n-1 points with respect to the first point.
        // A point p1 comes before p2 in sorted ouput 
        // if p2 has larger polar angle (in counterclockwise direction) than p1
        // In the tied case, the one has smaller distance from p0 comes first
        
        vector<int> p0=points[0];
        sort(points.begin(), points.end(), pointsComparator(p0));
        
        //As we need to output all the vertices instead of extreme points
        //We need to sort the points with the same largest polar angle w.r.p. p0 in another way to break tie
        //Closer one comes last
        
        vector<int> pn=points.back();
        if(orientation(p0,points[1],pn)!=0) {
            int index=n-1;
            while(orientation(p0,points[index],pn)==0)
                index--;
            
            reverse(points.begin()+index+1,points.end());
        }
        
        // Create an empty stack and push first three points to it.
        vector<vector<int>> vertices;
        
        vertices.push_back(points[0]);
        vertices.push_back(points[1]);
        vertices.push_back(points[2]);
        
        // Process remaining n-3 points
        
        for(int i=3;i<n;i++) {
            // Keep removing top while the angle formed by
            // points next-to-top, top, and points[i] makes a right (in clockwise) turn
            
            while(orientation(vertices[vertices.size()-2],vertices.back(),points[i])==1)
                vertices.pop_back();
            
            vertices.push_back(points[i]);
        }
        
        return vertices;
    }
    
    
private:
    // A utility function to return square of distance
    // between p1 and p2
    static int distsq(vector<int>  p1, vector<int>  p2) {
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    
    // To find orientation of ordered triplet (p, q, r).
    // The function returns following values
    // 0 --> p, q and r are colinear
    // 1 --> Clockwise
    // 2 --> Counterclockwise
    
    static int orientation(vector<int>  p,vector<int>  q,vector<int>  r) {
        int val=(q[1]-p[1])*(r[0]-q[0])-(q[0]-p[0])*(r[1]-q[1]);
        
        if(val==0)
            return 0;
        
        else
            return (val>0)? 1:2;
    }
    
    struct pointsComparator {
        vector<int> p0;
        bool operator () (const vector<int> & p1,const vector<int> & p2) {
            // Find orientation
            int o=orientation(p0,p1,p2);
            if(o==0)
                return distsq(p0,p2)>=distsq(p0,p1);
            
            return o==2;
        }
        
        pointsComparator(vector<int> p) : p0(p) {}
    };
};