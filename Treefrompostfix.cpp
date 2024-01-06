#include <iostream>
#include <stack>

using namespace std;

// Node representing a tree node
struct Node {
    string data;
    Node* left;
    Node* right;
};

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to create a new Node
Node* createNode(string val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to construct Expression Tree from postfix expression
Node* constructExpressionTree(string postfix) {
    stack<Node*> st;

    for (int i = 0; i < postfix.length(); ++i) {
        char c = postfix[i];
        if (isOperator(c)) {
            Node* newNode = createNode(string(1, c));
            newNode->right = st.top();
            st.pop();
            newNode->left = st.top();
            st.pop();
            st.push(newNode);
        } else {
            Node* operand = createNode(string(1, c));
            st.push(operand);
        }
    }

    return st.top();
}

// Recursive In-order traversal of Expression Tree
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Recursive Pre-order traversal of Expression Tree
void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Recursive Post-order traversal of Expression Tree
void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    string postfixExpression = "34+5*6-";

    Node* root = constructExpressionTree(postfixExpression);

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
