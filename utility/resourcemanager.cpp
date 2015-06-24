#include "resourcemanager.h"


ResourceManager::ResourceManager():
    dbhandler_(new DatabaseHandler),
    tracks_(new std::map<QString, std::shared_ptr<Track> >),
    tracks_string_list_(new QStringList)
{

}

void ResourceManager::fetchTracks()
{
    tracks_.reset();
    tracks_string_list_->clear();
    std::vector< std::shared_ptr<Track> > temp_tracks = dbhandler_->getTracks();

    for (unsigned int i = 0; i < temp_tracks.size(); ++i) {
        addTrack(temp_tracks.at(i));
    }
}

void ResourceManager::addTrack(std::shared_ptr<Track> track)
{
    tracks_->insert(std::pair<QString, std::shared_ptr<Track> >(track->getName(), track));
    tracks_string_list_->append(track->getName());
}

std::shared_ptr<Track> ResourceManager::getTrack(const QString &track)
{
    if (tracks_->size() == 0) fetchTracks();

    return tracks_->at(track);
}

QStringList *ResourceManager::getTrackQStringList()
{
    if (tracks_string_list_->size() == 0) fetchTracks();

    return tracks_string_list_;
}
