//  Copyright Neil Groves 2009.
//  Copyright Eric Niebler 2013
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef RANGES_V3_ALGORITHM_HEAP_ALGORITHM_HPP
#define RANGES_V3_ALGORITHM_HEAP_ALGORITHM_HPP

#include <utility>
#include <algorithm>
#include <range/v3/begin_end.hpp>
#include <range/v3/concepts.hpp>
#include <range/v3/range_traits.hpp>
#include <range/v3/utility/bindable.hpp>

namespace ranges
{
    inline namespace v3
    {
        struct heap_pusher : bindable<heap_pusher>
        {
            /// \brief template function \c heap_pusher::operator()
            ///
            /// range-based version of the \c push_heap std algorithm
            ///
            /// \pre \c RandomAccessRange is a model of the RandomAccessRange concept
            /// \pre \c Compare is a model of the BinaryPredicate concept
            template<typename RandomAccessRange>
            static RandomAccessRange invoke(heap_pusher, RandomAccessRange && rng)
            {
                CONCEPT_ASSERT(ranges::RandomAccessRange<RandomAccessRange>());
                std::push_heap(ranges::begin(rng), ranges::end(rng));
                return detail::forward<RandomAccessRange>(rng);
            }

            /// \overload
            template<typename RandomAccessRange, typename Compare>
            static RandomAccessRange invoke(heap_pusher, RandomAccessRange && rng, Compare comp_pred)
            {
                CONCEPT_ASSERT(ranges::RandomAccessRange<RandomAccessRange>());
                std::push_heap(ranges::begin(rng), ranges::end(rng), detail::move(comp_pred));
                return detail::forward<RandomAccessRange>(rng);
            }
        };

        constexpr heap_pusher push_heap {};

        struct heap_popper : bindable<heap_popper>
        {
            /// \brief template function \c heap_popper::operator()
            ///
            /// range-based version of the \c pop_heap std algorithm
            ///
            /// \pre \c RandomAccessRange is a model of the RandomAccessRange concept
            /// \pre \c Compare is a model of the BinaryPredicate concept
            template<typename RandomAccessRange>
            static RandomAccessRange invoke(heap_popper, RandomAccessRange && rng)
            {
                CONCEPT_ASSERT(ranges::RandomAccessRange<RandomAccessRange>());
                std::pop_heap(ranges::begin(rng), ranges::end(rng));
                return detail::forward<RandomAccessRange>(rng);
            }

            /// \overload
            template<typename RandomAccessRange, typename Compare>
            static RandomAccessRange invoke(heap_popper, RandomAccessRange && rng, Compare comp_pred)
            {
                CONCEPT_ASSERT(ranges::RandomAccessRange<RandomAccessRange>());
                std::pop_heap(ranges::begin(rng), ranges::end(rng), detail::move(comp_pred));
                return detail::forward<RandomAccessRange>(rng);
            }
        };

        constexpr heap_popper pop_heap {};

        struct heap_maker : bindable<heap_maker>
        {
            /// \brief template function \c heap_maker::operator()
            ///
            /// range-based version of the \c make_heap std algorithm
            ///
            /// \pre \c RandomAccessRange is a model of the RandomAccessRange concept
            /// \pre \c Compare is a model of the BinaryPredicate concept
            template<typename RandomAccessRange>
            static RandomAccessRange invoke(heap_maker, RandomAccessRange && rng)
            {
                CONCEPT_ASSERT(ranges::RandomAccessRange<RandomAccessRange>());
                std::make_heap(ranges::begin(rng), ranges::end(rng));
                return detail::forward<RandomAccessRange>(rng);
            }

            /// \overload
            template<typename RandomAccessRange, typename Compare>
            static RandomAccessRange invoke(heap_maker, RandomAccessRange && rng, Compare comp_pred)
            {
                CONCEPT_ASSERT(ranges::RandomAccessRange<RandomAccessRange>());
                std::make_heap(ranges::begin(rng), ranges::end(rng), detail::move(comp_pred));
                return detail::forward<RandomAccessRange>(rng);
            }
        };

        constexpr heap_maker make_heap {};

        struct heap_sorter : bindable<heap_sorter>
        {
            /// \brief template function \c heap_sorter::operator()
            ///
            /// range-based version of the \c sort_heap std algorithm
            ///
            /// \pre \c RandomAccessRange is a model of the RandomAccessRange concept
            /// \pre \c Compare is a model of the BinaryPredicate concept
            template<typename RandomAccessRange>
            static RandomAccessRange invoke(heap_sorter, RandomAccessRange && rng)
            {
                CONCEPT_ASSERT(ranges::RandomAccessRange<RandomAccessRange>());
                std::sort_heap(ranges::begin(rng), ranges::end(rng));
                return detail::forward<RandomAccessRange>(rng);
            }

            /// \overload
            template<typename RandomAccessRange, typename Compare>
            static RandomAccessRange invoke(heap_sorter, RandomAccessRange && rng, Compare comp_pred)
            {
                CONCEPT_ASSERT(ranges::RandomAccessRange<RandomAccessRange>());
                std::sort_heap(ranges::begin(rng), ranges::end(rng), detail::move(comp_pred));
                return detail::forward<RandomAccessRange>(rng);
            }
        };

        constexpr heap_sorter sort_heap {};

    } // inline namespace v3

} // namespace ranges

#endif // include guard
