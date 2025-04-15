#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
        Span(const Span& other);
        Span& operator=(const Span& other);

    public:
        Span(unsigned int N);
        ~Span();

        void addNumber(int number);
        
        template <typename InputIterator>
        void addRange(InputIterator first, InputIterator last)
        {
            unsigned int remaining = _maxSize - _numbers.size();
            if (static_cast<unsigned int>(std::distance(first, last)) > remaining)
                throw std::overflow_error("Not enough space in Span");
            _numbers.insert(_numbers.end(), first, last);
        }
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

#endif