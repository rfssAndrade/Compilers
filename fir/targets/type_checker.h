#ifndef __FIR_TARGETS_TYPE_CHECKER_H__
#define __FIR_TARGETS_TYPE_CHECKER_H__

#include "targets/basic_ast_visitor.h"
#include <cdk/types/reference_type.h>

namespace fir {

  /**
   * Print nodes as XML elements to the output stream.
   */
  class type_checker: public basic_ast_visitor {
    cdk::symbol_table<fir::symbol> &_symtab;
    std::shared_ptr<fir::symbol> _function;
    basic_ast_visitor *_parent;
    std::shared_ptr<cdk::basic_type> _inBlockReturnType = nullptr;

  public:
    type_checker(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<fir::symbol> &symtab, basic_ast_visitor *parent) :
        basic_ast_visitor(compiler), _symtab(symtab), _parent(parent) {
    }

  public:
    ~type_checker() {
      os().flush();
    }

  protected:
    void do_BooleanLogicalExpression(cdk::binary_operation_node *const node, int lvl);
    void do_PIDExpression(cdk::binary_operation_node *const node, int lvl);
    void do_IDExpression(cdk::binary_operation_node *const node, int lvl);
    void do_ScalarLogicalExpression(cdk::binary_operation_node *const node, int lvl);
    void do_GeneralLogicalExpression(cdk::binary_operation_node *const node, int lvl);
    std::shared_ptr<cdk::basic_type> verifyPointer(std::shared_ptr<cdk::reference_type> leftPtr, std::shared_ptr<cdk::reference_type> rightPtr);

    void processUnaryExpression(cdk::unary_operation_node *const node, int lvl);
    void processBinaryExpression(cdk::binary_operation_node *const node, int lvl);

  public:
    // do not edit these lines
#define __IN_VISITOR_HEADER__
#include "ast/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
    // do not edit these lines: end

  };

} // fir

//---------------------------------------------------------------------------
//     HELPER MACRO FOR TYPE CHECKING
//---------------------------------------------------------------------------

#define CHECK_TYPES(compiler, symtab, node) { \
  try { \
    fir::type_checker checker(compiler, symtab, this); \
    (node)->accept(&checker, 0); \
  } \
  catch (const std::string &problem) { \
    std::cerr << (node)->lineno() << ": " << problem << std::endl; \
    return; \
  } \
}

#define ASSERT_SAFE_EXPRESSIONS CHECK_TYPES(_compiler, _symtab, node)

#endif
