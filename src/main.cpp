#include "game.h"
#include <csignal>
#include <cstdlib>
#include <ncurses.h>

void screenSetUp() {
  /**
   * @brief Set up the screen.
   * @return Nothing.
   */
  initscr();
  noecho();
  refresh();
  start_color();
}

void exitCleanup(int /*_*/) {
  /**
   * @brief Clean up the screen.
   * @return Nothing.
   */
  endwin();
  std::system("clear");
  exit(0);
}

auto main() -> int {
  /**
   * @brief Main function.
   * @return 0 on success.
   */
  signal(SIGQUIT, exitCleanup);

  screenSetUp();
  Game game;
  game.run();

  return 0;
}
