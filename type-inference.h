#define MAX_ARGS 2

enum ast_node_type {
  IDENTIFIER = 0,
  APPLY = 1,
  LAMBDA = 2,
  LET = 3,
  LETREC = 4
};

struct ast_node {
  union {
    struct {
      char* name;
    };
    struct {
      struct ast_node* fn;
      struct ast_node* arg;
    };
    struct {
      char* v;
      struct ast_node* defn;
      struct ast_node* body;
    };
  };
  enum ast_node_type type;
};

enum lang_type_type {
  VARIABLE = 0,
  FUNCTION = 1,
  OPERATOR = 2,
  UNHANDLED_SYNTAX_NODE = -1,
  UNDEFINED_SYMBOL = -2,
  RECURSIVE_UNIFICATION = -3,
  TYPE_MISMATCH = -4,
  UNIFY_ERROR = -5,
  LOCAL_SCOPE_EXCEEDED = -6,
};

struct lang_type {
  union {
    struct {
      struct lang_type* instance;
      char* var_name;
    };
    struct {
      struct lang_type* from_type;
      struct lang_type* to_type;
    };
    struct {
      char* op_name;
      struct lang_type* types[MAX_ARGS];
      int args;
    };
    char* undefined_symbol;
  };
  int id;
  enum lang_type_type type;
};
