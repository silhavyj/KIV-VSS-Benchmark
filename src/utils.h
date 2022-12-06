#pragma once

#include <vector>
#include <list>
#include <cstdint>
#include <memory>

namespace kiv_vss::utils
{
    template<typename Container>
    [[nodiscard]] Container Generate_Data(std::size_t n)
    {
        Container data{};
        typename Container::value_type value{};

        for (std::size_t i = 0; i < n; ++i)
        {
            data.push_back(value);
        }
        
        return data;
    }

    [[nodiscard]] constexpr std::size_t Convert_KB_To_B(std::size_t size) noexcept
    {
        return 1024 * size;
    }

    [[nodiscard]] constexpr std::size_t Convert_MB_To_B(std::size_t size) noexcept
    {
        return 1024 * Convert_KB_To_B(size);
    }

    [[nodiscard]] constexpr std::size_t Convert_GB_To_B(std::size_t size) noexcept
    {
        return 1024 * Convert_MB_To_B(size);
    }

    template<typename Type>
    [[nodiscard]] constexpr std::size_t Convert_Size_To_Number_Of_Elements(std::size_t size) noexcept
    {
        return size / sizeof(Type);
    }

    template<typename Type>
    [[nodiscard]] constexpr std::vector<std::size_t> Generate_Test_Data_Sizes()
    {
        std::vector<std::size_t> sizes;
        for (std::size_t i = 100; i <= 1000; i += 100)
        {
            sizes.push_back(Convert_Size_To_Number_Of_Elements<Type>(Convert_KB_To_B(i)));
        }

        return sizes;
    }
}