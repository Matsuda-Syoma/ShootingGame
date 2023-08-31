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
	float Normalize = 0;						// ��΂�����
	int hp = 1;									// HP
	int Maxhp;
	int point = 0;								// ������X�R�A
	NwaySpawner* weapon = new NwaySpawner;		// Nway�̐���
	int ShootDelay;								// Shoot�̌��^�C�~���O(n�t���[����)
	int Bcount = 1;								// �e�̗�
	int Bspeed = 5;								// �e�̃X�s�[�h
	int Bsize = 4;								// �e�̃T�C�Y
	int ShootFrame = 60;						// ���t���[��
	int StopFrame = -1;							// �~�܂�t���[��
	bool BossFlg;
	int HpCircle;
	int BossMoveCount = 0;
	int BossMaxMoveCount;
public:

	// X���W,Y���W,���x,�e���x,�p�x,�X�R�A,�e��,HP,�e�̌��Ԋu,�~�܂�^�C�~���O
	Enemy(float _x, float _y, float _speed, int _bspeed, float _angle, int _score, int _bcount, int _hp,int _sframe, int _stop, int _bsize);
	~Enemy();

	void Update(GameMain* gamemain) override;	// �����̍X�V
	float Map(float value, float start1, float stop1, float start2, float stop2);
	void Draw(int camerashake)const override;	// �`��̍X�V
	void Hit(GameMain* gamemain)override;		// �_���[�W���󂯂����̏���
	int GetPoint();								// ���g�̃X�R�A���擾
	void SetBossFlg(bool _flg);
	void Shoot(GameMain* gamemain);
};

