#include "onboarding.hpp"

using namespace ftxui;

Onboarding::Onboarding() {
    auto screen = ScreenInteractive::TerminalOutput();
    Component inputUsername = Input(&username, "Ishmael");

    std::vector<std::string> petOptions = {"bird", "cat", "dog", "gecko"};
    int selectedPetOption = 0;
    Component petTypeSelection = Radiobox(&petOptions, &selectedPetOption);

    std::vector<std::string> petSexOptions = {"female", "male"};
    int petSexSelection = 0;
    Component selectedPetSex = Toggle(&petSexOptions, &petSexSelection);

    Component inputPetName = Input(&petName, "Ishmael");

    auto buttons = Container::Horizontal({
                                                 Button(
                                                         "Adopt", [&] { screen.ExitLoopClosure(); }, ButtonOption::Animated(Color::Red)),
                                                 Button(
                                                         "Cancel", [&] { screen.ExitLoopClosure(); }, ButtonOption::Animated(Color::Green)),
                                         });

    auto component = Container::Vertical({
                                                 inputUsername, petTypeSelection, selectedPetSex, inputPetName, buttons
                                         });

    auto renderer = Renderer(component, [&] {
        return vbox({
                            vbox({
                                         text(L" CPP Tomagotchi ") | bold | hcenter,
                                         text(L" Adopt and care for a friend! ") | bold | hcenter
                                 }) | border,
                            hbox(text("What should we call you? ")),
                            hbox(inputUsername->Render()),
                            separator(),
                            hbox(text("Hello " + username + "!")),
                            separator(),
                            hbox(text("What type of pet would you like to adopt?")),
                            vbox(petTypeSelection->Render()),
                            hbox(text("What is your pet's sex?")),
                            selectedPetSex->Render(),
                            hbox(text("What is your pet's name?")),
                            inputPetName->Render(),
                            hbox(text("Adopt a " + petSexOptions[petSexSelection] + " " + petOptions[selectedPetOption] + " named " + petName + "?")),
                            buttons->Render(),
                    }) |
               border;
    });

    screen.Loop(renderer);
};