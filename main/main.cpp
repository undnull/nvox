/* SPDX-License-Identifier: GPL-3.0 */
#include <core/fs.hpp>
#include <core/util/spdlog.hpp>
#include <exception>
#include <iostream>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

int main(int argc, char **argv)
{
    try {
        spdlog::logger *lp = spdlog::default_logger_raw();
        lp->sinks().clear();
        lp->sinks().push_back(util::createSink<spdlog::sinks::stderr_color_sink_mt>());
        lp->set_level(spdlog::level::trace);
    }
    catch(const spdlog::spdlog_ex &ex) {
        // Fallback to iostream and die
        std::cerr << ex.what() << std::endl;
        std::terminate();
    }

    fs::initialize();

    // code goes here (code goes here).
    // note: code goes here.
    // fixme: code goes here.
    // CODE SHOULD GO HERE (GOES HERE)
    spdlog::info("code goes here.");

    fs::shutdown();

    return 0;
}
