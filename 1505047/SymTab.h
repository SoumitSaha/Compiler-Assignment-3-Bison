#include<string>
#include<cstring>
#include<iostream>
#include<fstream>
#include <cstdio>
#include<stdio.h>
#include<vector>
#include<fstream>



#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H


class SymbolInfo
{
    private:
        std::string sname = "";
        std::string stype = "";

    public:
        SymbolInfo *next;
        std::string returntype;
        std::string kindofID; 
        std::string kindofVariable;
        std::string funcrettype;
        bool funcdefined;
        std::vector <std::string> parameters; 

        SymbolInfo(std::string nval, std::string tval);
        SymbolInfo(std::string tval);
        SymbolInfo();
        virtual ~SymbolInfo();
        std::string Getsname() { return sname; }
        void Setsname(std::string val) { sname = val; }
        std::string Getstype() { return stype; }
        void Setstype(std::string val) { stype = val; }
    protected:
};

#endif // SYMBOLINFO_H




#ifndef SCOPETABLE_H
#define SCOPETABLE_H

class ScopeTable
{
    public:
        int Tabid;
        int bucSize;
        ScopeTable *parentScope;
        SymbolInfo **symPtr;
        ScopeTable(int s, int id);
        virtual ~ScopeTable();
        unsigned long int hashfunc(char *str);
        SymbolInfo * LookUp(std::string sym);
        bool Insert(std::string symname, std::string symtype);
        void print();
        void printinFile(std::ofstream& logFile);
        bool Delete(std::string sym);
    protected:
    private:
};

#endif // SCOPETABLE_H




#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

class SymbolTable
{
    public:
        ScopeTable *current;
        int s_buc;
        int curTabid;

        SymbolTable(int s);
        virtual ~SymbolTable();
        void EnterScope(std::ofstream& logFile);
        void ExitScope(std::ofstream& logFile);
        bool Insert(std::string symbolname, std::string symboltype);
        bool Remove(std::string symbolname);
        SymbolInfo *LookUp(std::string symbolname);
        SymbolInfo *curLookUp(std::string symbolname);
        void PrintCurrent();
        void PrintAll();
        void PrintAllinFile(std::ofstream& logFile);
    protected:
    private:
};

#endif // SYMBOLTABLE_H