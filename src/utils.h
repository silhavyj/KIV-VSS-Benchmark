#pragma once

#include <vector>
#include <list>
#include <cstdint>
#include <memory>

namespace kiv_vss::utils
{
    /// Generates data.
    /// It creates a container holding default values of its datatype.
    /// \tparam Container Type of the container to be created
    /// \param n Number of elements in the container
    /// \return Container used in the benchmark
    template<typename Container>
    [[nodiscard]] Container Generate_Data(std::size_t n)
    {
        // Create an empty container;
        Container data{};

        // Create a variable of the container's datatype.
        typename Container::value_type value{};

        // Insert the value into the container;
        for (std::size_t i = 0; i < n; ++i)
        {
            data.push_back(value);
        }
        
        return data;
    }

    /// Converts KB to B 
    /// \param size Size to be converted
    /// \return Converted size [B]
    [[nodiscard]] constexpr std::size_t Convert_KB_To_B(std::size_t size) noexcept
    {
        return 1024 * size;
    }

    /// Converts MB to B 
    /// \param size Size to be converted
    /// \return Converted size [B]
    [[nodiscard]] constexpr std::size_t Convert_MB_To_B(std::size_t size) noexcept
    {
        return 1024 * Convert_KB_To_B(size);
    }

    /// Converts GB to B 
    /// \param size Size to be converted
    /// \return Converted size [B]
    [[nodiscard]] constexpr std::size_t Convert_GB_To_B(std::size_t size) noexcept
    {
        return 1024 * Convert_MB_To_B(size);
    }

    /// Converts a size into a number of elements
    /// \tparam Type Type of the element
    /// \param size Size to be converted into elements
    /// \return Number of elements 
    template<typename Type>
    [[nodiscard]] constexpr std::size_t Convert_Size_To_Number_Of_Elements(std::size_t size) noexcept
    {
        return size / sizeof(Type);
    }

    /// Generates different collection sizes.
    /// \tparam Type Data type used in the collection
    /// \param start First collection size
    /// \param stop Last collection size
    /// \param step Size step
    /// \return Collection sizes used in the benchmark
    template<typename Type>
    [[nodiscard]] constexpr std::vector<std::size_t> Generate_Test_Data_Sizes(std::size_t start, std::size_t stop, std::size_t step)
    {
        std::vector<std::size_t> sizes;
        for (std::size_t size = start; size <= stop; size += step)
        {
            sizes.push_back(Convert_Size_To_Number_Of_Elements<Type>(size));
        }

        return sizes;
    }
}

// EOF