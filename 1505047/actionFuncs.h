void writelog(string msg){
	logFile << "Line " << line_count << " : "<< msg << endl << endl;
}

void writeerr(string msg){
	errorFile << "Error at line " << line_count << " : " << msg <<  endl << endl;
	semErrors++;
}

void writewarning(string msg){
	errorFile << "Warning at line " << line_count << " : " << msg <<  endl << endl;
	warnings++;
}

void clrarg(){
	argumentlist.clear();
}

void logline(){
	logFile << endl <<endl;
}

void printstr(string str){
	logFile << str << endl;
}

SymbolInfo* makenewSymInfo(string type){
	SymbolInfo* temp = new SymbolInfo(type);
	return temp;
}

SymbolInfo* makenewemptySymInfo(){
	SymbolInfo* temp = new SymbolInfo();
	return temp;
}


SymbolInfo* makenewSymInfobyname(string name, string type){
	SymbolInfo* temp = new SymbolInfo(name, type);
	return temp;
}

int argsize(){
	return argumentlist.size();
}

SymbolInfo* variabletoid(SymbolInfo* var, SymbolInfo* id){
	cout << "variabletoid func" << endl;
	SymbolInfo* temp = table.LookUp(id->Getsname());
	SymbolInfo* temp2;
	if(temp == NULL){
		string str = "";
		str.append("Undeclared Variable : ");
		str.append(id->Getsname());
		writeerr(str);
		return 0;
	}
	else if(temp->kindofID != "VAR"){
		string str = "";
		str.append(id->Getsname());
		str.append(" is not a Variable.");
		writeerr(str);
		return 0;	
	}
	else{
		temp2 = new SymbolInfo(id->Getsname(), id->Getstype());
		temp2->kindofID = temp->kindofID;
		temp2->kindofVariable = temp->kindofVariable;
		temp2->parameters = temp->parameters;
		temp2->returntype = temp->returntype;
		temp2->funcrettype = temp->funcrettype;
		temp2->funcdefined = temp->funcdefined;
		return temp2;
	}	
}

SymbolInfo* variabletoarray(SymbolInfo * var, SymbolInfo * id, SymbolInfo * exp){
	cout << "variabletoarray func" << endl;
	SymbolInfo* temp = table.LookUp(id->Getsname());
	if(temp == NULL){
		string str = "";
		str.append("Undeclared Variable : ");
		str.append(id->Getsname());
		writeerr(str);
		return 0;
	}
	else if(temp->kindofID != "ARR"){
		string str = "";
		str.append(id->Getsname());
		writeerr(" is not an array.");
		return 0;	
	}
	else{
		if(exp->kindofVariable == "FLOAT"){
			writeerr("array index can't be float.");
			return 0;
		}
		SymbolInfo* temp2;
		temp2 = new SymbolInfo(id->Getsname(), id->Getstype());
		temp2->kindofID = temp->kindofID;
		temp2->kindofVariable = temp->kindofVariable;
		temp2->parameters = temp->parameters;
		temp2->returntype = temp->returntype;
		temp2->funcrettype = temp->funcrettype;
		temp2->funcdefined = temp->funcdefined;
		return temp2;
	}	
}

void func_dec(SymbolInfo * tysp, SymbolInfo * id){
	cout << "func_dec func" << endl;
	SymbolInfo* temp = table.LookUp(id->Getsname());
	if(temp != NULL){
		string str = "";
		str.append("Multiple declaration of ");
		str.append(id->Getsname());
		writeerr(str);
		return ;
	}
	else{
		table.Insert(id->Getsname(), "ID");
		SymbolInfo* temp2 = table.LookUp(id->Getsname());
		temp2->kindofID = "FUNC";
		temp2->funcrettype = tysp->kindofVariable;
		id->funcrettype = tysp->kindofVariable;
		int sizearg = argsize();
		for(int i = 0; i<argsize(); i++){
			temp2->parameters.push_back(argumentlist[i]);					
		}
		clrarg();
	}
	return;
}

void declistcomid(SymbolInfo * id){
	cout << "declistcomid func" << endl;
	if(lastVarType == "VOID"){
		writeerr("variable type can't be void.");
		return;
	}
	else{
		SymbolInfo* temp = table.curLookUp(id->Getsname());
		if(temp != NULL){
			string str = "";
			str.append("Multiple declaration of ");
			str.append(id->Getsname());
			writeerr(str);
			return;	
		}
		else{
			SymbolInfo* temp2;
			table.Insert(id->Getsname(), id->Getstype());
			temp2 = table.LookUp(id->Getsname());
			temp2->kindofVariable = lastVarType;
			temp2->kindofID = "VAR";
		}
	}
}

