#include <iostream>
#include "DriverList.h"
#include "CarsList.h"
int Driver::Order::counter = 0;

int main()
{
	DriverList drivers;
	drivers.add("Evgeniy", "8-988-777-77-77");
	drivers.add("Oleg", "8-928-177-53-35");
	drivers.add("Maksim", "8-951-527-26-26");
	drivers.add("Kostik", "8-951-534-26-56");
	drivers.listAll();
	CarsList cars;
	cars.add("Toyota Supra", "Green");
	cars.add("Gaz Volga", "White");
	cars.add("Kia Rio", "White");
	cars.listFree();
	drivers[1]->getInTheCar(cars.getRandomCar());
	drivers["Maksim"]->getInTheCar(cars.getRandomCar());
	drivers[0]->getInTheCar(cars.getRandomCar());
	Sleep(2000);
	drivers[3]->getInTheCar(cars.getRandomCar());
	Sleep(2000);
	drivers.newOrder(6.3);
	drivers.newOrder(5.1);
	drivers.newOrder(0.1);
	cars.listFree();
	drivers[1]->OrderStatus();
	drivers[2]->OrderStatus();
	Sleep(1000);
	cout << endl << endl;
	drivers["Oleg"]->orderComplete();
	drivers["Maksim"]->orderСancellation();
	drivers["Oleg"]->releaseTheCar();
	drivers[2]->releaseTheCar();
	cars.listFree();
}
