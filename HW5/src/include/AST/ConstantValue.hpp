#ifndef AST_CONSTANT_VALUE_NODE_H
#define AST_CONSTANT_VALUE_NODE_H

#include "AST/constant.hpp"
#include "AST/expression.hpp"

#include <memory>

class ConstantValueNode : public ExpressionNode {
  public:
    ConstantValueNode(const uint32_t line, const uint32_t col,
                      const Constant *p_constant);
    ~ConstantValueNode() = default;

    const PTypeSharedPtr &getTypePtr() const;
    const char *getConstantValueCString() const;
    const Constant *getConstantPtr() const;

    void accept(AstNodeVisitor &p_visitor) override;

  private:
    std::unique_ptr<const Constant> constant;
};

#endif
