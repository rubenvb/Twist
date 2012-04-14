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
 * Various utility functions
 */

#ifndef TWISTED_UTILITY
#define TWISTED_UTILITY

#include <iosfwd>
#include <map>
#include <sstream>
#include <string>
#include <vector>

// conversion to string
template <typename T>
const std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}
template<>
inline const std::string to_string<bool>(const bool& b)
{
    return b?"true":"false";
}
// convert a newline \n character string to \\n
inline const std::string output_form(const char c)
{
    if('\n' == c)
        return std::string("\\n (newline)");
    else
        return std::string(1,c);
}
inline const std::string output_form(const std::string token)
{
    if("\n" == token)
        return std::string("\\n");
    else
        return token;
}
// map value helpers 
template<typename T>
const T & map_value(const std::vector<T> &map, const typename std::vector<T>::size_type key)
{
    return map[key];
}
// return mapped value
template<typename T, typename Y>
const T & map_value(const std::map<Y,T> &map, const Y &key)
{
    return (*map.find(key)).second;
}
// put mapped value in &value and return true if found, otherwise return false
template<typename T, typename Y>
bool map_value(const std::map<Y,T> &map, const Y &key, T &value)
{
    const typename std::map<Y,T>::iterator it = map.find(key);
    if(it != map.end())
    {
        value = (*it).second;
        return true;
    }
    else
        return false;
}

#endif
