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
 * Error:
 *  various errors that can occur in the compilation process
 */

#ifndef TWISTED_ERROR
#define TWISTED_ERROR

#include <string>

#include "utility.h"

class error
{
public:
  error(const std::string& message) : m_message(message) {}
  
  const std::string& what() { return m_message; }
  
private:
  std::string m_message;
};

class commandline_error : public error
{
public:
  commandline_error(const std::string& message)
  : error("Commanline error: " + message) {}
};

class syntax_error : public error
{
public:
  syntax_error(const std::string& message, const std::string& filename,
               const std::size_t line_number, const std::size_t column_number)
  : error("Syntax error in " + filename + " on line " + to_string(line_number)
          + ", column " + to_string(column_number) + ":\n\t"
          + message ) {}
};

#endif
