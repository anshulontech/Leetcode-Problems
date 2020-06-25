// https://leetcode.com/problems/design-underground-system/

// Time Complexity:-O(1) for each Operation and O(N) for total set of operations.
    
// Approach:-
//     In this what we are going to do is to use two hash maps. One of them stores the information that who check I 
// at station 1 and at what time and the other one is used to store than time used in route from one station to other 
// and in how many sets that is the count . 
        
//     During checkIn function we will add the id as key and a pair represnts the checkIn station and the time to 
// checkInMap. 
    
//     During checkOutMap we will first take the checkIn station and than the checkIn time and than update the time 
// required and route to the checkOutMap which stores the information that for a particular route what is time 
// requitred ans in how many counts.
        
//     During getAverageTime function we will find that is that rute occured in map or not if it will than we will get 
// the total time and the count and return their divide .

class UndergroundSystem
{
private:
    unordered_map<int, pair<string, int>> checkInMap;
    unordered_map<string, pair<int, int>> checkOutMap;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        checkInMap[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t)
    {
        auto &checkIn = checkInMap[id];
        string route = checkIn.first + "-" + stationName;
        checkOutMap[route].first += t - checkIn.second;
        checkOutMap[route].second++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string route = startStation + "-" + endStation;
        auto &helper = checkOutMap[route];
        return (double)helper.first / helper.second;
    }
};