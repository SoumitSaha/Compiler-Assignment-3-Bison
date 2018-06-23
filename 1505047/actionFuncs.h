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

//void movecodesegment(int from, int to){
//	for(int i = 0; i<codesegment[from].size(); i++){
//		codesegment[to].push_back(codesegment[from][i]);					
//	}
//}

float inf(){
	return numeric_limits<float>::infinity();
}

int intinf(){
	return numeric_limits<int>::max();
}

//void clrcodesegment(int codesegmentno){
//	codesegment[codesegmentno].clear();
//}

//void showcodesegment(int nonterminalno){
//	for(int i = 0; i<codesegment[nonterminalno].size(); i++){
//		logFile << codesegment[nonterminalno][i] << " ";
//		if(codesegment[nonterminalno][i] == ";" || codesegment[nonterminalno][i] == "{" || codesegment[nonterminalno][i] == "}") 	logFile << endl;
//	}
//}

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
		temp2->arrsize = temp->arrsize;
		temp2->parameters = temp->parameters;
		temp2->intelements = temp->intelements;
		temp2->floatelements = temp->floatelements;
		temp2->returntype = temp->returntype;
		temp2->arrindex = temp->arrindex;
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
		//cout << exp->kindofVariable << " kind of Variable of exp" << endl;
		if(exp->kindofVariable == "FLOAT"){
		//	//cout << "Mynum : " << exp->intelements[0] << "  ArrSize of " << temp->Getsname() << " : " << temp->arrsize << endl;
			writeerr("array index can't be float.");
			return 0;
		} 
		//else temp->arrsize = exp->intelements[0];
		if(temp->kindofVariable == "INT"){
			while(temp->intelements.size() <= temp->arrindex){
				int a = 0;
				temp->intelements.push_back(0);
			}
		}
		else if(temp->kindofVariable == "FLOAT"){
			while(temp->floatelements.size() <= temp->arrindex){
				temp->floatelements.push_back(0);
			}
		}
		SymbolInfo* temp2;
		temp2 = new SymbolInfo(id->Getsname(), id->Getstype());
		temp2->kindofID = temp->kindofID;
		temp2->kindofVariable = temp->kindofVariable;
		temp2->arrsize = temp->arrsize;
		temp2->parameters = temp->parameters;
		temp2->intelements = temp->intelements;
		temp2->floatelements = temp->floatelements;
		temp2->returntype = temp->returntype;
		temp2->arrindex = temp->arrindex;
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
		SymbolInfo* temp = table.LookUp(id->Getsname());
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
		SymbolInfo* temp = table.LookUp(id->Getsname());
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
			int araSize = atoi((constint->Getsname()).c_str());
			temp2->arrsize = araSize;
			if(lastVarType == "INT"){								
				for(int i = temp2->intelements.size(); i<araSize; i++){
					temp2->intelements.push_back(0);
				}
				return;						
			}
			else if(lastVarType == "FLOAT"){								
				for(int i = temp2->floatelements.size(); i<araSize; i++){
					temp2->floatelements.push_back(0);
				}
				return;							
			}
			return;
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
		SymbolInfo* temp = table.LookUp(id->Getsname());
		if(temp!= NULL){
			////cout << "multiple hoise, line " << line_count <<  endl;
			string str = "";
			str.append("Multiple declaration of ");
			str.append(id->Getsname());
			writeerr(str);
			return;
		}
		else{
			////cout << "multiple hoy nai, line " << line_count <<  endl;
			table.Insert(id->Getsname(), id->Getstype());
			SymbolInfo* temp2 = table.LookUp(id->Getsname());
			//cout << "lastVarType : " << lastVarType << endl;

			temp2->kindofVariable = lastVarType;
			//cout << "kindofvariable of " << id->Getsname() << " " << temp2->kindofVariable << endl;
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
		SymbolInfo* temp = table.LookUp(id->Getsname());
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
			int araSize = atoi((constint->Getsname()).c_str());
			//cout << "Array Size : " << araSize << " assigned to "<< temp2->Getsname() << endl;
			temp2->arrsize = araSize;
			//cout << "after assigning arasize is : " << temp2->arrsize << endl;
			if(lastVarType == "INT"){								
				for(int i = temp2->intelements.size(); i<araSize; i++){
					temp2->intelements.push_back(0);
				}							
			}
			else if(lastVarType == "FLOAT"){								
				for(int i = temp2->floatelements.size(); i<araSize; i++){
					temp2->floatelements.push_back(0);
				}							
			}		
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
		//cout << "funcrettype of : " << temp->Getsname() << " " << temp->funcrettype  << endl;
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
		//cout << "setting funcrettype to : " << tysp->kindofVariable << endl;
		temp->funcrettype = tysp->kindofVariable;
		id->funcrettype = tysp->kindofVariable;
		//cout << "funcrettype of : " << temp->Getsname() << " " << temp->funcrettype << endl;
		//cout << argsize() << endl;
		for(int i = 0; i<argsize(); i++){
			//cout << "Hello" << endl;
			//cout << argumentlist[i]<< endl;
			temp->parameters.push_back(argumentlist[i]);					
		}
		temp->funcdefined = true;
	}
	clrarg();
	IDarguments = 0;
	//cout << "Out of here" << endl;
}


