#include "esp_log.h"

#include "fri3d_application/application.hpp"
#include "fri3d_application/partition_boot.hpp"
#include "fri3d_hello/hello.hpp"
#include "fri3d_launcher/launcher.hpp"
#include "fri3d_ota/ota.hpp"
#include "fri3d_splash/splash.hpp"

using namespace Fri3d::Application;
using namespace Fri3d::Apps;

extern "C" {
static const char *TAG = "main";

void app_main(void)
{
    esp_log_level_set(TAG, LOG_LOCAL_LEVEL);

    application.init();

    auto &appManager = application.getAppManager();

    CPartitionBoot micropython("MicroPython", "micropython");

    // (for now) the order in which you register determines the display order in the launcher
    appManager.registerApp(Launcher::launcher);
    appManager.registerApp(Splash::splash);
    appManager.registerApp(Ota::ota);
    appManager.registerApp(Hello::hello);
    appManager.registerApp(micropython);

#ifndef CONFIG_FRI3D_BADGE_OCTOPUS
    CPartitionBoot retroGo("Retro-Go Gaming", "launcher");
    appManager.registerApp(retroGo);
#endif

    application.run(Launcher::launcher);

    application.deinit();
}
};
