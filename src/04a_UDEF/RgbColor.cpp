#include "RgbColor.hpp"
#include <algorithm>

/** Default-Constructor */
RgbColor::RgbColor()
    : m_red(0), m_green(0), m_blue(0) {}

/** Color-Constructor */
RgbColor::RgbColor(unsigned int m_red, unsigned int m_green, unsigned int m_blue)
    : m_red(m_red), m_green(m_green), m_blue(m_blue) {}

//
RgbColor::RgbColor(uint32_t rgbVal) {
    m_red   = (rgbVal & 0xff0000) >> 16;
    m_green = (rgbVal & 0xff00  ) >> 8;
    m_blue  = (rgbVal & 0xff    );
}

/** Operators */
RgbColor RgbColor::operator+(const RgbColor& color) const {
    return {m_red     + color.m_red,
            m_green + color.m_green,
            m_blue   + color.m_blue};
}

RgbColor RgbColor::operator-(const RgbColor& color) const {
    return {m_red     - color.m_red,
            m_green - color.m_green,
            m_blue   - color.m_blue};
}

bool RgbColor::operator<(const RgbColor& color) const {
    return m_red   < color.m_red
        && m_blue  < color.m_blue
        && m_green < color.m_green;
}

bool RgbColor::operator>(const RgbColor& color) const {
    return m_red   > color.m_red
        && m_green > color.m_green
        && m_blue  > color.m_blue;
}

bool RgbColor::operator==(const RgbColor& color) const {
    return m_red    == color.m_red
         && m_green == color.m_green
         && m_blue  == color.m_blue;
}

RgbColor& RgbColor::operator++() {
    m_red   = std::min(m_red   + 1, 255U);
    m_blue  = std::min(m_blue  + 1, 255U);
    m_green = std::min(m_green + 1, 255U);
    return *this;
}

RgbColor RgbColor::operator++(int) {
    RgbColor rgbColor = *this;
    m_red   = std::min(m_red   + 1, 255U);
    m_blue  = std::min(m_blue  + 1, 255U);
    m_green = std::min(m_green + 1, 255U);
    return rgbColor;
}

RgbColor RgbColor::operator~() const {
    return {~m_red, ~m_green, ~m_blue};
}

/** Getter */
uint8_t RgbColor::red() const {
    return m_red;
}

uint8_t RgbColor::green() const {
    return m_green;
}

uint8_t RgbColor::blue() const {
    return m_blue;
}

RgbColor::operator bool() const {
    return m_red != 0u || m_green != 0u || m_blue != 0u;
}

RgbColor::operator double() const {
    uint32_t rgb =  ((static_cast<uint32_t>(m_red)   << 16)
                    |(static_cast<uint32_t>(m_green) << 8)
                    |(static_cast<uint32_t>(m_blue)));
    return static_cast<double>(rgb);
}

uint8_t RgbColor::luminosity() const {
    double lum = 0.21 * m_red
               + 0.72 * m_green
               + 0.07 * m_blue;
    return static_cast<uint8_t>(lum);
}

RgbColor RgbColor::negated() const {
    return {255   - m_red,
            255 - m_green,
            255  - m_blue};
}

std::string as_string(RgbColor c) {  // for println()
    std::string s("col(");
    s+= std::to_string(c.red());
    s+= std::to_string(c.green());
    s+= std::to_string(c.blue());
    s+= std::string(")");
    return s;
}