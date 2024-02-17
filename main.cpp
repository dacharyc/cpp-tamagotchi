#include <iostream>

#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

int main() {
  using namespace ftxui;

  auto document =  //
      vbox({
          text(L" CPP Tomagotchi ") | bold | hcenter,
          text(L" Adopt and care for a friend! ") | bold | hcenter
      }) | border;

  // Limit the size of the document to 80 char.
  document = document | size(WIDTH, LESS_THAN, 80);

  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);

  std::cout << screen.ToString() << '\0' << std::endl;

  return EXIT_SUCCESS;
}