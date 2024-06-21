/* CompiAst.cpp.  Generated automatically by treecc */
#line 32 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"

    #include <iostream>
    #include <string>
    #include <variant>
    #include <vector>
    #include <algorithm>
    #include "CompiAst.hpp"
    int labels = 0;
    int offset = 4;
    int offset_stmts = 0;
    int drec = 0;
    Variables vars;

    
    void resetCodegen(){
		offset = 0;
		labels = 0;
		drec = 0;
	}

	int getOffset(){
		
		return offset;
	}

	int addOffset()
	{
		return offset += 4;
	}
    int getOffset_stmt(){
		
		return offset_stmts;
	}

	int addOffset_stmt()
	{
		return offset_stmts += 4;
	}

	stdstring newLabel()
	{
		std::string temp = "label_" + std::to_string(labels);
		labels += 1;
		return temp;
	}

	stdstring newTemp()
	{	
		std::string temp = "T" + std::to_string(drec);
		drec += 1;
		return temp;
	}

    stdstring getPlace(AstNode* e){
		if(e->isA(NumExpr_kind))
			return e->place;
		return "["+e->place+"]";
	}
#line 62 "CompiAst.cpp"

#define YYNODESTATE_TRACK_LINES 1
#define YYNODESTATE_USE_ALLOCATOR 1
#line 1 "cpp_skel.cc"
/*
 * treecc node allocation routines for C++.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * Initialize the singleton instance.
 */
