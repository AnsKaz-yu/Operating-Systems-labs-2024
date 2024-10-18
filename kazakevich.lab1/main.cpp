#include "daemon_utils.h"
#include "Daemon.h"
#include <iostream>
#include <filesystem>


int main(int argc, char* argv[]) {
    std::cout << "START";

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config_file>" << std::endl;
        return EXIT_FAILURE;
    }

    signal(SIGHUP, Daemon::handleSignal);
    signal(SIGTERM, Daemon::handleSignal);

    ConfigManager* configManager = ConfigManager::getInstance();
    configManager->setConfigPath(argv[1]);

    daemonize();

    Daemon::getInstance()->run();

	return EXIT_SUCCESS;
}