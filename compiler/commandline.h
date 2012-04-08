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

// Commandline processing

#ifndef TWISTED_COMMANDLINE
#define TWISTED_COMMANDLINE

#include "settings.h"

void
#ifdef _WIN32
process_commandline(settings s, int, char*[])
#else
process_commandline(int argc, char* argv[])
#endif
{
  //FIXME assuming we're building a final application
  
   
}

#endif