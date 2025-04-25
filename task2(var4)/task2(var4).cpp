#include <iostream>

using namespace std;

//Створюємо абстрактний клас function з віртуальним деструктором та віртуальним методом
class function
{
public:
    function() = default;
    virtual ~function() = default;

    virtual double calculate(double x) const = 0;
};

//Стоврюємо похідний клас від function, класс line
class line : public function
{
private:
    double a;
    double b;
public:
    line(double newA = 0.0, double newB = 0.0) : a(newA), b(newB)
    {
        cout << "Straight const." << endl;
    }

    ~line() = default;

    double getA() const{ return a; }
    double getB() const { return b; }

    void setA(double newA) { this->a = newA; }
    void setB(double newB) { this->b = newB; }

    //Перевизначений метод обчислення з x для line
    double calculate(double x) const override
    {
        return a * x + b;
    }
};

//Стоврюємо похідний клас від function, класс ellipse
class ellipse : public function
{
private:
    double a;
    double b;
public:
    ellipse(double newA = 0.0, double newB = 0.0) : a(newA), b(newB)
    {
        cout << "Ellipse const." << endl;
    }

    ~ellipse() = default;

    double getA() const { return a; }
    double getB() const { return b; }

    void setA(double newA) { this->a = newA; }
    void setB(double newB) { this->b = newB; }

    //Перевизначений метод обчислення з x для ellipse
    double calculate(double x) const override
    {
        if (x * x > a * a)
        {
            throw out_of_range("x is out of range for the ellipse.");
        }

        return b * sqrt(1 - x * x / (a * a));
    }
};

//Стоврюємо похідний клас від function, класс hyperbola
class hyperbola : public function
{
private:
    double a;
    double b;
public:
    hyperbola(double newA = 0.0, double newB = 0.0) : a(newA), b(newB)
    {
        cout << "hyperbola const." << endl;
    }

    ~hyperbola() = default;

    double getA() const { return a; }
    double getB() const { return b; }

    void setA(double newA) { this->a = newA; }
    void setB(double newB) { this->b = newB; }

    //Перевизначений метод обчислення з x для hyperbola
    double calculate(double x) const override
    {
        if (x * x < a * a)
        {
            throw out_of_range("x is out of range for the ellipse.");
        }

        return b * sqrt(x * x / (a * a) - 1);
    }
};

int main()
{
    //Створюємо масив вказівників на абстрактний клас і присвоюємо адреси об'єктів похідних класів
    function* figures[3] = { new line(2.0, 3.0),
                             new ellipse(5.0, 3.0),
                             new hyperbola(4.0, 2.0)};

    //Присвоюємо x значення 3
    double x = 3.0;

    //Проходимося по всім елементам масиву і викликаємо метод calculate для кожного з них
    for (int i = 0; i < 3; i++)
    {
        try
        {
            cout << "Function value at x = " << x << ": " << figures[i]->calculate(x) << endl;
        }
        catch (const out_of_range& e)
        {
            cout << e.what() << endl;
        }
    }

    //Звільнямо пам'ять
    for (int i = 0; i < 3; i++)
    {
        delete figures[i];
    }
}
