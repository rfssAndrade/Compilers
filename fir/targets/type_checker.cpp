#include <string>
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated
#include <cdk/types/primitive_type.h>

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

// GENERAL
void fir::type_checker::do_BooleanLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  
  if(node->left()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *readl = dynamic_cast<fir::read_node *>(node->left());

    if(readl != nullptr)
      node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else if(!node->left()->is_typed(cdk::TYPE_INT))
    throw std::string("Integer expression expected in binary operators.");

  node->right()->accept(this, lvl + 2);
  if(node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputr = dynamic_cast<fir::read_node *>(node->right());

    if(inputr != nullptr)
       node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else if(!node->right()->is_typed(cdk::TYPE_INT))
    throw std::string("Integer expression expected in binary operators.");

   node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_PIDExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT))
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if (node->left()->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_INT))
    node->type(node->left()->type());
  else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_POINTER))
    node->type(node->right()->type());
  else if(node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputl = dynamic_cast<fir::read_node*>(node->left());
    fir::read_node *inputr = dynamic_cast<fir::read_node*>(node->right());

    if(inputl != nullptr)
      node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    else
      throw std::string("Unspecified type for unknown node.");

    if(inputr != nullptr)
      node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    else
      throw std::string("Unspecified type for unknown node.");
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  }
  else if(node->left()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputl = dynamic_cast<fir::read_node*>(node->left());

    if(inputl != nullptr) {
      if(node->right()->is_typed(cdk::TYPE_DOUBLE) || node->right()->is_typed(cdk::TYPE_INT))
        node->left()->type(node->right()->type());
      else
        throw std::string("Invalid expression in right argument of binary expression.");
    }
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else if(node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputr = dynamic_cast<fir::read_node*>(node->right());

    if(inputr != nullptr) {
      if(node->left()->is_typed(cdk::TYPE_DOUBLE) || node->left()->is_typed(cdk::TYPE_INT))
        node->right()->type(node->left()->type());
      else
        throw std::string("Invalid expression in left argument of binary expression.");
    }
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else
    throw std::string("Wrong types in binary expression.");
}

void fir::type_checker::do_IDExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT))
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputl = dynamic_cast<fir::read_node*>(node->left());
    fir::read_node *inputr = dynamic_cast<fir::read_node*>(node->right());

    if(inputl != nullptr && inputr != nullptr) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    }
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else if(node->left()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputl = dynamic_cast<fir::read_node*>(node->left());

    if(inputl != nullptr) {
      node->left()->type(node->right()->type());
      node->type(node->right()->type());
    }
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else if(node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputr = dynamic_cast<fir::read_node*>(node->right());

    if(inputr != nullptr) {
      node->right()->type(node->left()->type());
      node->type(node->left()->type());
    }
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else
    throw std::string("Wrong types in binary expression.");
}

void fir::type_checker::do_ScalarLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  
  if(node->left()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputl = dynamic_cast<fir::read_node*>(node->left());

    if(inputl != nullptr)
      node->left()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else if(!node->left()->is_typed(cdk::TYPE_INT) && !node->left()->is_typed(cdk::TYPE_DOUBLE))
    throw std::string("Wrong binary logical expression (expected integer or double).");
  
  node->right()->accept(this, lvl + 2);
  if(node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputr = dynamic_cast<fir::read_node*>(node->right());

    if(inputr != nullptr)
      node->right()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else if(!node->right()->is_typed(cdk::TYPE_INT) && !node->right()->is_typed(cdk::TYPE_DOUBLE))
    throw std::string("Wrong binary logical expression (expected integer or double).");

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_GeneralLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);

  if(node->left()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputl = dynamic_cast<fir::read_node *>(node->left());

    if(inputl != nullptr)
      node->left()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    else
      throw std::string("Unspecified type for unknown node.");
  }

  node->right()->accept(this, lvl + 2);
  if(node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *inputr = dynamic_cast<fir::read_node *>(node->right());

    if(inputr != nullptr)
      node->left()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    else
      throw std::string("Unspecified type for unknown node.");
  }

  if(node->left()->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_POINTER))
    verifyPointer(cdk::reference_type::cast(node->left()->type()),cdk::reference_type::cast(node->right()->type()));
  else if(node->left()->type()->name() != node->right()->type()->name()) {
    if(!((node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE))||
    (node->left()->is_typed(cdk::TYPE_INT)  &&  node->right()->is_typed(cdk::TYPE_INT))))
        throw std::string("Operator has incompatible types.");
  }
 node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

