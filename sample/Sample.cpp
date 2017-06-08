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
 * \file Sample.cpp
 * \brief 
 * \author Lev Sizov
 * \date 05.06.2017
 */

#include <Application.hpp>

using namespace Vulkalc;
using namespace std;

void main()
{
    //creating and configuring Application
    Application* application = new Application();
    SharedConfiguration configuration = application->getConfigurator()->getConfiguration();
    configuration->isErrorLoggingEnabled = false;
    configuration->applicationName = "Vulkalc sample";
    configuration->logStream = cout; //probably incorrect
    application.configure(false);
    //choosing device
    auto devices = application->enumeratePhysicalDevices();
    for(auto device : devices)
    {
        cout << "Device: " << device->getDeviceName() << endl;
    }
    application->setPhysicalDevice(devices[0]);
    //

    devices.clear();
    configuration.reset();
    delete application;
}