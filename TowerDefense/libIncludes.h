#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <filesystem>
#include <regex>
#include <fstream>
#include <exception>
#include <vector>
#include <cmath>
#include <thread>
#include <barrier>
#include <future>

const int MAP_SIZE_X = 15;
const int MAP_SIZE_Y = 10;
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 750;
const float gridSizeF = 60.f;
const unsigned gridSizeU = static_cast<unsigned>(gridSizeF);