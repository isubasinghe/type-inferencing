#define MAX_ARGS 2

typedef enum {
	VARIABLE = 0,
	FUNCTION = 1,
	OPERATOR = 2,
	UNHANDLED_SYNTAX_NODE = -1,
	UNDEFINED_SYMBOL = -2,
	RECURSIVE_UNIFICATION = -3,
	TYPE_MISMATCH = -4,
	UNIFY_ERROR = -5,
	LOCAL_SCOPE_EXCEEDED = -6,
	OUT_OF_TYPES = -7,
} type_t;
typedef struct Type {
	union {
		struct {
			struct Type *instance;
			char *var_name;
		};
		struct {
			struct Type *from_type;
			struct Type *to_type;
		};
		struct {
			char *op_name;
			struct Type *types[MAX_ARGS];
			int args;
		};
		char *undefined_symbol;
	};
	int id;
	type_t type;
} Type;
typedef enum {
	IDENTIFIER = 0,
	APPLY = 1,
	LAMBDA = 2,
	LET = 3,
	LETREC = 4
} term_t;
typedef struct Term {
	union {
		struct {
			char *name;
		};
		struct {
			struct Term *fn;
			struct Term *arg;
		};
		struct {
			char *v;
			struct Term *defn;
			struct Term *body;
		};
	};
	term_t type;
} Term;

typedef struct TypeList TypeList;
typedef struct Env {
	char *name;
	Type *node;
	struct Env *next;
} Env;
typedef struct Inferencer Inferencer;
Type *analyze(Inferencer *, Term *, Env *, TypeList *);

void print(Term *, Type *);
