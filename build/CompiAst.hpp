/* CompiAst.hpp.  Generated automatically by treecc */
#ifndef __yy_CompiAst_hpp
#define __yy_CompiAst_hpp
#line 3 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"

    #include <string>
    #include <unordered_map>
    #include <iostream>
    #include <iomanip>
    #include <vector>
    #include <variant>

    using valores = std::variant<std::string, int>;
    using stdstring = std::string;

    struct variable_valor{
        stdstring Identificador;
        stdstring direccion;
        valores valor;
    };

    struct variable_Tipo{
        stdstring Tipo;
        stdstring variable;
    };

    using Variables = std::vector<variable_valor>;
    using Tipos = std::vector<variable_Tipo>;

    void resetCodegen();
	int getOffset();
	int addOffset();
	stdstring newLabel();
    bool siTipo(Tipos& tipo_var, std::string var, std::string tipo);
    stdstring TipoVar(std::string var);
#line 37 "CompiAst.hpp"

#include <new>

const int AstNode_kind = 1;
const int Expr_kind = 2;
const int Program_kind = 3;
const int Stmt_kind = 24;
const int BinaryExpr_kind = 4;
const int NumExpr_kind = 18;
const int IdentExpr_kind = 19;
const int BoolExpr_kind = 20;
const int CaracterExpr_kind = 21;
const int CadenaExpr_kind = 22;
const int ArregloExpr_kind = 23;
const int DeclaracionStmt_kind = 27;
const int AddExpr_kind = 5;
const int MulExpr_kind = 6;
const int DivExpr_kind = 7;
const int SubExpr_kind = 8;
const int ModExpr_kind = 9;
const int MayorExpr_kind = 10;
const int MenorExpr_kind = 11;
const int MayorIExpr_kind = 12;
const int MenorIExpr_kind = 13;
const int IgualExpr_kind = 14;
const int DesigualExpr_kind = 15;
const int OrExpr_kind = 16;
const int AndExpr_kind = 17;
const int Vacio_kind = 25;
const int BlockStmts_kind = 26;
const int Declaracionvariable_kind = 28;
const int AsignarStmt_kind = 29;
const int ForStmt_kind = 30;
const int EscribaStmt_kind = 31;
const int IfStmt_kind = 32;
const int WhileStmt_kind = 33;
const int RetorneStmt_kind = 34;
const int LeaStmt_kind = 35;

class AstNode;
class Expr;
class Program;
class Stmt;
class BinaryExpr;
class NumExpr;
class IdentExpr;
class BoolExpr;
class CaracterExpr;
class CadenaExpr;
class ArregloExpr;
class DeclaracionStmt;
class AddExpr;
class MulExpr;
class DivExpr;
class SubExpr;
class ModExpr;
class MayorExpr;
class MenorExpr;
class MayorIExpr;
class MenorIExpr;
class IgualExpr;
class DesigualExpr;
class OrExpr;
class AndExpr;
class Vacio;
class BlockStmts;
class Declaracionvariable;
class AsignarStmt;
class ForStmt;
class EscribaStmt;
class IfStmt;
class WhileStmt;
class RetorneStmt;
class LeaStmt;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 126 "CompiAst.hpp"
private:

	static YYNODESTATE *state__;

public:

	static YYNODESTATE *getState()
		{
			if(state__) return state__;
			state__ = new YYNODESTATE();
			return state__;
		}

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual const char *currFilename() const;
	virtual long currLinenum() const;

};

class AstNode
{
protected:

	int kind__;
	const char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(const char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	AstNode();

public:

	stdstring place;
	stdstring code;

	virtual int semantica() = 0;
	virtual stdstring Gencode(Tipos & tipos) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AstNode();

};

class Expr : public AstNode
{
protected:

	Expr();

public:

	virtual int semantica() = 0;
	virtual stdstring Gencode(Tipos & tipos) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expr();

};

class Program : public AstNode
{
public:

	Program(AstNode * declVar, AstNode * declFun, AstNode * main);

public:

	AstNode * declVar;
	AstNode * declFun;
	AstNode * main;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Program();

};

class Stmt : public AstNode
{
protected:

	Stmt();

public:

	virtual int semantica() = 0;
	virtual stdstring Gencode(Tipos & tipos) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Stmt();

};

class BinaryExpr : public Expr
{
protected:

	BinaryExpr(Expr * expr1, Expr * expr2);

public:

	Expr * expr1;
	Expr * expr2;

