#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>


class Observer {
public:
    virtual void update(int newspaperNumber, const std::string& receiverName) = 0;
};

// субъект
class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(int newspaperNumber) = 0;
};

// конкретный наблюдатель
class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& observerName) : name(observerName) {}

    void update(int newspaperNumber, const std::string& receiverName) override {
        std::cout << "Newspaper " << newspaperNumber << " received " << name << " for " << receiverName << std::endl;
    }

    // для других методов
};

// конкретный субъект
class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;
    int state;

public:
    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers(int newspaperNumber) override {
        for (auto observer : observers) {
            observer->update(newspaperNumber, "ALL SUBSCRIBERS");
        }
    }

    int getState() {
        return state;
    }

    void setState(int newState) {
        state = newState;
        notifyObservers(state);
    }
};

#endif // CLASSES_H
