#include "databasehandler.h"

#include <core/practice.h>
#include <core/car.h>
#include <utility/constants.h>

QString getTracksQuery() {
    QString select = "SELECT * ";
    QString from = "FROM public.\"Track\" ";
    return select % from;
}

QString getPracticeFields() {
    QString fields = QString(" \"Practice\".\"Name (Track)\", ") %
            QString("\"Practice\".\"Net Time\", ") %
            QString("\"Practice\".\"Front Wing\", ") %
            QString("\"Practice\".\"Rear Wing\", ") %
            QString("\"Practice\".\"Engine\", ") %
            QString("\"Practice\".\"Brakes\", ") %
            QString("\"Practice\".\"Gear\", ") %
            QString("\"Practice\".\"Suspension\", ") %
            QString("\"Practice\".\"Tyre Type\", ") %
            QString("\"Practice\".\"Weather\", ") %
            QString("\"Practice\".\"Temperature\", ") %
            QString("\"Practice\".\"Humidity\" ");
    return fields;
}

QString getStintFields() {
    QString fields  = QString(" \"Stint\".\"Name (Track)\", ") %
            QString(" \"Stint\".\"Laps\" AS \"SLaps\", ") %
            QString(" \"Stint\".\"Fuel\" AS \"SFuel\", ") %
            QString(" \"Stint\".\"Consumption\" AS \"SConsumption\", ") %
            QString(" \"Stint\".\"Final%\" AS \"SFinalP\", ") %
            QString(" \"Stint\".\"Avg. Humidity\" AS \"SHumidity\", ") %
            QString(" \"Stint\".\"Avg. Temperature\" AS \"STemperature\", ") %
            QString(" \"Stint\".\"Tyre Type\" AS \"STyreType\", ") %
            QString(" \"Stint\".\"Weather\" AS \"SWeather\", ") %
            QString(" \"Stint\".\"Km\" AS \"SKm\" ");
}

QString getCarLvlFields() {
    QString car_string = QString(" \"Car\".\"Power\" AS \"CPower\", ") %
            QString("\"Car\".\"Handling\" AS \"CHandling\", ") %
            QString("\"Car\".\"Acceleration\" AS \"CAcceleration\", ") %
            QString("\"Car\".\"Chassis\" AS \"CChassis\", ") %
            QString("\"Car\".\"Engine\" AS \"CEngine\", ") %
            QString("\"Car\".\"Front Wing\" AS \"CFrontWing\", ") %
            QString("\"Car\".\"Rear Wing\" AS \"CRearWing\", ") %
            QString("\"Car\".\"Underbody\" AS \"CUnderbody\", ") %
            QString("\"Car\".\"Sidepods\" AS \"CSidepods\", ") %
            QString("\"Car\".\"Cooling\" AS \"CCooling\", ") %
            QString("\"Car\".\"Gearbox\" AS \"CGearbox\", ") %
            QString("\"Car\".\"Brakes\" AS \"CBrakes\", ") %
            QString("\"Car\".\"Suspension\" AS \"CSuspension\", ") %
            QString("\"Car\".\"Electronics\" AS \"CElectronics\" ");
    return car_string;
}

QString getCarWearFields() {
    QString car_wear_string = QString(" \"CarWear\".\"Chassis Wear\" AS \"CWChassis\", ") %
            QString("\"CarWear\".\"Engine Wear\" AS \"CWEngine\", ") %
            QString("\"CarWear\".\"Front Wing Wear\" AS \"CWFrontWing\", ") %
            QString("\"CarWear\".\"Rear Wing Wear\" AS \"CWRearWing\", ") %
            QString("\"CarWear\".\"Underbody Wear\" AS \"CWUnderbody\", ") %
            QString("\"CarWear\".\"Sidepods Wear\" AS \"CWSidepods\", ") %
            QString("\"CarWear\".\"Cooling Wear\" AS \"CWCooling\", ") %
            QString("\"CarWear\".\"Gearbox Wear\" AS \"CWGearbox\", ") %
            QString("\"CarWear\".\"Brakes Wear\" AS \"CWBrakes\", ") %
            QString("\"CarWear\".\"Suspension Wear\" AS \"CWSuspension\", ") %
            QString("\"CarWear\".\"Electronics Wear\" AS \"CWElectronics\" ");
    return car_wear_string;
}

QString getDriverFields() {
    QString driver_string = QString(" \"Driver\".\"Overall\", ") %
            QString("\"Driver\".\"Concentration\", ") %
            QString("\"Driver\".\"Talent\", ") %
            QString("\"Driver\".\"Aggresiveness\", ") %
            QString("\"Driver\".\"Experience\", ") %
            QString("\"Driver\".\"Tech. Insight\", ") %
            QString("\"Driver\".\"Stamina\", ") %
            QString("\"Driver\".\"Charisma\", ") %
            QString("\"Driver\".\"Motivation\", ") %
            QString("\"Driver\".\"Weight\" ");
    return driver_string;
}

