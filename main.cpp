#include <QCoreApplication>
#include "classes.h"

int main()
{
    ConcreteSubject subject;

    ConcreteObserver observer1("OBSERVER 1");
    ConcreteObserver observer2("OBSERVER 2");
    ConcreteObserver observer3("OBSERVER 3");

    subject.registerObserver(&observer1);
    subject.registerObserver(&observer2);
    subject.registerObserver(&observer3);

    subject.setState(1);

    subject.removeObserver(&observer2);
    std::cout << std::endl;

    subject.setState(2);

    return 0;
}
