/*
 * This file is part of the Camera Streaming Daemon
 *
 * Copyright (C) 2017  Intel Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <ostream>

#include "stream.h"

std::ostream &operator<<(std::ostream &os, const Stream::FrameSize &fs)
{
    return os << fs.width << "x" << fs.height;
}

std::ostream &operator<<(std::ostream &os, const Stream::PixelFormat &pf)
{
    os << (char)(pf.pixel_format & 0xFF);
    os << (char)(((pf.pixel_format) & 0xFF00) >> 8);
    os << (char)(((pf.pixel_format) & 0xFF0000) >> 16);
    os << (char)(((pf.pixel_format) & 0xFF000000) >> 24);
    os << "(";
    for (unsigned int i = 0; i < pf.frame_sizes.size(); i++) {
        if (i > 0)
            os << ",";
        os << pf.frame_sizes[i];
    }
    os << ")";
    return os;
}
