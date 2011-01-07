// The contents of this file are subject to the MonetDB Public License
// Version 1.1 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://monetdb.cwi.nl/Legal/MonetDBLicense-1.1.html
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
// License for the specific language governing rights and limitations
// under the License.
//
// The Original Code is the MonetDB Database System.
//
// The Initial Developer of the Original Code is CWI.
// Portions created by CWI are Copyright (C) 1997-July 2008 CWI.
// Copyright August 2008-2011 MonetDB B.V.
// All Rights Reserved.

#include <monetdb_config.h>
#include "mil.h"
#include "ListIterator.h"
#include "mel.h"
#include "parser.h"
#include <string.h>
#include <ctype.h>

int
mil::generate_code(ostream &o, Symbol *root)
{
	root->print(this, o);
	return 0;
}

ostream &
mil::gen_dependency(ostream &o, const Dependency &d)
{ 
	o << "module(" << d.Module()->Name() << ");\n";
	return o;
}

ostream &
mil::gen_module(ostream &o, const Module &d)
{ 
	o << "# This module is generated using the mel -mil utility\n";
	gen_list(o, d.Deps(), "");
	o << "module(_" << d.Name() << ");\n";
	return o;
}
