// Written by Adrian Musceac YO8RZZ , started October 2013.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef STATION_H
#define STATION_H

#include <QString>

class Station
{
public:
    Station();
    int id;
    QString callsign;
    QString radio_id;
    QString ip;
    QString hostname;
    int in_call;
    int channel_id;
    int called_by;     // calling station id
    int call_time;     // time of call
    int repeater;
    int local;
    int active;
    int waiting;
    bool mute;
    bool deaf;
};

#endif // STATION_H
