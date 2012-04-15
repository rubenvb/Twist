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
 * Main program entry
 */

#include <iostream>

#include "commandline.h"
#include "error.h"
#include "module.h"
#include "source_parser.h"
#include "settings.h"

int main(int argc, char* argv[])
try
{
  std::cout << "Twisted C compiler, version 0.0.1.\n";
  
  // assume plain app by default
  settings settings(settings::app);
  process_commandline(settings, argc, argv);
  
  module m(settings.module_name);
  source_parser p(settings);
  p.load_module();

}
catch(error& e)
{
  std::cout << e.what();
}
catch(...)
{
  std::cout << "Something bad happened. Please submit a bug report.\n";
}