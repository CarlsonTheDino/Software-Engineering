/*
 * posn.h - p2 version
 *
 *  cut down from gpxp.h v2.1 (11/2014)
 *      Author: rbh
 */

/* rbh 13/1/14
 * Posn v2.1 added (has NMEA c'tor from 2013/14 P2)
 *
 */

#ifndef POSN_H_
#define POSN_H_
#include <string>

namespace P2
{
    
    typedef double angle;
    typedef unsigned seconds;
    typedef double metres;
    typedef double speed;
    
    
    class Posn
    {
        //v2.1
    public:
        Posn(const std::string & latSt, const std::string & lonSt,
             const std::string & eleSt = "0");
        Posn(angle lat, angle lon, angle ele = 0.0);
        Posn(const std::string & NMEAlatSt, char northing,
             const std::string & NMEAlonSt, char easting);
        metres distanceTo(const Posn &) const;
        std::string toString(bool includeElevation = true) const;
        angle lat() const;
        angle lon() const;
        angle ele() const;
        std::string eleAsString() const;
        
        bool isSamePlaceAs(const Posn &, const unsigned & maxSeparation) const;
        
    private:
        angle lat_;
        angle lon_;
        metres ele_;
        Posn()
        {
        }
        ; //default c'tor not available
        angle convertFromNMEAangleString(const std::string &);
    };

    metres distanceBetween(const Posn &, const Posn &);
    
    angle ArcInRadians( const Posn &, const Posn & );
    
    
} // namespace P2


#endif /* POSN_H_ */

