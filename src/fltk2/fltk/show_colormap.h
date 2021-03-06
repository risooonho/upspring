// "$Id: show_colormap.h 5197 2006-06-14 07:43:46Z spitzak $"
/*! \file
Pretty much obsolete popup color chooser that lets you pick one
of the 256 indexed colors in fltk.
*/
// Copyright 1998-2006 by Bill Spitzak and others.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "fltk-bugs@fltk.org".
//

#ifndef fltk_show_colormap_h
#define fltk_show_colormap_h

#include "FL_API.h"
#include "Color.h"

namespace fltk {
FL_API Color show_colormap(Color oldcol);
}

#endif

//
// End of "$Id: show_colormap.h 5197 2006-06-14 07:43:46Z spitzak $".
//
