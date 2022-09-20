#include <iostream>
#include <math.h>
#include <queue>

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNumberOfSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        std::cout << " ";
}

void printInteger(int &n)
{
    std::cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == nullptr)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    
    ~AVLTree(){}
    
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == nullptr)
        {
            std::cout << "nullptr\n";
            return;
        }
        std::queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNumberOfSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == nullptr)
            {
                std::cout << " ";
                q.push(nullptr);
                q.push(nullptr);
            }
            else
            {
                std::cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNumberOfSpace(space);
            count++;
            if (count == maxNode)
            {
                std::cout << std::endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNumberOfSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void insert(const T &value)
    {
        root = insertNode(value, root);
    }
    
    int heightSub(Node* node)
    {
        if (node == nullptr)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
    
    int getBalanceFactor(Node* x)
    {
        if (x == nullptr) return 0;
        return heightSub(x->pLeft) - heightSub(x->pRight);
    }
    
    Node* rightRotate(Node* cur)
    {
        Node* lChild = cur->pLeft;
        cur->pLeft = lChild->pRight;
        lChild->pRight = cur;
        return lChild;
    }
    
    Node* leftRotate(Node* cur)
    {
        Node* rChild = cur->pRight;
        cur->pRight = rChild->pLeft;
        rChild->pLeft = cur;
        return rChild;
    }
    
    Node* insertNode(const T &value, Node* cur)
    {
        // standard BST add
        if (cur == nullptr) {
            Node* p = new Node(value);
            return p;
        }
        if (value < cur->data)
            cur->pLeft = insertNode(value, cur->pLeft);
        else if (value >= cur->data)
            cur->pRight = insertNode(value, cur->pRight);
        else
            return cur;
        
        // find first unbalanced node
        int bal = getBalanceFactor(cur);

        if (bal > 1)
        {
            if (value < cur->pLeft->data)
                // LEFT LEFT CASE
                return rightRotate(cur);
            else
            {
                // LEFT RIGHT CASE
                cur->pLeft = leftRotate(cur->pLeft);
                return rightRotate(cur);
            }
        }
        
        if (bal < -1) {
            if (value >= cur->pRight->data)
                // RIGHT RIGHT CASE
                return leftRotate(cur);
            else
            {
                // RIGHT LEFT CASE
                cur->pRight = rightRotate(cur->pRight);
                return leftRotate(cur);
            }
        }
        
        return cur;
    }
    
    void remove(const T &value)
    {
        //TODO
        root = deleteNode(value, root);
    }
    
    Node* deleteNode(T value, Node* cur)
    {
        
        if (!cur) return cur;
        if (value < cur->data)
            cur->pLeft = deleteNode(value, cur->pLeft);
        else if (value > cur->data)
            cur->pRight = deleteNode(value, cur->pRight);
        else if (cur->data == value)
        {
            if (cur->pLeft == nullptr && cur->pRight == nullptr)
            {
                delete cur;
                cur = nullptr;
                return cur;
            }
            else if (cur->pLeft == nullptr)
            {
                Node *p = cur->pRight;
                delete cur;
                return p;
            }
            else if (cur->pRight == nullptr)
            {
                Node*p = cur->pLeft;
                delete cur;
                return p;
            }
            else
            {
                Node* p = cur->pLeft;
                
                while (p && p->pRight)
                    p = p->pRight;
                
                cur->data = p->data;
                cur->pLeft = deleteNode(p->data, cur->pLeft);
            }
        }
        
        // ROTATION
        
        if (cur == nullptr)
            return cur;
        
        // find first unbalanced node
        int bal = getBalanceFactor(cur);
        
        if (bal > 1) {
            if (getBalanceFactor(cur->pLeft) >= 0)
            {
                // LEFT LEFT CASE
                return rightRotate(cur);
            }
            else
            {
                // LEFT RIGHT CASE
                cur->pLeft = leftRotate(cur->pLeft);
                return rightRotate(cur);
            }
        }
        
        if (bal < -1) {
            if (getBalanceFactor(cur->pRight) <= 0)
                // RIGHT RIGHT CASE
                return leftRotate(cur);
            else {
                // RIGHT LEFT CASE
                cur->pRight = rightRotate(cur->pRight);
                return leftRotate(cur);
            }
        }
        
        return cur;
    }
    
    void printInorder()
    {
        InOrder(root);
    }
    
    void InOrder(Node* cur)
    {
        if (cur == nullptr)
            return;
        
        InOrder(cur->pLeft);
        std::cout << cur->data << " ";
        InOrder(cur->pRight);
    }

    bool search(const T &value)
    {
        Node* tmp = root;
        
        while (tmp != nullptr)
        {
            if (value == tmp->data)
                return true;
            else if (value < tmp->data)
                tmp = tmp->pLeft;
            else if (value > tmp->data)
                tmp = tmp->pRight;
            
        }
        return false;
    }

    void clear()
    {
        clearNode(root);
    }
        
    void clearNode(Node* cur)
    {
        if (cur == nullptr) return;
        
        clearNode(cur->pLeft);
        clearNode(cur->pRight);
            
        delete cur;
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(nullptr), pRight(nullptr), balance(EH) {}
        ~Node() {}
    };
};


int main()
{
        
    AVLTree<int> avl;
    int arr[] = { 10,52,98,32,68,92,40,13,42,63,99,100 };
    
    for (int i = 0; i < 12; i++)
        avl.insert(arr[i]);
    
    avl.printTreeStructure();
    avl.remove(10);
    avl.printTreeStructure();
    avl.remove(13);
    avl.printTreeStructure();
    
    return 0;
}
