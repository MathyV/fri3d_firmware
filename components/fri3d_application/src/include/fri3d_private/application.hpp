#pragma once

#include "fri3d_application/application.hpp"
#include "fri3d_private/app_manager.hpp"
#include "fri3d_private/hardware_manager.hpp"
#include "fri3d_private/lvgl.hpp"
#include "fri3d_private/nvs_manager.hpp"

namespace Fri3d::Application
{

class CApplication : public IApplication
{
private:
    bool running;
    bool initialized;

    CAppManager appManager;
    CHardwareManager hardwareManager;
    CLVGL lvgl;
    CNvsManager nvsManager;

public:
    CApplication();

    void init() override;

    void deinit() override;

    IAppManager &getAppManager() override;

    void run(const CBaseApp &app) override;
};

} // namespace Fri3d::Application
