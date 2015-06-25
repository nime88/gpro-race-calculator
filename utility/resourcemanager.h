#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <memory>
#include <map>

#include <QStringList>
#include <QString>

#include <databasehandler.h>

// yo dawg this is singleton class (for general information)

class ResourceManager
{
private:
     explicit ResourceManager();

     ~ResourceManager();

     std::shared_ptr<DatabaseHandler> dbhandler_;
     std::shared_ptr< std::map<QString, std::shared_ptr<Track> > > tracks_;
     QStringList* tracks_string_list_;

     // gets tracks from the database
     void fetchTracks();

     // disallowing copying (really don't want copies hanging around)
     ResourceManager(ResourceManager const&) = delete;
     void operator=(ResourceManager const&) = delete;
public:
    static ResourceManager& getInstance() {
        static ResourceManager instance;

        return instance;
    }

    void addTrack(std::shared_ptr<Track> track);

    std::shared_ptr<Track> getTrack(const QString& track);
    QStringList* getTrackQStringList();

    // clears all the data (should be called when data needs to get rid of
    // before destructor comes into play
    void clear();


};

#endif // RESOURCEMANAGER_H
