#include <iostream>
#include <string>
#include <cmath>

// Завдання 1
class Vehicle {
protected:
    std::string brand, model;
public:
    Vehicle(std::string b, std::string m) : brand(b), model(m) {}
    virtual void PrintInfo() { std::cout << "Brand: " << brand << ", Model: " << model << std::endl; }
};

class Car : public Vehicle {
    int doors;
public:
    Car(std::string b, std::string m, int d) : Vehicle(b, m), doors(d) {}
    void PrintInfo() override { Vehicle::PrintInfo(); std::cout << "Doors: " << doors << std::endl; }
};

class Motorcycle : public Vehicle {
    bool hasSidecar;
public:
    Motorcycle(std::string b, std::string m, bool s) : Vehicle(b, m), hasSidecar(s) {}
    void PrintInfo() override { Vehicle::PrintInfo(); std::cout << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl; }
};

// Завдання 2
class Shape {
public:
    virtual double Area() const = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const override { return M_PI * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double Area() const override { return width * height; }
};

// Завдання 3
class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(std::string n, int i) : name(n), id(i) {}
    virtual double CalculateSalary() const = 0;
};

class HourlyEmployee : public Employee {
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(std::string n, int i, double rate, int hours) : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}
    double CalculateSalary() const override { return hourlyRate * hoursWorked; }
};

class SalariedEmployee : public Employee {
    double salary;
public:
    SalariedEmployee(std::string n, int i, double s) : Employee(n, i), salary(s) {}
    double CalculateSalary() const override { return salary; }
};

// Завдання 4
class Animal {
public:
    virtual void MakeSound() const = 0;
};

class Dog : public Animal {
public:
    void MakeSound() const override { std::cout << "Woof" << std::endl; }
};

class Cat : public Animal {
public:
    void MakeSound() const override { std::cout << "Meow" << std::endl; }
};

class Cow : public Animal {
public:
    void MakeSound() const override { std::cout << "Moo" << std::endl; }
};

// Завдання 5
class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(n), age(a) {}
    virtual void PrintInfo() const { std::cout << "Name: " << name << ", Age: " << age << std::endl; }
};

class Student : public Person {
    std::string major;
public:
    Student(std::string n, int a, std::string m) : Person(n, a), major(m) {}
    void PrintInfo() const override { Person::PrintInfo(); std::cout << "Major: " << major << std::endl; }
};

class Teacher : public Person {
    std::string subject;
public:
    Teacher(std::string n, int a, std::string s) : Person(n, a), subject(s) {}
    void PrintInfo() const override { Person::PrintInfo(); std::cout << "Subject: " << subject << std::endl; }
};

int main() {
    Car car("Toyota", "Corolla", 4);
    Motorcycle motorcycle("Harley", "Sportster", false);
    car.PrintInfo();
    motorcycle.PrintInfo();

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    std::cout << "Circle Area: " << circle.Area() << std::endl;
    std::cout << "Rectangle Area: " << rectangle.Area() << std::endl;

    HourlyEmployee hourly("Alice", 1, 20.0, 40);
    SalariedEmployee salaried("Bob", 2, 3000.0);
    std::cout << "Hourly Employee Salary: " << hourly.CalculateSalary() << std::endl;
    std::cout << "Salaried Employee Salary: " << salaried.CalculateSalary() << std::endl;

    Dog dog;
    Cat cat;
    Cow cow;
    dog.MakeSound();
    cat.MakeSound();
    cow.MakeSound();

    Student student("Charlie", 20, "Computer Science");
    Teacher teacher("David", 45, "Mathematics");
    student.PrintInfo();
    teacher.PrintInfo();

    return 0;
}
