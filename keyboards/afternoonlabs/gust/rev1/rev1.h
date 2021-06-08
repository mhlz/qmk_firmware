/* Copyright 2021 eithanshavit
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "gust.h"

#include "quantum.h"

#define LAYOUT( \
    M00, M01, M02, \
    M10, M11, M12,  \
    M20, M21, M22  \
) \
{ \
    { M00, M01, M02 }, \
    { M10, M11, M12 }, \
    { M20, M21, M22 }  \
}
