/*
 * 11/14
 *
 * with NMEA constructor & angle converter
 */


/*
 * posn.cpp
 *
 * cut-down P2 version of gpxp.cpp
 *
 * elevations now metreas
 *  
 *      Author: rbh
 */

#ifndef POSN_CPP_
#define POSN_CPP_

#include <sstream>
#include <cassert>
#include <cmath>


#include "../headers/posn.h"

namespace P2
{
    bool implemented = true;
    
    Posn::Posn(const std::string & NMEAlatSt, char northing, const std::string & NMEAlonSt, char easting)
    {
        assert((northing=='N' || northing =='S') && (easting == 'E' || easting == 'W'));
        angle lat = convertFromNMEAangleString(NMEAlatSt);
        angle lon = convertFromNMEAangleString(NMEAlonSt);
        lat *= (northing=='N'? 1 : -1); //'S' means negative angle
        lon *= (easting=='E'? 1 : -1); //'W' means negative angle
        lat_ = lat;
        lon_ = lon;
        ele_ = 0;
    }
    
    angle Posn::convertFromNMEAangleString(const std::string & NMEAangleSt)
    {
        std::istringstream iss(NMEAangleSt);
        double tmp, degrees, minutes;
        angle result;
        iss >> tmp;
        assert(tmp>=0); // all NMEA angles are positive
        degrees = floor(tmp/100);
        minutes = tmp - 100*degrees;
        result = degrees + minutes / 60.0; // /60.0 converts minutes to decimal fractions of a degree
        return result;
    }
    
    Posn::Posn(const std::string & latSt, const std::string & lonSt,
               const std::string & eleSt)
    {
        std::string st = latSt;
        st += " ";
        st += lonSt;
        st += " ";
        st += eleSt;
        st += " ";
        std::istringstream iss(st);
        iss >> lat_ >> lon_ >> ele_;
    }
    
    Posn::Posn(angle lat, angle lon, angle ele /*= 0.0*/)
    {
        lat_ = lat;
        lon_ = lon;
        ele_ = ele;
    }
    
    metres Posn::distanceTo(const Posn & to) const
    {
        return (P2::distanceBetween(*this, to));
    }
    
    std::string Posn::toString(bool includeElevation) const
    {
        std::string st;
        std::ostringstream oss(st);
        oss << "lat=\"" << lat_ << "\" lon=\"" << lon_ << "\"";
        if (includeElevation)
            oss << " ele=\"" << ele_ << "\"";
        return (oss.str());
    }
    
    
    angle Posn::lat() const
    {
        return (lat_);
    }
    angle Posn::lon() const
    {
        return (lon_);
    }
    metres Posn::ele() const
    {
        return (ele_);
    }
    
    std::string Posn::eleAsString() const
    {
        std::string st;
        std::ostringstream oss(st);
        oss << ele_;
        return (oss.str());
    }
    
    
        //download from http://blog.julien.cayzac.name/2008/10/arc-and-distance-between-two-points-on.html
    
        /// @brief The usual PI/180 constant
    static const angle DEG_TO_RAD = 0.017453292519943295769236907684886;
        /// @brief Earth's quatratic mean radius for WGS-84
    static const angle EARTH_RADIUS_IN_METERS = 6372797.560856;
    
    /** @brief Computes the arc, in radian, between two WGS-84 positions.
     *
     * The result is equal to <code>Distance(from,to)/EARTH_RADIUS_IN_METERS</code>
     *    <code>= 2*asin(sqrt(h(d/EARTH_RADIUS_IN_METERS )))</code>
     *
     * where:<ul>
     *    <li>d is the distance in meters between 'from' and 'to' positions.</li>
     *    <li>h is the haversine function: <code>h(x)=sin(x/2)</code></li>
     * </ul>
     *
     * The haversine formula gives:
     *    <code>h(d/R) = h(from.lat-to.lat)+h(from.lon-to.lon)+cos(from.lat)*cos(to.lat)</code>
     *
     * @sa http://en.wikipedia.org/wiki/Law_of_haversines
     */
    angle ArcInRadians(const Posn& from, const Posn& to)
    {
        angle latitudeArc  = (from.lat() - to.lat()) * DEG_TO_RAD;
        angle longitudeArc = (from.lon() - to.lon()) * DEG_TO_RAD;
        angle latitudeH = sin(latitudeArc * 0.5);
        latitudeH *= latitudeH;
        angle lontitudeH = sin(longitudeArc * 0.5);
        lontitudeH *= lontitudeH;
        angle tmp = cos(from.lat()*DEG_TO_RAD) * cos(to.lat()*DEG_TO_RAD);
        return 2.0 * asin(sqrt(latitudeH + tmp*lontitudeH));
    }
    
    /** @brief Computes the distance, in meters, between two WGS-84 positions.
     *
     * The result is equal to <code>EARTH_RADIUS_IN_METERS*ArcInRadians(from,to)</code>
     *
     * @sa ArcInRadians
     */
    metres distanceBetween(const Posn& from, const Posn& to)
    {
        return EARTH_RADIUS_IN_METERS*ArcInRadians(from, to);
    }
    
} // namespaceP2


#endif /* POSN_CPP_ */
