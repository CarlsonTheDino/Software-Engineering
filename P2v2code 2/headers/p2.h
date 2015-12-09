/*
 * p2.h
 * 2014 version - tasks re-ordered and generalised
 * now use Posn v2.1 with NMEA constructor
 *      Author:rbh
 */

#ifndef P2_H_
#define P2_H_
#include <string>
#include <list>
#include <pair>

#include "../headers/posn.h"

namespace P2
{
    namespace NMEA
    {
        //see specification for p2b()
        typedef std::pair<std::string, std::list<std::string>> P2Pair;
        
        /* p2a -better named CSisValid() or similar
         * takes a std::string, assumed to be an NMEA sentence
         * validates the checksum
         * 
         * checksum is a byte-wise XOR reduction
         * of the character codes of the raw sentence elements
         */
        bool p2a(const std::string & sentence);
        
        
        /* p2b - better named decompose()
         *
         * takes a (valid) sentence and splits it into component parts
         *
         * return type is a std::pair< , > with
         * first the sentence type including '$'
         * second std::list of the subsequent fields (comma seperated, commmas 
         * removed, check sum omitted)
         *
         */
        P2Pair p2b(const std::string & sentence);
        
        
        //forward declarations for compiler
        class foo;
        class bar;
        
        /* p2c - better named extractPosn()
         *
         * first of pair is NMEA sentence type which determines where
         * the position data is in the list (second of pair)
         *
         * assert only recognised sentence types are processed
         * return latitude 0.0 longitude 0.0 for ill-formed or un-recognised 
         * sentences
         * 
         * returns a P2::Posn as defined in posn.h
         */    
        P2::Posn p2c(P2Pair);
        
        
        /* p2d - better named routeFromNMEALog
         *
         * reads the file named as parameter
         * discards any blank lines
         * filters out any sentences that fail te check sum
         * generates & returns vector of Posn extracted from sentences
         *
         */
        std::vector<P2::Posn> p2d(const std::string & logFileName);
    }
    
} //namespace

#endif /* P2_H_ */
