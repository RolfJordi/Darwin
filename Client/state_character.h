#pragma once

#include <memory>

#include "state_interface.h"
#include "darwin_client.h"
#include "frame/common/application.h"
#include "frame/logger.h"
#include "frame/gui/draw_gui_interface.h"
#include "modal_character.h"

namespace darwin::state {

    class StateCharacter : public StateInterface {
    public:
        StateCharacter(
            frame::common::Application& app,
            std::unique_ptr<darwin::DarwinClient> darwin_client) :
            app_(app), darwin_client_(std::move(darwin_client)) {}
        ~StateCharacter() override = default;

        void Enter() override;
        void Update(StateContext& state_context) override;
        void Exit() override;

    private:
        frame::common::Application& app_;
        std::unique_ptr<darwin::DarwinClient> darwin_client_;
        frame::Logger& logger_ = frame::Logger::GetInstance();
        frame::gui::DrawGuiInterface* draw_gui_ = nullptr;
        darwin::modal::ModalCharacterParams modal_character_params_;
    };

}  // namespace darwin::state.