SymbolInfo * varassignlogic(SymbolInfo* exp, SymbolInfo* var, SymbolInfo* log_exp){
	cout << "varassignlogic func" << endl;
	string varType = var->kindofVariable;
	if(varType == "INT"){
		if(var->kindofID == "VAR"){
			var->intelements.push_back(0);
			if(log_exp->kindofVariable == "INT"){
				if(log_exp->kindofID == "VAR") var->intelements[0] = log_exp->intelements[0];
				else var->intelements[0] = log_exp->intelements[log_exp->arrindex];
			}
			else{
				writewarning("Assigning float value to integer.");
				if(log_exp->kindofID == "VAR") var->intelements[0] = (int)log_exp->floatelements[0];
				else var->intelements[0] = (int)log_exp->floatelements[log_exp->arrindex];
			}
		}
		else if(var->kindofID == "ARR"){
			var->intelements.push_back(0);
			if(log_exp->kindofVariable == "INT"){
				if(log_exp->kindofID == "VAR") var->intelements[var->arrindex] = log_exp->intelements[0];
				else var->intelements[var->arrindex] = log_exp->intelements[log_exp->arrindex];
			}
			else{
				writewarning("Assigning float value to integer.");
				if(log_exp->kindofID == "VAR") var->intelements[var->arrindex] = (int)log_exp->floatelements[0];
				else var->intelements[var->arrindex] = (int)log_exp->floatelements[log_exp->arrindex];
			}
		}
	}
	else if(varType == "FLOAT"){
		if(var->kindofID == "VAR"){
			var->floatelements.push_back(0);
			if(log_exp->kindofVariable == "INT"){
				if(log_exp->kindofID == "VAR")	var->floatelements[0] = (float)log_exp->intelements[0];
				else var->floatelements[0] = (float)log_exp->intelements[log_exp->arrindex];
			}
			else{
				if(log_exp->kindofID == "VAR") var->floatelements[0] = log_exp->floatelements[0];
				else var->floatelements[0] = log_exp->floatelements[log_exp->arrindex];
			}
		}
		else if(var->kindofID == "ARR"){
			var->floatelements.push_back(0);
			if(log_exp->kindofVariable == "INT"){
				if(log_exp->kindofID == "VAR") var->floatelements[var->arrindex] = (float)log_exp->intelements[0];
				else var->floatelements[var->arrindex] = (float)log_exp->intelements[log_exp->arrindex];
			}
			else{
				writewarning("Assigning float value to integer.");
				if(log_exp->kindofID == "VAR") var->floatelements[var->arrindex] = log_exp->floatelements[0];
				else var->floatelements[var->arrindex] = log_exp->floatelements[log_exp->arrindex];
			}
		}
	}
	return var;
}

