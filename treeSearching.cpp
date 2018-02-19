#include <iostream>

using namespace std;

int tree[50][2];


void preorder(int index)
{
    if(index == -1) return;

    cout << (char) (index + 'A');
    preorder(tree[index][0]);
    preorder(tree[index][1]);
}

void inorder(int index)
{
    if(index == -1) return;

    inorder(tree[index][0]);
    cout << (char) (index + 'A');
    inorder(tree[index][1]);
}

void postorder(int index)
{
    if(index == -1) return;

    postorder(tree[index][0]);
    postorder(tree[index][1]);
    cout << (char) (index + 'A');
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char me, left, right;
        cin >> me >> left >> right;
        me = me - 'A';
        if (left == '.')
        {
            tree[me][0] = -1;
        }else{
            tree[me][0] = left - 'A';
        }

        if (right == '.')
        {
            tree[me][1] = -1;
        }else{
            tree[me][1] = right - 'A';
        }
    }
    //pre order
    preorder(0);
    cout << '\n';
    //in order
    inorder(0);
    cout << '\n';
    // post order
    postorder(0);
    return 0;
}
