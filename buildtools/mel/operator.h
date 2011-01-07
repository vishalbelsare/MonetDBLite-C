/*
 * The contents of this file are subject to the MonetDB Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://monetdb.cwi.nl/Legal/MonetDBLicense-1.1.html
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is the MonetDB Database System.
 *
 * The Initial Developer of the Original Code is CWI.
 * Portions created by CWI are Copyright (C) 1997-July 2008 CWI.
 * Copyright August 2008-2011 MonetDB B.V.
 * All Rights Reserved.
 */

#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include "command.h"
#include "list.h"

class Operator:public Command {
      public:
	Operator(int t, char *n, char *fcn = NULL, Symbol *result = NULL, Symbol *op1 = NULL, Symbol *op2 = NULL, char *hlp = NULL);

	Symbol *op1() const;
	Symbol *op2() const;

	virtual const char *Token() const;
	virtual ostream & print(language * l, ostream & o) const;
      private:
	void set_op_names();
	int level;

	Symbol *_op1;
	Symbol *_op2;
};
#endif

