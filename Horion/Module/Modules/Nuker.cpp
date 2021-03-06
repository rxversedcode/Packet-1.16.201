#include "Nuker.h"

Nuker::Nuker() : IModule(0, Category::MISC, "Break multiple blocks at once") {
	this->registerBoolSetting("auto destroy", &this->autodestroy, this->autodestroy);
	this->registerBoolSetting("veinminer", &this->veinMiner, this->veinMiner);
	this->registerIntSetting("radius", &this->nukerRadius, this->nukerRadius, 1, 5);
}

Nuker::~Nuker() {
}

const char* Nuker::getModuleName() {
	return ("Nuker");
}

void Nuker::onTick(C_GameMode* gm) {
	if (!autodestroy) return;
	vec3_ti tempPos = *gm->player->getPos();
	for (int x = -nukerRadius; x < nukerRadius; x++) {
		for (int y = -nukerRadius; y < nukerRadius; y++) {
			for (int z = -nukerRadius; z < nukerRadius; z++) {
				tempPos.x = (int)gm->player->getPos()->x + x;
				tempPos.y = (int)gm->player->getPos()->y + y;
				tempPos.z = (int)gm->player->getPos()->z + z;
				if (tempPos.y > 0 && gm->player->region->getBlock(tempPos)->toLegacy()->material->isSolid) {
					gm->destroyBlock(&tempPos, 1);
				}
			}
		}
	}
}
