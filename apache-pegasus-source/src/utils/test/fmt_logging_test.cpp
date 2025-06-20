/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Microsoft Corporation
 *
 * -=- Robust Distributed System Nucleus (rDSN) -=-
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <fmt/core.h>
// IWYU pragma: no_include <gtest/gtest-message.h>
// IWYU pragma: no_include <gtest/gtest-test-part.h>
#include <gtest/gtest.h>

#include "common/gpid.h"
#include "common/replication.codes.h"
#include "runtime/task/task_code.h"
#include "utils/error_code.h"
#include "utils/errors.h"
#include "utils/string_view.h"

namespace dsn {
namespace replication {

TEST(fmt_logging, basic)
{
    ASSERT_EQ(fmt::format("{}", gpid(1, 1)), "1.1");
    ASSERT_EQ(fmt::format("{}", error_s::ok()), "ERR_OK");
    ASSERT_EQ(fmt::format("{}", error_s::make(ERR_TIMEOUT, "yes")), "ERR_TIMEOUT: yes");
    ASSERT_EQ(fmt::format("{}", ERR_OK), "ERR_OK");
    ASSERT_EQ(fmt::format("{}", LPC_REPLICATION_LOW), "LPC_REPLICATION_LOW");
    ASSERT_EQ(string_view("yes"), "yes");
    ASSERT_EQ(fmt::format("{}", string_view("yes\0yes")), "yes\0yes");
}

} // namespace replication
} // namespace dsn
