#ifndef __FIR_AST_WHILE_NODE_H__
#define __FIR_AST_WHILE_NODE_H__

#include <cdk/ast/expression_node.h>

namespace fir {

  /**
   * Class for describing while-cycle nodes.
   */
  class while_node: public cdk::basic_node {
    cdk::expression_node *_condition;
    cdk::basic_node *_instruction;
    cdk::basic_node *_finally;

  public:
    inline while_node(int lineno, cdk::expression_node *condition, cdk::basic_node *block, cdk::basic_node *finally) :
        basic_node(lineno), _condition(condition), _instruction(block), _finally(finally) {
    }

  public:
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline cdk::basic_node *instruction() {
      return _instruction;
    }
    inline cdk::basic_node *finally() {
      return _finally;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_while_node(this, level);
    }

  };

} // fir

#endif
