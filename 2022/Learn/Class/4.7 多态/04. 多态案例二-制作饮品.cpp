#include <iostream>
using namespace std;

// class MakingDrinks
// {
// public:
//     virtual void BoilWater_F() = 0;
//     virtual void ImportTheCup_F() = 0;
//     virtual void MakingDrinks_F() = 0;
// };

// class Coffee: public MakingDrinks
// {
// public:
//     void BoilWater_F()
//     {
//         cout << "1. Making coffee one step: boil the water!!! " << endl;
//     }

//     void BrewedCoffee_F()
//     {
//         cout << "2. Making coffee second step: brewed coffee!!! " << endl;
//     }
    
//     void ImportTheCup_F()
//     {
//         cout << "3. Making coffee third step: import the cup!!! " << endl;
//     }

//     void AddSugar()
//     {
//         cout << "4. Making coffee fourth step: add sugar!!! " << endl;
//     }

//     void AddMilk()
//     {
//         cout << "5. Making coffee fifth step: add milk!!! " << endl;
//     }

//     void MakingDrinks_F()
//     {
//         BoilWater_F();
//         BrewedCoffee_F();
//         ImportTheCup_F();
//         AddSugar();
//         AddMilk();
//     }

// };

// class Tea: public MakingDrinks
// {
// public:
//     void BoilWater_F()
//     {
//         cout << "1. Making tea one step: boil the water!!! " << endl;
//     }

//     void BrewedTea_F()
//     {
//         cout << "2. Making tea second step: brewed tea!!! " << endl;
//     }

//     void ImportTheCup_F()
//     {
//         cout << "3. Making tea third step: import the cup!!! " << endl;
//     }

//     void AddLemon()
//     {
//         cout << "4. Making tea fourth step: add lemon!!! " << endl;
//     }
//     void MakingDrinks_F()
//     {
//         BoilWater_F();
//         BrewedTea_F();
//         ImportTheCup_F();
//         AddLemon();
//     }
// };


// void test01()
// {
//     MakingDrinks* drinks = new Coffee;
//     drinks->MakingDrinks_F();
//     delete drinks;

//     drinks = new Tea;
//     drinks->MakingDrinks_F();
//     delete drinks;
    
// }

class AbstractDrinking
{
public:
    virtual void BoilWater() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomething() = 0;
    virtual void MakeDrink()
    {
        BoilWater();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Coffee:public AbstractDrinking
{
public:
    virtual void BoilWater()
    {
        cout << "Make coffee Boil water......" << endl;
    }
    virtual void Brew()
    {
        cout << "Make coffee Brew coffee...... " << endl; 
    }
    virtual void PourInCup()
    {
        cout << "Make coffee Pour in cup...... " << endl;
    }
    virtual void PutSomething()
    {
        cout << "Make coffee Put sugar & milk......" << endl;
    }
};

class Tea:public AbstractDrinking
{
    public:
    virtual void BoilWater()
    {
        cout << "Make Tea Boil water......" << endl;
    }
    virtual void Brew()
    {
        cout << "Make Tea Brew tea...... " << endl; 
    }
    virtual void PourInCup()
    {
        cout << "Make Tea Pour in cup...... " << endl;
    }
    virtual void PutSomething()
    {
        cout << "Make Tea Put lemon......" << endl;
    }
};

void adm_doWork(AbstractDrinking* makeDrink)
{
    makeDrink->MakeDrink();
}

void test01()
{
    AbstractDrinking* coffee = new Coffee;
    adm_doWork(coffee);
    delete coffee;

    AbstractDrinking* tea = new Tea;
    adm_doWork(tea);
    delete tea;
}

int main()
{
    test01();
    return 0;
}