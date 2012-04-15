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
 * Program-wide settings
 */

#ifndef TWISTED_SETTINGS
#define TWISTED_SETTINGS

#include "enums.h"
#include "types.h"

struct settings
{
  enum building
  {
    app,
    static_library,
    dynamic_library
  } building; // type of output file
  const std::string module_name;

  settings(enum building b)
  : building(b) {}

  bool add_file(const file& file)
  {
    filetype type = determine_filetype(file.first); // throws on error
    return m_files[type].insert(file).second;
  }
  const file& first_file() const
  {
    const auto it = m_files.find(filetype::source);
    if(it == m_files.end())
      throw error("No source files in file list.");
    else
      return *(it->second.begin());
  }
  
private:
  std::map<filetype, file_set> m_files;
};

#endif
