/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 * 
 *  http://aws.amazon.com/apache2.0
 * 
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */


#include <aws/testing/TestingEnvironment.h>

#include <aws/core/platform/FileSystem.h>
#include <aws/testing/platform/PlatformTesting.h>

#include <sstream>

namespace Aws
{
namespace Testing
{

void RedirectHomeToTempIfAppropriate()
{
    #if !defined(DISABLE_HOME_DIR_REDIRECT) 
        //Set $HOME to tmp on unix systems
        std::stringstream tempDir; //( P_tmpdir );
        tempDir << P_tmpdir;
        Aws::String dir = tempDir.str().c_str();
        if (dir.size() > 0 && *(dir.c_str() + dir.size() - 1) != Aws::FileSystem::PATH_DELIM)
        {
            tempDir << Aws::FileSystem::PATH_DELIM;
        }
        Aws::Environment::SetEnv("HOME", tempDir.str().c_str(), 1);
    #endif // !defined(DISABLE_HOME_DIR_REDIRECT)
}

} // namespace Testing
} // namespace Aws
