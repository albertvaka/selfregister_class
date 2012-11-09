SelfRegister class for C++
==========================

Description
-----------

This C++ class allows you to easily keep track of all your alive instances, just inheriting from it.

Inheriting `MyClass` from `SelfRegister<MyClass*>`, will give you a `MyClass::getAll()` method, that will return all the instances of MyClass you have created (and not destroyed yet).

The main benefit is that you can create and destroy objects whenever you need it, without having to manually update a central index of all them. This also eases freeing your memory.


Example
-------

The following is a usage example of this class in a videogame code:

    //Our Enemy class will be self-registering
    class Enemy : public SelfRegister<Enemy*> {
    	...
    };

	
    //Then in our game level class...
	
	Load() {
		
		...
		
		//We don't need to store them!
		new Enemy("enemy1.png");
		new Enemy("enemy2.png");
		new Enemy("enemy3.png");
		
		..
		
	}

	Update() {
		
		...
		
		//We can access all our existing enemies easily
		//(I use Boost's foreach, but of course this can be done using iterators)
		BOOST_FOREACH(Enemy * enemy, Enemy::getAll()) {
		
			if (enemy->inRange(player)) {
				enemy->shoot(player);
			}
			
		}
		
		...
		
	}

	Unload() {

		...
		
		//This will destroy all the currently existing instances (if any), preventing leaks.
		Enemy::destroyAll();
		
		...
		
	}
	