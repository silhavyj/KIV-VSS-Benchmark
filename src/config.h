#pragma once

#include <cstddef>
#include <vector>

#include "utils.h"

namespace kiv_vss::config
{
    using Data_Type = std::uint32_t;

    inline constexpr std::size_t Number_Of_Measurements = 10;

    inline constexpr std::size_t Start_Collection_Size = utils::Convert_KB_To_B(0);
    inline constexpr std::size_t End_Collection_Size = utils::Convert_KB_To_B(500);
    inline constexpr std::size_t Step_Size = utils::Convert_KB_To_B(25);

    static std::vector<std::size_t> element_counts = utils::Generate_Test_Data_Sizes<Data_Type>(Start_Collection_Size, End_Collection_Size, Step_Size);
}