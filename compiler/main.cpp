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
#include "builder.h"
#include "error.h"
#include "module.h"
#include "parser.h"
#include "settings.h"

int main(int argc, char* argv[])
try
{
  std::cout << "Twisted C compiler, version 0.0.1.\n";
  
  // assume plain app by default
  settings s(settings::app, "default");
  process_commandline(s, argc, argv);

  module m(s.module_name);
  builder b(s,m);
  b.heavy_lifting();
}
catch(error& e)
{
  std::cout << e.what();
}
catch(...)
{
  std::cout << "Something bad happened. Please submit a bug report.\n";
}
