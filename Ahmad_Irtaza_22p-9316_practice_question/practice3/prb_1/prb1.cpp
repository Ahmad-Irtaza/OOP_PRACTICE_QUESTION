#include <iostream>
#include <iomanip>

class Angle
{
private:
    int degrees;
    float minutes;
    char direction;

public:
    Angle(int deg, float min, char dir)
    {
        degrees = deg;
        minutes = min;
        direction = dir;
    }

    void getAngle()
    {
        std::cout << "Enter angle value (in degrees and minutes): ";
        std::cin >> degrees >> minutes;
        std::cout << "Enter direction (N, S, E, or W): ";
        std::cin >> direction;
    }

    void displayAngle()
    {
        std::cout << std::setw(3) << degrees << '\xF8' << std::fixed << std::setprecision(1)
                  << std::setw(5) << minutes << "' " << direction << std::endl;
    }
};

int main()
{
    Angle initialAngle(149, 34.8, 'W');
    initialAngle.displayAngle();

    char choice;
    do
    {
        Angle angle(0, 0.0, ' ');

        angle.getAngle();
        angle.displayAngle();

        std::cout << "Do you want to enter another angle? (Y/N): ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

//        .............code Ends...............