/* CompiAst.cpp.  Generated automatically by treecc */
#line 36 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"

    #include <iostream>
    #include <string>
    #include <variant>
    #include <iomanip>
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
        else if(e->isA(CaracterExpr_kind))
            return e->place;
        else if(e->isA(BoolExpr_kind))
            return e->place;
		return "dword ["+e->place+"]";
	}


    bool siTipo(Tipos& tipo_var, std::string var, std::string tipo)
    {
        for (int i =0 ; i < tipo_var.size(); i++)
        {
            if(tipo_var[i].variable == var)
            {
                if(tipo_var[i].Tipo == tipo)
                {
                    return true;
                }
            }
        }
        return false;
    }


    stdstring TipoVar(Tipos& tipo_var, std::string var)
    {
        for (int i =0 ; i < tipo_var.size(); i++)
        {
            if(tipo_var[i].variable == var)
            {
                return tipo_var[i].Tipo;
            }
        }

        return "";
    }
#line 97 "CompiAst.cpp"

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
#line 376 "CompiAst.cpp"
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

Program::Program(AstNode * declVar, AstNode * declFun, AstNode * main)
	: AstNode()
{
	this->kind__ = Program_kind;
	this->declVar = declVar;
	this->declFun = declFun;
	this->main = main;
}

Program::~Program()
{
	// not used
}

stdstring Program::Gencode(Tipos & tipos)
#line 922 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    declVar->Gencode(tipos);
    declFun->Gencode(tipos);
    main->Gencode(tipos);
    for (const auto& var : vars) {
       
        code += "\tpush 0\n";
    }

    code += "\tcall main\n";
    code += "\tadd esp, " + std::to_string(getOffset() - 4) + "\n";
    code += "\t#stop\n";
    code += "main:\n";
    code += "\tpush ebp\n";
    code += "\tmov ebp, esp\n";
    code += "\tsub esp, " + std::to_string(getOffset_stmt()) + "\n";
    code += main->code;
    code += "\tleave\n\tret\n";

    
    return code;
}
#line 474 "CompiAst.cpp"

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

stdstring NumExpr::Gencode(Tipos & tipos)
#line 462 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = std::to_string(value);
    code = "";
    return "";
}
#line 558 "CompiAst.cpp"

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

stdstring IdentExpr::Gencode(Tipos & tipos)
#line 474 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
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
    }
    return "";
}
#line 603 "CompiAst.cpp"

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

BoolExpr::BoolExpr(int booleano)
	: Expr()
{
	this->kind__ = BoolExpr_kind;
	this->booleano = booleano;
}

BoolExpr::~BoolExpr()
{
	// not used
}

stdstring BoolExpr::Gencode(Tipos & tipos)
#line 468 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = std::to_string(booleano);
    code = "";
    return "";
}
#line 637 "CompiAst.cpp"

