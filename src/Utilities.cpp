/*
* The MIT License (MIT)
*
* Copyright (c) 2017 Lev Sizov
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

/*!
 * \file Utilities.cpp
 * \brief This class contains utility functions definitions
 * \author Lev Sizov
 * \date 03.06.2017
 */

#include "include/Utilities.hpp"

using namespace Vulkalc;

VULKALC_API const char* Vulkalc::getCurrentTimeString()
{
    auto now = chrono::system_clock::now();
    auto now_time_t = chrono::system_clock::to_time_t(now);
#ifdef _MSC_VER
    std::shared_ptr<char*> time = std::make_shared<char*>((char*)malloc(sizeof(char) * 26));
    ctime_s(*time.get(), sizeof(char) * 26, &now_time_t);
    return *time.get();
#else
    return ctime(&now_time_t);
#endif
}

VULKALC_API bool Vulkalc::checkFileNameExtension(std::string fileName, std::string extension)
{
    if(fileName == "" || extension == "" || extension.find_last_of(".") != std::string::npos)
        return false;

    std::string fullExtension = ".";
    fullExtension.append(extension);
    uint32_t extPos = static_cast<uint32_t>(fileName.find_last_of(fullExtension));
    if(extPos != std::string::npos)
    {
        //check that "extension" is extension, not part of the name
        std::string name = fileName.substr(0, extPos - 1); //it should be name, without extension
        name.append(fullExtension); //if buf is test.comp.test, then fileName will be test.comp
        return fileName == name;
    }
    return false;
}
