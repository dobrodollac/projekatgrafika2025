//
// Created by matfrg on 11/9/25.
//

#include "MainKontroler.h"

#include "spdlog/spdlog.h"

#include <engine/platform/PlatformController.hpp>

namespace app {
void MainKontroler::initialize() {
    spdlog::info("Kontroler je uspesno inicijalizovan.");
  }
bool MainKontroler::loop() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    if(platform->key(engine::platform::KeyId::KEY_ESCAPE).is_down()) {
        return false;
    }
    return true;
}
} // app