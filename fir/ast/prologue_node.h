#ifndef __FIR_AST_PROLOGUE_H__
#define __FIR_AST_PROLOGUE_H__

#include <cdk/ast/basic_node.h>

namespace fir {

  class prologue_node: public cdk::basic_node {
    fir::block_node *_prologue;

  public:
    prologue_node(int lineno, fir::block_node *prologue) :
        cdk::basic_node(lineno), _prologue(prologue) {
    }

  public:

    fir::block_node* prologue() {
        return _prologue;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_prologue_node(this, level);
    }

  };

} // fir

#endif
