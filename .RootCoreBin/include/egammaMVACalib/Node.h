#ifndef egamma_Node_H
#define egamma_Node_H

#include <vector>
#include <cstdint>
namespace TMVA { class DecisionTreeNode; }

namespace egammaMVACalibNmsp
{
    /** Node of a binary tree, defined by the index of the variable 
      * (m_var, set to -1 for leaf nodes),
      * the cut value or the response (m_val) and pointers to the left
      * and right child nodes.
      * The full tree structure can be accessed from the top node and the
      * structure obeys: value > m_val -> left node, else right node.
      *
      * The class provides (recursive) functions to create, destroy and evaluate
      * the response of the complete decision or regression tree 
      * (when called from the top node).
      **/
    class Node
    {
      public:    
	Node(const int ivar, const float val): m_var(ivar), m_val(val), m_left(0), m_right(0) {}
	Node(const TMVA::DecisionTreeNode *node);
        ~Node();
	
	int8_t GetVar() const { return m_var; }
	float GetVal() const { return m_val; }
	Node* GetNext(const float value) const ;
    
	float GetResponse(const std::vector<float>& values) const;
	float GetResponse(const std::vector<float*>& pointers) const;
	
	void AddToVectors(std::vector<int>& vars, std::vector<float>& values) const;
	
	static Node* newNode(const std::vector<int>& vars, const std::vector<float>& values, int &i);
	
      private:
	int8_t m_var; //! index of the variable to cut for internal nodes, -1 for leaf nodes
	float m_val; //! cut value for internal nodes or response for leaf nodes
	Node *m_left; //! pointer to left child node (value > m_val)
	Node *m_right; //! pointer to right child node (value <= m_val)
    };
}

#endif
