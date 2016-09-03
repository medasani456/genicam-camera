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

#ifndef FFMPEG_DECODER_H
#define FFMPEG_DECODER_H

#include <QImage>
#include <QSize>
//#include "../api/qarvdecoder.h"
#include <qarvdecoder.h>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libswscale/swscale.h>
}

namespace QArv {

/*
 * This decoder works by first decoding into RGB48 using libswscale, and then
 * copying data into the appropriate container.
 */
class SwScaleDecoder : public QArvDecoder {
public:
  SwScaleDecoder(QSize size, enum PixelFormat inputPixfmt,
                 ArvPixelFormat arvPixFmt,
                 int swsFlags = SWS_FAST_BILINEAR | SWS_BITEXACT);
  virtual ~SwScaleDecoder();
  void decode(QByteArray frame);
  const cv::Mat getCvImage();
  int cvType();
  ArvPixelFormat pixelFormat();
  QByteArray decoderSpecification();
  enum PixelFormat swscalePixelFormat();

private:
  bool OK;
  QSize size;
  struct SwsContext *ctx;
  uint8_t *image_pointers[4];
  int image_strides[4];
  uint8_t bufferBytesPerPixel;
  int cvMatType;
  enum PixelFormat inputPixfmt, outputPixFmt;
  struct AVPicture srcInfo;
  ArvPixelFormat arvPixelFormat;
  int flags;
};
}

#endif
