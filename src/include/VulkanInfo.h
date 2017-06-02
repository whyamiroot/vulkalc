/*
* MIT License
*
* Copyright (c) 2017 Lev Sizov a.k.a "ToxikCoder"
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
 * \file VulkanInfo.h
 * \brief Provides VulkanInfo class which contains information about Vulkan runtime and installation
 * \author Lev Sizov
 * \date 28.05.17
 *
 *  Provides VulkanInfo class which contains information about Vulkan runtime and installation
 */

#ifndef VULKALC_LIBRARY_VULKANINFO_H
#define VULKALC_LIBRARY_VULKANINFO_H

#include "export.h"

/*!
 * \copydoc Vulkalc
 */
namespace Vulkalc
{
    class VULKALC_API VulkanInfo
    {
    public:
        /*!
         * \brief Constructor for VulkanInfo
         *
         * Constructs VulkanInfo object and fetches information about Vulkan
         */
        VulkanInfo();

        ~VulkanInfo();

    private:

    };
}

#endif //VULKALC_LIBRARY_VULKANINFO_H