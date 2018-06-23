#include "SymTab.h"
using namespace std;

SymbolInfo::SymbolInfo(string nval, string tval)
{
    Setsname(nval);
    Setstype(tval);
    next = 0;
}

SymbolInfo::SymbolInfo(string tval)
{
    kindofVariable = tval;
    if(tval == "INT") intelements.push_back(0);
    else if(tval == "FLOAT") floatelements.push_back(0);
    next = 0;
}

SymbolInfo::SymbolInfo(){}

SymbolInfo::~SymbolInfo()
{
    //dtor
}






ScopeTable::ScopeTable(int s, int id)
{
    symPtr = new SymbolInfo*[s];
    bucSize = s;
    Tabid = id;
    for(int i = 0; i<s; i++){
        symPtr[i] = 0;
    }
}

ScopeTable::~ScopeTable()
{
    SymbolInfo *temp;
    SymbolInfo *temp2;
    for(int i = 0; i < bucSize; i++){
        temp = symPtr[i];
        while(temp != 0){
            temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
    delete[] symPtr;
}

unsigned long int ScopeTable::hashfunc(char *str)
{
    unsigned long int index = 9199;
    int c;
    int i = 0;
    while(c = str[i]){
        index = index * 33 + c;
        i++;
    }
    return index;
}

SymbolInfo * ScopeTable::LookUp(string sym)
{

    unsigned long int index;
    char *cstr = new char[sym.length() + 1];
    strcpy(cstr, sym.c_str());
    index = hashfunc(cstr);
    index = index % bucSize;
    delete []cstr;
    SymbolInfo *temp;
    temp = symPtr[index];
    if (temp == 0) {
        //cout << " Not Found" << endl;
        return 0;
    }
    else{
        int i = 0;
        while(temp != 0){
            if (temp->Getsname() == sym) {
                //cout << " Found at ScopeTable# " << Tabid << " at position " << index << "," << i << endl;
                return temp;
            }
            else {
                temp = temp->next;
                i++;
            }
        }
    }
    //cout << " Not Found" << endl;
    return 0;
}



bool ScopeTable::Insert(string symname, string symtype){
    SymbolInfo *temp;
    temp = LookUp(symname);
    if(temp == 0){
        SymbolInfo *temp2;
        temp2 = new SymbolInfo(symname,symtype);
        unsigned long int index;
        char *cstr = new char[symname.length() + 1];
        strcpy(cstr, symname.c_str());
        index = hashfunc(cstr);
        index = index % bucSize;
        delete []cstr;
        temp = symPtr[index];
        int i = 0;
        if(temp == 0){
            symPtr[index] = temp2;
            cout << " Inserted in ScopeTable #" << Tabid << " at position " << index << "," << i << " " << symname << endl;
            return true;
        }
        i++;
        while(temp->next != 0){
            temp = temp->next;
            i++;
        }
        temp->next = temp2;
        cout << " Inserted in ScopeTable #" << Tabid << " at position " << index << "," << i << " " << symname << endl;
        return true;
    }
    cout << " < " << symname << "," << symtype << " > already exists in curent scope" << endl;
    return false;
}

void ScopeTable::print(){
    SymbolInfo *temp;
    cout << " ScopeTable# " << Tabid << endl;
    for(int i = 0; i < bucSize; i++){
        temp = symPtr[i];
        cout << " " << i << " -->";
        while(temp != 0){
            cout << " < " << temp->Getsname() << ", " << temp->Getstype() << " > ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void ScopeTable::printinFile(ofstream& logFile){
    //fprintf(logout,"\n");
    logFile << endl ;
    SymbolInfo *temp;
    //fprintf(logout," ScopeTable# %d\n",Tabid);
    logFile << " ScopeTable# " << Tabid << endl;
    for(int i = 0; i < bucSize; i++){
        temp = symPtr[i];
        if(temp != 0){
            //fprintf(logout," %d -->",i);
            logFile << i << "-->";
            while(temp != 0){
                //fprintf(logout," < %s, %s > ",temp->Getstype().data(),temp->Getsname().data());
                logFile << " < " << temp->Getstype() << ", " << temp->Getsname() << " > " << endl;
                temp = temp->next;
            }
            //fprintf(logout,"\n");
            logFile << endl << endl;
        }
    }
    //fprintf(logout,"\n");
    logFile << endl ;
}

bool ScopeTable::Delete(string sym){
    SymbolInfo *temp;
    temp = LookUp(sym);
    if(temp == 0){
        return false;
    }
    unsigned long int index;
    char *cstr = new char[sym.length() + 1];
    strcpy(cstr, sym.c_str());
    index = hashfunc(cstr);
    index = index % bucSize;
    delete []cstr;
    temp = symPtr[index];
    SymbolInfo *par;
    par = 0;
    int i = 0;
    while (temp != 0){
        if (temp->Getsname().compare(sym)){
            par = temp;
            temp = temp->next;
            i++;
        }
        else break;
    }
    if (par == 0){
        symPtr[index] = temp->next;
        delete temp;
        //cout << " Deleted entry at " << index << "," << i << " from current ScopeTable" << endl;
        return true;
    }
    par->next = temp->next;
    delete temp;
    //cout << " Deleted entry at " << index << "," << i << " from current ScopeTable" << endl;
    return true;
}









SymbolTable::SymbolTable(int s)
{
    curTabid = 1;
    s_buc = s;
    ScopeTable *s1;
    s1 = new ScopeTable(s,curTabid);
    s1->parentScope = 0;
    current = s1;
}

SymbolTable::~SymbolTable()
{
	ScopeTable *temp;
	if(current != 0){
		temp = current;
		current = current->parentScope;
		while(temp != 0){
			delete temp;
			temp = current;
			if(temp != 0) current = current->parentScope;
		}
	}
}

void SymbolTable::EnterScope(ofstream& logFile){
    curTabid++;
    ScopeTable *s1;
    s1 = new ScopeTable(s_buc,curTabid);
    s1->parentScope = current;
    current = s1;
    logFile << " New ScopeTable with id " << curTabid << " created" << endl <<endl;
}

void SymbolTable::ExitScope(ofstream& logFile){
    if(curTabid >= 1){
        curTabid--;
        ScopeTable *temp;
        temp = current;
        current = current->parentScope;
        delete temp;
        logFile << " ScopeTable with id " << curTabid + 1 << " removed" << endl <<endl; 
    }
}

bool SymbolTable::Insert(string symbolname, string symboltype){
    bool x;
    x = current->Insert(symbolname, symboltype);
    return x;
}

bool SymbolTable::Remove(string symbolname){
    bool x;
    x = current->Delete(symbolname);
    return x;
}

SymbolInfo * SymbolTable::LookUp(string symbolname){
    ScopeTable *temp;
    temp = current;
    SymbolInfo *found;
    while(temp != 0){
        found = temp->LookUp(symbolname);
        if(found) break;
        temp = temp->parentScope;
    }
    return found;
}

void SymbolTable::PrintCurrent(){
    current->print();
}

void SymbolTable::PrintAll(){
    ScopeTable *temp;
    temp = current;
    while(temp != 0){
        temp->print();
        temp = temp->parentScope;
        cout << endl;
    }
}

void SymbolTable::PrintAllinFile(ofstream& logFile){
    ScopeTable *temp;
    temp = current;
    while(temp != 0){
        temp->printinFile(logFile);
        temp = temp->parentScope;
        //cout << endl;
    }
}
