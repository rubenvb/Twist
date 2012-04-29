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
 * Class that puts all the pieces together
 */

class module;
class settings;

class builder
{
public:
  builder(const settings& settings, module& module)
  : m_settings(settings), m_module(module)
  {}
  
  void heavy_lifting()
  {
  }
  
private:
  const settings& m_settings;
  module& m_module;
};
