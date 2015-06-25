#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <vector>
#include <memory>

#include <QtSql>
#include <QStringList>

#include <core/track.h>
#include <core/practice.h>
#include <core/driver.h>
#include <core/car.h>
#include <core/stint.h>

class DatabaseHandler
{
private:
    //keeping track of the tracks if we have gotten it already
    //so no unnecessary db access is done
    std::vector< std::shared_ptr<Track> > tracks_;
    //keeping list of the practice data

    std::vector< std::shared_ptr<Practice> > practice_data_;

    std::vector< std::shared_ptr<Stint> > stint_data_;

    // disallowing copying
    DatabaseHandler(const DatabaseHandler&);
    DatabaseHandler operator=(const DatabaseHandler&);

public:
    DatabaseHandler();

    bool beginConnection();
    void endConnection();

    void setDatabase(QString dbtype, QString name, QString user_name, QString password);

    const std::vector< std::shared_ptr<Track> >& getTracks();
    QStringList getTrackNames();
    const std::vector< std::shared_ptr<Practice> >& getPracticeData();
    const std::vector< std::shared_ptr<Stint> >& getStintData();
};

#endif // DATABASEHANDLER_H