	virtual int semantica() = 0;
	virtual stdstring Gencode(Tipos & tipos) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpr();

};

class NumExpr : public Expr
{
public:

	NumExpr(int value);

public:

	int value;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NumExpr();

};

class IdentExpr : public Expr
{
public:

	IdentExpr(stdstring text);

public:

	stdstring text;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IdentExpr();

};

class BoolExpr : public Expr
{
public:

	BoolExpr(int booleano);

public:

	int booleano;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BoolExpr();

};

class CaracterExpr : public Expr
{
public:

	CaracterExpr(char character);

public:

	char character;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~CaracterExpr();

};

class CadenaExpr : public Expr
{
public:

	CadenaExpr(stdstring cadena);

public:

	stdstring cadena;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~CadenaExpr();

};

class ArregloExpr : public Expr
{
public:

	ArregloExpr(stdstring txt);

public:

	stdstring txt;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArregloExpr();

};

class DeclaracionStmt : public Expr
{
public:

	DeclaracionStmt(AstNode * ident1, AstNode * ident2);

public:

	AstNode * ident1;
	AstNode * ident2;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DeclaracionStmt();

};

class AddExpr : public BinaryExpr
{
public:

	AddExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpr();

};

class MulExpr : public BinaryExpr
{
public:

	MulExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MulExpr();

};

class DivExpr : public BinaryExpr
{
public:

	DivExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpr();

};

class SubExpr : public BinaryExpr
{
public:

	SubExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpr();

};

class ModExpr : public BinaryExpr
{
public:

	ModExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ModExpr();

};

class MayorExpr : public BinaryExpr
{
public:

	MayorExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MayorExpr();

};

class MenorExpr : public BinaryExpr
{
public:

	MenorExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MenorExpr();

};

class MayorIExpr : public BinaryExpr
{
public:

	MayorIExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MayorIExpr();

};

class MenorIExpr : public BinaryExpr
{
public:

	MenorIExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MenorIExpr();

};

class IgualExpr : public BinaryExpr
{
public:

	IgualExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IgualExpr();

};

class DesigualExpr : public BinaryExpr
{
public:

	DesigualExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DesigualExpr();

};

class OrExpr : public BinaryExpr
{
public:

	OrExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OrExpr();

};

class AndExpr : public BinaryExpr
{
public:

	AndExpr(Expr * expr1, Expr * expr2);

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AndExpr();

};

class Vacio : public Stmt
{
public:

	Vacio();

public:

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Vacio();

};

class BlockStmts : public Stmt
{
public:

	BlockStmts(AstNode * stmt1, AstNode * stmt2);

public:

	AstNode * stmt1;
	AstNode * stmt2;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BlockStmts();

};

class Declaracionvariable : public Stmt
{
public:

	Declaracionvariable(AstNode * ident, AstNode * ident2);

public:

	AstNode * ident;
	AstNode * ident2;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Declaracionvariable();

};

class AsignarStmt : public Stmt
{
public:

	AsignarStmt(IdentExpr * var, AstNode * var_value);

public:

	IdentExpr * var;
	AstNode * var_value;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AsignarStmt();

};

class ForStmt : public Stmt
{
public:

	ForStmt(AsignarStmt * asignacion, Expr * hasta, AstNode * stmtst);

public:

	AsignarStmt * asignacion;
	Expr * hasta;
	AstNode * stmtst;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ForStmt();

};

class EscribaStmt : public Stmt
{
public:

	EscribaStmt(AstNode * expr1);

public:

	AstNode * expr1;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EscribaStmt();

};

class IfStmt : public Stmt
{
public:

	IfStmt(AstNode * condi, AstNode * stmt_tr, AstNode * stmt_f);

public:

	AstNode * condi;
	AstNode * stmt_tr;
	AstNode * stmt_f;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStmt();

};

class WhileStmt : public Stmt
{
public:

	WhileStmt(AstNode * condi, AstNode * stmt_tr);

public:

	AstNode * condi;
	AstNode * stmt_tr;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStmt();

};

class RetorneStmt : public Stmt
{
public:

	RetorneStmt(AstNode * retorno);

public:

	AstNode * retorno;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~RetorneStmt();

};

class LeaStmt : public Stmt
{
public:

	LeaStmt(AstNode * leer);

public:

	AstNode * leer;

	virtual int semantica();
	virtual stdstring Gencode(Tipos & tipos);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LeaStmt();

};



#endif
