// https://leetcode.com/problems/walking-robot-simulation/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dist=INT_MIN;
        int x=0,y=0;
        int direction=1; // 1 represents north, 2 represents east ,-sign changes direction to opposite side.
        for(int i=0;i<commands.size();i++)
            if(commands[i]==-2)
                if(direction==1)
                    direction=-2;
                else
                    if(direction==-1)
                        direction=2;
                    else
                        if(direction==2)
                            direction=1;
                        else
                            direction=-1;
            else
                if(commands[i]==-1)
                    if(direction==1)
                        direction=2;
                    else
                        if(direction==-1)
                            direction=-2;
                        else
                            if(direction==2)
                                direction=-1;
                            else
                                direction=1;
            else
                if(direction==-1)
                    {
                        int temp=y-commands[i];
                        int max=temp;
                        int flag=0;
                        for(int j=0;j<obstacles.size();j++)
                        {
                            if(obstacles[j][0]==x)
                                if(obstacles[j][1]<y&&obstacles[j][1]>=temp) {
                                    flag=1;
                                    if(obstacles[j][1]>max)
                                        max=obstacles[j][1];
                            }
                            
                        }
                        if(flag==1)
                            y=max+1;
                        else
                            y=temp;
                    
                        if((x*x+y*y)>dist)
                            dist=x*x+y*y;
                    }
                else
                    if(direction==1)
                    {
                        int temp=y+commands[i];
                        int min=temp;
                        int flag=0;
                        for(int j=0;j<obstacles.size();j++)
                        {
                            if(obstacles[j][0]==x)
                                if(obstacles[j][1]>y&&obstacles[j][1]<=temp)
                                {
                                    flag=1;
                                    if(obstacles[j][1]<min)
                                        min=obstacles[j][1];
                                }
                        }
                        if(flag==1)
                            y=min-1;
                        else
                            y=temp;
                        
                        if((x*x+y*y)>dist)
                            dist=x*x+y*y;
                    }
                    else
                        if(direction==2)
                        {
                            int temp=x+commands[i];
                            int min=temp;
                            int flag=0;
                            for(int j=0;j<obstacles.size();j++)
                            {
                                if(obstacles[j][1]==y)
                                    if(obstacles[j][0]>x&&obstacles[j][0]<=temp)
                                    {
                                        flag=1;
                                        if(obstacles[j][0]<min)
                                            min=obstacles[j][0];
                                    }
                            }
                            if(flag==1)
                                x=min-1;
                            else
                                x=temp;
                            
                            if((x*x+y*y)>dist)
                            dist=x*x+y*y;
                        }
                        else
                        {
                            int temp=x-commands[i];
                            int max=temp;
                            int flag=0;
                            for(int j=0;j<obstacles.size();j++)
                            {
                                if(obstacles[j][1]==y)
                                    if(obstacles[j][0]<x&&obstacles[j][0]>=temp)
                                    {
                                        flag=1;
                                        if(obstacles[j][0]>max)
                                            max=obstacles[j][0];
                                    }
                            }
                            if(flag==1)
                                x=max+1;
                            else
                                x=temp;
                            
                            if((x*x+y*y)>dist)
                            dist=x*x+y*y;
                        }
        
        return dist;
    }
};