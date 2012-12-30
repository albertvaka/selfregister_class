#ifndef SelfRegister_H_
#define SelfRegister_H_

#include <set>
#include <cassert>

/**
 * Inheriting from this class gives you a static method getAll()
 * that returns a set with all the current instances of the class.
 */
template <typename T>
class SelfRegister {
public:
	SelfRegister()
	{ 
		_getAll().insert((T)this); 
	}
	SelfRegister(const SelfRegister& other)
	{
		_getAll().insert((T)this); 
	}
	void operator=(const SelfRegister& other)
	{
		_getAll().insert((T)this); 
	}
	~SelfRegister()
	{
		assert( _getAll().find((T)this) != _getAll().end() );
		_getAll().erase((T)this);
	}
	static const std::set<T>& getAll()
	{
		return _getAll();
	}
	static void destroyAll() { 
		for(typename std::set<T>::iterator i=_getAll().begin();
			i!=_getAll().end();
			i=_getAll().begin())
		{
			delete *i;
		}
	}
private:
	static std::set<T>& _getAll()
	{
		static std::set<T> instancies;
		return instancies;
	}

};

#endif
