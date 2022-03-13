#ifndef _HOME_ADAM_MYSTERIOUS_DUNGEON_SRC_GAME_H
#define _HOME_ADAM_MYSTERIOUS_DUNGEON_SRC_GAME_H

#include "map.h"
#include "monster.h"
#include <memory>

// TODO(adam): class 'Game' defines a non-default destructor but does not define
// a copy constructor, a copy assignment operator, a move constructor or a move
// assignment operator

class Game {
  /**
   * @brief The purpose of this class is to represent the game.
   * @details The game is represented by a map and a player.
   *          The player is represented by a character and a color.
   *          The map is represented by a vector of strings.
   *          The map is not stored within the class, only a pointer to it.
   *          The path is a vector of points.
   */
  int level{};
  Player player;
  std::unique_ptr<Map> map;
  std::vector<std::unique_ptr<Monster>> monsters;
  void initalizeMonsters(int count);
  void updateEntityPosition(Entity &entity, int dx = 0, int dy = 0);
  auto areEntitiesInVicinity(const Entity &entity1, const Entity &entity2,
                             int range) const -> bool;

public:
  Game();
  ~Game();

  void run();
  void init();
  void updatePositions();
  void render();
  void fight(Entity &attacker, Entity &defender);
  void handleInput();
  void loadLevel();
  auto isGameOver() -> bool;
  auto isLevelComplete() -> bool;
  void gameOver();
};

#endif
