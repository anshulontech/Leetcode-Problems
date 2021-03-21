// Solution:-

class AuthenticationManager
{
private:
    unordered_map<string, int> map;
    int time;

public:
    AuthenticationManager(int timeToLive)
    {
        time = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        map[tokenId] = currentTime + time;
    }

    void renew(string tokenId, int currentTime)
    {
        if (map.find(tokenId) == map.end() || map[tokenId] <= currentTime)
            return;

        map[tokenId] = currentTime + time;
    }

    int countUnexpiredTokens(int currentTime)
    {
        int res = 0;
        for (auto &x : map)
            if (x.second > currentTime)
                res++;

        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */