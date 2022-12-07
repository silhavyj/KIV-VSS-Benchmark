#include <iostream>
#include <fstream>

#include "nlohmann/json.hpp"

#include "config.h"
#include "utils.h"
#include "benchmark.h"

namespace kiv_vss
{
    /// Runs a benchmark.
    /// The output precision is std::chrono::milliseconds.
    /// \tparam removal_type Type of the benchmark (from which position elements will be removed - begin, end, or middle)
    /// \param filename Name of the output file (JSON format)
    template<benchmark::NRemoval_Type removal_type>
    void Run_Benchmark(const char* filename)
    {
        // Create a benchmark.
        benchmark::CBenchmark<std::chrono::milliseconds> benchmark{};

        // Results of the benchmark.
        nlohmann::json json_data{};

        // Just to give some visual info to the user.
        std::cout << filename << " (sizes): ";

        // Go through all the collection sizes.
        for (const auto& count : config::element_counts)
        {
            // Print out process.
            std::cout << count << " " << std::flush;

            nlohmann::json::array_t times_vector;
            nlohmann::json::array_t times_list;

            // Repeat the benchmark 10 times.
            for (std::size_t i = 0; i < config::Number_Of_Measurements; ++i)
            {
                // BENCHMARK - std::vector
                auto data_vector = kiv_vss::utils::Generate_Data<std::vector<config::Data_Type>>(count);
                const auto time_vector = benchmark.Run<decltype(data_vector), removal_type>(data_vector);
                times_vector.push_back(time_vector);

                // BENCHMARK - std::list
                auto data_list = kiv_vss::utils::Generate_Data<std::list<config::Data_Type>>(count);
                const auto time_list = benchmark.Run<decltype(data_list), removal_type>(data_list);
                times_list.push_back(time_list);
            }

            // Store the results (current size).
            json_data[std::to_string(count * sizeof(config::Data_Type))] = {
                { "vector", times_vector },
                { "list"  , times_list   }
            };
        }

        // Store the results into a file.
        std::fstream file(filename, std::ios::out);
        if (file)
        {
            file << json_data;
        }

        std::cout << std::endl;
    }
}

int main()
{
    using namespace kiv_vss;

    // kiv_vss::Run_Benchmark<benchmark::NRemoval_Type::End>("end.json");   
    // kiv_vss::Run_Benchmark<benchmark::NRemoval_Type::Begin>("begin.json");
    // kiv_vss::Run_Benchmark<benchmark::NRemoval_Type::Middle>("middle.json");

    return 0;
}

// EOF