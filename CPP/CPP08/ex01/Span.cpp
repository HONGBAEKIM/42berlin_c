#include "Span.hpp"

Span::Span(int nb) : n(nb)
{
}

Span::~Span()
{
}

Span::Span(Span const &s) : n(s.n), vec(s.vec)
{
}

Span &Span::operator=(Span const &rhs)
{
    if (n <= rhs.n)
        throw (OutOfRangeException());
    if (this != &rhs)
        vec = rhs.vec;
    return (*this);
}

void Span::addNumber(int nb)
{
    //current number of elements < maximum size Span object
    if (vec.size() < n)
    {
        //Adds the value 'nb' to the end of the 'vec' vector
        vec.push_back(nb);
    }
    else
        throw(OutOfRangeException());
}

void Span::addRange(std::vector<int> v)
{
    //current size of 'vec' + size of the input vector 'v' > maximum size 'n'
    if (vec.size() + v.size() > n)
        throw(OutOfRangeException());
    //'v' are inserted atr the end of the vector 'vec'
    vec.insert(vec.end(), v.begin(), v.end());
}

unsigned int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw(NoSpanException());
    
    // Initialize mini to the maximum value representable by an unsigned int
    unsigned int mini = static_cast<unsigned int>(std::numeric_limits<int>::max());

    // Create a copy of vec and sort it
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());

    // Iterate through the sorted vector to find the shortest span
    for (unsigned int i = 0; i < tmp.size() - 1; i++)
        mini = std::min(mini, static_cast<unsigned int>(tmp[i + 1] - tmp[i]));
    return (mini);
}

unsigned int Span::longestSpan()
{
    if (vec.size() < 2)
        throw(NoSpanException());

    //reasons to use int instead of unsigned int
    //1.Enpty Vector (0 Elements)
    //There is no '0' in unsigned int

    //2.Single Element Vector (1 Element)
    //if the vector has only one element,
    //the difference between the maxi and mini is zero.
    //if 'int' is used, this difference can be negative, zero, or positive.
    
    //2.Handling negative valuse

    int mini = *std::min_element(vec.begin(), vec.end());
    int maxi = *std::max_element(vec.begin(), vec.end());

    return (static_cast<unsigned int>(maxi - mini));
}

Span::Span() : n(0)
{

}