std::shared_ptr<cdk::basic_type> fir::type_checker::verifyPointer(std::shared_ptr<cdk::reference_type> leftPtr, std::shared_ptr<cdk::reference_type> rightPtr) {
    std::shared_ptr<cdk::basic_type> left, right;
    left = leftPtr;
    right = rightPtr;
    while (left->name() == cdk::TYPE_POINTER && right->name() == cdk::TYPE_POINTER) {
      left = cdk::reference_type::cast(left)->referenced();
      right = cdk::reference_type::cast(right)->referenced();
    }
    if (left->name() == cdk::TYPE_POINTER || right->name() == cdk::TYPE_POINTER)
      throw std::string("Wrong pointer type.");
    if (left->name() == cdk::TYPE_INT && right->name() == cdk::TYPE_INT)
      return cdk::primitive_type::create(4, cdk::TYPE_INT);
    else if (left->name() == cdk::TYPE_DOUBLE && right->name() == cdk::TYPE_DOUBLE)
      return cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);
    else if (left->name() == cdk::TYPE_STRING && right->name() == cdk::TYPE_STRING)
      return cdk::primitive_type::create(4, cdk::TYPE_STRING);
    else
      throw std::string("Wrong pointer type.");
}

//---------------------------------------------------------------------------

void fir::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl + 2);
    cdk::expression_node *expression = dynamic_cast<cdk::expression_node *>(node->node(i));
    if (expression != nullptr && expression->is_typed(cdk::TYPE_UNSPEC)) {
      fir::read_node *read = dynamic_cast<fir::read_node *>(expression);

      if (read != nullptr)
        read->type(cdk::primitive_type::create(4, cdk::TYPE_INT)); // FIXME: Read??
      else
        throw std::string("Unspecified type for unknown node.");
    }
  }
}

//---------------------------------------------------------------------------

void fir::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}
void fir::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT))
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node*>(node->argument());

    if(read != nullptr) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    }
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else
    throw std::string("Wrong type in argument, integer expected.");
}
void fir::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}
void fir::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

void fir::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}

//---------------------------------------------------------------------------

void fir::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT))
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if (node->argument()->is_typed(cdk::TYPE_DOUBLE))
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node*>(node->argument());

    if(read != nullptr) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    }
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else
    throw std::string("Wrong type in argument, integer or double expected.");
}

void fir::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void fir::type_checker::processBinaryExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in left argument of binary expression");

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in right argument of binary expression");

  // in Simple, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void fir::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void fir::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void fir::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  do_IDExpression(node, lvl);
}
void fir::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  do_IDExpression(node, lvl);
}
void fir::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  do_IDExpression(node, lvl);
}
void fir::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void fir::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void fir::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void fir::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  do_ScalarLogicalExpression(node, lvl);
}
void fir::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  do_GeneralLogicalExpression(node, lvl);
}
void fir::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  do_GeneralLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

void fir::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  auto variable = _symtab.find(id);
  if (variable) {
    node->type(variable->type());
  } else {
    throw std::string("undeclared variable '" + id + "'");
  }
}

void fir::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void fir::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 2);
  node->rvalue()->accept(this, lvl + 2);

  if (node->lvalue()->is_typed(cdk::TYPE_INT)) {
    if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      fir::read_node *inputr = dynamic_cast<fir::read_node *>(node->rvalue());

      if (inputr != nullptr) {
        node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
        node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      } else
        throw std::string("Unspecified type for unknown node.");
    } else {
      throw std::string("wrong assignment to integer");
    }
  } else if (node->lvalue()->is_typed(cdk::TYPE_POINTER)) {
      if (node->rvalue()->is_typed(cdk::TYPE_POINTER)) {
        fir::null_node *n = dynamic_cast<fir::null_node *>(node->rvalue());

        if (n == nullptr)
          verifyPointer(cdk::reference_type::cast(node->lvalue()->type()), cdk::reference_type::cast(node->rvalue()->type()));

        node->type(node->rvalue()->type());
      } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
        fir::stack_alloc_node *stackr = dynamic_cast<fir::stack_alloc_node *>(node->rvalue());

        if (stackr != nullptr) {
          node->rvalue()->type(node->lvalue()->type());
          node->type(node->lvalue()->type()); //FIXME: maybe missing 193 to 198
        } else
          throw std::string("Unspecified type for unknown node.");
      } else {
        throw std::string("wrong assignment to pointer");
      }

  } else if (node->lvalue()->is_typed(cdk::TYPE_DOUBLE)) {

    if (node->rvalue()->is_typed(cdk::TYPE_DOUBLE) || node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      fir::read_node *inputr = dynamic_cast<fir::read_node *>(node->rvalue());

      if (inputr != nullptr) {
        node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_DOUBLE));
        node->type(cdk::primitive_type::create(4, cdk::TYPE_DOUBLE));
      } else
        throw std::string("Unspecified type for unknown node.");
    } else {
      throw std::string("wrong assignment to real");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_STRING)) {

    if (node->rvalue()->is_typed(cdk::TYPE_STRING)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else {
      throw std::string("wrong assignment to string");
    }

  } else {
    throw std::string("wrong types in assignment");
  }
}

