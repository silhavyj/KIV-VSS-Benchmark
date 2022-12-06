#include <iostream>
#include <fstream>

#include "nlohmann/json.hpp"

#include "config.h"
#include "utils.h"
#include "benchmark.h"

namespace kiv_vss
{
    template<benchmark::NRemoval_Type removal_type>
    void Run_Benchmark(const char* filename)
    {
        benchmark::CBenchmark<std::chrono::milliseconds> benchmark{};
        nlohmann::json json_data{};

        std::cout << filename << " (sizes): ";

        for (const auto& size : config::element_counts)
        {
            std::cout << size << " " << std::flush;

            nlohmann::json::array_t times_vector;
            nlohmann::json::array_t times_list;

            for (std::size_t i = 0; i < config::Number_Of_Measurements; ++i)
            {
                auto data_vector = kiv_vss::utils::Generate_Data<std::vector<config::Data_Type>>(size);
                const auto time_vector = benchmark.Run<decltype(data_vector), removal_type>(data_vector);
                times_vector.push_back(time_vector);

                auto data_list = kiv_vss::utils::Generate_Data<std::list<config::Data_Type>>(size);
                const auto time_list = benchmark.Run<decltype(data_list), removal_type>(data_list);
                times_list.push_back(time_list);
            }

            json_data[std::to_string(size)] = {
                { "vector", times_vector },
                { "list"  , times_list   }
            };
        }

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
    kiv_vss::Run_Benchmark<benchmark::NRemoval_Type::Begin>("begin.json");
    // kiv_vss::Run_Benchmark<benchmark::NRemoval_Type::Middle>("middle.json");

    return 0;
}