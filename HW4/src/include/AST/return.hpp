#ifndef AST_RETURN_NODE_H
#define AST_RETURN_NODE_H

#include "AST/ast.hpp"
#include "AST/expression.hpp"
#include "visitor/AstNodeVisitor.hpp"

#include <memory>
using namespace std;

class ReturnNode final : public AstNode {
  private:
    unique_ptr<ExpressionNode> m_ret_val;

  public:
    ~ReturnNode() = default;
    ReturnNode(const uint32_t line, const uint32_t col,
               ExpressionNode *p_ret_val)
        : AstNode{line, col}, m_ret_val(p_ret_val){}
    const int checkInvalidRetrunType() const;
    const char *getReturnTypeCString() const;
    const uint32_t getReturnLocationCol() const;
    void accept(AstNodeVisitor &p_visitor) override { p_visitor.visit(*this); }
    void visitChildNodes(AstNodeVisitor &p_visitor) override;
};

#endif
