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

// "Hello from thread!" demo program

f(i){ std.io.print(i) }

entry
{
  std.concurrency.thread t1(f,1)
  std.concurrency.thread t2(f,2)
  
  std.concurrency.thread.join_all()
}
