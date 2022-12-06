#pragma once

#include <cstddef>
#include <vector>

#include "utils.h"

namespace kiv_vss::config
{
    using Data_Type = std::uint32_t;

    static std::vector<std::size_t> element_counts = utils::Generate_Test_Data_Sizes<Data_Type>();
    inline constexpr std::size_t Number_Of_Measurements = 10;
}