void declistarr(SymbolInfo * id, SymbolInfo * constint){
	cout << "declistarr func" << endl;
	if(lastVarType == "VOID"){
		writeerr("array type can't be void.");
		return;
	}
	else{
		SymbolInfo* temp = table.curLookUp(id->Getsname());
		if(temp!= NULL){
			string str = "";
			str.append("Multiple declaration of ");
			str.append(id->Getsname());
			writeerr(str);
			return;
		}
		else{
			SymbolInfo* temp2;
			table.Insert(id->Getsname(), id->Getstype());
			temp2 = table.LookUp(id->Getsname());
			temp2->kindofVariable = lastVarType;
			temp2->kindofID = "ARR";
		}
		return;
	}
}

void onlyid(SymbolInfo * id){
	cout << "onlyid func" << endl;
	if(lastVarType == "VOID"){
		writeerr("variable type can't be void");
		return;
	}
	else{
		SymbolInfo* temp = table.curLookUp(id->Getsname());
		if(temp!= NULL){
			string str = "";
			str.append("Multiple declaration of ");
			str.append(id->Getsname());
			writeerr(str);
			return;
		}
		else{
			table.Insert(id->Getsname(), id->Getstype());
			SymbolInfo* temp2 = table.LookUp(id->Getsname());
			temp2->kindofVariable = lastVarType;
			temp2->kindofID = "VAR";
		}
	}
}

void onlyarray(SymbolInfo * id, SymbolInfo * constint){
	cout << "onlyarray func" << endl;
	if(lastVarType == "VOID"){
		writeerr("array type can't be void");
		return;
	}
	else{
		SymbolInfo* temp = table.curLookUp(id->Getsname());
		if(temp!= NULL){
			string str = "";
			str.append("Multiple declaration of ");
			str.append(id->Getsname());
			writeerr(str);
			return;
		}
		else{
			SymbolInfo* temp2;
			table.Insert(id->Getsname(), id->Getstype());
			temp2 = table.LookUp(id->Getsname());
			temp2->kindofVariable = lastVarType;
			temp2->kindofID = "ARR";
		}
	}
}

void func_def(SymbolInfo * tysp, SymbolInfo * id){
	cout << "func_def func" << endl;
	SymbolInfo *temp = table.LookUp(id->Getsname());
	if(argsize() != IDarguments){
		string str = "Parameter mismatch for Function ";
		str.append(id->Getsname());
		writeerr(str);
		clrarg();
		return;
	}												
	if(temp != NULL){
		id->funcrettype = temp->funcrettype;
		if(temp->funcdefined == true){
			string str = "";
			str.append(id->Getsname());
			str.append(" alredy defined.");
			writeerr(str);
			clrarg();
			IDarguments = 0;
			return;
		}
		else if(temp->funcrettype != tysp->kindofVariable){
			string str = "Return type mismatch for Function ";
			str.append(id->Getsname());
			writeerr(str);
			clrarg();
			IDarguments = 0;
			return; 
		}
		else if(temp->parameters.size() != argsize()){
			string str = "Parameter mismatch for Function ";
			str.append(id->Getsname());
			writeerr(str);
			IDarguments = 0;
			clrarg();
			return;					
		}
		else{
			for(int i = 0; i<temp->parameters.size(); i++){
				if(temp->parameters[i] != argumentlist[i]){
					string str = "Parameter mismatch for Function ";
					str.append(id->Getsname());
					writeerr(str);
					IDarguments = 0;
					clrarg();
					return;		
				}
			}				
		}
	}
	else{
		table.Insert(id->Getsname(), "ID");
		SymbolInfo* temp = table.LookUp(id->Getsname());
		temp->kindofID = "FUNC";
		temp->funcrettype = tysp->kindofVariable;
		id->funcrettype = tysp->kindofVariable;
		for(int i = 0; i<argsize(); i++){
			temp->parameters.push_back(argumentlist[i]);					
		}
		temp->funcdefined = true;
	}
	clrarg();
	IDarguments = 0;
}


SymbolInfo * varassignlogic(SymbolInfo* exp, SymbolInfo* var, SymbolInfo* log_exp){
	cout << "varassignlogic func" << endl;
	string varType = var->kindofVariable;
	if(varType == "INT"){
		if(var->kindofID == "VAR"){
			if(log_exp->kindofVariable != "INT"){
				writewarning("Assigning float value to integer. Type mismatch.");
			}
		}
		else if(var->kindofID == "ARR"){
			if(log_exp->kindofVariable != "INT"){
				writewarning("Assigning float value to integer. Type mismatch.");
			}
		}
	}
	else if(varType == "FLOAT"){
		if(var->kindofID == "ARR"){
			if(log_exp->kindofVariable != "INT"){
				writewarning("Assigning float value to integer.");
			}
		}
	}
	return var;
}

