#pragma once

#include <chrono>

namespace kiv_vss::benchmark
{
    /// Position from which an element will be removed.
    enum class [[nodiscard]] NRemoval_Type: std::uint8_t
    {
        Begin = 0, ///< Beginning of the collection
        End,       ///< End of the collection
        Middle     ///< Middle of the collection
    };

    /// Defines benchmark functions
    /// \tparam Time_Precision measurement precision (e.g. std::chrono::milliseconds)
    template<class Time_Precision>
    class CBenchmark
    {
        // Clocked used in the benchmark.
        using Clock = std::chrono::high_resolution_clock;        

    public:
        /// Default constructor
        CBenchmark() = default;

        /// Default destructor
        ~CBenchmark() = default;

        /// Runs a benchmark (removes all elements from a container).
        /// \tparam Container Type of the container to be benchmarked (std::vector, std::list)
        /// \tparam removal_type Position from which an element will be removed (beginning, end, or middle)
        /// \param data Container to be benchmarked
        /// \return How much time it took to remove all elements
        template<typename Container, NRemoval_Type removal_type>
        [[nodiscard]] std::size_t Run(Container& data) const
        {
            std::size_t total_time{0};  // Total time of execution
            const auto n = data.size(); // Number of elements in the container

            // Keep removing elements until the container is empty
            while (!data.empty())
            {
                total_time += Remove_Element<Container, removal_type>(data); 
            }

            // Return the total amount of time it took to remove all elements.
            return std::chrono::duration_cast<Time_Precision>(std::chrono::nanoseconds(total_time)).count();
        }

    private:
        /// Removes an element from the container
        /// \tparam Container Type of the container from which the element will be removed
        /// \tparam removal_type Position of the element to be removed (beginning, end, or middle)
        /// \param data Container from which the element will be removed
        /// \return How much time it took to remove the element.
        template<typename Container, NRemoval_Type removal_type>
        [[nodiscard]] inline double Remove_Element(Container& data) const
        {
            const std::size_t index_middle = data.size() / 2; // Index of the element in the middle
            auto it_middle = data.begin();                    // Iterator to the beginning of the container

            // Measure the start time.
            const auto start_time = Clock::now();

            switch (removal_type)
            {
                // Remove the element at the beginning of the container.
                case NRemoval_Type::Begin:
                    data.erase(data.begin());
                    break;

                // Remove the element at the end of the container
                case NRemoval_Type::End:
                    data.erase(std::prev(data.end())); // data.end() - 1
                    break;

                // Remove the element at the middle of the container.
                case NRemoval_Type::Middle:
                    std::advance(it_middle, index_middle); // Iterate to the middle of the container
                    data.erase(it_middle);
                    break;

                default:
                    // TODO Print out an error message
                    break;
            }

            // Measure the end time.
            const auto end_time = Clock::now();

            // Calculate how much time it took to remove the element.
            return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
    };
}

// EOF