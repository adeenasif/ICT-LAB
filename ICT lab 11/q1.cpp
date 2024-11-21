#include <iostream>
#include <string.h>
using namespace std;

class Animal{
    private:
        string name;
        int age;

    public:
        void setName(string Name){
            name = Name;
        }

        void setAge(int Age){
            age = Age;
        }
        
        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

        void displayInfo(){
            cout << "Name: " << name << endl;
            cout << "Age: "  << age << endl;
        }
};
class Mammal: public Animal{
    public:
        void feedBaby(){
            cout << "Feeding baby mammal" << endl;
        }
};

class Bird: public Animal{
    public:
        void layEgg(){
            cout << "Laying an egg" << endl;
        }
};
class Reptile: public Animal{
    public:
        void shedSkin(){
            cout << "Shedding skin" << endl;
        }
};

int main(){
    Mammal mammalInfo;
    Bird birdInfo;
    Reptile reptileInfo;

    mammalInfo.setName("Lion");
    mammalInfo.setAge(10);
    cout << "Mammal: " << endl;
    mammalInfo.displayInfo();
    mammalInfo.feedBaby();
    cout << endl;

    birdInfo.setName("Parrot");
    birdInfo.setAge(7);
    cout << "Bird: " << endl;
    birdInfo.displayInfo();
    birdInfo.layEgg();
    cout << endl;

    reptileInfo.setName("Snake");
    reptileInfo.setAge(4);
    cout << "Reptile: " << endl;
    reptileInfo.displayInfo();
    reptileInfo.shedSkin();
    cout << endl;
}