SymbolInfo * rellogicrel(SymbolInfo* log_exp, SymbolInfo* rel_exp1, SymbolInfo* log_op, SymbolInfo* rel_exp3){
	cout << "rellogicrel func" << endl;
	SymbolInfo* temp = makenewSymInfo("INT");
	string logicop = log_op->Getsname();
	return temp;
}

SymbolInfo* varinc(SymbolInfo* var){
	cout << "varinc func" << endl;
	if(var->kindofVariable == "FUNC"){
		writeerr("Function can't be incremented or decremented.");
		return 0;
	}
	return var;
}

SymbolInfo* vardec(SymbolInfo* var){
	cout << "vardec func" << endl;
	if(var->kindofVariable == "FUNC"){
		writeerr("Function can't be incremented or decremented.");
		return 0;
	}
	return var;
}

SymbolInfo* simprelopsimp(SymbolInfo* rel_exp, SymbolInfo* sim_exp1, SymbolInfo* rel_op, SymbolInfo* sim_exp3){
	cout << "simprelopsimp func" << endl;
	SymbolInfo* temp = makenewSymInfo("INT");
	string relop = rel_op->Getsname();
	string simex1 = sim_exp1->kindofVariable;
	string simex3 = sim_exp3->kindofVariable;

	if(simex3 != simex1){
		writewarning("Type mismatch.");
	}
	return temp;
}

SymbolInfo* termmulopunary(SymbolInfo* term1, SymbolInfo* term2, SymbolInfo* mul_op, SymbolInfo* una_exp){
	cout << "termmulopunary func" << endl;
	string mulop = mul_op->Getsname();
	if(mulop == "*"){
		if(term2->kindofID == "VAR"){	
			if(una_exp->kindofID == "VAR"){		
				if(term2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(una_exp->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
			else if(una_exp->kindofID == "ARR"){		
				if(term2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(una_exp->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
		}
		else if(term2->kindofID == "ARR"){	
			if(una_exp->kindofID == "VAR"){		
				if(term2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(una_exp->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
			else if(una_exp->kindofID == "ARR"){		
				if(term2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(una_exp->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
		}
	}
	else if(mulop == "/"){
		if(term2->kindofVariable == "FLOAT"){
			SymbolInfo* temp = makenewSymInfo("FLOAT");
			return temp;
		}
		else if(una_exp->kindofVariable == "FLOAT"){
			SymbolInfo* temp = makenewSymInfo("FLOAT");
			return temp;
		}
		else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
			SymbolInfo* temp = makenewSymInfo("INT");
			return temp;
		}
	}
	else if(mulop == "%"){
		SymbolInfo* temp = makenewSymInfo("INT");
		temp->kindofID = "VAR";
		if(term2->kindofVariable == "FLOAT" || una_exp->kindofVariable == "FLOAT") {
			writeerr("Unsuported operand for mod operator");
			return 0;
		}
		return temp;
	}
}


SymbolInfo* simexpaddopterm(SymbolInfo* sim_exp1,SymbolInfo* sim_exp2,SymbolInfo* add_op,SymbolInfo* term){
	cout << "simexpaddopterm func" << endl;
	string addop = add_op->Getsname();
	if(addop == "+"){ 
		if(sim_exp2->kindofID == "VAR"){
			if(term->kindofID == "VAR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
			else if(term->kindofID == "ARR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
		}
		else if(sim_exp2->kindofID == "ARR"){
			if(term->kindofID == "VAR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
			else if(term->kindofID == "ARR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
		}
	}
	else if(addop == "-"){
		if(sim_exp2->kindofID == "VAR"){
			if(term->kindofID == "VAR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
			else if(term->kindofID == "ARR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
		}
		else if(sim_exp2->kindofID == "ARR"){
			if(term->kindofID == "VAR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
			else if(term->kindofID == "ARR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					return temp;
				}
			}
		}
	}
	return 0;
}

SymbolInfo* addopuna(SymbolInfo* una_exp1, SymbolInfo* add_op, SymbolInfo* una_exp2){
	cout << "addopuna func" << endl;
	return una_exp2;
}

SymbolInfo* notuna(SymbolInfo* una_exp1, SymbolInfo* una_exp2){
	cout << "notuna func" << endl;
	SymbolInfo* temp = makenewSymInfo("INT");
	temp->kindofID = "VAR";
	return temp;
}