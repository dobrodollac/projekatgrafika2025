//
// Created by matfrg on 11/9/25.
//

#include "Aplikacija.h"

#include "MainKontroler.h"
#include "spdlog/spdlog.h"

namespace app {
void Aplikacija::app_setup() {
    spdlog::info("Postavljanje aplikacije je gotovo.");
    auto main_kontroler = register_controller<app::MainKontroler>();
    main_kontroler->after(engine::core::Controller::get<engine::core::EngineControllersEnd>());
}
} // app