#ifndef YYNODESTATE_REENTRANT
YYNODESTATE *YYNODESTATE::state__ = 0;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	((unsigned)(unsigned long)(&(((struct _YYNODESTATE_align_##type *)0)->field)))
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Constructor for YYNODESTATE.
 */
YYNODESTATE::YYNODESTATE()
{
	/* Initialize the allocation state */
	blocks__ = 0;
	push_stack__ = 0;
	used__ = 0;

#ifndef YYNODESTATE_REENTRANT
	/* Register this object as the singleton instance */
	if(!state__)
	{
		state__ = this;
	}
#endif
}

/*
 * Destructor for YYNODESTATE.
 */
YYNODESTATE::~YYNODESTATE()
{
	/* Free all node memory */
	clear();

#ifndef YYNODESTATE_REENTRANT
	/* We are no longer the singleton instance */
	if(state__ == this)
	{
		state__ = 0;
	}
#endif
}

#ifdef YYNODESTATE_USE_ALLOCATOR

/*
 * Allocate a block of memory.
 */
void *YYNODESTATE::alloc(size_t size__)
{
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = blocks__;
	if(!block__ || (used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = new YYNODESTATE_block;
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   inherit the "failed" method to report the
			   out of memory state and/or abort the program */
			failed();
			return (void *)0;
		}
		block__->next__ = blocks__;
		blocks__ = block__;
		used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + used__);
	used__ += size__;
	return result__;
}

/*
 * Deallocate a block of memory.
 */
void YYNODESTATE::dealloc(void *ptr__, size_t size__)
{
	/* Nothing to do for this type of node allocator */
}

/*
 * Push the node allocation state.
 */
int YYNODESTATE::push()
{
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = blocks__;
	saved_used__ = used__;

	/* Allocate space for a push item */
	push_item__ = (struct YYNODESTATE_push *)
			alloc(sizeof(struct YYNODESTATE_push));
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = push_stack__;
	push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
void YYNODESTATE::pop()
{
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		used__ = push_item__->saved_used__;
		push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(blocks__ != saved_block__)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
}

/*
 * Clear the node allocation pool completely.
 */
void YYNODESTATE::clear()
{
	struct YYNODESTATE_block *temp_block__;
	while(blocks__ != 0)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
	push_stack__ = 0;
	used__ = 0;
}

#endif /* YYNODESTATE_USE_ALLOCATOR */

/*
 * Default implementation of functions which may be overridden.
 */
void YYNODESTATE::failed()
{
}

#ifdef YYNODESTATE_TRACK_LINES

const char *YYNODESTATE::currFilename() const
{
	return (const char *)0;
}

long YYNODESTATE::currLinenum() const
{
	return 0;
}

#endif
#line 341 "CompiAst.cpp"
void *AstNode::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void AstNode::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

AstNode::AstNode()
{
	this->kind__ = AstNode_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

AstNode::~AstNode()
{
	// not used
}

int AstNode::isA(int kind) const
{
	if(kind == AstNode_kind)
		return 1;
	else
		return 0;
}

const char *AstNode::getKindName() const
{
	return "AstNode";
}

Expr::Expr()
	: AstNode()
{
	this->kind__ = Expr_kind;
}

Expr::~Expr()
{
	// not used
}

int Expr::isA(int kind) const
{
	if(kind == Expr_kind)
		return 1;
	else
		return AstNode::isA(kind);
}

const char *Expr::getKindName() const
{
	return "Expr";
}

Program::Program(Stmt * stmts)
	: AstNode()
{
	this->kind__ = Program_kind;
	this->stmts = stmts;
}

Program::~Program()
{
	// not used
}

int Program::semantica()
#line 288 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    stmts->semantica();

    return 0.0;
}
#line 420 "CompiAst.cpp"

stdstring Program::Gencode()
#line 482 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    //stmts->Gencode();

    //hacer push de 
    stmts->Gencode();;
    //code = varia;
    for (const auto& var : vars) {
        std::cout<< var.Identificador << " = " << var.direccion <<"\n";
        code += "\tpush 0\n";
    }

    code += "\tcall main\n";
    code += "\tadd esp, " + std::to_string(getOffset() - 4) + "\n";
    code += "\tmov eax, 1\n";
    code += "\tint 0x80\n";
    code += "main:\n";
    code += "\tpush ebp\n";
    code += "\tmov ebp, esp\n";
    code += "\tsub esp, " + std::to_string(getOffset_stmt()) + "\n";
    code += stmts->code;
    code += "\tleave\n\tret\n";

    
    return code;
}
#line 449 "CompiAst.cpp"

int Program::isA(int kind) const
{
	if(kind == Program_kind)
		return 1;
	else
		return AstNode::isA(kind);
}

const char *Program::getKindName() const
{
	return "Program";
}

Stmt::Stmt()
	: AstNode()
{
	this->kind__ = Stmt_kind;
}

Stmt::~Stmt()
{
	// not used
}

int Stmt::isA(int kind) const
{
	if(kind == Stmt_kind)
		return 1;
	else
		return AstNode::isA(kind);
}

const char *Stmt::getKindName() const
{
	return "Stmt";
}

BinaryExpr::BinaryExpr(Expr * expr1, Expr * expr2)
	: Expr()
{
	this->kind__ = BinaryExpr_kind;
	this->expr1 = expr1;
	this->expr2 = expr2;
}

BinaryExpr::~BinaryExpr()
{
	// not used
}

int BinaryExpr::isA(int kind) const
{
	if(kind == BinaryExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *BinaryExpr::getKindName() const
{
	return "BinaryExpr";
}

NumExpr::NumExpr(int value)
	: Expr()
{
	this->kind__ = NumExpr_kind;
	this->value = value;
}

NumExpr::~NumExpr()
{
	// not used
}

int NumExpr::semantica()
#line 240 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    
    return value;
}
#line 532 "CompiAst.cpp"

stdstring NumExpr::Gencode()
#line 399 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = std::to_string(value);
    code = "";
    return "";
}
#line 541 "CompiAst.cpp"

int NumExpr::isA(int kind) const
{
	if(kind == NumExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *NumExpr::getKindName() const
{
	return "NumExpr";
}

IdentExpr::IdentExpr(stdstring text)
	: Expr()
{
	this->kind__ = IdentExpr_kind;
	this->text = text;
}

IdentExpr::~IdentExpr()
{
	// not used
}

int IdentExpr::semantica()
#line 245 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    

    return 0.0;
}
#line 575 "CompiAst.cpp"

stdstring IdentExpr::Gencode()
#line 406 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    bool encontrado = false;
    for (const auto& var : vars) {
        if (var.Identificador == text) {
            encontrado = true;
            place = var.direccion;
            break;
        }
    }

    if (!encontrado) {
        place = "ebp + " +std::to_string(addOffset());
        vars.push_back({text, place, 0});
        //code = "\tpush 0\n";
    }
    return "";
}
#line 596 "CompiAst.cpp"

int IdentExpr::isA(int kind) const
{
	if(kind == IdentExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *IdentExpr::getKindName() const
{
	return "IdentExpr";
}

DeclaracionStmt::DeclaracionStmt(Expr * ident1, Expr * ident2)
	: Expr()
{
	this->kind__ = DeclaracionStmt_kind;
	this->ident1 = ident1;
	this->ident2 = ident2;
}

DeclaracionStmt::~DeclaracionStmt()
{
	// not used
}

int DeclaracionStmt::semantica()
#line 284 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    return 0.0;
}
#line 629 "CompiAst.cpp"

stdstring DeclaracionStmt::Gencode()
#line 463 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    ident1->Gencode();
    ident2->Gencode();
    
    code = ident1->code + ident2->code;

    return code;
}
#line 641 "CompiAst.cpp"

int DeclaracionStmt::isA(int kind) const
{
	if(kind == DeclaracionStmt_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *DeclaracionStmt::getKindName() const
{
	return "DeclaracionStmt";
}

AddExpr::AddExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = AddExpr_kind;
}

AddExpr::~AddExpr()
{
	// not used
}

int AddExpr::semantica()
#line 169 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{

    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return v1 + v2;
}
#line 676 "CompiAst.cpp"

stdstring AddExpr::Gencode()
#line 301 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - " + std::to_string(addOffset_stmt());

    expr1->Gencode();
    expr2->Gencode();
    code += expr1->code + expr2->code;
    code += "\tmov eax, [" + expr1->place + "]\n";
    code += "\tadd eax, [" + expr2->place + "]\n";
    code += "\tmov [" + place + "], eax\n";
    return code;
}
#line 691 "CompiAst.cpp"

int AddExpr::isA(int kind) const
{
	if(kind == AddExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *AddExpr::getKindName() const
{
	return "AddExpr";
}

MulExpr::MulExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = MulExpr_kind;
}

MulExpr::~MulExpr()
{
	// not used
}

int MulExpr::semantica()
#line 177 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return v1 * v2;
}
#line 725 "CompiAst.cpp"

stdstring MulExpr::Gencode()
#line 313 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	
	expr1->Gencode();
    expr2->Gencode();
    code += expr1->code + expr2->code;
	code += "\tmov eax, " + getPlace(expr1) +"\n\timul eax, " + getPlace(expr2) + "\n";
	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 739 "CompiAst.cpp"

int MulExpr::isA(int kind) const
{
	if(kind == MulExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *MulExpr::getKindName() const
{
	return "MulExpr";
}

DivExpr::DivExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = DivExpr_kind;
}

DivExpr::~DivExpr()
{
	// not used
}

int DivExpr::semantica()
#line 191 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return v1 / v2;
}
#line 773 "CompiAst.cpp"

stdstring DivExpr::Gencode()
#line 336 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	
	expr1->Gencode();
    expr2->Gencode();
    code += expr1->code + expr2->code;

	code += "\tmov eax, " + getPlace(expr1) +"\n\tcdq\n\tmov ebx, "+ getPlace(expr2) +"\n\tidiv ebx\n";

	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 789 "CompiAst.cpp"

int DivExpr::isA(int kind) const
{
	if(kind == DivExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *DivExpr::getKindName() const
{
	return "DivExpr";
}

SubExpr::SubExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = SubExpr_kind;
}

SubExpr::~SubExpr()
{
	// not used
}

int SubExpr::semantica()
#line 184 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica();
    double v2 = expr2->semantica( );

    return v1 - v2;
}
#line 823 "CompiAst.cpp"

stdstring SubExpr::Gencode()
#line 324 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - " + std::to_string(addOffset_stmt());

    expr1->Gencode();
    expr2->Gencode();
    code += expr1->code + expr2->code;
    code += "\tmov eax, [" + expr1->place + "]\n";
    code += "\tsub eax, [" + expr2->place + "]\n";
    code += "\tmov [" + place + "], eax\n";
    return code;
}
#line 838 "CompiAst.cpp"

int SubExpr::isA(int kind) const
{
	if(kind == SubExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *SubExpr::getKindName() const
{
	return "SubExpr";
}

MayorExpr::MayorExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = MayorExpr_kind;
}

MayorExpr::~MayorExpr()
{
	// not used
}

int MayorExpr::semantica()
#line 198 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return v1 > v2;
}
#line 872 "CompiAst.cpp"

stdstring MayorExpr::Gencode()
#line 349 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	expr1->Gencode();
    expr2->Gencode();
    code += expr1->code + expr2->code;

	code += "\tmov eax, " + getPlace(expr1) +"\n\tcmp eax, " + getPlace(expr2) + "\n";
	std::string label = newLabel();
	std::string final = newLabel();
	code += "\tjle "+ label +"\n";
	code += "\tmov eax, 0\n\tjmp "+final+"\n"+label+": \n\t mov eax, 1\n"+final+":\n";
	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 890 "CompiAst.cpp"

int MayorExpr::isA(int kind) const
{
	if(kind == MayorExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *MayorExpr::getKindName() const
{
	return "MayorExpr";
}

MenorExpr::MenorExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = MenorExpr_kind;
}

MenorExpr::~MenorExpr()
{
	// not used
}

int MenorExpr::semantica()
#line 205 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return v1 < v2;
}
#line 924 "CompiAst.cpp"

stdstring MenorExpr::Gencode()
#line 364 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return "";
}
#line 934 "CompiAst.cpp"

int MenorExpr::isA(int kind) const
{
	if(kind == MenorExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *MenorExpr::getKindName() const
{
	return "MenorExpr";
}

MayorIExpr::MayorIExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = MayorIExpr_kind;
}

MayorIExpr::~MayorIExpr()
{
	// not used
}

int MayorIExpr::semantica()
#line 212 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return v1 >= v2;
}
#line 968 "CompiAst.cpp"

stdstring MayorIExpr::Gencode()
#line 371 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return "";
}
#line 978 "CompiAst.cpp"

int MayorIExpr::isA(int kind) const
{
	if(kind == MayorIExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *MayorIExpr::getKindName() const
{
	return "MayorIExpr";
}

MenorIExpr::MenorIExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = MenorIExpr_kind;
}

MenorIExpr::~MenorIExpr()
{
	// not used
}

int MenorIExpr::semantica()
#line 219 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return v1 <= v2;
}
#line 1012 "CompiAst.cpp"

stdstring MenorIExpr::Gencode()
#line 378 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return "";
}
#line 1022 "CompiAst.cpp"

