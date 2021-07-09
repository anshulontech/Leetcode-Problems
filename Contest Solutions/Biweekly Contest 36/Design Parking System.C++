// Solution:-

class ParkingSystem
{
    vector<int> maxSpace, currSpace;

public:
    ParkingSystem(int big, int medium, int small)
    {
        maxSpace.resize(4);
        currSpace.resize(4);
        maxSpace[1] = big;
        maxSpace[2] = medium;
        maxSpace[3] = small;
    }

    bool addCar(int carType)
    {
        if (maxSpace[carType] == currSpace[carType])
            return false;

        currSpace[carType]++;
        return true;
    }
};