int BoolExpr::isA(int kind) const
{
	if(kind == BoolExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *BoolExpr::getKindName() const
{
	return "BoolExpr";
}

CaracterExpr::CaracterExpr(char character)
	: Expr()
{
	this->kind__ = CaracterExpr_kind;
	this->character = character;
}

CaracterExpr::~CaracterExpr()
{
	// not used
}

stdstring CaracterExpr::Gencode(Tipos & tipos)
#line 491 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{

    int valor_ascii = static_cast<int>(character);
    place = std::to_string(valor_ascii);
    code = "";
    return "";
}
#line 673 "CompiAst.cpp"

int CaracterExpr::isA(int kind) const
{
	if(kind == CaracterExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *CaracterExpr::getKindName() const
{
	return "CaracterExpr";
}

CadenaExpr::CadenaExpr(stdstring cadena)
	: Expr()
{
	this->kind__ = CadenaExpr_kind;
	this->cadena = cadena;
}

CadenaExpr::~CadenaExpr()
{
	// not used
}

stdstring CadenaExpr::Gencode(Tipos & tipos)
#line 499 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "";
    code = "";
    return "";
}
#line 707 "CompiAst.cpp"

int CadenaExpr::isA(int kind) const
{
	if(kind == CadenaExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *CadenaExpr::getKindName() const
{
	return "CadenaExpr";
}

ArregloExpr::ArregloExpr(stdstring txt)
	: Expr()
{
	this->kind__ = ArregloExpr_kind;
	this->txt = txt;
}

ArregloExpr::~ArregloExpr()
{
	// not used
}

stdstring ArregloExpr::Gencode(Tipos & tipos)
#line 505 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    code = "";
    place ="";
    return "";
}
#line 741 "CompiAst.cpp"

int ArregloExpr::isA(int kind) const
{
	if(kind == ArregloExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *ArregloExpr::getKindName() const
{
	return "ArregloExpr";
}

DeclaracionStmt::DeclaracionStmt(AstNode * ident1, AstNode * ident2)
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

stdstring DeclaracionStmt::Gencode(Tipos & tipos)
#line 774 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    ident1->Gencode(tipos);
    ident2->Gencode(tipos);
    
    code = ident1->code + ident2->code;

    return code;
}
#line 779 "CompiAst.cpp"

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

stdstring AddExpr::Gencode(Tipos & tipos)
#line 261 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - " + std::to_string(addOffset_stmt());

    expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;
    code += "\tmov eax, " + getPlace(expr1) + "\n";
    code += "\tadd eax, " + getPlace(expr2) + "\n";
    code += "\tmov [" + place + "], eax\n";
    return code;
}
#line 818 "CompiAst.cpp"

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

stdstring MulExpr::Gencode(Tipos & tipos)
#line 273 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	
	expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;
	code += "\tmov eax, " + getPlace(expr1) +"\n";
    code += "\timul eax, " + getPlace(expr2) + "\n";
	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 857 "CompiAst.cpp"

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

stdstring DivExpr::Gencode(Tipos & tipos)
#line 297 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	
	expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;

	code += "\tmov eax, " + getPlace(expr2) +"\n";
    code += "\tcdq\n";
    code += "\tmov ebx, "+ getPlace(expr1) +"\n";
    code += "\tidiv ebx\n";

	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 900 "CompiAst.cpp"

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

stdstring SubExpr::Gencode(Tipos & tipos)
#line 285 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - " + std::to_string(addOffset_stmt());

    expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;
    code += "\tmov eax, " + getPlace(expr1) + "\n";
    code += "\tsub eax, " + getPlace(expr2) + "\n";
    code += "\tmov [" + place + "], eax\n";
    return code;
}
#line 939 "CompiAst.cpp"

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

ModExpr::ModExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = ModExpr_kind;
}

ModExpr::~ModExpr()
{
	// not used
}

stdstring ModExpr::Gencode(Tipos & tipos)
#line 419 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	
	expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;

	code += "\tmov eax, " + getPlace(expr1) +"\n";
    code += "\tcdq\n";
    code += "\tmov ebx, "+ getPlace(expr2) +"\n";
    code += "\tidiv ebx\n";

	code += "\tmov ["+ place + "], edx\n";
	code += "\tmov eax, edx\n";
	return code;
}
#line 983 "CompiAst.cpp"