int MenorIExpr::isA(int kind) const
{
	if(kind == MenorIExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *MenorIExpr::getKindName() const
{
	return "MenorIExpr";
}

IgualExpr::IgualExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = IgualExpr_kind;
}

IgualExpr::~IgualExpr()
{
	// not used
}

int IgualExpr::semantica()
#line 226 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return v1 == v2;
}
#line 1056 "CompiAst.cpp"

stdstring IgualExpr::Gencode()
#line 385 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return "";
}
#line 1066 "CompiAst.cpp"

int IgualExpr::isA(int kind) const
{
	if(kind == IgualExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *IgualExpr::getKindName() const
{
	return "IgualExpr";
}

DesigualExpr::DesigualExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = DesigualExpr_kind;
}

DesigualExpr::~DesigualExpr()
{
	// not used
}

int DesigualExpr::semantica()
#line 233 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return v1 != v2;
}
#line 1100 "CompiAst.cpp"

stdstring DesigualExpr::Gencode()
#line 392 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    double v1 = expr1->semantica( );
    double v2 = expr2->semantica( );

    return "";
}
#line 1110 "CompiAst.cpp"

int DesigualExpr::isA(int kind) const
{
	if(kind == DesigualExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *DesigualExpr::getKindName() const
{
	return "DesigualExpr";
}

BlockStmts::BlockStmts(AstNode * stmt1, AstNode * stmt2)
	: Stmt()
{
	this->kind__ = BlockStmts_kind;
	this->stmt1 = stmt1;
	this->stmt2 = stmt2;
}

BlockStmts::~BlockStmts()
{
	// not used
}

int BlockStmts::semantica()
#line 278 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    stmt1->semantica();
    stmt2->semantica();
    return 0.0;
}
#line 1145 "CompiAst.cpp"

stdstring BlockStmts::Gencode()
#line 454 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    stmt1->Gencode();
    stmt2->Gencode();

    code = stmt1->code + stmt2->code;

    return code;
}
#line 1157 "CompiAst.cpp"

