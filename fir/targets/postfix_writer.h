#ifndef __FIR_TARGETS_POSTFIX_WRITER_H__
#define __FIR_TARGETS_POSTFIX_WRITER_H__

#include "targets/basic_ast_visitor.h"

#include <set>
#include <vector>
#include <sstream>
#include <cdk/emitters/basic_postfix_emitter.h>

namespace fir {

  //!
  //! Traverse syntax tree and generate the corresponding assembly code.
  //!
  class postfix_writer: public basic_ast_visitor {
    cdk::symbol_table<fir::symbol> &_symtab;
    std::set<std::string> _functions_to_declare;
    
    bool _errors = false, _inFunction = false, _inFunctionName = false, _inFunctionArgs = false, _inFunctionBody = false, _inPrologue = false, _inBlock = false, _inEpilogue = false;
    bool _inWhileInit;
    bool _returnSeen; // when building a function
    std::vector<int> _whileCondition, _whileFinally; // for leave/restart
    
    std::shared_ptr<fir::symbol> _function; // for keeping track of the current function and its arguments
    int _offset; // current framepointer offset (0 means no vars defined)
    cdk::typename_type _lvalueType;

    std::string _currentFunctionName;
    std::string _currentEpilogueLabel; // where to jump when a return occurs of an exclusive section ends
    std::string _currentFunctionEndLabel;
    
    cdk::basic_postfix_emitter &_pf;
    int _lbl;

  public:
    postfix_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<fir::symbol> &symtab, cdk::basic_postfix_emitter &pf) :
        basic_ast_visitor(compiler), _symtab(symtab), _errors(false), _inFunction(false), _inFunctionName(false), _inFunctionArgs(
            false), _inFunctionBody(false), _returnSeen(false), _function(nullptr), _offset(0), _lvalueType(
            cdk::TYPE_VOID), _currentFunctionName(""), _currentEpilogueLabel(""), _currentFunctionEndLabel(""), _pf(pf), _lbl(0) {
    }

  public:
    ~postfix_writer() {
      os().flush();
    }

  private:
    /** Method used to generate sequential labels. */
    inline std::string mklbl(int lbl) {
      std::ostringstream oss;
      if (lbl < 0)
        oss << ".L" << -lbl;
      else
        oss << "_L" << lbl;
      return oss.str();
    }
    
    void error(int lineno, std::string s) {
      std::cerr << "error: " << lineno << ": " << s << std::endl;
    }

  public:
  // do not edit these lines
#define __IN_VISITOR_HEADER__
#include "ast/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
  // do not edit these lines: end

  };

} // fir

#endif