int ModExpr::isA(int kind) const
{
	if(kind == ModExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *ModExpr::getKindName() const
{
	return "ModExpr";
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

stdstring MayorExpr::Gencode(Tipos & tipos)
#line 313 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;
    std::string Etiqueta_mayor = newLabel();
	std::string Etiqueta_Fin = newLabel();
	code += "\tmov eax, " + getPlace(expr1) +"\n\tcmp eax, " + getPlace(expr2) + "\n";
	code += "\tjle "+ Etiqueta_mayor +"\n";
	code += "\tmov eax, 1\n";
    code += "\tjmp "+Etiqueta_Fin+"\n";
    code += Etiqueta_mayor + ": \n";
    code += "\t mov eax, 0\n";
    code += Etiqueta_Fin + ":\n";
	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 1028 "CompiAst.cpp"

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

stdstring MenorExpr::Gencode(Tipos & tipos)
#line 331 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;
    std::string Etiqueta_menor = newLabel();
	std::string Etiqueta_Fin = newLabel();
	code += "\tmov eax, " + getPlace(expr1) +"\n\tcmp eax, " + getPlace(expr2) + "\n";
	code += "\tjge "+ Etiqueta_menor +"\n";
	code += "\tmov eax, 1\n";
    code += "\tjmp "+Etiqueta_Fin+"\n";
    code += Etiqueta_menor + ": \n";
    code += "\t mov eax, 0\n";
    code += Etiqueta_Fin+":\n";
	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 1073 "CompiAst.cpp"

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

stdstring MayorIExpr::Gencode(Tipos & tipos)
#line 349 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;
    std::string Etiqueta_mayor = newLabel();
	std::string Etiqueta_Fin = newLabel();
	code += "\tmov eax, " + getPlace(expr1) +"\n\tcmp eax, " + getPlace(expr2) + "\n";
	code += "\tjl " + Etiqueta_mayor +"\n";
	code += "\tmov eax, 1\n";
    code += "\tjmp " + Etiqueta_Fin + "\n";
    code += Etiqueta_mayor + ": \n";
    code += "\t mov eax, 0\n" ;
    code += Etiqueta_Fin + ":\n";
	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 1118 "CompiAst.cpp"

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

stdstring MenorIExpr::Gencode(Tipos & tipos)
#line 367 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;
    std::string Etiqueta_menor = newLabel();
	std::string Etiqueta_Fin = newLabel();
	code += "\tmov eax, " + getPlace(expr1) +"\n\tcmp eax, " + getPlace(expr2) + "\n";
	code += "\tjg "+ Etiqueta_menor +"\n";
	code += "\tmov eax, 1\n";
    code += "\tjmp "+Etiqueta_Fin+"\n";
    code += Etiqueta_menor+": \n";
    code += "\t mov eax, 0\n"+Etiqueta_Fin+":\n";
	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 1162 "CompiAst.cpp"

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

stdstring IgualExpr::Gencode(Tipos & tipos)
#line 384 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;
    std::string Etiqueta_igual = newLabel();
	std::string Etiqueta_Fin = newLabel();
	code += "\tmov eax, " + getPlace(expr1) +"\n\tcmp eax, " + getPlace(expr2) + "\n";
	code += "\tjne "+ Etiqueta_igual +"\n";
	code += "\tmov eax, 1\n";
    code += "\tjmp "+Etiqueta_Fin+"\n"; 
    code += Etiqueta_igual+": \n";
    code += "\t mov eax, 0\n"+Etiqueta_Fin+":\n";
	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 1206 "CompiAst.cpp"

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

stdstring DesigualExpr::Gencode(Tipos & tipos)
#line 401 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
	expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;
    std::string Etiqueta_desigual = newLabel();
	std::string Etiqueta_Fin = newLabel();
	code += "\tmov eax, " + getPlace(expr1) +"\n\tcmp eax, " + getPlace(expr2) + "\n";
	code += "\tje "+ Etiqueta_desigual +"\n";
	code += "\tmov eax, 1\n"; 
    code += "\tjmp "+Etiqueta_Fin+"\n";
    code += Etiqueta_desigual + ": \n"; 
    code += "\t mov eax, 0\n";
    code += Etiqueta_Fin +":\n";
	code += "\tmov ["+ place + "], eax\n";
	return code;
}
#line 1251 "CompiAst.cpp"

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

OrExpr::OrExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = OrExpr_kind;
}

OrExpr::~OrExpr()
{
	// not used
}

stdstring OrExpr::Gencode(Tipos & tipos)
#line 436 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
    
    expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;

    code += "\tmov eax, " + getPlace(expr1) +"\n";
    code += "\tor eax, " + getPlace(expr2) + "\n";
    code += "\tmov ["+ place + "], eax\n";
    return code;
}
#line 1291 "CompiAst.cpp"

