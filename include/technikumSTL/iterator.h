#pragma once

#include <iostream>
#include "string.h"


namespace technikum
{
  class string;

  class iterator 
  {
		private:
			char* currentIndex;

		public:
            iterator();

            iterator(char* index);

			~iterator();

			char& operator*() const;

            char* operator->() const;

			iterator& operator++();

            iterator operator++(int);

			iterator& operator--();

			iterator operator--(int);

			bool operator==(const iterator& other) const;

			bool operator!=(const iterator& other) const;
  };
}  // namespace technikum