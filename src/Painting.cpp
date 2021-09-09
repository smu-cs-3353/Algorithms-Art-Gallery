//
// Created by tallb on 9/6/2021.
//

#include "Painting.h"

Painting::Painting() {
    id = 0;
    value = 0;
    width = 0;
    height = 0;
    x = 0;
    y = 0;
}

Painting::Painting(int p_id, int p_value, int p_width, int p_height) {
    id = p_id;
    value = p_value;
    width = p_width;
    height = p_height;
    x = 0;
    y = 0;
}

void Painting::setID(int p_id) {
    id = p_id;
}

void Painting::setValue(int p_value) {
    value = p_value;
}

void Painting::setWidth(int p_width) {
    width = p_width;
}

void Painting::setHeight(int p_height) {
    height = p_height;
}

void Painting::setX(int p_x) {
    x = p_x;
}

void Painting::setY(int p_y) {
    y = p_y;
}

void Painting::display() {
    std::cout << "Painting id #" << id << ":" << std::endl;
    std::cout << "\tValue: $" << value << std::endl;
    std::cout << "\tDimensions: " << width << "x" << height << std::endl;
    std::cout << "\tLocation: (" << x << ", " << y << ")" << std::endl;
}

bool Painting::operator<(const Painting &painting) const {
    return id < painting.id;
}

