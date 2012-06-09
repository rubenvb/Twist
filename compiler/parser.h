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
 * Lexer/Parser/"Module builder"
 */

#ifndef TWISTED_PARSER
#define TWISTED_PARSER

#include <fstream>

#include "module.h"
#include "settings.h"

class parser
{
private:
  module& m_module;
  const settings& m_settings;
  std::ifstream m_stream;
  const std::string m_filename;
  size_t m_line_number;

public:
  parser(const settings& settings, module& module)
  : m_settings(settings), m_module(module)
  {}

  bool all_files_parsed() const
  {
    // Find all file_set's and handle missing ones 
  }
  void load_modules()
  {
    const file_set& source_files = m_settings.files(filetype::source);
    for(auto sources_it = source_files.begin(); sources_it != source_files.end(); ++sources_it)
    {
      
    }
  }
  
private:
  bool next_token(std::string& token, const std::set<char>& special_characters)
  {
    token.clear();
    bool inside_quotes = false;
    char c;

    while(m_stream.get(c))
    {
      if(inside_quotes)
      {
        if('\"' == c)
          break; // end of token at end of quotes
        else if('\n' == c)
          throw syntax_error("Quoted strings cannot span several lines.",
                             m_filename, m_line_number);
        else if(token.empty() && std::isspace(c, m_stream.getloc()))
          throw syntax_error("Beginning quote must not be followed by a white"
                             "space.", m_filename, m_line_number);
        else
          goto add_char;
      }
      else
      {
        if(token.empty())
        {
          if('\n' == c)
            ++m_line_number;

          if(contains(special_characters, c))
          { // special characters are tokens of their own
            token.append( 1, c );
            return true;
          }
          else if('\"' == c)
          {
            inside_quotes = true;
            continue;
          }
          else if(std::isspace(c, m_stream.getloc()))
            continue;
          else if('#' == c)
          { // skip over comments
            std::string temp;
            std::getline(m_stream, temp);
            m_stream.putback('\n');
          }
          else if('\\' == c)
          {
            std::string temp;
            std::getline(m_stream, temp);
            ++m_line_number;
          }
          else
            goto add_char;
        }
        else if(std::isspace(c, m_stream.getloc())
                || contains(special_characters, c))
        { // special characters or whitespace seperate tokens
          m_stream.putback(c);
          break;
        }
        else if('\"' == c)
        {
          throw syntax_error("Beginning quotes must be preceded by a white"
                             "space or a special character.", m_filename,
                             m_line_number);
        }
        else
          add_char:
          token.append(1, c);
      }
    }
    return !token.empty();
  }
};

#endif