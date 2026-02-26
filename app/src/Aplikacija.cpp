//
// Created by matfrg on 11/9/25.
//

#include "Aplikacija.h"

#include "GUIKontroler.h"
#include "MainKontroler.h"
#include "spdlog/spdlog.h"

namespace app {
void Aplikacija::app_setup() {
    spdlog::info("Postavljanje aplikacije je gotovo.");
    auto main_kontroler = register_controller<app::MainKontroler>();
    auto gui_kontroler = register_controller<app::GUIKontroler>();
    main_kontroler->after(engine::core::Controller::get<engine::core::EngineControllersEnd>());
    main_kontroler->before(gui_kontroler);
}
}// namespace app