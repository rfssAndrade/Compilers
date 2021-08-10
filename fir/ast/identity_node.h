#ifndef __FIR_AST_IDENTITY_NODE_H__
#define __FIR_AST_IDENTITY_NODE_H__

#include <cdk/ast/unary_operation_node.h>
#include <cdk/ast/expression_node.h>

namespace fir {

  class identity_node: public cdk::unary_operation_node {
  public:
    identity_node(int lineno, cdk::expression_node *arg) :
        unary_operation_node(lineno, arg) {
    }

    void accept(basic_ast_visitor *av, int level) {
      av->do_identity_node(this, level);
    }

  };

} // fir

#endif
