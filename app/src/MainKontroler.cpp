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
    shader->set_vec3("viewPos", graphics->camera()->Position);
    shader->set_vec3("dirLight.direction", glm::vec3(-1.0f, -0.4f, -0.3f));
    shader->set_vec3("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
    shader->set_vec3("dirLight.diffuse", glm::vec3(0.15f, 0.15f, 0.2f));
    shader->set_vec3("dirLight.specular", glm::vec3(0.1f, 0.1f, 0.1f));
    auto camera = graphics->camera();
    shader->set_vec3("spotLight.position", camera->Position);
    shader->set_vec3("spotLight.direction", camera->Front);


    shader->set_vec3("spotLight.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
    shader->set_vec3("spotLight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
    shader->set_vec3("spotLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));

    shader->set_float("spotLight.constant", 1.0f);
    shader->set_float("spotLight.linear", 0.09f);
    shader->set_float("spotLight.quadratic", 0.032f);

    shader->set_float("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    shader->set_float("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));


    strumfeta->draw(shader);
}
void MainKontroler::draw_veliki_strumf() {
    auto resources = get<engine::resources::ResourcesController>();
    auto graphics = get<engine::graphics::GraphicsController>();
    engine::resources::Model *velikiStrumf = resources->model("velikiStrumf");
    engine::resources::Shader *shader = resources->shader("basic");
    shader->use();
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(pozicija_velikog_strumfa, -2.8f, -13.75f));
    model = glm::rotate(model, glm::radians(ugao_velikog_strumfa), glm::vec3(0.0f, -1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.7f));
    shader->set_mat4("model", model);

    shader->set_vec3("viewPos", graphics->camera()->Position);
    shader->set_vec3("dirLight.direction", glm::vec3(-1.0f, -0.4f, -0.3f));
    shader->set_vec3("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
    shader->set_vec3("dirLight.diffuse", glm::vec3(0.15f, 0.15f, 0.2f));
    shader->set_vec3("dirLight.specular", glm::vec3(0.1f, 0.1f, 0.1f));

    auto camera = graphics->camera();
    shader->set_vec3("spotLight.position", camera->Position);
    shader->set_vec3("spotLight.direction", camera->Front);


    shader->set_vec3("spotLight.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
    shader->set_vec3("spotLight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
    shader->set_vec3("spotLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));

    shader->set_float("spotLight.constant", 1.0f);
    shader->set_float("spotLight.linear", 0.09f);
    shader->set_float("spotLight.quadratic", 0.032f);

    shader->set_float("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    shader->set_float("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));

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
    shader->set_vec3("viewPos", graphics->camera()->Position);
    shader->set_vec3("dirLight.direction", glm::vec3(-1.0f, -0.4f, -0.3f));
    shader->set_vec3("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
    shader->set_vec3("dirLight.diffuse", glm::vec3(0.15f, 0.15f, 0.2f));
    shader->set_vec3("dirLight.specular", glm::vec3(0.1f, 0.1f, 0.1f));

    auto camera = graphics->camera();
    shader->set_vec3("spotLight.position", camera->Position);
    shader->set_vec3("spotLight.direction", camera->Front);


    shader->set_vec3("spotLight.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
    shader->set_vec3("spotLight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
    shader->set_vec3("spotLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));

    shader->set_float("spotLight.constant", 1.0f);
    shader->set_float("spotLight.linear", 0.09f);
    shader->set_float("spotLight.quadratic", 0.032f);

    shader->set_float("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    shader->set_float("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));


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
    shader->set_vec3("viewPos", graphics->camera()->Position);
    shader->set_vec3("dirLight.direction", glm::vec3(-1.0f, -0.4f, -0.3f));
    shader->set_vec3("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
    shader->set_vec3("dirLight.diffuse", glm::vec3(0.15f, 0.15f, 0.2f));
    shader->set_vec3("dirLight.specular", glm::vec3(0.1f, 0.1f, 0.1f));

    auto camera = graphics->camera();
    shader->set_vec3("spotLight.position", camera->Position);
    shader->set_vec3("spotLight.direction", camera->Front);

    shader->set_vec3("spotLight.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
    shader->set_vec3("spotLight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
    shader->set_vec3("spotLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));

    shader->set_float("spotLight.constant", 1.0f);
    shader->set_float("spotLight.linear", 0.09f);
    shader->set_float("spotLight.quadratic", 0.032f);

    shader->set_float("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    shader->set_float("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));


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
    shader->set_vec3("viewPos", graphics->camera()->Position);
    shader->set_vec3("dirLight.direction", glm::vec3(-1.0f, -0.4f, -0.3f));
    shader->set_vec3("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
    shader->set_vec3("dirLight.diffuse", glm::vec3(0.15f, 0.15f, 0.2f));
    shader->set_vec3("dirLight.specular", glm::vec3(0.1f, 0.1f, 0.1f));

    auto camera = graphics->camera();
    shader->set_vec3("spotLight.position", camera->Position);
    shader->set_vec3("spotLight.direction", camera->Front);


    shader->set_vec3("spotLight.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
    shader->set_vec3("spotLight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
    shader->set_vec3("spotLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));

    shader->set_float("spotLight.constant", 1.0f);
    shader->set_float("spotLight.linear", 0.09f);
    shader->set_float("spotLight.quadratic", 0.032f);

    shader->set_float("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    shader->set_float("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));

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

    if (platform->key(engine::platform::KeyId::KEY_G).state() == engine::platform::Key::State::JustPressed) {
        ugao_velikog_strumfa += 120.0f;
        prikazi_gargamela = !prikazi_gargamela;
        pokreni_velikog_strumfa = true;
    }

    if (platform->key(engine::platform::KeyId::KEY_E).state() == engine::platform::Key::State::JustPressed) {
        prikazi_strumfetu = !prikazi_strumfetu;
        prikazi_bubala = !prikazi_bubala;
        prikazi_velikog_strumfa = !prikazi_velikog_strumfa;
    }
}
void MainKontroler::update() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    float dt = platform->dt();

    if (pokreni_velikog_strumfa) {
        if (pozicija_velikog_strumfa > -2.0f) {
            pozicija_velikog_strumfa -= 0.75f * dt;
            if (pozicija_velikog_strumfa <= -2.0f) {
                pozicija_velikog_strumfa = -2.0f;
                pokreni_velikog_strumfa = false;
            }
        }
    }
    update_camera();
}
void MainKontroler::begin_draw() {
    engine::graphics::OpenGL::clear_buffers();
}

void MainKontroler::draw() {
    if (prikazi_strumfetu) {
        draw_strumfeta();
    }
    if (prikazi_velikog_strumfa) {
        draw_veliki_strumf();
    }
    if (prikazi_velikog_strumfa) {
        draw_bubalo();
    }
    if (prikazi_gargamela) {
        draw_gargamel();
    }
    draw_kuca();
}
void MainKontroler::end_draw() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    platform->swap_buffers();
}
}// namespace app