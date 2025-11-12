//
// Created by matfrg on 11/12/25.
//

#include "GUIKontroler.h"

#include <engine/graphics/GraphicsController.hpp>
#include <engine/platform/PlatformController.hpp>
#include <imgui.h>

namespace app {
void GUIKontroler::initialize() {
    set_enable(false);
}
void GUIKontroler::poll_events() {
    const auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    if (platform->key(engine::platform::KeyId::KEY_F2).state() == engine::platform::Key::State::JustPressed) {
        set_enable(!is_enabled());
    }
}
void GUIKontroler::draw() {
    auto graphics = engine::core::Controller::get<engine::graphics::GraphicsController>();
    auto camera = graphics->camera();
    graphics->begin_gui();
    ImGui::Begin("Informacije o trenutnom stanju kamere");
    ImGui::Text("Pozicija kamere: (%f, %f, %f)", camera->Position.x,camera->Position.y, camera->Position.z);
    ImGui::End();
    graphics->end_gui();

}
} // app