SymbolInfo * rellogicrel(SymbolInfo* log_exp, SymbolInfo* rel_exp1, SymbolInfo* log_op, SymbolInfo* rel_exp3){
	cout << "rellogicrel func" << endl;
	SymbolInfo* temp = makenewSymInfo("INT");
	string logicop = log_op->Getsname();
	if(logicop == "&&"){
		if(rel_exp1->kindofVariable == "FLOAT"){
			rel_exp1->floatelements.push_back(0);
			if(rel_exp1->floatelements[0] == 0){
				temp->intelements[0] = 0;								
			}
			else if(rel_exp3->kindofVariable == "FLOAT"){
				rel_exp3->floatelements.push_back(0);
				if(rel_exp3->floatelements[0] == 0) temp->intelements[0] = 0;
				else temp->intelements[0] = 1;
			}
			else if(rel_exp3->kindofVariable == "INT"){
				rel_exp3->intelements.push_back(0);
				if(rel_exp3->intelements[0] == 0) temp->intelements[0] = 0;
				else temp->intelements[0] = 1;
			}
		}
		else if(rel_exp1->kindofVariable == "INT"){
			rel_exp1->intelements.push_back(0);
			if(rel_exp1->intelements[0] == 0) temp->intelements[0] = 0;
			else if(rel_exp3->kindofVariable == "FLOAT"){
				if(rel_exp3->floatelements[0] == 0) temp->intelements[0] = 0;
				else temp->intelements[0] = 1;
			}
			else if(rel_exp3->kindofVariable == "INT"){
				rel_exp3->intelements.push_back(0);
				if(rel_exp3->intelements[0] == 0) temp->intelements[0] = 0;
				else temp->intelements[0] = 1;
			}
		}
	}
	else if(logicop == "||"){
		if(rel_exp1->kindofVariable == "FLOAT"){
			rel_exp1->floatelements.push_back(0);
			if(rel_exp1->floatelements[0] != 0){
				temp->intelements[0] = 1;								
			}
			else if(rel_exp3->kindofVariable == "FLOAT"){
				rel_exp3->floatelements.push_back(0);
				if(rel_exp3->floatelements[0] != 0) temp->intelements[0] = 1;
				else temp->intelements[0] =0;
			}
			else if(rel_exp3->kindofVariable == "INT"){
				if(rel_exp3->intelements[0] != 0) temp->intelements[0] = 1;
				else temp->intelements[0] =0;
			}
		}
		else if(rel_exp1->kindofVariable == "INT"){
			rel_exp1->intelements.push_back(0);
			if(rel_exp1->intelements[0] != 0) temp->intelements[0] = 1;
			else if(rel_exp3->kindofVariable == "FLOAT"){
				rel_exp3->floatelements.push_back(0);									
				if(rel_exp3->floatelements[0] != 0) temp->intelements[0] = 1;
				else temp->intelements[0] =0;
			}
			else if(rel_exp3->kindofVariable == "INT"){
				rel_exp3->intelements.push_back(0);
				if(rel_exp3->intelements[0] != 0) temp->intelements[0] = 1;
				else temp->intelements[0] =0;
			}
		}
	}
	return temp;
}

SymbolInfo* varinc(SymbolInfo* var){
	cout << "varinc func" << endl;
	if(var->kindofID == "ARR"){
		if(var->kindofVariable == "INT"){
			var->intelements[var->arrindex] = var->intelements[var->arrindex]+1; 
		}
		else if(var->kindofVariable == "FLOAT"){
			var->floatelements[var->arrindex] = var->floatelements[var->arrindex]+1.0; 
		}			
	}
	else if(var->kindofID == "VAR"){
		if(var->kindofVariable == "INT"){
			var->intelements[0] = var->intelements[0]+1; 
		}
		else if(var->kindofVariable == "FLOAT"){
			var->floatelements[0] = var->floatelements[0]+1.0; 
		}					
	}
	else if(var->kindofVariable == "FUNC"){
		writeerr("Function can't be incremented or decremented.");
		return 0;
	}
	return var;
}

