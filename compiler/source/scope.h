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
 * All elements contained in a named scope, including 
 */

#include <map>

class scope
{
public:
  scope( const std::string& name ) : m_name(name) {}

private:
  const std::string m_name;
  
  std::map<string,
};
