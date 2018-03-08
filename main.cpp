#include <boost/static_assert.hpp>
#include <iostream>

// Реализовать constexpr функцию bin_id - определения ближайшей большей степени двойки
namespace
{
  constexpr size_t bin_id(size_t x, size_t power = 0)
  {
    return ( x / 2 == 0 ? power : bin_id((x + 1) / 2 , power + 1) ) ;
  }

  BOOST_STATIC_ASSERT(bin_id(0) == 0);
  BOOST_STATIC_ASSERT(bin_id(1) == 0);
  BOOST_STATIC_ASSERT(bin_id(2) == 1);
  BOOST_STATIC_ASSERT(bin_id(4) == 2);
  BOOST_STATIC_ASSERT(bin_id(7) == 3);
  BOOST_STATIC_ASSERT(bin_id(8) == 3);
  BOOST_STATIC_ASSERT(bin_id(9) == 4);
  BOOST_STATIC_ASSERT(bin_id(1023) == 10);
  BOOST_STATIC_ASSERT(bin_id(1024) == 10);
  BOOST_STATIC_ASSERT(bin_id(1025) == 11);
  BOOST_STATIC_ASSERT(bin_id(1024*1024-33) == 20);
  BOOST_STATIC_ASSERT(bin_id(1024*1024) == 20);
  BOOST_STATIC_ASSERT(bin_id(1024*1024+33) == 21);
  BOOST_STATIC_ASSERT(bin_id(1024*1024*1024-127) == 30);
  BOOST_STATIC_ASSERT(bin_id(1024*1024*1024) == 30);
  BOOST_STATIC_ASSERT(bin_id(1024*1024*1024+127) == 31);
}

int main()
{
    size_t n;
    while(std::cin >> n)
        std::cout << bin_id(n) << std::endl;
    return 0;
}