int BlockStmts::isA(int kind) const
{
	if(kind == BlockStmts_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *BlockStmts::getKindName() const
{
	return "BlockStmts";
}

Declaracionvariable::Declaracionvariable(Expr * ident, Expr * ident2)
	: Stmt()
{
	this->kind__ = Declaracionvariable_kind;
	this->ident = ident;
	this->ident2 = ident2;
}

Declaracionvariable::~Declaracionvariable()
{
	// not used
}

int Declaracionvariable::semantica()
#line 295 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    //stmts->semantica();

    return 0.0;
}
#line 1192 "CompiAst.cpp"

stdstring Declaracionvariable::Gencode()
#line 472 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    ident->Gencode();
    ident2->Gencode();

    code = ident->code + ident2->code;


    return code;
}
#line 1205 "CompiAst.cpp"

int Declaracionvariable::isA(int kind) const
{
	if(kind == Declaracionvariable_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *Declaracionvariable::getKindName() const
{
	return "Declaracionvariable";
}

AsignarStmt::AsignarStmt(AstNode * var, AstNode * var_value)
	: Stmt()
{
	this->kind__ = AsignarStmt_kind;
	this->var = var;
	this->var_value = var_value;
}

AsignarStmt::~AsignarStmt()
{
	// not used
}

int AsignarStmt::semantica()
#line 251 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
   
    return 0.0;
}
#line 1239 "CompiAst.cpp"

stdstring AsignarStmt::Gencode()
#line 424 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
   
    return "";
}
#line 1247 "CompiAst.cpp"

