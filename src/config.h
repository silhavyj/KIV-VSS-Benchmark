#pragma once

#include <cstddef>
#include <vector>

#include "utils.h"

namespace kiv_vss::config
{
    using Data_Type = std::uint32_t;                          ///< Data type used in both containers
    inline constexpr std::size_t Number_Of_Measurements = 10; ///< How many times each measurement will be done

    // These values are used to generate different collection sizes.
    inline constexpr std::size_t Start_Collection_Size = utils::Convert_KB_To_B(0); ///< Initial size of the collection
    inline constexpr std::size_t End_Collection_Size = utils::Convert_KB_To_B(500); ///< Final (last) size of the collection
    inline constexpr std::size_t Step_Size = utils::Convert_KB_To_B(25);            ///< Size step

    /// Collection sizes used in the benchmark.
    static std::vector<std::size_t> element_counts = utils::Generate_Test_Data_Sizes<Data_Type>(Start_Collection_Size, End_Collection_Size, Step_Size);
}

// EOF