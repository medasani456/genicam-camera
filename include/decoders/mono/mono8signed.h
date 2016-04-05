/*
 * QArv, a Qt interface to aravis.
 * Copyright (C) 2012-2014 Jure Varlec <jure.varlec@ad-vega.si>
 * Andrej Lajovic <andrej.lajovic@ad-vega.si>
 *
 * This program is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "include/decoders/monounpacked.h"
extern "C" {
  #include <arvenums.h>
}

namespace QArv {

class Mono8SignedFormat : public QObject, public QArvPixelFormat {
	Q_OBJECT
	Q_INTERFACES(QArvPixelFormat)
	public:
		ArvPixelFormat pixelFormat() { return ARV_PIXEL_FORMAT_MONO_8_SIGNED; }
		QArvDecoder* makeDecoder(QSize size) { 
			return new MonoUnpackedDecoder<int8_t, 8, ARV_PIXEL_FORMAT_MONO_8_SIGNED>(size); 
		}
};

}