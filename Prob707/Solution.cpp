// Approach 1:-

class myNode
{
public:
    int val;
    myNode *next;

    myNode(int value)
    {
        val = value;
        next = nullptr;
    }
};

class MyLinkedList
{
private:
    myNode *root = nullptr;
    int size = 0;

public:
    MyLinkedList()
    {
    }

    int get(int index)
    {
        if (index >= size)
            return -1;

        myNode *temp = root;
        while (index > 0)
        {
            temp = temp->next;
            index--;
        }

        return temp->val;
    }

    void addAtHead(int val)
    {
        size++;
        myNode *temp = new myNode(val);
        temp->next = root;
        root = temp;
        return;
    }

    void addAtTail(int val)
    {
        size++;
        if (root == NULL)
        {
            root->next = new myNode(val);
            return;
        }

        myNode *temp = root;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new myNode(val);
        return;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;

        size++;

        myNode *temp = root;

        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        while (index - 1 > 0)
        {
            temp = temp->next;
            index--;
        }

        myNode *node = new myNode(val);
        node->next = temp->next;
        temp->next = node;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;

        size--;

        if (index == 0)
        {
            root = root->next;
            return;
        }

        myNode *temp = root;

        while (index - 1 > 0)
        {
            temp = temp->next;
            index--;
        }

        temp->next = temp->next->next;
        return;
    }
};