int AsignarStmt::isA(int kind) const
{
	if(kind == AsignarStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *AsignarStmt::getKindName() const
{
	return "AsignarStmt";
}

EscribaStmt::EscribaStmt(AstNode * expr1)
	: Stmt()
{
	this->kind__ = EscribaStmt_kind;
	this->expr1 = expr1;
}

EscribaStmt::~EscribaStmt()
{
	// not used
}

int EscribaStmt::semantica()
#line 256 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << expr1->semantica();
    std::string cadena = stream.str();
    
    return 0.0;
}
#line 1283 "CompiAst.cpp"

stdstring EscribaStmt::Gencode()
#line 429 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    
    expr1->Gencode();

    
    code += "\tmov eax, 1\n";
    code += "\tmov ebx, " + getPlace(expr1) + "\n"; 
    code += "\tint 0x80\n";
    return code;
}
#line 1297 "CompiAst.cpp"

int EscribaStmt::isA(int kind) const
{
	if(kind == EscribaStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *EscribaStmt::getKindName() const
{
	return "EscribaStmt";
}

IfStmt::IfStmt(AstNode * condi, AstNode * stmt_t, AstNode * stmt_f)
	: Stmt()
{
	this->kind__ = IfStmt_kind;
	this->condi = condi;
	this->stmt_t = stmt_t;
	this->stmt_f = stmt_f;
}

IfStmt::~IfStmt()
{
	// not used
}

int IfStmt::semantica()
#line 264 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{

   // std::cout<< toString(condi) << " = " <<condi->semantica() << "\n" ;
    if(condi->semantica() != 0.0)
    {
        stmt_t->semantica();
    }else
    {
        stmt_f->semantica();
    }
    
    return 0.0;
}
#line 1341 "CompiAst.cpp"

stdstring IfStmt::Gencode()
#line 440 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{

   // std::cout<< toString(condi) << " = " <<condi->semantica() << "\n" ;
    if(condi->semantica() != 0.0)
    {
        stmt_t->semantica();
    }else
    {
        stmt_f->semantica();
    }
    
    return "";
}
#line 1358 "CompiAst.cpp"

int IfStmt::isA(int kind) const
{
	if(kind == IfStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *IfStmt::getKindName() const
{
	return "IfStmt";
}

