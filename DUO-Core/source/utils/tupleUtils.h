#pragma once

#include <tuple>
#include <type_traits>

namespace DUO
{

    template <int N, typename... T> using NthTypeOf = typename std::tuple_element<N, std::tuple<T...>>::type;

}