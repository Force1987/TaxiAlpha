#pragma once
#include <iostream>
#include "Driver.h"
class DriverList
{
	unsigned int counter = 0;
	Driver** drivers = NULL;
	
public:
	~DriverList() {
		for (unsigned int i = 0; i < counter; i++)
			delete drivers[i];
		delete[] drivers;
	}
	Driver* operator[] (string name) {
		for (unsigned int i = 0; i < counter; i++) {
			if (drivers[i]->getName() == name)
				return drivers[i];
		}
		return NULL;
	}
	Driver* operator[] (unsigned int num) {
		if (num <= counter)
			return drivers[num];
		else return NULL;
	}

	int getCounter() {
		return counter;
	}
	void add (string name, string phone) {
		Driver** buf = new Driver * [++counter];
		for (unsigned int i = 0; i < counter-1; i++)
			buf[i] = drivers[i];
		buf[counter-1] = new Driver(counter, name, phone);
		delete[]drivers;
		drivers = buf;
	}
	void newOrder(double distance) {
		if (drivers == NULL)
			cout << "Driver data is corrupted or not initialized\n";
		else
		{
			int* freeDrivers = new int[this->counter];
			int counter=0;
			for (unsigned int i = 0; i < this->counter; i++) {
				if (drivers[i]->isEmployed() == false&& drivers[i]->isOnline())
					freeDrivers[counter++] = i;
			}
			if (counter == 0)
				cout << "All online drivers are busy. Can't process the order\n";
			else {
				drivers[freeDrivers[rand() % counter]]->assignAnOrder(distance);
			}
			delete[]freeDrivers;
		}
	}
	void listAll() {
		cout << "All drivers:\n";
		for (unsigned int i = 0; i < counter; i++) {
			drivers[i]->print();
		}
	}

	void listFree() {
		cout << "Free drivers:\n";
		for (unsigned int i = 0; i < counter; i++) {
			if(drivers[i]->isOnline()&&drivers[i]->isEmployed())
			drivers[i]->print();
		}
	}
};

