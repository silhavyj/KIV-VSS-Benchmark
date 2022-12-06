#pragma once

#include <chrono>

namespace kiv_vss::benchmark
{
    enum class [[nodiscard]] NRemoval_Type: std::uint8_t
    {
        Begin = 0,
        End,
        Middle
    };

    template<class Time_Precision>
    class CBenchmark
    {
        using Clock = std::chrono::high_resolution_clock;        

    public:
        CBenchmark() = default;
        ~CBenchmark() = default;

        template<typename Container, NRemoval_Type removal_type>
        [[nodiscard]] std::size_t Run(Container& data) const
        {
            std::size_t total_time{0};
            const auto n = data.size();

            while (!data.empty())
            {
                total_time += Remove_Element<Container, removal_type>(data); 
            }

            return std::chrono::duration_cast<Time_Precision>(std::chrono::nanoseconds(total_time)).count();
        }

    private:
        template<typename Container, NRemoval_Type removal_type>
        [[nodiscard]] inline double Remove_Element(Container& data) const
        {
            const std::size_t index_middle = data.size() / 2;
            auto it_middle = data.begin();

            const auto start_time = Clock::now();
            switch (removal_type)
            {
                case NRemoval_Type::Begin:
                    data.erase(data.begin());
                    break;

                case NRemoval_Type::End:
                    data.erase(std::prev(data.end()));
                    break;

                case NRemoval_Type::Middle:
                    std::advance(it_middle, index_middle);
                    data.erase(it_middle);
                    break;

                default:
                    // TODO error
                    break;
            }
            const auto end_time = Clock::now();

            return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        }
    };
}