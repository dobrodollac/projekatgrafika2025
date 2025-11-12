//
// Created by matfrg on 11/9/25.
//

#include "MainKontroler.h"

#include "spdlog/spdlog.h"

#include <engine/graphics/GraphicsController.hpp>
#include <engine/graphics/OpenGL.hpp>
#include <engine/platform/PlatformController.hpp>
#include <engine/resources/ResourcesController.hpp>

namespace app {
/*class MainPlatformEventObserver : public engine::platform::PlatformEventObserver {
public:
    void on_mouse_move(engine::platform::MousePosition position) override;

};
void MainPlatformEventObserver::on_mouse_move(engine::platform::MousePosition position) {
    auto camera = engine::core::Controller::get<engine::graphics::GraphicsController>()->camera();
    camera->rotate_camera(position.dx, position.dy);
}*/



void MainKontroler::initialize() {
    spdlog::info("Kontroler je uspesno inicijalizovan.");
    engine::graphics::OpenGL::enable_depth_testing();
}
bool MainKontroler::loop() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    if (platform->key(engine::platform::KeyId::KEY_ESCAPE).is_down()) {
        return false;
    }
    return true;
}
void MainKontroler::draw_strumfeta() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *strumfeta = resources->model("strumfeta");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-2.5f, -2.8f, -13.5f));
    model = glm::rotate(model, glm::radians(-45.0f), glm::vec3(.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.6f));
    shader->set_mat4("model", model);
    strumfeta->draw(shader);
}
void MainKontroler::draw_velikiStrumf() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *velikiStrumf = resources->model("velikiStrumf");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(pozicijaVelikogStrumfa, -2.8f, -13.75f));
    model = glm::rotate(model, glm::radians(ugaoVelikogStrumfa), glm::vec3(0.0f, -1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.7f));
    shader->set_mat4("model", model);
    velikiStrumf->draw(shader);
}
void MainKontroler::draw_bubalo() {

    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *bubalo = resources->model("bubalo");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-3.5f, -2.8f, -13.5f));
    model = glm::rotate(model, glm::radians(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.6f));
    shader->set_mat4("model", model);
    bubalo->draw(shader);
}
void MainKontroler::draw_gargamel() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *gargamel = resources->model("gargamel");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(4.0f, -2.8f, -13.0f));
    model = glm::rotate(model, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.15f));
    shader->set_mat4("model", model);
    gargamel->draw(shader);
}
void MainKontroler::draw_kuca() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *kuca = resources->model("kuca");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-5.25f, -3.0f, -13.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.5f));
    shader->set_mat4("model", model);
    kuca->draw(shader);
}
void MainKontroler::update_camera() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    auto camera = engine::core::Controller::get<engine::graphics::GraphicsController>()->camera();
    float dt = platform->dt();
    if (platform->key(engine::platform::KEY_W)
                .state() == engine::platform::Key::State::Pressed) {
        camera->move_camera(engine::graphics::Camera::Movement::FORWARD, dt);
    }
    if (platform->key(engine::platform::KEY_S)
                .state() == engine::platform::Key::State::Pressed) {
        camera->move_camera(engine::graphics::Camera::Movement::BACKWARD, dt);
    }
    if (platform->key(engine::platform::KEY_A)
                .state() == engine::platform::Key::State::Pressed) {
        camera->move_camera(engine::graphics::Camera::Movement::LEFT, dt);
    }
    if (platform->key(engine::platform::KEY_D)
                .state() == engine::platform::Key::State::Pressed) {
        camera->move_camera(engine::graphics::Camera::Movement::RIGHT, dt);
    }
    /*auto mouse = platform->mouse();
    camera->rotate_camera(mouse.dx, mouse.dy);*/
    bool trenutnoG = platform->key(engine::platform::KEY_G).state() == engine::platform::Key::State::Pressed;
    if (trenutnoG && !prethodnoG) {
        ugaoVelikogStrumfa += 120.0f;
        prikaziGargamela = !prikaziGargamela;
        pokreniVelikogStrumfa = true;
    }

    prethodnoG = trenutnoG;



}
void MainKontroler::update() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    float dt = platform->dt();

    if (pokreniVelikogStrumfa) {
        if (pozicijaVelikogStrumfa > -2.0f) {
            pozicijaVelikogStrumfa -= 0.75f * dt;
            if (pozicijaVelikogStrumfa <= -2.0f) {
                pozicijaVelikogStrumfa = -2.0f;
                pokreniVelikogStrumfa = false;
            }
        }
    }
    update_camera();
}
void MainKontroler::begin_draw() {
    engine::graphics::OpenGL::clear_buffers();
}

void MainKontroler::draw() {
    draw_strumfeta();
    draw_velikiStrumf();
    draw_bubalo();
    if(prikaziGargamela) {
        draw_gargamel();
    }
    draw_kuca();
}
void MainKontroler::end_draw() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    platform->swap_buffers();
}
}// namespace app