SymbolInfo* vardec(SymbolInfo* var){
	cout << "vardec func" << endl;
	if(var->kindofID == "ARR"){
		if(var->kindofVariable == "INT"){
			var->intelements[var->arrindex] = var->intelements[var->arrindex]-1; 
		}
		else if(var->kindofVariable == "FLOAT"){
			var->floatelements[var->arrindex] = var->floatelements[var->arrindex]-1.0; 
		}			
	}
	else if(var->kindofID == "VAR"){
		if(var->kindofVariable == "INT"){
			var->intelements[0] = var->intelements[0]-1; 
		}
		else if(var->kindofVariable == "FLOAT"){
			var->floatelements[0] = var->floatelements[0]-1.0; 
		}					
	}
	else if(var->kindofVariable == "FUNC"){
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

	if(relop == "=="){
		if(simex1 == "INT"){
			if(sim_exp1->intelements[0] == sim_exp3->intelements[0]) temp->intelements[0] =1;
			else temp->intelements[0] =0;
		}
		else if(simex1 == "FLOAT"){
			if(sim_exp1->floatelements[0] == sim_exp3->floatelements[0]) temp->intelements[0] =1;
			else temp->intelements[0] =0;		
		}
	}
	else if(relop == "!="){
		if(simex1 == "INT"){
			if(sim_exp1->intelements[0] != sim_exp3->intelements[0]) temp->intelements[0] =1;
			else temp->intelements[0] =0;
		}
		else if(simex1 == "FLOAT"){
			if(sim_exp1->floatelements[0] != sim_exp3->floatelements[0]) temp->intelements[0] =1;
			else temp->intelements[0] =0;	
		}
	}
	else if(relop == "<=" || relop == "<"){
		if(simex1 == "INT"){
			if(simex3 == "INT"){
				if(sim_exp1->intelements[0] < sim_exp3->intelements[0]) temp->intelements[0] =1;
				else if(sim_exp1->intelements[0] == sim_exp3->intelements[0]) temp->intelements[0] =1;
				else temp->intelements[0] =0;
			}
			else if(simex3 == "FLOAT"){
				if(sim_exp1->intelements[0] < sim_exp3->floatelements[0]) temp->intelements[0] =1;
				else if(sim_exp1->intelements[0] == sim_exp3->floatelements[0]) temp->intelements[0] =1;
				else temp->intelements[0] =0;
			}
		}
		else if(simex1 == "FLOAT"){
			if(simex3 == "INT"){
				if(sim_exp1->floatelements[0] < sim_exp3->intelements[0]) temp->intelements[0] =1;
				else if(sim_exp1->floatelements[0] == sim_exp3->intelements[0])temp->intelements[0] =1;
				else temp->intelements[0] =0;
			}
			else if(simex3 == "FLOAT"){
				if(sim_exp1->floatelements[0] < sim_exp3->floatelements[0]) temp->intelements[0] =1;
				else if(sim_exp1->floatelements[0] == sim_exp3->floatelements[0]) temp->intelements[0] =1;
				else temp->intelements[0] =0;
			}
		}
	}
	else if(relop == ">=" || relop == ">"){
		if(simex1 == "INT"){
			if(simex3 == "INT"){
				if(sim_exp1->intelements[0] > sim_exp3->intelements[0]) temp->intelements[0] =1;
				else if(sim_exp1->intelements[0] == sim_exp3->intelements[0])temp->intelements[0] =1;
				else temp->intelements[0] =0;
			}
			else if(simex3 == "FLOAT"){
				if(sim_exp1->intelements[0] > sim_exp3->floatelements[0]) temp->intelements[0] =1;
				else if(sim_exp1->intelements[0] == sim_exp3->floatelements[0]) temp->intelements[0] =1;
				else temp->intelements[0] =0;
			}
		}
		else if(simex1 == "FLOAT"){
			if(simex3 == "INT"){
				if(sim_exp1->floatelements[0] > sim_exp3->intelements[0]) temp->intelements[0] =1;
				else if(sim_exp1->floatelements[0] == sim_exp3->intelements[0]) temp->intelements[0] =1;
				else temp->intelements[0] =0;
			}
			else if(simex3 == "FLOAT"){
				if(sim_exp1->floatelements[0] > sim_exp3->floatelements[0]) temp->intelements[0] =1;
				else if(sim_exp1->floatelements[0] == sim_exp3->floatelements[0]) temp->intelements[0] =1;
				else temp->intelements[0] =0;
			}
		}
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
					if(una_exp->kindofVariable == "INT") temp->floatelements[0]=term2->floatelements[0] * una_exp->intelements[0];
					else temp->floatelements[0]=term2->floatelements[0] * una_exp->floatelements[0];
					return temp;
				}
				else if(una_exp->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term2->kindofVariable == "INT") temp->floatelements[0]=term2->intelements[0] * una_exp->floatelements[0];
					else temp->floatelements[0]=term2->floatelements[0] * una_exp->floatelements[0];
					return temp;
				}
				else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=term2->intelements[0] * una_exp->intelements[0];
					return temp;
				}
			}
			else if(una_exp->kindofID == "ARR"){		
				if(term2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(una_exp->kindofVariable == "INT") temp->floatelements[0]=term2->floatelements[0] * una_exp->intelements[una_exp->arrindex];							
					else temp->floatelements[0]=term2->floatelements[0] * una_exp->floatelements[una_exp->arrindex];
					return temp;
				}
				else if(una_exp->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term2->kindofVariable == "INT") temp->floatelements[0]=term2->intelements[0] * una_exp->floatelements[una_exp->arrindex];
					else temp->floatelements[0]=term2->floatelements[0] * una_exp->floatelements[una_exp->arrindex];
					return temp;
				}
				else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=term2->intelements[0] * una_exp->intelements[0];
					return temp;
				}
			}
		}
		else if(term2->kindofID == "ARR"){	
			if(una_exp->kindofID == "VAR"){		
				if(term2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(una_exp->kindofVariable == "INT") temp->floatelements[0]=term2->floatelements[term2->arrindex] * una_exp->intelements[0];
					else temp->floatelements[0]=term2->floatelements[term2->arrindex] * una_exp->floatelements[0];
					return temp;
				}
				else if(una_exp->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term2->kindofVariable == "INT") temp->floatelements[0]=term2->intelements[term2->arrindex] * una_exp->floatelements[0];
					else temp->floatelements[0]=term2->floatelements[term2->arrindex] * una_exp->floatelements[0];
					return temp;
				}
				else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=term2->intelements[term2->arrindex] * una_exp->intelements[0];
					return temp;
				}
			}
			else if(una_exp->kindofID == "ARR"){		
				if(term2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(una_exp->kindofVariable == "INT") temp->floatelements[0]=term2->floatelements[term2->arrindex] * una_exp->intelements[una_exp->arrindex];
					else temp->floatelements[0]=term2->floatelements[term2->arrindex] * una_exp->floatelements[una_exp->arrindex];
					return temp;
				}
				else if(una_exp->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term2->kindofVariable == "INT") temp->floatelements[0]=term2->intelements[term2->arrindex] * una_exp->floatelements[una_exp->arrindex];
					else temp->floatelements[0]=term2->floatelements[term2->arrindex] * una_exp->floatelements[una_exp->arrindex];
					return temp;
				}
				else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=term2->intelements[term2->arrindex] * una_exp->intelements[0];
					return temp;
				}
			}
		}
	}
	else if(mulop == "/"){
		if(term2->kindofVariable == "FLOAT"){
			SymbolInfo* temp = makenewSymInfo("FLOAT");
			if(una_exp->kindofVariable == "INT"){
				if(term2->kindofID == "VAR"){
					if(una_exp->kindofID == "VAR"){
						if(una_exp->intelements[0] != 0)temp->floatelements[0]=term2->floatelements[0] / una_exp->intelements[0];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}							
					}
					else if(una_exp->kindofID == "ARR"){
						if(una_exp->intelements[una_exp->arrindex] != 0)temp->floatelements[0]=term2->floatelements[0] / una_exp->intelements[una_exp->arrindex];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}
					}
				}
				else if(term2->kindofID == "ARR"){
					if(una_exp->kindofID == "VAR"){
						if(una_exp->intelements[0] != 0)temp->floatelements[0]=term2->floatelements[term2->arrindex] / una_exp->intelements[0];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}							
					}
					else if(una_exp->kindofID == "ARR"){
						if(una_exp->intelements[una_exp->arrindex] != 0) temp->floatelements[0]=term2->floatelements[term2->arrindex] / una_exp->intelements[una_exp->arrindex];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}
					}
				}
			}
			else if(una_exp->kindofVariable == "FLOAT"){
				if(term2->kindofID == "VAR"){
					if(una_exp->kindofID == "VAR"){
						if(una_exp->floatelements[0] != 0)temp->floatelements[0]=term2->floatelements[0] / una_exp->floatelements[0];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}							
					}
					else if(una_exp->kindofID == "ARR"){
						if(una_exp->floatelements[una_exp->arrindex] != 0)temp->floatelements[0]=term2->floatelements[0] / una_exp->floatelements[una_exp->arrindex];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}
					}
				}
				else if(term2->kindofID == "ARR"){
					if(una_exp->kindofID == "VAR"){
						if(una_exp->floatelements[0] != 0)temp->floatelements[0]=term2->floatelements[term2->arrindex] / una_exp->floatelements[0];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}							
					}
					else if(una_exp->kindofID == "ARR"){
						if(una_exp->floatelements[una_exp->arrindex] != 0) temp->floatelements[0]=term2->floatelements[term2->arrindex] / una_exp->floatelements[una_exp->arrindex];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}
					}
				}
			}
			return temp;
		}
		else if(una_exp->kindofVariable == "FLOAT"){
			SymbolInfo* temp = makenewSymInfo("FLOAT");
			if(term2->kindofVariable == "INT"){
				if(term2->kindofID == "VAR"){
					if(una_exp->kindofID == "VAR"){
						if(una_exp->floatelements[0] != 0)temp->floatelements[0]=term2->intelements[0] / una_exp->floatelements[0];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}							
					}
					else if(una_exp->kindofID == "ARR"){
						if(una_exp->floatelements[una_exp->arrindex] != 0)temp->floatelements[0]=term2->intelements[0] / una_exp->floatelements[una_exp->arrindex];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}
					}
				}
				else if(term2->kindofID == "ARR"){
					if(una_exp->kindofID == "VAR"){
						if(una_exp->floatelements[0] != 0)temp->floatelements[0]=term2->intelements[term2->arrindex] / una_exp->floatelements[0];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}							
					}
					else if(una_exp->kindofID == "ARR"){
						if(una_exp->floatelements[una_exp->arrindex] != 0) temp->floatelements[0]=term2->intelements[term2->arrindex] / una_exp->floatelements[una_exp->arrindex];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}
					}
				}
			}
			else if(term2->kindofVariable == "FLOAT"){
				if(term2->kindofID == "VAR"){
					if(una_exp->kindofID == "VAR"){
						if(una_exp->floatelements[0] != 0)temp->floatelements[0]=term2->floatelements[0] / una_exp->floatelements[0];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}							
					}
					else if(una_exp->kindofID == "ARR"){
						if(una_exp->floatelements[una_exp->arrindex] != 0)temp->floatelements[0]=term2->floatelements[0] / una_exp->floatelements[una_exp->arrindex];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}
					}
				}
				else if(term2->kindofID == "ARR"){
					if(una_exp->kindofID == "VAR"){
						if(una_exp->floatelements[0] != 0)temp->floatelements[0]=term2->floatelements[term2->arrindex] / una_exp->floatelements[0];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}							
					}
					else if(una_exp->kindofID == "ARR"){
						if(una_exp->floatelements[una_exp->arrindex] != 0) temp->floatelements[0]=term2->floatelements[term2->arrindex] / una_exp->floatelements[una_exp->arrindex];
						else{
							temp->floatelements[0]=inf();
							writeerr("Divide by zero");
							return 0;
						}
					}
				}
			}				
			return temp;
		}
		else if(una_exp->kindofVariable == "INT" && term2->kindofVariable == "INT"){
			SymbolInfo* temp = makenewSymInfo("INT");
			if(term2->kindofID == "VAR"){	
				if(una_exp->kindofID == "VAR"){			
					if(una_exp->intelements[0] != 0)temp->intelements[0]=term2->intelements[0] / una_exp->intelements[0];
					else{
						temp->intelements[0]=intinf();
						writeerr("Divide by zero");
						return 0;
					}
				}
				else if(una_exp->kindofID == "ARR"){
					if(una_exp->intelements[una_exp->arrindex] != 0)temp->intelements[0]=term2->intelements[0] / una_exp->intelements[una_exp->arrindex];
					else{
						temp->intelements[0]=intinf();
						writeerr("Divide by zero");
						return 0;
					}
				}
			}
			else if(term2->kindofID == "ARR"){
				if(una_exp->kindofID == "VAR"){			
					if(una_exp->intelements[0] != 0)temp->intelements[0]=term2->intelements[term2->arrindex] / una_exp->intelements[0];
					else{
						temp->intelements[0]=intinf();
						writeerr("Divide by zero");
						return 0;
					}
				}
				else if(una_exp->kindofID == "ARR"){
					if(una_exp->intelements[una_exp->arrindex] != 0) temp->intelements[0]=term2->intelements[term2->arrindex] / una_exp->intelements[una_exp->arrindex];
					else{
						temp->floatelements[0]=intinf();
						writeerr("Divide by zero");
						return 0;
					}
				}
			}
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
		else if(term2->kindofVariable == "INT" && una_exp->kindofVariable == "INT"){
			if(term2->kindofID == "VAR"){
				if(una_exp->kindofID == "VAR")temp->intelements[0]=(term2->intelements[0])%(una_exp->intelements[0]);
				else temp->intelements[0]= (term2->intelements[0])%(una_exp->intelements[una_exp->arrindex]);					
			}
			else{
				if(una_exp->kindofID == "VAR")temp->intelements[0]=(term2->intelements[term2->arrindex])%(una_exp->intelements[0]);
				else temp->intelements[0]=(term2->intelements[term2->arrindex])%(una_exp->intelements[una_exp->arrindex]);					
			}
		}
		return temp;
	}
}


