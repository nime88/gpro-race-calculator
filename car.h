#ifndef CAR_H
#define CAR_H

class Car
{
    private:
    static const char car_field_names_[] = {"Car.\"Name (Track)\"", "Car.Season", "Car.Power", "Car.Handling",
                                           "Car.Acceleration", "Car.Chassis", "Car.Engine", "Car.\"Front Wing\"",
                                           "Car.\"Rear Wing\"", "Car.Underbody", "Car.Sidepods", "Car.Cooling",
                                           "Car.Gearbox", "Car.Brakes", "Car.Suspension", "Car.Electronics"};

public:
    Car();

    static const char* const getFieldNames() { return car_field_names_; }
};

#endif // CAR_H
