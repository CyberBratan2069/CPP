/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created 01 Mai. 2025
 * @last modified 06 Mai. 2025
 * @version 1.0
 * @brief
 **********************************************************************************************************************/


// file: FixedPoint.hpp
#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP

#include <string>
#include <algorithm>

struct RgbColor {
private:
    unsigned int m_red;
    unsigned int m_green;
    unsigned int m_blue;

public:
    /** Constructor */
    RgbColor(); // Default
    RgbColor(unsigned int m_red, unsigned int m_green, unsigned int m_blue); // Color
    explicit RgbColor(uint32_t rgbVal);

    /** Getter > 255*/
    [[nodiscard]] uint8_t red()   const ;
    [[nodiscard]] uint8_t green() const ;
    [[nodiscard]] uint8_t blue()  const ;

    /** Operators */
    RgbColor operator+(const RgbColor& color) const;
    RgbColor operator-(const RgbColor& color) const;
    bool operator<(const RgbColor& color) const;
    bool operator>(const RgbColor& color) const;
    bool operator==(const RgbColor& color) const;
    RgbColor& operator++();    // Prefix ++c
    RgbColor  operator++(int); // Postfix c++

    /** Inverted Operator */
    RgbColor operator~() const;

    explicit operator bool() const;
    explicit operator double() const;

    [[nodiscard]] uint8_t luminosity() const;
    [[nodiscard]] RgbColor negated()   const;
};

std::string as_string(RgbColor);  // for println()

#endif