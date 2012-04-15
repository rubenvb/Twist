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
 * Commandline processing
 */

#ifndef TWISTED_COMMANDLINE
#define TWISTED_COMMANDLINE

#include "error.h"
#include "platform.h"
#include "settings.h"
#include "types.h"

#include <algorithm>

// Forward declarations
void add_file(settings&, const std::string&);

// Implementations
void process_commandline(settings& settings, int argc, char* argv[])
{
  const string_vector arguments(argv+1, argv+argc);

  std::cout << "Arguments:\n";
  std::for_each(arguments.begin(), arguments.end(), 
                [](const std::string& arg)
                { std::cout << "\t" << arg << "\n"; } );

  for(auto arg_it = arguments.begin(); arg_it != arguments.end(); ++arg_it)
  {
    const std::string& argument = *arg_it;
    const size_t index = argument.find_first_not_of("-");
    if(index == 0)
    { // Filename or second part of previous argument
      if(argument.find_first_of("*?") != std::string::npos)
        throw commandline_error("Wildcards are not supported yet.");
      file file;
      if(make_file(argument, file))
        settings.add_file(file);
      else
        throw commandline_error(argument + " is not a valid filename.");
    }
    else if(index == 1)
    {
    }
    else if(index == 2)
      throw commandline_error("Arguments beginning with \'--\' not yet implemented.");
    else
      throw commandline_error("Invalid argument: " + argument + ".");
  }
}

#endif
