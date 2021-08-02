// Solution:-

struct Node
{
    string name;
    map<string, Node *> next;
    bool toDelete = false;
    Node(string n = "") : name(n) {}
};

class Solution
{
private:
    void addPath(Node *node, vector<string> path)
    {
        for (auto &x : path)
        {
            if (node->next.count(x) == 0)
                node->next[x] = new Node(x);

            node = node->next[x];
        }
    }

    unordered_map<string, Node *> visited;

    string deletePath(Node *node)
    {
        string subFolder = "";
        for (auto &[name, next] : node->next)
            subFolder += deletePath(next);

        if (subFolder.size() != 0)
        {
            if (visited.find(subFolder) != visited.end())
                visited[subFolder]->toDelete = node->toDelete = true;
            else
                visited[subFolder] = node;
        }

        return "(" + node->name + subFolder + ")";
    }

    vector<vector<string>> res;
    vector<string> currPath;

    void getPath(Node *node)
    {
        if (node->toDelete)
            return;

        currPath.push_back(node->name);
        res.push_back(currPath);

        for (auto &[name, next] : node->next)
            getPath(next);

        currPath.pop_back();
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        Node node;

        for (auto &path : paths)
            addPath(&node, path);

        deletePath(&node);

        for (auto &[name, next] : node.next)
            getPath(next);

        return res;
    }
};