//---------------------------------------------------------------------------
void fir::type_checker::do_evaluation_node(fir::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);

  if(node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node *>(node->argument());

    if(read != nullptr) {
      node->argument()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    }
    else {
      throw std::string("Unspecified type for unknown node.");
    }
  }
}

void fir::type_checker::do_print_node(fir::print_node *const node, int lvl) {
  node->arguments()->accept(this, lvl + 2);

  for(size_t i = 0; i < node->arguments()->size(); i++) {
    cdk::expression_node *expression = dynamic_cast<cdk::expression_node *>(node->arguments()->node(i));
     if (expression != nullptr && (expression->is_typed(cdk::TYPE_VOID) || expression->is_typed(cdk::TYPE_POINTER))){
        throw std::string("Wrong type in print argument.");
     }
  }
}

//---------------------------------------------------------------------------

void fir::type_checker::do_read_node(fir::read_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
}

//---------------------------------------------------------------------------

void fir::type_checker::do_while_node(fir::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (node->condition()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node *>(node->condition());

    if(read != nullptr) {
      node->condition()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else {
      throw std::string("Unspecified type for unknown node.");
    }

  } else if (!node->condition()->is_typed(cdk::TYPE_INT)) 
    throw std::string("Expected integer condition.");
}

//---------------------------------------------------------------------------

void fir::type_checker::do_if_node(fir::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (node->condition()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node *>(node->condition());

    if(read != nullptr) {
      node->condition()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else {
      throw std::string("Unspecified type for unknown node.");
    }

  } else if (!node->condition()->is_typed(cdk::TYPE_INT)) 
    throw std::string("Expected integer condition.");
}

void fir::type_checker::do_if_else_node(fir::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (node->condition()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node *>(node->condition());

    if(read != nullptr) {
      node->condition()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else {
      throw std::string("Unspecified type for unknown node.");
    }

  } else if (!node->condition()->is_typed(cdk::TYPE_INT)) 
    throw std::string("Expected integer condition.");
}

//---------------------------------------------------------------------------

void fir::type_checker::do_address_of_node(fir::address_of_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 2);
  if (!node->lvalue()->is_typed(cdk::TYPE_UNSPEC) && !node->lvalue()->is_typed(cdk::TYPE_VOID))
    node->type(cdk::reference_type::create(4, node->lvalue()->type()));
  else
    throw std::string("Wrong type in unary logical expression.");
}

void fir::type_checker::do_block_node(fir::block_node *const node, int lvl) {
  if (node->declarations())
    node->declarations()->accept(this, lvl + 2);
  
  if (node->instructions())
    node->instructions()->accept(this, lvl + 2);
}

void fir::type_checker::do_function_call_node(fir::function_call_node *const node, int lvl) {
  ASSERT_UNSPEC;

  std::string id;

  if (node->identifier() == "fir")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();

  auto function = _symtab.find(id);
  if (function == nullptr) throw std::string("function '" + id + "' is undeclared.");
  if (!function->isFunction()) throw std::string("function '" + id + "' is not a function.");

  node->type(function->type());

  if (node->arguments()->size() == function->number_of_arguments()) {
    node->arguments()->accept(this, lvl + 4);
    for (size_t ax = 0; ax < node->arguments()->size(); ax++) {
      if (node->argument(ax)->type() == function->argument_type(ax)) continue;
      if (function->argument_is_typed(ax, cdk::TYPE_DOUBLE) && node->argument(ax)->is_typed(cdk::TYPE_INT)) continue;
      throw std::string("type mismatch for argument " + std::to_string(ax + 1) + " of '" + id + "'.");
    }
  } else {
    throw std::string(
        "number of arguments in call (" + std::to_string(node->arguments()->size()) + ") must match declaration ("
            + std::to_string(function->number_of_arguments()) + ").");
  }
}
void fir::type_checker::do_function_declaration_node(fir::function_declaration_node *const node, int lvl) {
  std::string id;

  if (node->identifier() == "fir")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();

  auto function = fir::make_symbol(false, node->qualifier(), node->type(), id, false, true, true);

  std::vector < std::shared_ptr < cdk::basic_type >> argtypes;
  for (size_t ax = 0; ax < node->arguments()->size(); ax++)
    argtypes.push_back(node->argument(ax)->type());
  function->set_argument_types(argtypes);

  std::shared_ptr<fir::symbol> previous = _symtab.find(function->name());
  if (previous) {
    if (previous->number_of_arguments() == argtypes.size()) {
      for (size_t i = 0; i < argtypes.size(); i++) {
        if (previous->arguments().at(i)->name() != argtypes.at(i)->name())
          throw std::string("'" + function->name() + "' call has no matching function types.");
        else if(previous->arguments().at(i)->name() == cdk::TYPE_POINTER && argtypes.at(i)->name() == cdk::TYPE_POINTER)
          verifyPointer(cdk::reference_type::cast(previous->arguments().at(i)), cdk::reference_type::cast(argtypes.at(i)));
      }

    } else {
      throw std::string("conflicting declaration for '" + function->name() + "'");
    }
  } else {
    _symtab.insert(function->name(), function);
    _parent->set_new_symbol(function);
  }
}
void fir::type_checker::do_function_definition_node(fir::function_definition_node *const node, int lvl) {
  std::string id;

  if (node->identifier() == "fir")
    id = "_main";
  else if (node->identifier() == "_main")
    id = "._main";
  else
    id = node->identifier();

  if (node->return_value()) {  // FIXME: not working
    node->return_value()->accept(this, lvl + 2);
    if (node->return_value()->type()->name() != node->type()->name() && !(node->return_value()->is_typed(cdk::TYPE_INT) && node->is_typed(cdk::TYPE_DOUBLE))) 
      throw std::string("Missmatch in default return value and function type"); 
  }

  auto function = fir::make_symbol(false, node->qualifier(), node->type(), id, false, true);

  std::vector < std::shared_ptr < cdk::basic_type >> argtypes;
  for (size_t ax = 0; ax < node->arguments()->size(); ax++)
    argtypes.push_back(node->argument(ax)->type());
  function->set_argument_types(argtypes);

  std::shared_ptr<fir::symbol> previous = _symtab.find(function->name());
  if (previous) {
    if (previous->isFunction()) {
      if (!previous->forward())
          throw std::string("'" + function->name() + "' has already been defined.");

      if (function->qualifier() != previous->qualifier())
        throw std::string("'" + function->name() + "' declaration has a different qualifier.");

      if (function->type()->name() != previous->type()->name()) 
        throw std::string("'" + function->name() + "' redeclaration has a different return type.");
      
      if (function->type()->name() == cdk::TYPE_POINTER && previous->type()->name() == cdk::TYPE_POINTER)
        verifyPointer(cdk::reference_type::cast(previous->type()), cdk::reference_type::cast(function->type()));

      if (previous->number_of_arguments() == function->arguments().size()) {
        for (size_t i = 0; i < function->arguments().size(); i++) {
          if (previous->arguments().at(i)->name() != function->arguments().at(i)->name())
            throw std::string("'" + function->name() + "' call has no matching function types.");
          else if(previous->arguments().at(i)->name() == cdk::TYPE_POINTER && function->arguments().at(i)->name() == cdk::TYPE_POINTER)
            verifyPointer(cdk::reference_type::cast(previous->arguments().at(i)), cdk::reference_type::cast(function->arguments().at(i)));
        }
      } else 
        throw std::string("'" + function->name() + "' has a different number of arguments.");
      
      _symtab.replace(function->name(), function);
      _parent->set_new_symbol(function);
      
      const std::string &id = ":" + node->identifier();
      auto symbol = fir::make_symbol(false, node->qualifier(), node->type(), id, (bool)node->return_value(), false);
      if (!_symtab.insert(id, symbol)) { 
        throw std::string("variable '" + id + "' redeclared");
      }
    } else {
      throw std::string("'" + function->name() + "' has been declared as a different type of symbol.");
      }
  } else {
    _symtab.insert(function->name(), function);
    _parent->set_new_symbol(function);

    const std::string &id = ":" + node->identifier();
    auto symbol = fir::make_symbol(false, node->qualifier(), node->type(), id, (bool)node->return_value(), false);
    if (!_symtab.insert(id, symbol)) {
      throw std::string("variable '" + id + "' redeclared");
    }
  }
}
void fir::type_checker::do_index_node(fir::index_node *const node, int lvl) {
  ASSERT_UNSPEC;
  std::shared_ptr < cdk::reference_type > btype;

  if (node->base()) {
    node->base()->accept(this, lvl + 2);
    btype = cdk::reference_type::cast(node->base()->type());
    if (!node->base()->is_typed(cdk::TYPE_POINTER)) throw std::string("pointer expression expected in index left-value");
  } else {
    btype = cdk::reference_type::cast(_function->type());
    if (!_function->is_typed(cdk::TYPE_POINTER)) throw std::string("return pointer expression expected in index left-value");
  }

  node->index()->accept(this, lvl + 2);
  if(node->index()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node *>(node->index());

    if(read != nullptr)
      node->index()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    else
      throw std::string("Unspecified type for unknown node.");
  } else if (!node->index()->is_typed(cdk::TYPE_INT)) throw std::string("integer expression expected in left-value index");

  node->type(btype->referenced());
}
void fir::type_checker::do_leave_node(fir::leave_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_null_node(fir::null_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, nullptr));
}
void fir::type_checker::do_restart_node(fir::restart_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_return_node(fir::return_node *const node, int lvl) {
  // EMPTY
}
void fir::type_checker::do_sizeof_node(fir::sizeof_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->expression()->accept(this, lvl + 2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}
void fir::type_checker::do_stack_alloc_node(fir::stack_alloc_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if(node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    fir::read_node *read = dynamic_cast<fir::read_node *>(node->argument());

    if(read != nullptr)
      node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    else
      throw std::string("Unspecified type for unknown node.");
  }
  else if (!node->argument()->is_typed(cdk::TYPE_INT))
    throw std::string("Integer expression expected in allocation expression.");

  node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
}
void fir::type_checker::do_variable_declaration_node(fir::variable_declaration_node *const node, int lvl) {
  if (node->initializer() != nullptr) {
    node->initializer()->accept(this, lvl + 2);
    if (node->initializer()->is_typed(cdk::TYPE_UNSPEC)){
       fir::read_node *input = dynamic_cast<fir::read_node*>(node->initializer());
       fir::stack_alloc_node *stack = dynamic_cast<fir::stack_alloc_node*>(node->initializer());
      if(input != nullptr) {
        if(node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_DOUBLE))
          node->initializer()->type(node->type());
        else
          throw std::string("Unable to read.");
      } else if (stack != nullptr) {
        if (node->is_typed(cdk::TYPE_POINTER))
          node->initializer()->type(node->type());
      } else
        throw std::string("Unspecified type for unknown node.");
    
    } else if (node->is_typed(cdk::TYPE_INT)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (node->is_typed(cdk::TYPE_STRING)) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (node->is_typed(cdk::TYPE_POINTER)) {
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        throw std::string("Wrong type for initializer (pointer expected).");
      }
    } else {
      throw std::string("unknown type for initializer.");
    }
  }

  const std::string &id = node->identifier();
  auto symbol = fir::make_symbol(false, node->qualifier(), node->type(), id, (bool)node->initializer(), false);
  if (_symtab.insert(id, symbol)) {
    _parent->set_new_symbol(symbol);
  } else {
    throw std::string("variable '" + id + "' redeclared");
  }
}
void fir::type_checker::do_body_node(fir::body_node *const node, int lvl) {
  if (node->prologue())
    node->prologue()->accept(this, lvl + 2);

  if (node->block())
    node->block()->accept(this, lvl + 2);

  if (node->epilogue())
    node->epilogue()->accept(this, lvl + 2);
}
void fir::type_checker::do_identity_node(fir::identity_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}
void fir::type_checker::do_prologue_node(fir::prologue_node *const node, int lvl) {
  if (node->prologue())
    node->prologue()->accept(this, lvl + 2);
}