SymbolInfo* simexpaddopterm(SymbolInfo* sim_exp1,SymbolInfo* sim_exp2,SymbolInfo* add_op,SymbolInfo* term){
	cout << "simexpaddopterm func" << endl;
	string addop = add_op->Getsname();
	if(addop == "+"){
		////cout << "ekhane " << endl; 
		if(sim_exp2->kindofID == "VAR"){
			////cout << "ekhane " << endl;
			if(term->kindofID == "VAR"){
				////cout << "ekhane " << endl;						
				if(sim_exp2->kindofVariable == "FLOAT"){
					////cout << "ekhane " << endl;
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					//temp->intelements.push_back(0);
					temp->floatelements.push_back(0);
					if(term->kindofVariable == "INT"){
						temp->floatelements[0] =sim_exp2->floatelements[0] + term->intelements[0];							
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[0] + term->floatelements[0];
					}
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					////cout << "ekhane " << endl;
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					//temp->intelements.push_back(0);
					temp->floatelements.push_back(0);
					if(sim_exp2->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->intelements[0] + term->floatelements[0];							
					}
					else{
						temp->floatelements[0]= sim_exp2->floatelements[0] + term->floatelements[0];
					}
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					////cout << "ekhane " << endl;
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0] = sim_exp2->intelements[0] + term->intelements[0];
					return temp;
				}
			}
			else if(term->kindofID == "ARR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term->kindofVariable == "INT"){
						temp->floatelements[0] = sim_exp2->floatelements[0] + term->intelements[term->arrindex];							
					}
					else{
						temp->floatelements[0]= sim_exp2->floatelements[0] + term->floatelements[term->arrindex];
					}
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(sim_exp2->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->intelements[0] + term->floatelements[term->arrindex];							
					}
					else{
						temp->floatelements[0] = sim_exp2->floatelements[0] + term->floatelements[term->arrindex];
					}
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0] =sim_exp2->intelements[0] + term->intelements[term->arrindex];
					return temp;
				}
			}
		}
		else if(sim_exp2->kindofID == "ARR"){
			if(term->kindofID == "VAR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term->kindofVariable == "INT"){
						temp->floatelements[0] =sim_exp2->floatelements[sim_exp2->arrindex] + term->intelements[0];							
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] + term->floatelements[0];
					}
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(sim_exp2->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->intelements[sim_exp2->arrindex] + term->floatelements[0];							
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] + term->floatelements[0];
					}
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=sim_exp2->intelements[sim_exp2->arrindex] + term->intelements[0];
					return temp;
				}
			}
			else if(term->kindofID == "ARR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] + term->intelements[term->arrindex];
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] + term->floatelements[term->arrindex];
					}
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(sim_exp2->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->intelements[sim_exp2->arrindex] + term->floatelements[term->arrindex];
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] + term->floatelements[term->arrindex];
					}
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=sim_exp2->intelements[sim_exp2->arrindex] + term->intelements[term->arrindex];
					return temp;
				}
			}
		}
	}
	else if(addop == "-"){
		////cout << "ekhane " << endl;
		if(sim_exp2->kindofID == "VAR"){
			if(term->kindofID == "VAR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->floatelements[0] - term->intelements[0];							
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[0] - term->floatelements[0];
					}
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(sim_exp2->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->intelements[0] - term->floatelements[0];							
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[0] - term->floatelements[0];
					}
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=sim_exp2->intelements[0] - term->intelements[0];
					return temp;
				}
			}
			else if(term->kindofID == "ARR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->floatelements[0] - term->intelements[term->arrindex];							
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[0] - term->floatelements[term->arrindex];
					}
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(sim_exp2->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->intelements[0] - term->floatelements[term->arrindex];							
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[0] - term->floatelements[term->arrindex];
					}
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=sim_exp2->intelements[0] - term->intelements[term->arrindex];
					return temp;
				}
			}
		}
		else if(sim_exp2->kindofID == "ARR"){
			if(term->kindofID == "VAR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] - term->intelements[0];							
					}
					else{
						temp->floatelements[0]= sim_exp2->floatelements[sim_exp2->arrindex] - term->floatelements[0];
					}
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(sim_exp2->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->intelements[sim_exp2->arrindex] - term->floatelements[0];							
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] - term->floatelements[0];
					}
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=sim_exp2->intelements[sim_exp2->arrindex] - term->intelements[0];
					return temp;
				}
			}
			else if(term->kindofID == "ARR"){						
				if(sim_exp2->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(term->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] - term->intelements[term->arrindex];
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] - term->floatelements[term->arrindex];
					}
					return temp;
				}
				else if(term->kindofVariable == "FLOAT"){
					SymbolInfo* temp = makenewSymInfo("FLOAT");
					if(sim_exp2->kindofVariable == "INT"){
						temp->floatelements[0]=sim_exp2->intelements[sim_exp2->arrindex] - term->floatelements[term->arrindex];
					}
					else{
						temp->floatelements[0]=sim_exp2->floatelements[sim_exp2->arrindex] - term->floatelements[term->arrindex];
					}
					return temp;
				}
				else if(term->kindofVariable == "INT" && sim_exp2->kindofVariable == "INT"){
					SymbolInfo* temp = makenewSymInfo("INT");
					temp->intelements[0]=sim_exp2->intelements[sim_exp2->arrindex] - term->intelements[term->arrindex];
					return temp;
				}
			}
		}
	}
	return 0;
}

