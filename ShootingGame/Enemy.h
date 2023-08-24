#pragma once
#include"CharaBase.h"
#include"DxLib.h"
//#include"BulletsSpawner.h"
#include"NwaySpawner.h"
class GameMain;								// �O���錾
class Enemy : public CharaBase
{
private:
	float angle;								// �p�x
	float acceleration;							// ���x�̕ω���
	float angleVelocity;						// �p�x�̕ω���
	float moveX;								// �ړ����鋗��X
	float moveY;								// �ړ����鋗��Y
	int hp = 1;									// HP
	int point = 0;								// ������X�R�A
	NwaySpawner* weapon = new NwaySpawner;		// Nway�̐���
	int ShootDelay;								// Shoot�̌��^�C�~���O(n�t���[����)
	int Bcount = 1;								// �e�̗�
	int Bspeed = 5;								// �e�̃X�s�[�h
	int ShootFrame = 60;						// ���t���[��
public:

	// X���W�AY���W�A���x�A�p�x�A�X�R�A
	Enemy(float _x, float _y, float _speed, int _bspeed, float _angle, int _score, int _bcount, int _hp,int _sframe);
	~Enemy();

	void Update(GameMain* gamemain) override;	// �����̍X�V
	void Draw(int camerashake)const override;	// �`��̍X�V
	void Hit(GameMain* gamemain)override;		// �_���[�W���󂯂����̏���
	int GetPoint();								// ���g�̃X�R�A���擾
};

