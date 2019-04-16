/* 
	Class:		TypeInfo
	Purpose:	Wrapper class enclosing type_info class
				which determines the type id for an object
*/

#ifndef TYPEINFO_H
#define TYPEINFO_H

#include <typeinfo>

using namespace std;

class TypeInfo
{
	public:
		//Keyword explicit ensures the constructor is used as defined
		explicit TypeInfo(const type_info& info) : _typeInfo(info) 
		{ }

		bool operator < (const TypeInfo& rhs) const
		{
			return _typeInfo.before(rhs._typeInfo) != 0;
		}

	private:
		const type_info& _typeInfo;
};

#endif