SymbolInfo* addopuna(SymbolInfo* una_exp1, SymbolInfo* add_op, SymbolInfo* una_exp2){
	cout << "addopuna func" << endl;
	if(add_op->Getsname() == "-"){
		if(una_exp2->kindofVariable == "VAR"){
			una_exp2->intelements[0] = (-1)*(una_exp2->intelements[0]);
		}
		else if(una_exp2->kindofVariable == "ARR"){
			una_exp2->intelements[una_exp2->arrindex] = (-1)*(una_exp2->intelements[una_exp2->arrindex]);
		}
	}
	return una_exp2;
}

SymbolInfo* notuna(SymbolInfo* una_exp1, SymbolInfo* una_exp2){
	cout << "notuna func" << endl;
	SymbolInfo* temp = makenewSymInfo("INT");
	temp->kindofID = "VAR";
	int value;
	if(una_exp2->kindofVariable == "INT"){
		if(una_exp2->kindofID == "VAR") value = una_exp2->intelements[0];
		else if(una_exp2->kindofID == "ARR")value = una_exp2->intelements[una_exp2->arrindex];
	}
	else if(una_exp2->kindofVariable == "FLOAT"){
		if(una_exp2->kindofID == "VAR") value = (int)una_exp2->floatelements[0];
		else if(una_exp2->kindofID == "ARR") value = (int)una_exp2->floatelements[una_exp2->arrindex];
	} 
	if(value != 0) value = 0;
	else value = 1;
	temp->intelements[0]=value;
	return temp;
}