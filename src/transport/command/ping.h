/**
 * Copyright (C) 2013 Tadas Vilkeliskis <vilkeliskis.t@gmail.com>
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
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
#ifndef CH_INCLUDE_GUARD_B3F7ACA4_559D_45B4_9E0F_B1248AF16E1D
#define CH_INCLUDE_GUARD_B3F7ACA4_559D_45B4_9E0F_B1248AF16E1D

#include <memory>

#include "transport/client.h"
#include "transport/abstract_response.h"
#include "transport/command/abstract_command.h"

namespace chimp {

namespace transport {
namespace command {

class Ping : public AbstractCommand {
    public:
        class PingResponse : public AbstractResponse {
            public:
                msgpack_sbuffer *ToMessagePack();
        };

        Ping(chimp::transport::Client *client);
        int Execute();
        int FromMessagePack(const msgpack_unpacked *msg);
        msgpack_sbuffer *ToMessagePack();
    private:
        chimp::transport::Client *client_;
};

}
}
}


#endif /* end of include guard */
