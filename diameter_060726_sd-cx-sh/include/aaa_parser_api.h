/* BEGIN_COPYRIGHT                                                        */
/*                                                                        */
/* Open Diameter: Open-source software for the Diameter and               */
/*                Diameter related protocols                              */
/*                                                                        */
/* Copyright (C) 2002-2006 Open Diameter Project                          */
/*                                                                        */
/* This library is free software; you can redistribute it and/or modify   */
/* it under the terms of the GNU Lesser General Public License as         */
/* published by the Free Software Foundation; either version 2.1 of the   */
/* License, or (at your option) any later version.                        */
/*                                                                        */
/* This library is distributed in the hope that it will be useful,        */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of         */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      */
/* Lesser General Public License for more details.                        */
/*                                                                        */
/* You should have received a copy of the GNU Lesser General Public       */
/* License along with this library; if not, write to the Free Software    */
/* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307    */
/* USA.                                                                   */
/*                                                                        */
/* In addition, when you copy and redistribute some or the entire part of */
/* the source code of this software with or without modification, you     */
/* MUST include this copyright notice in each copy.                       */
/*                                                                        */
/* If you make any changes that are appeared to be useful, please send    */
/* sources that include the changed part to                               */
/* diameter-developers@lists.sourceforge.net so that we can reflect your  */
/* changes to one unified version of this software.                       */
/*                                                                        */
/* END_COPYRIGHT                                                          */

#ifndef __AAA_PARSER_API_H__
#define __AAA_PARSER_API_H__

// Local dependencies
//#include "aaa_dictionary_api.h"

// Standard C++ dependencies
#include <string>
#include <list>

// ACE dependencies
#include <ace/Basic_Types.h>

// Local dependencies
#include "framework.h"
#include "aaa_parser_defs.h"



// Boost dependencies
#include <boost/function/function0.hpp>
#include <boost/function/function1.hpp>

/*!
 *==================================================
 * This section defines the generic parsing template
 *==================================================
 */

/*! \brief Parser Message Parser Definition
 *
 * AAAParser is a template class for generic parser.
 */
template <class RAWDATA,
          class APPDATA,
			 class BYTEARRAY>

class AAAParser
{
    public:
        /*!
        * constructor
        */
        AAAParser() {
        }

        /*!
        * destructor
        */
        virtual ~AAAParser() {
        }

        /*!
        * Parse raw data and translate it into application level data.
        */
        virtual void parseRawToApp();

        /*!
        * Parse application level data and translate it into raw data.
        */
        virtual void parseAppToRaw();

        /*!
        * Set raw data to the parser.
        *
        * \param data Parser Data
        */
        void setRawData(RAWDATA data) 
		  {
            rawData = data;
        }

        /*!
        * Set application level data to the parser.
        *
        * \param data Parser Data
        */
        void setAppData(APPDATA data) 
		  {
            appData = data;
        }

        /*!
        * Set dictionary data to the parser.
        *
        * \param data Dictionary data
        */
        void setByteArrayData( BYTEARRAY data ) 
		  {
            byteArrayData = data;
        }

        /*!
        * Get raw data from the parser.
        */
        RAWDATA getRawData() 
		  {
            return rawData;
        }

        /*! This template is used for obtaining raw data casted to a
        * specific type.
        */
        template <class T> void getRawData(T*& data) 
		  {
            data = (T*)rawData;
        }

        /*!
        * Get application level data from the parser.
        */
        APPDATA getAppData() 
		  {
            return appData;
        }

        /*! This template is used for obtaining application data
        *  casted to a * specific type.
        */
        template <class T> void getAppData(T*& data) 
		  {
            data = (T*)appData;
        }

        /*!
        * Get dictionary data from the parser.
        */
        BYTEARRAY  getByteArrayData() 
		  {
            return byteArrayData ; 
        }

        /*! This template is used for obtaining dictionary data
        *  casted to a * specific type.
        */
//        template <class T> void getDictData(T*& data) {
//            data = (T*)dictData;
//        }

    private:
        RAWDATA      rawData;   /**< Raw data  */
        APPDATA      appData;   /**< Application data translated from/to raw data */
        BYTEARRAY    byteArrayData;  /**< Dictionary data */
};

#endif // __AAA_PARSER_API_H__
