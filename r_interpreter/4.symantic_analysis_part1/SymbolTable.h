#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>
#include <string>
#include "SymbolTableEntry.h"
using namespace std;

class SYMBOL_TABLE
{
private:
  std::map<string, SYMBOL_TABLE_ENTRY> hashTable;

public:
  //Constructor
  SYMBOL_TABLE( ) { }

  // Add SYMBOL_TABLE_ENTRY x to this symbol table.
  // If successful, return true; otherwise, return false.
  bool addEntry(SYMBOL_TABLE_ENTRY x)
  {
    // Make sure there isn't already an entry with the same name
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    if ((itr = hashTable.find(x.getName())) == hashTable.end())
    {
      hashTable.insert(make_pair(x.getName(), x));
      return(true);
    }
    else return(false);
  }

  // If a SYMBOL_TABLE_ENTRY with name theName is
  // found in this symbol table, then return true;
  // otherwise, return false.
 TYPE_INFO findEntryData(string theName)
  {

	 TYPE_INFO typeInfo = {UNDEFINED, NOT_APPLICABLE, NOT_APPLICABLE};
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    if ((itr = hashTable.find(theName)) == hashTable.end())
        return(typeInfo);
    else return(itr->second.getTypeCode());
  }

bool findEntry(string theName)
  {

	 TYPE_INFO typeInfo = {UNDEFINED, NOT_APPLICABLE, NOT_APPLICABLE};
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    if ((itr = hashTable.find(theName)) == hashTable.end())
        return(false);
    else return(true);
  }
	// handy little function to grab the type (i hope)
	TYPE_INFO getEntryType (string theName)
	{
    TYPE_INFO typ = {UNDEFINED, NOT_APPLICABLE, NOT_APPLICABLE};
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
		itr = hashTable.find(theName);
		typ = itr->second.getTypeCode();
		return(typ);
	}

};

#endif  // SYMBOL_TABLE_H
