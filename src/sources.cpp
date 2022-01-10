#include <vultr.h>

void use_game_memory(void *m) { Vultr::g_game_memory = static_cast<Vultr::GameMemory *>(m); }
void vultr_init(void) {}
void vultr_update(void) {}
