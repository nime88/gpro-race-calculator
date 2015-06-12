#ifndef STRATEGY_H
#define STRATEGY_H

#include <memory>

#include <QWidget>
#include <QTableWidgetItem>

class Strategy
{
private:
    int q1_temperature_;
    int q2_temperature_;
    double race_temperature_;
    int q1_humidity_;
    int q2_humidity_;
    double race_humidity_;

    QTableWidgetItem* q1_temperature_item_;
    QTableWidgetItem* q2_temperature_item_;
    QTableWidgetItem* race_temperature_item_;
    QTableWidgetItem* q1_humidity_item_;
    QTableWidgetItem* q2_humidity_item_;
    QTableWidgetItem* race_humidity_item_;

    template <typename T>
    inline bool checkTemperature(T temperature) {
        if (temperature < 0) return false;
        else if (temperature > 50) return false;
        return true;
    }

    template <typename T>
    inline bool checkHumidity(T humidity) {
        if (humidity < 0) return false;
        else if (humidity > 100) return false;
        return true;
    }
public:
    Strategy();

    // field initializations
    void initFields(std::shared_ptr<QWidget> parent);

    // setters
    inline void setQ1Temperature(const int temperature) { q1_temperature_ = temperature; }
    inline void setQ2Temperature(const int temperature) { q2_temperature_ = temperature; }
    inline void setRaceTemperature(const double temperature) { race_temperature_ = temperature; }
    inline void setQ1Humidity(const int humidity) { q1_humidity_ = humidity; }
    inline void setQ2Humidity(const int humidity) { q2_humidity_ = humidity; }
    inline void setRaceHumidity(const double humidity) { race_humidity_ = humidity; }

    // getters
    inline int getQ1Temperature() const { return q1_temperature_; }
    inline int getQ2Temperature() const { return q2_temperature_; }
    inline double getRaceTemperature() const { return race_temperature_; }
    inline int getQ1Humidity() const { return q1_humidity_; }
    inline int getQ2Humidity() const { return q2_humidity_; }
    inline double getRaceHumidity() const { return race_humidity_; }

    template <typename T>
    inline void setValueByLocation (T value, int row, int column) {
        //column 0 is temperature functions
        if (column == 0) {
            // setting q1 temperature
            if (row == 0) {
                if (checkTemperature(value)) { setQ1Temperature(value); }
                else if (value < 0) setQ1Temperature(0);
                else setQ1Temperature(50);
            }
            // setting q2 temperature
            else if (row == 1) {
                if (checkTemperature(value)) { setQ2Temperature(value); }
                else if (value < 0) setQ2Temperature(0);
                else setQ2Temperature(50);
            }
            // setting race temperature
            else if (row == 2) {
                if (checkTemperature(value)) { setRaceTemperature(value); }
                else if (value < 0) setRaceTemperature(0);
                else setRaceTemperature(50);
            }
        }
        // column 1 is humidity functions
        else if (column == 1) {
            // setting q1 humidity
            if (row == 0) {
                if (checkHumidity(value)) { setQ1Humidity(value); }
                else if (value < 0) setQ1Humidity(0);
                else setQ1Humidity(100);
            }
            // setting q2 humidity
            else if (row == 1) {
                if (checkHumidity(value)) { setQ2Humidity(value); }
                else if (value < 0) setQ2Humidity(0);
                else setQ2Humidity(100);
            }
            // setting race humidity
            else if (row == 2) {
                if (checkHumidity(value)) { setRaceHumidity(value); }
                else if (value < 0) setRaceHumidity(0);
                else setRaceHumidity(100);
            }
        }
    }

};

#endif // STRATEGY_H