int OrExpr::isA(int kind) const
{
	if(kind == OrExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *OrExpr::getKindName() const
{
	return "OrExpr";
}

AndExpr::AndExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = AndExpr_kind;
}

AndExpr::~AndExpr()
{
	// not used
}

stdstring AndExpr::Gencode(Tipos & tipos)
#line 449 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "ebp - "+std::to_string(addOffset_stmt());
    
    expr1->Gencode(tipos);
    expr2->Gencode(tipos);
    code += expr1->code + expr2->code;

    code += "\tmov eax, " + getPlace(expr1) +"\n";
    code += "\tand eax, " + getPlace(expr2) + "\n";
    code += "\tmov ["+ place + "], eax\n";
    return code;
}
#line 1331 "CompiAst.cpp"

int AndExpr::isA(int kind) const
{
	if(kind == AndExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *AndExpr::getKindName() const
{
	return "AndExpr";
}

Vacio::Vacio()
	: Stmt()
{
	this->kind__ = Vacio_kind;
}

Vacio::~Vacio()
{
	// not used
}

stdstring Vacio::Gencode(Tipos & tipos)
#line 889 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    place = "";
    code = "";
    return "";
}
#line 1364 "CompiAst.cpp"

int Vacio::isA(int kind) const
{
	if(kind == Vacio_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *Vacio::getKindName() const
{
	return "Vacio";
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

stdstring BlockStmts::Gencode(Tipos & tipos)
#line 765 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    stmt1->Gencode(tipos);
    stmt2->Gencode(tipos);

    code = stmt1->code + stmt2->code;

    return code;
}
#line 1402 "CompiAst.cpp"

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

Declaracionvariable::Declaracionvariable(AstNode * ident, AstNode * ident2)
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

stdstring Declaracionvariable::Gencode(Tipos & tipos)
#line 783 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    ident->Gencode(tipos);
    ident2->Gencode(tipos);

    code = ident->code + ident2->code;


    return code;
}
#line 1441 "CompiAst.cpp"

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

AsignarStmt::AsignarStmt(IdentExpr * var, AstNode * var_value)
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

stdstring AsignarStmt::Gencode(Tipos & tipos)
#line 513 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{

    bool encontrado = false;
    for (const auto& vari : vars) {
        if (vari.Identificador == var->text) {
            encontrado = true;
            
            var->Gencode(tipos);

            break;
        }
    }

    if (!encontrado) {
        
        std::string msgcompleto = "Error:variable no declarada " + var->text;
        throw std::runtime_error(msgcompleto.c_str());\
    }
    
    
    if(var_value->isA(NumExpr_kind))
    {
        
        if(siTipo(tipos, var->text, "Entero"))
        {
            var_value->Gencode(tipos);
        }else
        {
            std::string msgcompleto = "Error: La Variable " + var->text + " no es de tipo Entero" ;
            throw std::runtime_error(msgcompleto.c_str());\
        }

    }else if (var_value->isA(IdentExpr_kind))
    {

        for (const auto& vari : vars) {
            if (vari.Identificador == var->text) {
                encontrado = true;
                std::string tipo = TipoVar(tipos, static_cast<IdentExpr *>(var_value)->text);
                
                if(siTipo(tipos, var->text, tipo))
                {
                    var_value->Gencode(tipos);
                }else
                {
                    std::string msgcompleto = "Error: La Variable " + var->text + " no es de tipo " + tipo ;
                    throw std::runtime_error(msgcompleto.c_str());\
                }

                break;
            }
        }   

        if (!encontrado) {
            std::string msgcompleto = "Error: La Variable " + var->text + " no esta declarada " ;
            throw std::runtime_error(msgcompleto.c_str());\
        }

    }else if(var_value->isA(CaracterExpr_kind))
    {
        if(siTipo(tipos, var->text, "Caracter"))
        {
            var_value->Gencode(tipos);
        }else
        {
            std::string msgcompleto = "Error: La Variable " + var->text + " no es de tipo Caracter" ;
            throw std::runtime_error(msgcompleto.c_str());\
        }

    }else if(var_value->isA(BoolExpr_kind))
    {
        if(siTipo(tipos, var->text, "Booleano"))
        {
            var_value->Gencode(tipos);

        }else
        {
            std::string msgcompleto = "Error: La Variable " + var->text + " no es de tipo Booleano" ;
            throw std::runtime_error(msgcompleto.c_str());\
        }

    }else
    {
        var_value->Gencode(tipos);
    }
    
    

    place = var->place;
    code += var_value->code;
    code += "\tmov eax, " + getPlace(var_value) + "\n";
    code += "\tmov " + getPlace(var) + ", eax\n"; 
    return "";
}
#line 1565 "CompiAst.cpp"

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

ForStmt::ForStmt(AsignarStmt * asignacion, Expr * hasta, AstNode * stmtst)
	: Stmt()
{
	this->kind__ = ForStmt_kind;
	this->asignacion = asignacion;
	this->hasta = hasta;
	this->stmtst = stmtst;
}

ForStmt::~ForStmt()
{
	// not used
}

stdstring ForStmt::Gencode(Tipos & tipos)
#line 811 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    std::string label1 = newLabel(); 
    
    std::string label2 = newLabel(); 
    std::string label3 = newLabel(); 
   

    asignacion->Gencode(tipos);
    hasta->Gencode(tipos);
    stmtst->Gencode(tipos);

    
    code += asignacion->code;
    code += label1 + ":\n";
    code += "\tmov eax, " + getPlace(asignacion) + "\n";
    code += "\tcmp eax, "+getPlace(hasta)+"\n";
    code += "\tjg " + label3 + "\n";
    code += stmtst->code;
    code += "\tadd " + getPlace(asignacion) + ", 1\n";
    code += "\tjmp " + label1 + "\n";
    code += label3 + ":\n";
    return code;
}
#line 1619 "CompiAst.cpp"

