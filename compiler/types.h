/**
 * CTwist compiler "twist"
 *
 * Written in 2012 by Ruben Van Boxem <vanboxem.ruben@gmail.com>
 *
 * To the extent possible under law, the author(s) have dedicated all copyright and related
 * and neighboring rights to this software to the public domain worldwide. This software is
 * distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along with this software.
 * If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 **/

/*
 * Types:
 *  - standard library includes
 *  - typedefs and type adaptors
 */

#ifndef TWISTED_TYPES
#define TWISTED_TYPES

#include <map>
#include <set>
#include <string>
#include <vector>

// C++ types
typedef std::vector<std::string> string_vector;

// Ctwist compiler specific types
class type;
typedef std::map<std::string, type> type_map;
typedef std::pair<std::string, time_t> file;
typedef std::set<file> file_set;

#endif
