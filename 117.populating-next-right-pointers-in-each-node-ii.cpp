/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)return root;
        Node* cur = root;
        while(cur != NULL){
            // Dummy Variable to indicate leftmost of current node
            Node* dummy = new Node(-1);
            // Get a reference of that node
            Node * prev = dummy;
            while(cur != NULL){
                // if the left of cur is not null,
                // make prev next point to it
                if(cur->left){
                    prev->next = cur->left;
                    // then update the prev
                    prev = prev -> next;
                }
                // Similarly deal with right
                if(cur->right){
                    prev->next = cur->right;
                    prev = prev -> next;
                }
                // move to next node in this line
                cur = cur->next;
            }
            // move to leftmost valid node at this level,
            // note that prev was a reference to dummy
            cur = dummy->next;
        }
        return root;
    }
};
// @lc code=end

