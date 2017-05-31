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

#include <Application.hpp>
#include "catch.hpp"

using namespace Vulkalc;

/*TEST_CASE("Only one Application instance exists")
{
    Application application = Application::getInstance();
    Application anotherApplication = Application::getInstance();
    REQUIRE(application == anotherApplication);
}*/

TEST_CASE("Application is initialized when created")
{
    Application application = Application::getInstance();
    REQUIRE(application.isApplicationInitialized());
}

TEST_CASE("Application is configured after calling Application::configure()")
{
    Application application = Application::getInstance();
    application.configure();
    REQUIRE(application.isApplicationConfigured());
}

TEST_CASE("Not configured Application calling log")
{
    Application application = Application::getInstance();
    REQUIRE_THROWS_AS(application.log("test", Application::LOG_INFO), Application::ApplicationNotConfiguredException);
}

