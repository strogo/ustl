// This file is part of the ustl library, an STL implementation.
// Copyright (C) 2003 by Mike Sharov <msharov@talentg.com>
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
// License along with this library; if not, write to the 
// Free Software Foundation, Inc., 59 Temple Place - Suite 330, 
// Boston, MA  02111-1307  USA.
//
// ufacets.h
//

#ifndef UFACETS_H_265F2577462E4C3C468F674E7F4E11E1
#define UFACETS_H_265F2577462E4C3C468F674E7F4E11E1

#include "ulocale.h"

namespace ustl {

class ctype_base {
public:
    typedef int mask;
    enum mask_bits {
	upper	= (1 << 0),
	lower	= (1 << 1),
	alpha	= (1 << 2),
	digit	= (1 << 3),
	xdigit	= (1 << 4),
	space	= (1 << 5),
	print	= (1 << 6),
	graph	= (1 << 7),
	cntrl	= (1 << 8),
	punct	= (1 << 9),
	alnum	= (1 << 10)
    };
};

class ctype : public locale::facet, public ctype_base {
public:
    static const locale::category c_Category = locale::ctype;
public:
			ctype (void);
    bool		is (mask m, wchar_t c) const;
    const char*		scan_is (mask m, const char* first, const char* last) const;
    const char*		scan_not (mask m, const char* first, const char* last) const;
    wchar_t		toupper (wchar_t c) const;
    const char*		toupper (char* first, const char* last) const;
    wchar_t		tolower (wchar_t c) const;
    const char*		tolower (char* first, const char* last) const;
    inline wchar_t	widen (char c) const	{ return (c); }
    const char*		widen (const char* first, const char* last, wchar_t* result) const;
    char		narrow (wchar_t c, char dfault) const;
    const wchar_t*	narrow (const wchar_t* first, const wchar_t* last, char dfault, char* result) const;
};

class numpunct : public locale::facet {
public:
    wchar_t		decimal_point (void) const;
    wchar_t		thousands_sep (void) const;
    string		grouping (void) const;
    string		truename (void) const;
    string		falsename (void) const;
};

class num_get : public locale::facet {
public:
    static const category c_Category = locale::numeric;
    typedef uint32_t	iosflags_t;
public:
			num_get (void);
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, bool& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, short& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, int& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, long& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, u_short& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, u_int& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, u_long& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, float& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, double& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, long double& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, void*& v) const;
#ifdef __GNUC__
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, long long& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, unsigned long long& v) const;
#endif
};

class num_put : public locale::facet {
public:
    typedef uint32_t	iosflags_t;
public:
			num_put (void);
    iterator		put (iterator first, iterator last, iosflags_t flags, bool v, wchar_t filler = ' ') const;
    iterator		put (iterator first, iterator last, iosflags_t flags, long v, wchar_t filler = ' ') const;
    iterator		put (iterator first, iterator last, iosflags_t flags, u_long v, wchar_t filler = ' ') const;
    iterator		put (iterator first, iterator last, iosflags_t flags, float v, wchar_t filler = ' ') const;
    iterator		put (iterator first, iterator last, iosflags_t flags, double v, wchar_t filler = ' ') const;
    iterator		put (iterator first, iterator last, iosflags_t flags, long double v, wchar_t filler = ' ') const;
    iterator		put (iterator first, iterator last, iosflags_t flags, void* v, wchar_t filler = ' ') const;
#ifdef __GNUC__
    iterator		put (iterator first, iterator last, iosflags_t flags, long long v, wchar_t filler = ' ') const;
    iterator		put (iterator first, iterator last, iosflags_t flags, unsigned long long v, wchar_t filler = ' ') const;
#endif
};

class collate : public locale::facet {
public:
			collate (void);
    int			compare (const char* f1, const char* l1, const char* f2, const char* l2) const;
    string		transform (const char* f1, const char* l1) const;
    inline hashvalue_t	hash (const char* f1, const char* l1) const { return (char_hash (f1, l1)); }
};

class time_base {
public:
    enum dateorder { no_order, dmy, mdy, ymd, ydm };
};

struct tm;

class time_get : public locale::facet, public time_base {
public:
			time_get (void);
    dateorder		date_order (void) const;
    const_iterator	get_time (const_iterator first, const_iterator last, iosflags_t flags, tm* v) const;
    const_iterator	get_date (const_iterator first, const_iterator last, iosflags_t flags, tm* v) const;
    const_iterator	get_weekday (const_iterator first, const_iterator last, iosflags_t flags, tm* v) const;
    const_iterator	get_monthname (const_iterator first, const_iterator last, iosflags_t flags, tm* v) const;
    const_iterator	get_year (const_iterator first, const_iterator last, iosflags_t flags, tm* v) const;
};

class time_put : public locale::facet, public time_base {
public:
			time_put (void);
    iterator		put (iterator first, iterator last, iosflags_t flags, const tm* v, wchar_t filler = ' ') const;
};

class money_base {
public:
    enum part { none, space, symbol, sign, value };
    struct pattern { char field [4]; };
};

class money_punct : public locale::facet, public money_base {
public:
			money_punct (void);
    wchar_t		decimal_point (void) const;
    wchar_t		thousands_sep (void) const;
    string		grouping (void) const;
    string		curr_symbol (void) const;
    string		positive_sign (void) const;
    string		negative_sign (void) const;
    int			frac_digits (void) const;
    pattern		pos_format (void) const;
    pattern		neg_format (void) const;
};

class money_get : public locale::facet, public money_base {
public:
			money_get (void);
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, long double& v) const;
    const_iterator	get (const_iterator first, const_iterator last, iosflags_t flags, string& v) const;
};

class money_put : public locale::facet, public money_base {
public:
			money_put (void);
    iterator		put (iterator first, iterator last, iosflags_t flags, long double v, wchar_t filler = ' ') const;
    iterator		put (iterator first, iterator last, iosflags_t flags, const string& v, wchar_t filler = ' ') const;
};

class messages : public locale::facet {
public:
    typedef int		catalog;
public:
			messages (void);
    catalog		open (const string& name, const locale& loc);
    string		get (catalog c, int s, int msgid) const;
    void		close (catalog c);
};

#define CTYPE_IS_FUNC(what)					\
    inline bool is##what (wchar_t c, const locale& loc)		\
    { return (use_facet<ctype>(loc).is (ctype_base::what, c)); }

CTYPE_IS_FUNC(space)
CTYPE_IS_FUNC(print)
CTYPE_IS_FUNC(cntrl)
CTYPE_IS_FUNC(upper)
CTYPE_IS_FUNC(lower)
CTYPE_IS_FUNC(alpha)
CTYPE_IS_FUNC(digit)
CTYPE_IS_FUNC(xdigit)
CTYPE_IS_FUNC(alnum)
CTYPE_IS_FUNC(graph)
CTYPE_IS_FUNC(punct)

#undef CTYPE_IS_FUNC

inline wchar_t toupper (wchar_t c, const locale& loc)
{ return (use_facet<ctype>(loc).toupper (c)); }

inline wchar_t tolower (wchar_t c, const locale& loc)
{ return (use_facet<ctype>(loc).tolower (c)); }

}; // namespace ustl

#endif
