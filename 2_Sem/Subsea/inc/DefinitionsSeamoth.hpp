#ifndef INC_SUBSEA_DEFINITIONSSEAMOTH_HPP
#define INC_SUBSEA_DEFINITIONSSEAMOTH_HPP

namespace wlf
{
	float m_maxSpeed = 500; // Максимальная скорость Мотылька
	int m_clip = 8; // Вместительность магазина
	int m_ammo = 8; // Кол-во торпед в магазине

	int m_bulletR = 10; // Размер пули
	float m_bulletSpeed = 500; // Скорость пули
	float m_bulletLifeTime = 5; // Время жизни пули (сек)
	float m_bulletCD = 1; // Время перезарядки пули (сек)

	int m_torpedotR = 20; // Размер торпеды
	float m_torpedoSpeed = 300; // Скорость торпеды
	float m_torpedoLifeTime = 10; // Время жизни торпеды (сек)
	float m_torpedoCD = 2; // Время перезарядки торпеды (сек)
}

#endif //INC_SUBSEA_DEFINITIONSSEAMOTH_HPP
