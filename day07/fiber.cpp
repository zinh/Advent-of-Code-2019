#include <iostream>
#include <boost/fiber/all.hpp>

void
fn(int idx, int from, int to){
  for(int i = from; i < to; i++) {
    std::cout << idx << ' ' << i << std::endl;
    boost::this_fiber::yield();
  }
}

int
main(){
  std::cout << "main start: " << boost::this_fiber::get_id() << std::endl;
  boost::fibers::fiber f1(fn, 1, 5, 10);
  boost::fibers::fiber f2(fn, 2, 0, 5);
  f1.join();
  f2.join();
  return 0;
}