int ForStmt::isA(int kind) const
{
	if(kind == ForStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *ForStmt::getKindName() const
{
	return "ForStmt";
}

RepitaStmt::RepitaStmt(AstNode * stmtst, Expr * condi)
	: Stmt()
{
	this->kind__ = RepitaStmt_kind;
	this->stmtst = stmtst;
	this->condi = condi;
}

RepitaStmt::~RepitaStmt()
{
	// not used
}

stdstring RepitaStmt::Gencode(Tipos & tipos)
#line 794 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    std::string Etiqueta_repita = newLabel(); 
    stmtst->Gencode(tipos);
    condi->Gencode(tipos);


    code += Etiqueta_repita + ":\n";
    code += stmtst->code;
    code += condi->code;
    code += "\tmov eax, " + getPlace(condi) + "\n";
    code += "\tcmp eax, 0\n";
    code += "\tjne " + Etiqueta_repita + "\n";


    return code;
}
#line 1665 "CompiAst.cpp"

int RepitaStmt::isA(int kind) const
{
	if(kind == RepitaStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *RepitaStmt::getKindName() const
{
	return "RepitaStmt";
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

stdstring EscribaStmt::Gencode(Tipos & tipos)
#line 608 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    bool encontrado = false;

    if(expr1->isA(NumExpr_kind))
    {
        expr1->Gencode(tipos);
        code += expr1->code;
        code += "\tmov eax, 1\n";
        code += "\tmov ebx, " + getPlace(expr1) + "\n"; 

    }else if (expr1->isA(IdentExpr_kind))
    {
        std::string tipo = TipoVar(tipos, static_cast<IdentExpr *>(expr1)->text);

        for (const auto& vari : vars) {
            if (vari.Identificador == static_cast<IdentExpr *>(expr1)->text) {
                encontrado = true;

                expr1->Gencode(tipos);

                break;
            }
        }   

        if (!encontrado) {
            std::string msgcompleto = "Error:variable no declarada " + static_cast<IdentExpr *>(expr1)->text;
            throw std::runtime_error(msgcompleto.c_str());
        }
        code += expr1->code;
        if(tipo == "Entero")
        {
            code += "\tmov eax, 1\n";
            code += "\tmov ebx, " + getPlace(expr1) + "\n"; 
            
        }else if(tipo == "Caracter")
        {
            code += "\tmov eax, 11\n";
            code += "\tmov ebx, " + getPlace(expr1) + "\n"; 

        }else if(tipo == "Booleano")
        {
            code += "\tmov esi, 0x10000000\n";
            code += "\tlea ebx, [esi+4]\n";
            std::string label1 = newLabel();
            std::string label2 = newLabel();
            code += "\tmov eax, "+ getPlace(expr1) +"\n";
            code += "\tcmp eax, 0\n";
            code += "\tje "+ label1 +"\n";
            
            code += "\tmov dword [ebx], 0x64726576\n"; 
            code += "\tmov dword [ebx + 4], 0x72656461\n";
            code += "\tmov dword  [ebx + 8], 0x6f\n"; 
            code += "\tmov dword  [ebx + 9], 0\n";
            code += "\tjmp "+ label2 +"\n";
            
            code += label1 + ":\n"; 
            code += "\tmov dword [ebx], 0x736c6166\n"; 
            code += "\tmov dword [ebx + 4], 0x6f\n";
            code += "\tmov dword  [ebx + 5], 0\n"; 
            
            code += label2 + ":\n";
            code += "\tmov eax, 4\n";
            code += "\tlea ebx, [esi+4]\n";
            
        }
       

    }else if(expr1->isA(CaracterExpr_kind))
    {
        expr1->Gencode(tipos);
        code += expr1->code;
        code += "\tmov eax, 11\n";
        code += "\tmov ebx, " + getPlace(expr1) + "\n"; 
    
    }else if (expr1->isA(BoolExpr_kind))
    {
        expr1->Gencode(tipos);
        code += "\tmov esi, 0x10000000\n";
        code += "\tlea ebx, [esi+4]\n";
        
        
        if(expr1->place == "1"){
            code += "\tmov dword [ebx], 0x64726576\n"; 
            code += "\tmov dword [ebx + 4], 0x72656461\n";
            code += "\tmov dword  [ebx + 8], 0x6f\n"; 
            code += "\tmov dword  [ebx + 9], 0\n";
        }
        else
        {
            code += "\tmov dword [ebx], 0x736c6166\n"; 
            code += "\tmov dword [ebx + 4], 0x6f\n";
            code += "\tmov dword  [ebx + 5], 0\n"; 
        }
        
        code += "\tmov eax, 4\n";
        code += "\tlea ebx, [esi+4]\n";

    
    }else if(expr1->isA(CadenaExpr_kind))
    {
        expr1->Gencode(tipos);
        
        code += "\tmov esi, 0x10000000\n";
        code += "\tlea ebx, [esi+4]\n";
        int i = 0;
        
        std::stringstream ss;
        for (i = 0; static_cast<CadenaExpr *>(expr1)->cadena[i] != '\0'; ++i) {

            if (i % 4 == 0) {
                code += "\n\tmov [ebx + " + std::to_string(i) + "], 0x";   
            }
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(static_cast<CadenaExpr *>(expr1)->cadena[i]);
            
           if(i >= 0 && (i-3) % 4 == 0 || i == static_cast<CadenaExpr *>(expr1)->cadena.size() - 1)
            {
                
                std::vector<std::string> pares;
                for (size_t i = 0; i < ss.str().length(); i += 2) {
                    pares.push_back(ss.str().substr(i, 2));
                }
                std::reverse(pares.begin(), pares.end());
                std::ostringstream resultado;
                for (const auto& par : pares) {
                    resultado << par;
                }

                code += resultado.str();
                ss.str("");
            }

        }

        code += "\n\tmov [ebx +"+std::to_string(i)+"], 0\n";
        code += "\tmov eax, 4\n";
        code += "\tlea ebx, [esi+4]\n";
    }
    else
    {
        expr1->Gencode(tipos);
        code += expr1->code;
        code += "\tmov eax, 1\n";
        code += "\tmov ebx, " + getPlace(expr1) + "\n"; 
    }
    

    
   
    code += "\tint 0x80\n";

    code += "\tmov eax, 11\n";
    code += "\tmov ebx, 10\n"; 
    code += "\tint 0x80\n";
    return code;
}
#line 1849 "CompiAst.cpp"

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

IfStmt::IfStmt(AstNode * condi, AstNode * stmt_tr, AstNode * stmt_f)
	: Stmt()
{
	this->kind__ = IfStmt_kind;
	this->condi = condi;
	this->stmt_tr = stmt_tr;
	this->stmt_f = stmt_f;
}

IfStmt::~IfStmt()
{
	// not used
}

stdstring IfStmt::Gencode(Tipos & tipos)
#line 857 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    std::string label1 = newLabel(); // label de for
    std::string label2 = newLabel(); // finalizacion del for
    std::string label3 = newLabel(); // label que no entro al for
    std::string label4 = newLabel();

    condi->Gencode(tipos);
    stmt_tr->Gencode(tipos);
    stmt_f->Gencode(tipos);
    code += label1 + ":\n";
    code += condi->code;
    code += "\tmov eax, " + getPlace(condi) + "\n";
    code += "\tcmp eax, 0\n";
    code += "\tje " + label3 + "\n";
    code += stmt_tr->code;
    code += "\tjmp "+ label4 +"\n";
    code += label3 + ":\n";
    code += stmt_f->code;
    code += label4 + ":\n";
    return code;
}
#line 1901 "CompiAst.cpp"

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

WhileStmt::WhileStmt(AstNode * condi, AstNode * stmt_tr)
	: Stmt()
{
	this->kind__ = WhileStmt_kind;
	this->condi = condi;
	this->stmt_tr = stmt_tr;
}

WhileStmt::~WhileStmt()
{
	// not used
}

stdstring WhileStmt::Gencode(Tipos & tipos)
#line 836 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    std::string label1 = newLabel(); // label de for
    std::string label2 = newLabel(); // finalizacion del for
    std::string label3 = newLabel(); // label que no entro al for
   

    condi->Gencode(tipos);
    stmt_tr->Gencode(tipos);

    code += label1 + ":\n";
    code += condi->code;
    code += "\tmov eax, " + getPlace(condi) + "\n";
    code += "\tcmp eax, 0\n";
    code += "\tje " + label3 + "\n";
    code += stmt_tr->code;
    code += "\tjmp " + label1 + "\n";
    code += label3 + ":\n";
    return code;
}
#line 1950 "CompiAst.cpp"

int WhileStmt::isA(int kind) const
{
	if(kind == WhileStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *WhileStmt::getKindName() const
{
	return "WhileStmt";
}

RetorneStmt::RetorneStmt(AstNode * retorno)
	: Stmt()
{
	this->kind__ = RetorneStmt_kind;
	this->retorno = retorno;
}

RetorneStmt::~RetorneStmt()
{
	// not used
}

stdstring RetorneStmt::Gencode(Tipos & tipos)
#line 879 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{

    retorno->Gencode(tipos);
    code += retorno->code;
    code += "\tmov ecx, " + getPlace(retorno) + "\n";

    return code;
}
#line 1987 "CompiAst.cpp"

int RetorneStmt::isA(int kind) const
{
	if(kind == RetorneStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *RetorneStmt::getKindName() const
{
	return "RetorneStmt";
}

LeaStmt::LeaStmt(AstNode * leer)
	: Stmt()
{
	this->kind__ = LeaStmt_kind;
	this->leer = leer;
}

LeaStmt::~LeaStmt()
{
	// not used
}

stdstring LeaStmt::Gencode(Tipos & tipos)
#line 896 "/home/mirian/Compiladores_2/Proyecto_Compilador/CompiAst.tc"
{
    
    bool encontrado = false;
    for (const auto& vari : vars) {
        if (vari.Identificador == static_cast<IdentExpr *>(leer)->text) {
            encontrado = true;
            
           leer->Gencode(tipos);

            break;
        }
    }

    if (!encontrado) {
        
        std::string msgcompleto = "Error:variable no declarada " + static_cast<IdentExpr *>(leer)->text;
        throw std::runtime_error(msgcompleto.c_str());\
    }

    code += "\tmov eax, 5\n";
    code += "\tint 0x80\n";
    code += "\tmov "+getPlace(leer)+", eax\n";

    return "";
}
#line 2041 "CompiAst.cpp"

int LeaStmt::isA(int kind) const
{
	if(kind == LeaStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *LeaStmt::getKindName() const
{
	return "LeaStmt";
}

