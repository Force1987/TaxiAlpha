#pragma once
#include <iostream>
#include "Car.h"
class CarsList
{
	int counter = 0;
	Car** cars = nullptr;
public:
	~CarsList() {
		for (int i = 0; i < counter; i++)
			delete cars[i];
		delete[] cars;
	}
	void add(string model, string color) {
		Car** buf = new Car * [++counter];
		for (int i = 0; i < counter - 1; i++)
			buf[i] = cars[i];
		buf[counter - 1] = new Car (model, color, counter);
		delete[]cars;
		cars = buf;
	}
	void listAll() {
		if (cars == NULL)
			cout << "No registered cars.";
		else
		{
			cout << "All cars:\n";
			for (int i = 0; i < counter; i++)
				cars[i]->print();
		}
	}

	void listFree() {
		if (cars == NULL)
			cout << "No registered cars.";
		else
		{
			cout << "All free cars:\n";
			for (int i = 0; i < counter; i++)
				if (cars[i]->getStatus() == false)
					cars[i]->print();
		}
	}

	Car* getRandomCar() {
		Car* result = NULL;
		if (cars == NULL)
			cout << "No registered cars.";
		else
		{
			int counter = 0;
			int* freeCars = new int[this->counter];
			for (int i = 0; i < this->counter; i++)
				if (cars[i]->getStatus() == false)
					freeCars[counter++] = i;
			if (counter == 0)
				cout << "All cars are busy\n";
			else
				result = cars[freeCars[rand() % counter]];
			delete[]freeCars;
		}
		return result;
	}

};