QString getRiskFields() {
    QString risk_string = QString(" \"Risk\".\"Name (Track)\", ") %
            QString(" \"Risk\".\"Clear\", ") %
            QString(" \"Risk\".\"Wet\", ") %
            QString(" \"Risk\".\"Defend\", ") %
            QString(" \"Risk\".\"Malfunction\", ") %
            QString(" \"Risk\".\"Overtake\" ");
    return risk_string;
}

QString getPracticeDataQuery() {
    QString select = "SELECT ";
    QString practice_fields = getPracticeFields() % QString(", ");
    QString track_fields = QString("\"Track\".*, ");
    QString car_lvl_fields = getCarLvlFields() % QString(", ");
    QString car_wear_fields = getCarWearFields() % QString(", ");
    QString driver_fields = getDriverFields();
    QString from = QString("FROM ") %
            QString("public.\"Practice\", ") %
            QString("public.\"Car\", ") %
            QString("public.\"CarWear\", ") %
            QString("public.\"Driver\", ") %
            QString("public.\"Track\" ") ;
    QString where = QString("WHERE ") %
            QString("\"Practice\".\"Name (Track)\" = \"Car\".\"Name (Track)\" AND ") %
            QString("\"Practice\".\"Name (Track)\" = \"CarWear\".\"Name (Track)\" AND ") %
            QString("\"Practice\".\"Name (Track)\" = \"Driver\".\"Name (Track)\" AND ") %
            QString("\"Practice\".\"Name (Track)\" = \"Track\".\"Name\" AND ") %
            QString("\"Practice\".\"Season\" = \"Car\".\"Season\" AND ") %
            QString("\"Practice\".\"Season\" = \"CarWear\".\"Season\" AND ") %
            QString("\"Practice\".\"Season\" = \"Driver\".\"Season\"");

    return select %
            practice_fields % track_fields % car_lvl_fields % car_wear_fields % driver_fields %
            from % where;
}

QString getStintDataQuery() {
    QString select = "SELECT ";
    QString stint_fields = getStintFields() % QString(", ");
    QString track_fields = QString("\"Track\".*, ");
    QString car_lvl_fields = getCarLvlFields() % QString(", ");
    QString car_wear_fields = getCarWearFields() % QString(", ");
    QString risk_fields = getRiskFields() % QString(", ");
    QString driver_fields = getDriverFields();
    QString from = QString("FROM ") %
            QString("public.\"Stint\", ") %
            QString("public.\"Track\", ") %
            QString("public.\"Car\", ") %
            QString("public.\"CarWear\", ") %
            QString("public.\"Risk\", ") %
            QString("public.\"Driver\" ");
    QString where = QString("WHERE ") %
    QString("\"Stint\".\"Name (Track)\" = \"Car\".\"Name (Track)\" AND ") %
    QString("\"Stint\".\"Name (Track)\" = \"CarWear\".\"Name (Track)\" AND ") %
    QString("\"Stint\".\"Name (Track)\" = \"Driver\".\"Name (Track)\" AND ") %
    QString("\"Stint\".\"Name (Track)\" = \"Track\".\"Name\" AND ") %
    QString("\"Stint\".\"Name (Track)\" = \"Risk\".\"Name (Track)\" AND ") %
    QString("\"Stint\".\"Season\" = \"Car\".\"Season\" AND ") %
    QString("\"Stint\".\"Season\" = \"CarWear\".\"Season\" AND ") %
    QString("\"Stint\".\"Season\" = \"Risk\".\"Season\" AND ") %
    QString("\"Stint\".\"Season\" = \"Driver\".\"Season\"");
    return select %
            stint_fields % track_fields % car_lvl_fields % car_wear_fields %
            risk_fields % driver_fields %
            from % where;
}

std::shared_ptr<Track> transform2Track (const QSqlQuery & query) {
    int field_no;
    std::shared_ptr<Track> temp_track = std::shared_ptr<Track>(new Track);

    for (unsigned int i = 0; i < Track::getFieldNames().size(); ++i) {
        field_no = query.record().indexOf(Track::getFieldNames().at(i));
        temp_track->setValue((TrackSlots)i, query.value(field_no));
    }

    return temp_track;
}

std::shared_ptr<Car> transform2Car(const QSqlQuery & query) {
    int field_no = 0;
    std::shared_ptr<Car> temp_car = std::shared_ptr<Car>(new Car);

    // track name (used in identification)
    field_no = query.record().indexOf(Car::getStatNames().at(CAR_TRACK_NAME));
    temp_car->setTrack(query.value(field_no).toString());

    //setting stats
    for (unsigned int i = 0; i < 3; ++i) {
        field_no = query.record().indexOf(Car::getStatNames().at(i+1));
        temp_car->setStat((CarStatsSlots)i, query.value(field_no).toInt());
    }

    // setting lvls
    for (unsigned int i = 0; i < 11; ++i) {
        field_no = query.record().indexOf(Car::getStatNames().at(i+4));
        temp_car->setLvl((CarSlots)i, query.value(field_no).toInt());
    }

    // setting wears
    for (unsigned int i = 0; i < 11; ++i) {
        field_no = query.record().indexOf(Car::getWearNames().at(i));
        temp_car->setWear((CarSlots)i, query.value(field_no).toInt());
    }

    return temp_car;

}

