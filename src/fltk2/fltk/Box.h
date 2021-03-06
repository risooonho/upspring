//
// "$Id: Box.h 5571 2006-12-30 08:20:02Z spitzak $"
//
// Define your own values for box() on a widget by making one of these.
//
// Copyright 2002 by Bill Spitzak and others.
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

#ifndef fltk_Box_h
#define fltk_Box_h

#include "Color.h"
#include "Flags.h"
#include "Symbol.h"

namespace fltk {

typedef Symbol Box;

class FL_API FrameBox : public Box {
protected:
  const char* data_;
  const Box* down_;
  int dx_, dy_, dw_, dh_;
public:
  const char* data() const {return data_;}
  void data(const char* d) {data_ = d;}
  void _draw(const Rectangle&) const;
  void inset(Rectangle&) const;
  /*! dx,dy,dw,dh lets you peek at constants rather than use inset(). */
  int dx() const {return dx_;}
  int dy() const {return dy_;}
  int dw() const {return dw_;}
  int dh() const {return dh_;}
  bool fills_rectangle() const;
  bool is_frame() const;
  FrameBox(const char* name, int dx,int dy,int dw,int dh, const char* pattern, const Box* down=0)
    : Box(name),data_(pattern),down_(down),dx_(dx),dy_(dy),dw_(dw),dh_(dh) {}
};

class FL_API FlatBox : public Box {
public:
  void _draw(const Rectangle&) const;
  bool fills_rectangle() const;
  bool is_frame() const;
  FlatBox(const char* n);
};

class FL_API HighlightBox : public FlatBox {
  const Box* down_;
public:
  void _draw(const Rectangle&) const;
  void inset(Rectangle&) const;
  bool fills_rectangle() const;
  bool is_frame() const;
  HighlightBox(const char* n, const Box* d);
};

}

#endif

//
// End of "$Id: Box.h 5571 2006-12-30 08:20:02Z spitzak $".
//
