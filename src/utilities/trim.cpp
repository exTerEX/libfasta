/*
 * Copyright 2021 Andreas Sagen

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <algorithm>
#include <iostream>

std::string &ltrim(std::string &__s) {
    auto it = std::find_if(__s.begin(), __s.end(), [](char c) {
        return !std::isspace<char>(c, std::locale::classic());
    });

    __s.erase(__s.begin(), it);

    return __s;
}

std::string &rtrim(std::string &__s) {
    auto it = std::find_if(__s.rbegin(), __s.rend(), [](char c) {
        return !std::isspace<char>(c, std::locale::classic());
    });

    __s.erase(it.base(), __s.end());

    return __s;
}