std::shared_ptr<Driver> transform2Driver(const QSqlQuery & query) {
    int field_no = 0;
    std::shared_ptr<Driver> temp_driver = std::shared_ptr<Driver>(new Driver);

    // track name
    field_no = query.record().indexOf(Driver::getNames().at(0));
    temp_driver->setMiscValue(DRIVER_TRACK_NAME, query.value(field_no));

    // stats
    for (unsigned int i = 1; i < Driver::getNames().size(); ++i) {
        field_no = query.record().indexOf(Driver::getNames().at(i));
        temp_driver->setStatValue((DriverStatSlots) (i-1), query.value(field_no));
    }

    return temp_driver;
}

std::shared_ptr<Practice> transform2Practice(const QSqlQuery & query) {
    int field_no = 0;
    std::shared_ptr<Practice> temp_practice = std::shared_ptr<Practice>(new Practice);

    std::shared_ptr<Track> temp_track = transform2Track(query);
    temp_practice->setTrack(temp_track);

    std::shared_ptr<Car> temp_car = transform2Car(query);
    temp_practice->setCar(temp_car);

    std::shared_ptr<Driver> temp_driver = transform2Driver(query);
    temp_practice->setDriver(temp_driver);

    for (unsigned int i = 0; i < temp_practice->getColumnNames().size(); ++i) {
        field_no = query.record().indexOf(temp_practice->getColumnNames().at(i));
        temp_practice->setValue((PracticeSlots)i, query.value(field_no));
    }

    return temp_practice;
}

std::shared_ptr<Stint> transform2Stint(const QSqlQuery & query) {
    int field_no = 0;
    std::shared_ptr<Stint> temp_stint = std::shared_ptr<Stint>(new Stint);

    std::shared_ptr<Track> temp_track;
}

DatabaseHandler::DatabaseHandler():
    db_(), tracks_(), practice_data_(), stint_data_()
{

}

bool DatabaseHandler::beginConnection() {
    QSettings settings(General::ProgramName, General::CompanyName);

    QString type = settings.value(Settings::DatabaseTypeText, QVariant("QPSQL")).toString();
    QString name = settings.value(Settings::DatabaseNameText, QVariant("")).toString();
    QString username = settings.value(Settings::DatabaseUserNameText, QVariant("")).toString();
    QString password = settings.value(Settings::DatabasePasswordText, QVariant("")).toString();

    if ( type.size() == 0 || name.size() == 0 || username.size() == 0) return false;

    if (db_.connectionNames().size() == 0) db_ = QSqlDatabase::addDatabase(type);

    if (db_.databaseName() != name) db_.setDatabaseName(name);

    if (db_.userName() != username) db_.setUserName(username);

    if(db_.password() != password)  db_.setPassword(password);

    return db_.open();
}

void DatabaseHandler::endConnection() {
    db_.close();
}

const std::vector< std::shared_ptr<Track> > &DatabaseHandler::getTracks() {
    if (tracks_.size() > 0) return tracks_;

    std::vector< std::shared_ptr<Track> > tracks;

    if (!beginConnection()) {
        return tracks_;
    }

    // selecting all tracks
    QSqlQuery query = db_.exec(getTracksQuery());

     while (query.next()) {
        tracks.push_back(transform2Track(query));
     }

     endConnection();

     tracks_ = tracks;

     return tracks_;
}

QStringList DatabaseHandler::getTrackNames() {
    QStringList qsl;

    if (getTracks().size() > 0) {
        for(unsigned int i = 0; i < getTracks().size(); ++i) {
            qsl.append(getTracks().at(i)->getName());
        }
        return qsl;
    }

    while (getTracks().size() == 0)

     for(unsigned int i = 0; i < getTracks().size(); ++i) {
         qsl.append(getTracks().at(i)->getName());
     }

     return qsl;
}

const std::vector<std::shared_ptr<Practice> > &DatabaseHandler::getPracticeData()
{
    if (practice_data_.size() > 0) return practice_data_;

    std::vector< std::shared_ptr<Practice> > raw_practice_data;

    if (!beginConnection()) {
        practice_data_ = raw_practice_data;
        return practice_data_;
    }

    QSqlQuery query = db_.exec(getPracticeDataQuery());

    while (query.next()) {
       query.next();
       raw_practice_data.push_back(transform2Practice(query));
    }

     endConnection();

     practice_data_ = raw_practice_data;

     return practice_data_;
}

const std::vector<std::shared_ptr<Stint> > &DatabaseHandler::getStintData()
{
    if ( stint_data_.size() > 0 ) return stint_data_;


}
