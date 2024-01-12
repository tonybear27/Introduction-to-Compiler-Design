#ifndef AST_DECL_NODE_H
#define AST_DECL_NODE_H

#include "AST/ConstantValue.hpp"
#include "AST/ast.hpp"
#include "AST/utils.hpp"
#include "AST/variable.hpp"

#include <memory>
#include <vector>

class PType;

class DeclNode : public AstNode {
  public:
    typedef std::vector<std::unique_ptr<VariableNode>> VarNodes;

    // variable declaration
    DeclNode(const uint32_t line, const uint32_t col,
             const std::vector<IdInfo> *p_id_list, const PType *p_type);

    // constant variable declaration
    DeclNode(const uint32_t, const uint32_t col,
             const std::vector<IdInfo> *p_id_list,
             ConstantValueNode *p_constant);

    ~DeclNode() = default;

    const VarNodes &getVariables() const;

    void accept(AstNodeVisitor &p_visitor) override;
    void visitChildNodes(AstNodeVisitor &p_visitor) override;

    const char* get_first_name_Cstr(){return vars[0]->getNameCString();};

  private:
    VarNodes vars;
};

#endif
